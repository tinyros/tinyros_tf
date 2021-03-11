#!/usr/bin/env python

# Copyright (c) 2011, Dorian Scholz, TU Darmstadt
# All rights reserved.
#
# Redistribution and use in source and binary forms, with or without
# modification, are permitted provided that the following conditions
# are met:
#
#   * Redistributions of source code must retain the above copyright
#     notice, this list of conditions and the following disclaimer.
#   * Redistributions in binary form must reproduce the above
#     copyright notice, this list of conditions and the following
#     disclaimer in the documentation and/or other materials provided
#     with the distribution.
#   * Neither the name of the TU Darmstadt nor the names of its
#     contributors may be used to endorse or promote products derived
#     from this software without specific prior written permission.
#
# THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
# "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
# LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS
# FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE
# COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,
# INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING,
# BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
# LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
# CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
# LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN
# ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
# POSSIBILITY OF SUCH DAMAGE.

import os
import tinyros
import sys
import math
from operator import itemgetter
from python_qt_binding import loadUi
from python_qt_binding.QtCore import Qt, QTimer, qWarning, Slot
from python_qt_binding.QtGui import QIcon
from python_qt_binding.QtWidgets import QAction, QMenu, QWidget
from python_qt_binding.QtWidgets import QCompleter

from .topic_completer import TopicCompleter

from .rosplot import ROSData, RosPlotException

primitive_types_ = ['int8','uint8','int16','uint16','int32','uint32','int64','uint64',
                    'float32','float64','string','bool','char','byte']

def get_nested_attribute(msg, nested_attributes):
    value = msg
    for attr in nested_attributes.split('/'):
        value = getattr(value, attr)
    return value

def get_array_index_or_slice_object(index_string):
    assert index_string != '', 'empty array index'
    index_string_parts = index_string.split(':')
    if len(index_string_parts) == 1:
        try:
            array_index = int(index_string_parts[0])
        except ValueError:
            assert False, "non-integer array index step '%s'" % index_string_parts[0]
        return array_index
    slice_args = [None, None, None]
    if index_string_parts[0] != '':
        try:
            slice_args[0] = int(index_string_parts[0])
        except ValueError:
            assert False, "non-integer slice start '%s'" % index_string_parts[0]
    if index_string_parts[1] != '':
        try:
            slice_args[1] = int(index_string_parts[1])
        except ValueError:
            assert False, "non-integer slice stop '%s'" % index_string_parts[1]
    if len(index_string_parts) > 2 and index_string_parts[2] != '':
            try:
                slice_args[2] = int(index_string_parts[2])
            except ValueError:
                assert False, "non-integer slice step '%s'" % index_string_parts[2]
    if len(index_string_parts) > 3:
        assert False, 'too many slice arguments'
    return slice(*slice_args)

# code adapted from rqt_plot
def msgevalgen(pattern_str):
    evals = []  # list of (field_name, slice_object) pairs
    fields = [f for f in pattern_str.split('/') if f]
    for f in fields:
        if '[' in f:
            field_name, rest = f.split('[', 1)
            if not rest.endswith(']'):
                print("missing closing ']' in slice spec '%s'" % f)
                return None
            rest = rest[:-1]  # slice content, removing closing bracket
            try:
                array_index_or_slice_object = get_array_index_or_slice_object(rest)
            except AssertionError as e:
                print("field '%s' has invalid slice argument '%s': %s" % (field_name, rest, str(e)))
                return None
            evals.append((field_name, array_index_or_slice_object))
        else:
            evals.append((f, None))
    def msgeval(msg, evals):
        for i, (field_name, slice_object) in enumerate(evals):
            try: # access field first
                msg = getattr(msg, field_name)
            except AttributeError:
                print("no field named %s in %s" % (field_name, pattern))
                return None

            if slice_object is not None: # access slice
                try:
                    msg = msg.__getitem__(slice_object)
                except IndexError as e:
                    print("%s: %s" % (str(e), pattern))
                    return None
                if isinstance(msg, list):
                    rest = evals[i + 1:]
                    return [msgeval(m, rest) for m in msg]
        return msg
    return (lambda msg: msgeval(msg, evals)) if evals else None

