import sys
python3 = True if sys.hexversion > 0x03000000 else False
import struct
import tinyros
import std_msgs.msg

class Char(tinyros.Message):
    __slots__ = ['data']
    _slot_types = ['char']

    def __init__(self):
        super(Char, self).__init__()
        self.data = 0

    def serialize(self, buff):
        offset = 0
        try:
            struct_data = struct.Struct("<B")
            buff.write(struct_data.pack(self.data))
            offset += 1
        except struct.error as ex:
            print('Unable to serialize messages: %s'%str(ex))
        return offset

    def deserialize(self, buff):
        offset = 0
        try:
            struct_data = struct.Struct("<B")
            (self.data,) = struct_data.unpack(buff[offset:(offset + 1)])
            offset += 1
        except struct.error as ex:
            print('Unable to deserialize messages: %s'%str(ex))
        return offset

    def serializedLength(self):
        length = 0
        length += 1
        return length

    def echo(self):
        string_echo = '{'
        string_echo += '"data": "%s'%data
        string_echo += '"'
        string_echo += '}'
        return string_echo

    def getType(self):
        return "std_msgs/Char"

    def getMD5(self):
        return "18741a80dcc02fcae20538073fcb0872"

_struct_I = struct.Struct('<I')

