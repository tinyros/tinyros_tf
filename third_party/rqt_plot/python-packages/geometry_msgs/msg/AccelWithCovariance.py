import sys
python3 = True if sys.hexversion > 0x03000000 else False
import struct
import tinyros
import geometry_msgs.msg

class AccelWithCovariance(tinyros.Message):
    __slots__ = ['accel','covariance']
    _slot_types = ['geometry_msgs/Accel','float64[36]']

    def __init__(self):
        super(AccelWithCovariance, self).__init__()
        self.accel = geometry_msgs.msg.Accel()
        self.covariance = [0. for x in range(0, 36)]

    def serialize(self, buff):
        offset = 0
        offset += self.accel.serialize(buff)
        try:
            for i in range(0, 36):
                try:
                    struct_covariancei = struct.Struct("<d")
                    buff.write(struct_covariancei.pack(self.covariance[i]))
                    offset += 8
                except struct.error as ex:
                    print('Unable to serialize messages: %s'%str(ex))
        except struct.error as ex:
            print('Unable to serialize messages: %s'%str(ex))
        return offset

    def deserialize(self, buff):
        offset = 0
        offset += self.accel.deserialize(buff[offset:])
        try:
            self.covariance = [0. for x in range(0, 36)]
            for i in range(0, 36):
                try:
                    struct_covariancei = struct.Struct("<d")
                    (self.covariance[i],) = struct_covariancei.unpack(buff[offset:(offset + 8)])
                    offset += 8
                except struct.error as ex:
                    print('Unable to deserialize messages: %s'%str(ex))
        except struct.error as ex:
            print('Unable to deserialize messages: %s'%str(ex))
        return offset

    def serializedLength(self):
        length = 0
        length += self.accel.serializedLength()
        for i in range(0, 36):
            length += 8
        return length

    def echo(self):
        string_echo = '{'
        string_echo += '"accel": {"'
        string_echo += self.accel.echo()
        string_echo += '}, '
        string_echo += '"covariance": ['
        for i in range(0, 36):
            if i == (36 - 1): 
                string_echo += '{"covariance%s": %s'%(i,covariance[i])
                string_echo += '}'
            else:
                string_echo += '{"covariance%s": %s'%(i,covariance[i])
                string_echo += '}, '
        string_echo += ']'
        string_echo += '}'
        return string_echo

    def getType(self):
        return "geometry_msgs/AccelWithCovariance"

    def getMD5(self):
        return "6c9c3b4380e0391a48b0a1be79b38ac6"

_struct_I = struct.Struct('<I')

