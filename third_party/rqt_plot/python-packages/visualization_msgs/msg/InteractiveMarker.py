import sys
python3 = True if sys.hexversion > 0x03000000 else False
import struct
import tinyros
import visualization_msgs.msg
import std_msgs.msg
import geometry_msgs.msg

class InteractiveMarker(tinyros.Message):
    __slots__ = ['header','pose','name','description','scale','menu_entries','controls']
    _slot_types = ['std_msgs/Header','geometry_msgs/Pose','string','string','float32','visualization_msgs/MenuEntry[]','visualization_msgs/InteractiveMarkerControl[]']

    def __init__(self):
        super(InteractiveMarker, self).__init__()
        self.header = std_msgs.msg.Header()
        self.pose = geometry_msgs.msg.Pose()
        self.name = ''
        self.description = ''
        self.scale = 0.
        self.menu_entries = []
        self.controls = []

    def serialize(self, buff):
        offset = 0
        offset += self.header.serialize(buff)
        offset += self.pose.serialize(buff)
        try:
            _x = self.name
            length = len(_x)
            if python3 or type(_x) == unicode:
                _x = _x.encode('utf-8')
                length = len(_x)
            if python3:
                buff.write(struct.pack('<I%sB'%length, length, *_x))
            else:
                buff.write(struct.pack('<I%ss'%length, length, _x))
            offset += 4
            offset += length
        except struct.error as ex:
            print('Unable to serialize messages: %s'%str(ex))
        try:
            _x = self.description
            length = len(_x)
            if python3 or type(_x) == unicode:
                _x = _x.encode('utf-8')
                length = len(_x)
            if python3:
                buff.write(struct.pack('<I%sB'%length, length, *_x))
            else:
                buff.write(struct.pack('<I%ss'%length, length, _x))
            offset += 4
            offset += length
        except struct.error as ex:
            print('Unable to serialize messages: %s'%str(ex))
        try:
            struct_scale = struct.Struct("<f")
            buff.write(struct_scale.pack(self.scale))
            offset += 4
        except struct.error as ex:
            print('Unable to serialize messages: %s'%str(ex))
        try:
            menu_entries_length = len(self.menu_entries)
            buff.write(_struct_I.pack(menu_entries_length))
            offset += 4
            for i in range(0, menu_entries_length):
                offset += self.menu_entries[i].serialize(buff)
        except struct.error as ex:
            print('Unable to serialize messages: %s'%str(ex))
        try:
            controls_length = len(self.controls)
            buff.write(_struct_I.pack(controls_length))
            offset += 4
            for i in range(0, controls_length):
                offset += self.controls[i].serialize(buff)
        except struct.error as ex:
            print('Unable to serialize messages: %s'%str(ex))
        return offset

    def deserialize(self, buff):
        offset = 0
        offset += self.header.deserialize(buff[offset:])
        offset += self.pose.deserialize(buff[offset:])
        try:
            (length_name,) = _struct_I.unpack(buff[offset:(offset + 4)])
            offset += 4
            if python3:
                self.name = buff[offset:(offset + length_name)].decode('utf-8')
            else:
                self.name = buff[offset:(offset + length_name)]
            offset += length_name
        except struct.error as ex:
            print('Unable to deserialize messages: %s'%str(ex))
        try:
            (length_description,) = _struct_I.unpack(buff[offset:(offset + 4)])
            offset += 4
            if python3:
                self.description = buff[offset:(offset + length_description)].decode('utf-8')
            else:
                self.description = buff[offset:(offset + length_description)]
            offset += length_description
        except struct.error as ex:
            print('Unable to deserialize messages: %s'%str(ex))
        try:
            struct_scale = struct.Struct("<f")
            (self.scale,) = struct_scale.unpack(buff[offset:(offset + 4)])
            offset += 4
        except struct.error as ex:
            print('Unable to deserialize messages: %s'%str(ex))
        try:
            (menu_entries_length,) = _struct_I.unpack(buff[offset:(offset + 4)])
            self.menu_entries = [visualization_msgs.msg.MenuEntry() for x in range(0, menu_entries_length)]
            offset += 4
            for i in range(0, menu_entries_length):
                offset += self.menu_entries[i].deserialize(buff[offset:])
        except struct.error as ex:
            print('Unable to deserialize messages: %s'%str(ex))
        try:
            (controls_length,) = _struct_I.unpack(buff[offset:(offset + 4)])
            self.controls = [visualization_msgs.msg.InteractiveMarkerControl() for x in range(0, controls_length)]
            offset += 4
            for i in range(0, controls_length):
                offset += self.controls[i].deserialize(buff[offset:])
        except struct.error as ex:
            print('Unable to deserialize messages: %s'%str(ex))
        return offset

    def serializedLength(self):
        length = 0
        length += self.header.serializedLength()
        length += self.pose.serializedLength()
        name_x = self.name
        name_length = len(name_x)
        if python3 or type(name_x) == unicode:
            name_x = name_x.encode('utf-8')
            name_length = len(name_x)
        length += 4
        length += name_length
        description_x = self.description
        description_length = len(description_x)
        if python3 or type(description_x) == unicode:
            description_x = description_x.encode('utf-8')
            description_length = len(description_x)
        length += 4
        length += description_length
        length += 4
        menu_entries_length = len(self.menu_entries)
        length += 4
        for i in range(0, menu_entries_length):
            length += self.menu_entries[i].serializedLength()
        controls_length = len(self.controls)
        length += 4
        for i in range(0, controls_length):
            length += self.controls[i].serializedLength()
        return length

    def echo(self):
        string_echo = '{'
        string_echo += '"header": {"'
        string_echo += self.header.echo()
        string_echo += '}, '
        string_echo += '"pose": {"'
        string_echo += self.pose.echo()
        string_echo += '}, '
        string_echo += '"name": "%s"'%name
        string_echo += '", '
        string_echo += '"description": "%s"'%description
        string_echo += '", '
        string_echo += '"scale": %s'%scale
        string_echo += ', '
        string_echo += '"menu_entries": ['
        menu_entries_length = len(self.menu_entries)
        for i in range(0, menu_entries_length):
            if i == (menu_entries_length - 1): 
                string_echo += '{"menu_entries%s": {'%i
                string_echo += self.menu_entries[i].echo()
                string_echo += '}}'
            else:
                string_echo += '{"menu_entries%s": {'%i
                string_echo += self.menu_entries[i].echo()
                string_echo += '}}, '
        string_echo += '], '
        string_echo += '"controls": ['
        controls_length = len(self.controls)
        for i in range(0, controls_length):
            if i == (controls_length - 1): 
                string_echo += '{"controls%s": {'%i
                string_echo += self.controls[i].echo()
                string_echo += '}}'
            else:
                string_echo += '{"controls%s": {'%i
                string_echo += self.controls[i].echo()
                string_echo += '}}, '
        string_echo += ']'
        string_echo += '}'
        return string_echo

    def getType(self):
        return "visualization_msgs/InteractiveMarker"

    def getMD5(self):
        return "9ebcf376fedf5708487702be1923ba61"

_struct_I = struct.Struct('<I')

