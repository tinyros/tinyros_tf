import sys
python3 = True if sys.hexversion > 0x03000000 else False
import struct
import tinyros
import std_msgs.msg

class UInt64MultiArray(tinyros.Message):
    __slots__ = ['layout','data']
    _slot_types = ['std_msgs/MultiArrayLayout','uint64[]']

    def __init__(self):
        super(UInt64MultiArray, self).__init__()
        self.layout = std_msgs.msg.MultiArrayLayout()
        self.data = []

    def serialize(self, buff):
        offset = 0
        offset += self.layout.serialize(buff)
        try:
            data_length = len(self.data)
            buff.write(_struct_I.pack(data_length))
            offset += 4
            for i in range(0, data_length):
                try:
                    struct_datai = struct.Struct("<Q")
                    buff.write(struct_datai.pack(self.data[i]))
                    offset += 8
                except struct.error as ex:
                    print('Unable to serialize messages: %s'%str(ex))
        except struct.error as ex:
            print('Unable to serialize messages: %s'%str(ex))
        return offset

    def deserialize(self, buff):
        offset = 0
        offset += self.layout.deserialize(buff[offset:])
        try:
            (data_length,) = _struct_I.unpack(buff[offset:(offset + 4)])
            self.data = [0 for x in range(0, data_length)]
            offset += 4
            for i in range(0, data_length):
                try:
                    struct_datai = struct.Struct("<Q")
                    (self.data[i],) = struct_datai.unpack(buff[offset:(offset + 8)])
                    offset += 8
                except struct.error as ex:
                    print('Unable to deserialize messages: %s'%str(ex))
        except struct.error as ex:
            print('Unable to deserialize messages: %s'%str(ex))
        return offset

    def serializedLength(self):
        length = 0
        length += self.layout.serializedLength()
        data_length = len(self.data)
        length += 4
        for i in range(0, data_length):
            length += 8
        return length

    def echo(self):
        string_echo = '{'
        string_echo += '"layout": {"'
        string_echo += self.layout.echo()
        string_echo += '}, '
        string_echo += '"data": ['
        data_length = len(self.data)
        for i in range(0, data_length):
            if i == (data_length - 1): 
                string_echo += '{"data%s": %s'%(i,data[i])
                string_echo += '}'
            else:
                string_echo += '{"data%s": %s'%(i,data[i])
                string_echo += '}, '
        string_echo += ']'
        string_echo += '}'
        return string_echo

    def getType(self):
        return "std_msgs/UInt64MultiArray"

    def getMD5(self):
        return "a0fe08f13f702ecfc59c58150f66678a"

_struct_I = struct.Struct('<I')