def get_topic_type(topic_name):
    val = tinyros.nh().getTopicList()
    # exact match first, followed by prefix match
    topic = topic_name
    if not topic.startswith('/'):
        topic = '/' + topic_name
    matches = [(t, t_type) for t, t_type in val if t == topic]
    if not matches:
        matches = [(t, t_type) for t, t_type in val if topic.startswith(t+'/')]
        # choose longest match
        matches.sort(key=itemgetter(0), reverse=True)
        # try to ignore messages which don't have the field specified as part of the topic name
        while matches:
            t, t_type = matches[0]
            msg_class = tinyros.nh().get_message_class(t_type)
            if not msg_class:
                # if any class is not fetchable skip ignoring any message types
                break
            msg = msg_class()
            nested_attributes = topic[len(t) + 1:].rstrip('/')
            nested_attributes = nested_attributes.split('[')[0]
            if nested_attributes == '':
                break
            try:
                get_nested_attribute(msg, nested_attributes)
            except AttributeError:
                # ignore this type since it does not have the requested field
                matches.pop(0)
                continue
            matches = [(t, t_type)]
            break
    if matches:
        t, t_type = matches[0]
        return t_type, t, msgevalgen(topic[len(t):])
    else:
        return None, None, None

def parse_type(type):
    if not type:
        raise Exception("Invalid empty type")
    if '[' in type:
        var_length = type.endswith('[]')
        splits = type.split('[')
        if len(splits) > 2:
            raise Exception("Currently only support 1-dimensional array types: %s"%type)
        if var_length:
            return type[:-2], True, None
        else:
            try:
                length = int(splits[1][:-1])
                return splits[0], True, length
            except ValueError:
                raise Exception("Invalid array dimension: [%s]"%splits[1][:-1])
    else:
        return type, False, None
        
def is_valid_constant_type(x):
    return x in primitive_types_
    
def type_convert_val(type, val):
    if type in ['float32','float64']:
        return float(val)
    elif type in ['string']:
        return val.strip() #string constants are always stripped 
    elif type in ['int8', 'uint8', 'int16','uint16','int32','uint32','int64','uint64', 'char', 'byte']:
        # bounds checking
        bits = [('int8', 8), ('uint8', 8), ('int16', 16),('uint16', 16),\
                ('int32', 32),('uint32', 32), ('int64', 64),('uint64', 64),\
                ('byte', 8), ('char', 8)]
        b = [b for t, b in bits if t == type][0]
        if type[0] == 'u' or type == 'char':
            lower = 0
            upper = int(math.pow(2, b)-1)
        else:
            upper = int(math.pow(2, b-1)-1)   
            lower = -upper - 1 #two's complement min
        val = int(val) #python will autocast to long if necessary
        if val > upper or val < lower:
            raise Exception("cannot coerce [%s] to %s (out of bounds)"%(val, type))
        return val
    elif type == 'bool':
        # TODO: need to nail down constant spec for bool
        return True if eval(val) else False
    raise Exception("invalid constant type: [%s]"%type)
    
def get_type_class(type_name):
    if type_name in primitive_types_:
        if type_name == 'string':
            return str
        elif type_name == 'bool':
            return bool
        else:
            return type(type_convert_val(type_name, 0))
    else:
        return tinyros.nh().get_message_class(type_name)

def get_plot_fields(topic):
    topic_name = topic
    if not topic_name.startswith('/'):
        topic_name = '/' + topic_name
    topic_type, real_topic, _ = get_topic_type(topic_name)
    if topic_type is None:
        message = "topic %s does not exist" % ( topic_name )
        return [], message
    field_name = topic_name[len(real_topic)+1:]

    slot_type, is_array, array_size = parse_type(topic_type)
    field_class = tinyros.nh().get_message_class(slot_type)

    fields = [f for f in field_name.split('/') if f]

    for field in fields:
        # parse the field name for an array index
        try:
            field, _, field_index = parse_type(field)
        except Exception:
            message = "invalid field %s in topic %s" % ( field, real_topic )
            return [], message

        if field not in getattr(field_class, '__slots__', []):
            message = "no field %s in topic %s" % ( field_name, real_topic )
            return [], message
        slot_type = field_class._slot_types[field_class.__slots__.index(field)]
        slot_type, slot_is_array, array_size = parse_type(slot_type)
        is_array = slot_is_array and field_index is None

        field_class = get_type_class(slot_type)

    if field_class in (int, float, bool):
        topic_kind = 'boolean' if field_class == bool else 'numeric'
        if is_array:
            if array_size is not None:
                message = "topic %s is fixed-size %s array" % ( topic_name, topic_kind )
                return [ "%s[%d]" % (topic_name, i) for i in range(array_size) ], message
            else:
                message = "topic %s is variable-size %s array" % ( topic_name, topic_kind )
                return [], message
        else:
            message = "topic %s is %s" % ( topic_name, topic_kind )
            return [ topic_name ], message
    else:
        if not is_valid_constant_type(slot_type):
            numeric_fields = []
            for i, slot in enumerate(field_class.__slots__):
                slot_type = field_class._slot_types[i]
                slot_type, is_array, array_size = parse_type(slot_type)
                slot_class = get_type_class(slot_type)
                if slot_class in (int, float) and not is_array:
                    numeric_fields.append(slot)
            message = ""
            if len(numeric_fields) > 0:
                message = "%d plottable fields in %s" % ( len(numeric_fields), topic_name )
            else:
                message = "No plottable fields in %s" % ( topic_name )
            return [ "%s/%s" % (topic_name, f) for f in numeric_fields ], message
        else:
            message = "Topic %s is not numeric" % ( topic_name )
            return [], message

