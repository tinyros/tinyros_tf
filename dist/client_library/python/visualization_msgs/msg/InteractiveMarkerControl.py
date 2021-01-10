import sys
python3 = True if sys.hexversion > 0x03000000 else False
import struct
import tinyros
import visualization_msgs.msg
import geometry_msgs.msg

class InteractiveMarkerControl(tinyros.Message):
    __slots__ = ['name','orientation','orientation_mode','interaction_mode','always_visible','markers','independent_marker_orientation','description']
    _slot_types = ['string','geometry_msgs.msg.Quaternion','uint8','uint8','bool','visualization_msgs.msg.Marker[]','bool','string']

    INHERIT =  0
    FIXED =  1
    VIEW_FACING =  2
    NONE =  0
    MENU =  1
    BUTTON =  2
    MOVE_AXIS =  3
    MOVE_PLANE =  4
    ROTATE_AXIS =  5
    MOVE_ROTATE =  6
    MOVE_3D =  7
    ROTATE_3D =  8
    MOVE_ROTATE_3D =  9

    def __init__(self):
        super(InteractiveMarkerControl, self).__init__()
        self.name = ''
        self.orientation = geometry_msgs.msg.Quaternion()
        self.orientation_mode = 0
        self.interaction_mode = 0
        self.always_visible = False
        self.markers = []
        self.independent_marker_orientation = False
        self.description = ''

    def serialize(self, buff):
        offset = 0
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
        offset += self.orientation.serialize(buff)
        try:
            struct_orientation_mode = struct.Struct("<B")
            buff.write(struct_orientation_mode.pack(self.orientation_mode))
            offset += 1
        except struct.error as ex:
            print('Unable to serialize messages: %s'%str(ex))
        try:
            struct_interaction_mode = struct.Struct("<B")
            buff.write(struct_interaction_mode.pack(self.interaction_mode))
            offset += 1
        except struct.error as ex:
            print('Unable to serialize messages: %s'%str(ex))
        try:
            struct_always_visible = struct.Struct("<B")
            buff.write(struct_always_visible.pack(self.always_visible))
            offset += 1
        except struct.error as ex:
            print('Unable to serialize messages: %s'%str(ex))
        try:
            markers_length = len(self.markers)
            buff.write(_struct_I.pack(markers_length))
            offset += 4
            for i in range(0, markers_length):
                offset += self.markers[i].serialize(buff)
        except struct.error as ex:
            print('Unable to serialize messages: %s'%str(ex))
        try:
            struct_independent_marker_orientation = struct.Struct("<B")
            buff.write(struct_independent_marker_orientation.pack(self.independent_marker_orientation))
            offset += 1
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
        return offset

    def deserialize(self, buff):
        offset = 0
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
        offset += self.orientation.deserialize(buff[offset:])
        try:
            struct_orientation_mode = struct.Struct("<B")
            (self.orientation_mode,) = struct_orientation_mode.unpack(buff[offset:(offset + 1)])
            offset += 1
        except struct.error as ex:
            print('Unable to deserialize messages: %s'%str(ex))
        try:
            struct_interaction_mode = struct.Struct("<B")
            (self.interaction_mode,) = struct_interaction_mode.unpack(buff[offset:(offset + 1)])
            offset += 1
        except struct.error as ex:
            print('Unable to deserialize messages: %s'%str(ex))
        try:
            struct_always_visible = struct.Struct("<B")
            (self.always_visible,) = struct_always_visible.unpack(buff[offset:(offset + 1)])
            self.always_visible = bool(self.always_visible)
            offset += 1
        except struct.error as ex:
            print('Unable to deserialize messages: %s'%str(ex))
        try:
            (markers_length,) = _struct_I.unpack(buff[offset:(offset + 4)])
            self.markers = [visualization_msgs.msg.Marker() for x in range(0, markers_length)]
            offset += 4
            for i in range(0, markers_length):
                offset += self.markers[i].deserialize(buff[offset:])
        except struct.error as ex:
            print('Unable to deserialize messages: %s'%str(ex))
        try:
            struct_independent_marker_orientation = struct.Struct("<B")
            (self.independent_marker_orientation,) = struct_independent_marker_orientation.unpack(buff[offset:(offset + 1)])
            self.independent_marker_orientation = bool(self.independent_marker_orientation)
            offset += 1
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
        return offset

    def serializedLength(self):
        length = 0
        name_x = self.name
        name_length = len(name_x)
        if python3 or type(name_x) == unicode:
            name_x = name_x.encode('utf-8')
            name_length = len(name_x)
        length += 4
        length += name_length
        length += self.orientation.serializedLength()
        length += 1
        length += 1
        length += 1
        markers_length = len(self.markers)
        length += 4
        for i in range(0, markers_length):
            length += self.markers[i].serializedLength()
        length += 1
        description_x = self.description
        description_length = len(description_x)
        if python3 or type(description_x) == unicode:
            description_x = description_x.encode('utf-8')
            description_length = len(description_x)
        length += 4
        length += description_length
        return length

    def echo(self):
        string_echo = '{'
        string_echo += '"name": "%s"'%name
        string_echo += '", '
        string_echo += '"orientation": {"'
        string_echo += self.orientation.echo()
        string_echo += '}, '
        string_echo += '"orientation_mode": %s'%orientation_mode
        string_echo += ', '
        string_echo += '"interaction_mode": %s'%interaction_mode
        string_echo += ', '
        string_echo += '"always_visible": %s'%always_visible
        string_echo += ', '
        string_echo += '"markers": ['
        markers_length = len(self.markers)
        for i in range(0, markers_length):
            if i == (markers_length - 1): 
                string_echo += '{"markers%s": {'%i
                string_echo += self.markers[i].echo()
                string_echo += '}}'
            else:
                string_echo += '{"markers%s": {'%i
                string_echo += self.markers[i].echo()
                string_echo += '}}, '
        string_echo += '], '
        string_echo += '"independent_marker_orientation": %s'%independent_marker_orientation
        string_echo += ', '
        string_echo += '"description": "%s"'%description
        string_echo += '"'
        string_echo += '}'
        return string_echo

    def getType(self):
        return "visualization_msgs/InteractiveMarkerControl"

    def getMD5(self):
        return "22b3d411f6992b5b98c859d9077512ba"

_struct_I = struct.Struct('<I')

