import sys
python3 = True if sys.hexversion > 0x03000000 else False
import struct
import tinyros
import visualization_msgs.msg
import std_msgs.msg
import geometry_msgs.msg

class InteractiveMarkerPose(tinyros.Message):
    __slots__ = ['header','pose','name']
    _slot_types = ['std_msgs/Header','geometry_msgs/Pose','string']

    def __init__(self):
        super(InteractiveMarkerPose, self).__init__()
        self.header = std_msgs.msg.Header()
        self.pose = geometry_msgs.msg.Pose()
        self.name = ''

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
        string_echo += '"'
        string_echo += '}'
        return string_echo

    def getType(self):
        return "visualization_msgs/InteractiveMarkerPose"

    def getMD5(self):
        return "d719f99881759f7a03f9f5411bdb7074"

_struct_I = struct.Struct('<I')

