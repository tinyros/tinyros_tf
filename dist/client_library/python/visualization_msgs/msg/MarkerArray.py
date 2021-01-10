import sys
python3 = True if sys.hexversion > 0x03000000 else False
import struct
import tinyros
import visualization_msgs.msg

class MarkerArray(tinyros.Message):
    __slots__ = ['markers']
    _slot_types = ['visualization_msgs.msg.Marker[]']

    def __init__(self):
        super(MarkerArray, self).__init__()
        self.markers = []

    def serialize(self, buff):
        offset = 0
        try:
            markers_length = len(self.markers)
            buff.write(_struct_I.pack(markers_length))
            offset += 4
            for i in range(0, markers_length):
                offset += self.markers[i].serialize(buff)
        except struct.error as ex:
            print('Unable to serialize messages: %s'%str(ex))
        return offset

    def deserialize(self, buff):
        offset = 0
        try:
            (markers_length,) = _struct_I.unpack(buff[offset:(offset + 4)])
            self.markers = [visualization_msgs.msg.Marker() for x in range(0, markers_length)]
            offset += 4
            for i in range(0, markers_length):
                offset += self.markers[i].deserialize(buff[offset:])
        except struct.error as ex:
            print('Unable to deserialize messages: %s'%str(ex))
        return offset

    def serializedLength(self):
        length = 0
        markers_length = len(self.markers)
        length += 4
        for i in range(0, markers_length):
            length += self.markers[i].serializedLength()
        return length

    def echo(self):
        string_echo = '{'
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
        string_echo += ']'
        string_echo += '}'
        return string_echo

    def getType(self):
        return "visualization_msgs/MarkerArray"

    def getMD5(self):
        return "032534c86d6c02fcd8eb187cf568eb46"

_struct_I = struct.Struct('<I')

