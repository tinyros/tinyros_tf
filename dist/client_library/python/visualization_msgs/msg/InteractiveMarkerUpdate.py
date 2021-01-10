import sys
python3 = True if sys.hexversion > 0x03000000 else False
import struct
import tinyros
import visualization_msgs.msg

class InteractiveMarkerUpdate(tinyros.Message):
    __slots__ = ['server_id','seq_num','type','markers','poses','erases']
    _slot_types = ['string','uint64','uint8','visualization_msgs.msg.InteractiveMarker[]','visualization_msgs.msg.InteractiveMarkerPose[]','string[]']

    KEEP_ALIVE =  0
    UPDATE =  1

    def __init__(self):
        super(InteractiveMarkerUpdate, self).__init__()
        self.server_id = ''
        self.seq_num = 0
        self.type = 0
        self.markers = []
        self.poses = []
        self.erases = []

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
            struct_type = struct.Struct("<B")
            buff.write(struct_type.pack(self.type))
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
            poses_length = len(self.poses)
            buff.write(_struct_I.pack(poses_length))
            offset += 4
            for i in range(0, poses_length):
                offset += self.poses[i].serialize(buff)
        except struct.error as ex:
            print('Unable to serialize messages: %s'%str(ex))
        try:
            erases_length = len(self.erases)
            buff.write(_struct_I.pack(erases_length))
            offset += 4
            for i in range(0, erases_length):
                try:
                    _x = self.erases[i]
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
            struct_type = struct.Struct("<B")
            (self.type,) = struct_type.unpack(buff[offset:(offset + 1)])
            offset += 1
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
        try:
            (poses_length,) = _struct_I.unpack(buff[offset:(offset + 4)])
            self.poses = [visualization_msgs.msg.InteractiveMarkerPose() for x in range(0, poses_length)]
            offset += 4
            for i in range(0, poses_length):
                offset += self.poses[i].deserialize(buff[offset:])
        except struct.error as ex:
            print('Unable to deserialize messages: %s'%str(ex))
        try:
            (erases_length,) = _struct_I.unpack(buff[offset:(offset + 4)])
            self.erases = ['' for x in range(0, erases_length)]
            offset += 4
            for i in range(0, erases_length):
                try:
                    (length_erasesi,) = _struct_I.unpack(buff[offset:(offset + 4)])
                    offset += 4
                    if python3:
                        self.erases[i] = buff[offset:(offset + length_erasesi)].decode('utf-8')
                    else:
                        self.erases[i] = buff[offset:(offset + length_erasesi)]
                    offset += length_erasesi
                except struct.error as ex:
                    print('Unable to deserialize messages: %s'%str(ex))
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
        length += 1
        markers_length = len(self.markers)
        length += 4
        for i in range(0, markers_length):
            length += self.markers[i].serializedLength()
        poses_length = len(self.poses)
        length += 4
        for i in range(0, poses_length):
            length += self.poses[i].serializedLength()
        erases_length = len(self.erases)
        length += 4
        for i in range(0, erases_length):
            erasesi_x = self.erases[i]
            erasesi_length = len(erasesi_x)
            if python3 or type(erasesi_x) == unicode:
                erasesi_x = erasesi_x.encode('utf-8')
                erasesi_length = len(erasesi_x)
            length += 4
            length += erasesi_length
        return length

    def echo(self):
        string_echo = '{'
        string_echo += '"server_id": "%s"'%server_id
        string_echo += '", '
        string_echo += '"seq_num": %s'%seq_num
        string_echo += ', '
        string_echo += '"type": %s'%type
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
        string_echo += '"poses": ['
        poses_length = len(self.poses)
        for i in range(0, poses_length):
            if i == (poses_length - 1): 
                string_echo += '{"poses%s": {'%i
                string_echo += self.poses[i].echo()
                string_echo += '}}'
            else:
                string_echo += '{"poses%s": {'%i
                string_echo += self.poses[i].echo()
                string_echo += '}}, '
        string_echo += '], '
        string_echo += '"erases": ['
        erases_length = len(self.erases)
        for i in range(0, erases_length):
            if i == (erases_length - 1): 
                string_echo += '"erases[i]": "%s"'%erases[i]
                string_echo += '"'
            else:
                string_echo += '"erases[i]": "%s"'%erases[i]
                string_echo += '", '
        string_echo += ']'
        string_echo += '}'
        return string_echo

    def getType(self):
        return "visualization_msgs/InteractiveMarkerUpdate"

    def getMD5(self):
        return "ae37189a6cc8de1bae3ccd7710af4288"

_struct_I = struct.Struct('<I')

