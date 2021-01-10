import sys
python3 = True if sys.hexversion > 0x03000000 else False
import struct
import tinyros
import visualization_msgs.msg

class InteractiveMarkerInit(tinyros.Message):
    __slots__ = ['server_id','seq_num','markers']
    _slot_types = ['string','uint64','visualization_msgs.msg.InteractiveMarker[]']

    def __init__(self):
        super(InteractiveMarkerInit, self).__init__()
        self.server_id = ''
        self.seq_num = 0
        self.markers = []

    def serialize(self, buff):
        offset = 0
        try:
            _x = self.server_id
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
            struct_seq_num = struct.Struct("<Q")
            buff.write(struct_seq_num.pack(self.seq_num))
            offset += 8
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
        return offset

    def deserialize(self, buff):
        offset = 0
        try:
            (length_server_id,) = _struct_I.unpack(buff[offset:(offset + 4)])
            offset += 4
            if python3:
                self.server_id = buff[offset:(offset + length_server_id)].decode('utf-8')
            else:
                self.server_id = buff[offset:(offset + length_server_id)]
            offset += length_server_id
        except struct.error as ex:
            print('Unable to deserialize messages: %s'%str(ex))
        try:
            struct_seq_num = struct.Struct("<Q")
            (self.seq_num,) = struct_seq_num.unpack(buff[offset:(offset + 8)])
            offset += 8
        except struct.error as ex:
            print('Unable to deserialize messages: %s'%str(ex))
        try:
            (markers_length,) = _struct_I.unpack(buff[offset:(offset + 4)])
            self.markers = [visualization_msgs.msg.InteractiveMarker() for x in range(0, markers_length)]
            offset += 4
            for i in range(0, markers_length):
                offset += self.markers[i].deserialize(buff[offset:])
        except struct.error as ex:
            print('Unable to deserialize messages: %s'%str(ex))
        return offset

    def serializedLength(self):
        length = 0
        server_id_x = self.server_id
        server_id_length = len(server_id_x)
        if python3 or type(server_id_x) == unicode:
            server_id_x = server_id_x.encode('utf-8')
            server_id_length = len(server_id_x)
        length += 4
        length += server_id_length
        length += 8
        markers_length = len(self.markers)
        length += 4
        for i in range(0, markers_length):
            length += self.markers[i].serializedLength()
        return length

    def echo(self):
        string_echo = '{'
        string_echo += '"server_id": "%s"'%server_id
        string_echo += '", '
        string_echo += '"seq_num": %s'%seq_num
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
        string_echo += ']'
        string_echo += '}'
        return string_echo

    def getType(self):
        return "visualization_msgs/InteractiveMarkerInit"

    def getMD5(self):
        return "b8259a8319519330ca4da698883a3e0e"

_struct_I = struct.Struct('<I')

