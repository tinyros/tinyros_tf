import sys
python3 = True if sys.hexversion > 0x03000000 else False
import struct
import tinyros
import visualization_msgs.msg
import std_msgs.msg
import geometry_msgs.msg

class InteractiveMarkerFeedback(tinyros.Message):
    __slots__ = ['header','client_id','marker_name','control_name','event_type','pose','menu_entry_id','mouse_point','mouse_point_valid']
    _slot_types = ['std_msgs/Header','string','string','string','uint8','geometry_msgs/Pose','uint32','geometry_msgs/Point','bool']

    KEEP_ALIVE =  0
    POSE_UPDATE =  1
    MENU_SELECT =  2
    BUTTON_CLICK =  3
    MOUSE_DOWN =  4
    MOUSE_UP =  5

    def __init__(self):
        super(InteractiveMarkerFeedback, self).__init__()
        self.header = std_msgs.msg.Header()
        self.client_id = ''
        self.marker_name = ''
        self.control_name = ''
        self.event_type = 0
        self.pose = geometry_msgs.msg.Pose()
        self.menu_entry_id = 0
        self.mouse_point = geometry_msgs.msg.Point()
        self.mouse_point_valid = False

    def serialize(self, buff):
        offset = 0
        offset += self.header.serialize(buff)
        try:
            _x = self.client_id
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
            _x = self.marker_name
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
            _x = self.control_name
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
            struct_event_type = struct.Struct("<B")
            buff.write(struct_event_type.pack(self.event_type))
            offset += 1
        except struct.error as ex:
            print('Unable to serialize messages: %s'%str(ex))
        offset += self.pose.serialize(buff)
        try:
            buff.write(_struct_I.pack(self.menu_entry_id))
            offset += 4
        except struct.error as ex:
            print('Unable to serialize messages: %s'%str(ex))
        offset += self.mouse_point.serialize(buff)
        try:
            struct_mouse_point_valid = struct.Struct("<B")
            buff.write(struct_mouse_point_valid.pack(self.mouse_point_valid))
            offset += 1
        except struct.error as ex:
            print('Unable to serialize messages: %s'%str(ex))
        return offset

    def deserialize(self, buff):
        offset = 0
        offset += self.header.deserialize(buff[offset:])
        try:
            (length_client_id,) = _struct_I.unpack(buff[offset:(offset + 4)])
            offset += 4
            if python3:
                self.client_id = buff[offset:(offset + length_client_id)].decode('utf-8')
            else:
                self.client_id = buff[offset:(offset + length_client_id)]
            offset += length_client_id
        except struct.error as ex:
            print('Unable to deserialize messages: %s'%str(ex))
        try:
            (length_marker_name,) = _struct_I.unpack(buff[offset:(offset + 4)])
            offset += 4
            if python3:
                self.marker_name = buff[offset:(offset + length_marker_name)].decode('utf-8')
            else:
                self.marker_name = buff[offset:(offset + length_marker_name)]
            offset += length_marker_name
        except struct.error as ex:
            print('Unable to deserialize messages: %s'%str(ex))
        try:
            (length_control_name,) = _struct_I.unpack(buff[offset:(offset + 4)])
            offset += 4
            if python3:
                self.control_name = buff[offset:(offset + length_control_name)].decode('utf-8')
            else:
                self.control_name = buff[offset:(offset + length_control_name)]
            offset += length_control_name
        except struct.error as ex:
            print('Unable to deserialize messages: %s'%str(ex))
        try:
            struct_event_type = struct.Struct("<B")
            (self.event_type,) = struct_event_type.unpack(buff[offset:(offset + 1)])
            offset += 1
        except struct.error as ex:
            print('Unable to deserialize messages: %s'%str(ex))
        offset += self.pose.deserialize(buff[offset:])
        try:
            (self.menu_entry_id,) = _struct_I.unpack(buff[offset:(offset + 4)])
            offset += 4
        except struct.error as ex:
            print('Unable to deserialize messages: %s'%str(ex))
        offset += self.mouse_point.deserialize(buff[offset:])
        try:
            struct_mouse_point_valid = struct.Struct("<B")
            (self.mouse_point_valid,) = struct_mouse_point_valid.unpack(buff[offset:(offset + 1)])
            self.mouse_point_valid = bool(self.mouse_point_valid)
            offset += 1
        except struct.error as ex:
            print('Unable to deserialize messages: %s'%str(ex))
        return offset

    def serializedLength(self):
        length = 0
        length += self.header.serializedLength()
        client_id_x = self.client_id
        client_id_length = len(client_id_x)
        if python3 or type(client_id_x) == unicode:
            client_id_x = client_id_x.encode('utf-8')
            client_id_length = len(client_id_x)
        length += 4
        length += client_id_length
        marker_name_x = self.marker_name
        marker_name_length = len(marker_name_x)
        if python3 or type(marker_name_x) == unicode:
            marker_name_x = marker_name_x.encode('utf-8')
            marker_name_length = len(marker_name_x)
        length += 4
        length += marker_name_length
        control_name_x = self.control_name
        control_name_length = len(control_name_x)
        if python3 or type(control_name_x) == unicode:
            control_name_x = control_name_x.encode('utf-8')
            control_name_length = len(control_name_x)
        length += 4
        length += control_name_length
        length += 1
        length += self.pose.serializedLength()
        length += 4
        length += self.mouse_point.serializedLength()
        length += 1
        return length

    def echo(self):
        string_echo = '{'
        string_echo += '"header": {"'
        string_echo += self.header.echo()
        string_echo += '}, '
        string_echo += '"client_id": "%s"'%client_id
        string_echo += '", '
        string_echo += '"marker_name": "%s"'%marker_name
        string_echo += '", '
        string_echo += '"control_name": "%s"'%control_name
        string_echo += '", '
        string_echo += '"event_type": %s'%event_type
        string_echo += ', '
        string_echo += '"pose": {"'
        string_echo += self.pose.echo()
        string_echo += '}, '
        string_echo += '"menu_entry_id": %s'%menu_entry_id
        string_echo += ', '
        string_echo += '"mouse_point": {"'
        string_echo += self.mouse_point.echo()
        string_echo += '}, '
        string_echo += '"mouse_point_valid": %s'%mouse_point_valid
        string_echo += ''
        string_echo += '}'
        return string_echo

    def getType(self):
        return "visualization_msgs/InteractiveMarkerFeedback"

    def getMD5(self):
        return "2b2c717ae73a04857e91f4992896e58f"

_struct_I = struct.Struct('<I')