def is_plottable(topic_name):
    fields, message = get_plot_fields(topic_name)
    return len(fields) > 0, message

class PlotWidget(QWidget):
    _redraw_interval = 40

    def __init__(self, initial_topics=None, start_paused=False):
        super(PlotWidget, self).__init__()
        self.setObjectName('PlotWidget')

        self._initial_topics = initial_topics

        ui_file = os.path.join(os.path.abspath(os.path.dirname(os.path.abspath(__file__))), 'resource', 'plot.ui')
        loadUi(ui_file, self)
        self.subscribe_topic_button.setIcon(QIcon.fromTheme('list-add'))
        self.remove_topic_button.setIcon(QIcon.fromTheme('list-remove'))
        self.pause_button.setIcon(QIcon.fromTheme('media-playback-pause'))
        self.clear_button.setIcon(QIcon.fromTheme('edit-clear'))
        self.data_plot = None

        self.subscribe_topic_button.setEnabled(False)
        if start_paused:
            self.pause_button.setChecked(True)

        self._topic_completer = TopicCompleter(self.topic_edit)
        self._topic_completer.update_topics()
        self.topic_edit.setCompleter(self._topic_completer)

        self._start_time = tinyros.Time.now().toSec()
        self._rosdata = {}
        self._remove_topic_menu = QMenu()

        # init and start update timer for plot
        self._update_plot_timer = QTimer(self)
        self._update_plot_timer.timeout.connect(self.update_plot)

    def switch_data_plot_widget(self, data_plot):
        self.enable_timer(enabled=False)

        self.data_plot_layout.removeWidget(self.data_plot)
        if self.data_plot is not None:
            self.data_plot.close()

        self.data_plot = data_plot
        self.data_plot_layout.addWidget(self.data_plot)
        self.data_plot.autoscroll(self.autoscroll_checkbox.isChecked())

        # setup drag 'n drop
        self.data_plot.dropEvent = self.dropEvent
        self.data_plot.dragEnterEvent = self.dragEnterEvent

        if self._initial_topics:
            for topic_name in self._initial_topics:
                self.add_topic(topic_name)
            self._initial_topics = None
        else:
            for topic_name, rosdata in self._rosdata.items():
                data_x, data_y = rosdata.next()
                self.data_plot.add_curve(topic_name, topic_name, data_x, data_y)

        self._subscribed_topics_changed()

    @Slot('QDragEnterEvent*')
    def dragEnterEvent(self, event):
        # get topic name
        if not event.mimeData().hasText():
            if not hasattr(event.source(), 'selectedItems') or len(event.source().selectedItems()) == 0:
                qWarning('Plot.dragEnterEvent(): not hasattr(event.source(), selectedItems) or len(event.source().selectedItems()) == 0')
                return
            item = event.source().selectedItems()[0]
            topic_name = item.data(0, Qt.UserRole)
            if topic_name == None:
                qWarning('Plot.dragEnterEvent(): not hasattr(item, ros_topic_name_)')
                return
        else:
            topic_name = str(event.mimeData().text())

        # check for plottable field type
        plottable, message = is_plottable(topic_name)
        if plottable:
            event.acceptProposedAction()
        else:
            qWarning('Plot.dragEnterEvent(): rejecting: "%s"' % (message))

    @Slot('QDropEvent*')
    def dropEvent(self, event):
        if event.mimeData().hasText():
            topic_name = str(event.mimeData().text())
        else:
            droped_item = event.source().selectedItems()[0]
            topic_name = str(droped_item.data(0, Qt.UserRole))
        self.add_topic(topic_name)

    @Slot(str)
    def on_topic_edit_textChanged(self, topic_name):
        # on empty topic name, update topics
        if topic_name in ('', '/'):
            self._topic_completer.update_topics()

        plottable, message = is_plottable(topic_name)
        self.subscribe_topic_button.setEnabled(plottable)
        self.subscribe_topic_button.setToolTip(message)

    @Slot()
    def on_topic_edit_returnPressed(self):
        if self.subscribe_topic_button.isEnabled():
            self.add_topic(str(self.topic_edit.text()))

    @Slot()
    def on_subscribe_topic_button_clicked(self):
        self.add_topic(str(self.topic_edit.text()))

    @Slot(bool)
    def on_pause_button_clicked(self, checked):
        self.enable_timer(not checked)

    @Slot(bool)
    def on_autoscroll_checkbox_clicked(self, checked):
        self.data_plot.autoscroll(checked)
        if checked:
            self.data_plot.redraw()

    @Slot()
    def on_clear_button_clicked(self):
        self.clear_plot()

    def update_plot(self):
        if self.data_plot is not None:
            needs_redraw = False
            for topic_name, rosdata in self._rosdata.items():
                try:
                    data_x, data_y = rosdata.next()
                    if data_x or data_y:
                        self.data_plot.update_values(topic_name, data_x, data_y)
                        needs_redraw = True
                except RosPlotException as e:
                    qWarning('PlotWidget.update_plot(): error in rosplot: %s' % e)
            if needs_redraw:
                self.data_plot.redraw()

    def _subscribed_topics_changed(self):
        self._update_remove_topic_menu()
        if not self.pause_button.isChecked():
            # if pause button is not pressed, enable timer based on subscribed topics
            self.enable_timer(self._rosdata)
        self.data_plot.redraw()

    def _update_remove_topic_menu(self):
        def make_remove_topic_function(x):
            return lambda: self.remove_topic(x)

        self._remove_topic_menu.clear()
        for topic_name in sorted(self._rosdata.keys()):
            action = QAction(topic_name, self._remove_topic_menu)
            action.triggered.connect(make_remove_topic_function(topic_name))
            self._remove_topic_menu.addAction(action)

        if len(self._rosdata) > 1:
            all_action = QAction('All', self._remove_topic_menu)
            all_action.triggered.connect(self.clean_up_subscribers)
            self._remove_topic_menu.addAction(all_action)

        self.remove_topic_button.setMenu(self._remove_topic_menu)

    def add_topic(self, topic_name):
        topics_changed = False
        for topic_name in get_plot_fields(topic_name)[0]:
            if topic_name in self._rosdata:
                qWarning('PlotWidget.add_topic(): topic already subscribed: %s' % topic_name)
                continue
            self._rosdata[topic_name] = ROSData(topic_name, self._start_time)
            if self._rosdata[topic_name].error is not None:
                qWarning(str(self._rosdata[topic_name].error))
                del self._rosdata[topic_name]
            else:
                data_x, data_y = self._rosdata[topic_name].next()
                self.data_plot.add_curve(topic_name, topic_name, data_x, data_y)
                topics_changed = True

        if topics_changed:
            self._subscribed_topics_changed()

    def remove_topic(self, topic_name):
        self._rosdata[topic_name].close()
        del self._rosdata[topic_name]
        self.data_plot.remove_curve(topic_name)

        self._subscribed_topics_changed()

    def clear_plot(self):
        for topic_name, _ in self._rosdata.items():
            self.data_plot.clear_values(topic_name)
        self.data_plot.redraw()

    def clean_up_subscribers(self):
        for topic_name, rosdata in self._rosdata.items():
            rosdata.close()
            self.data_plot.remove_curve(topic_name)
        self._rosdata = {}

        self._subscribed_topics_changed()

    def enable_timer(self, enabled=True):
        if enabled:
            self._update_plot_timer.start(self._redraw_interval)
        else:
            self._update_plot_timer.stop()
