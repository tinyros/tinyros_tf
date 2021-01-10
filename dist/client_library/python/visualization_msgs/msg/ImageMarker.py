import sys
python3 = True if sys.hexversion > 0x03000000 else False
import struct
import tinyros
import visualization_msgs.msg
import std_msgs.msg
import geometry_msgs.msg
import tinyros

class ImageMarker(tinyros.Message):
    __slots__ = ['header','ns','id','type','action','position','scale','outline_color','filled','fill_color','lifetime','points','outline_colors']
    _slot_types = ['std_msgs.msg.Header','string','int32','int32','int32','geometry_msgs.msg.Point','float32','std_msgs.msg.ColorRGBA','uint8','std_msgs.msg.ColorRGBA','tinyros.Duration','geometry_msgs.msg.Point[]','std_msgs.msg.ColorRGBA[]']

    CIRCLE = 0
    LINE_STRIP = 1
    LINE_LIST = 2
    POLYGON = 3
    POINTS = 4
    ADD = 0
    REMOVE = 1

    def __init__(self):
        super(ImageMarker, self).__init__()
        self.header = std_msgs.msg.Header()
        self.ns = ''
        self.id = 0
        self.type = 0
        self.action = 0
        self.position = geometry_msgs.msg.Point()
        self.scale = 0.
        self.outline_color = std_msgs.msg.ColorRGBA()
        self.filled = 0
        self.fill_color = std_msgs.msg.ColorRGBA()
        self.lifetime = tinyros.Duration()
        self.points = []
        self.outline_colors = []

    def serialize(self, buff):
        offset = 0
        offset += self.header.serialize(buff)
        try:
            _x = self.ns
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
            struct_id = struct.Struct("<i")
            buff.write(struct_id.pack(self.id))
            offset += 4
        except struct.error as ex:
            print('Unable to serialize messages: %s'%str(ex))
        try:
            struct_type = struct.Struct("<i")
            buff.write(struct_type.pack(self.type))
            offset += 4
        except struct.error as ex:
            print('Unable to serialize messages: %s'%str(ex))
        try:
            struct_action = struct.Struct("<i")
            buff.write(struct_action.pack(self.action))
            offset += 4
        except struct.error as ex:
            print('Unable to serialize messages: %s'%str(ex))
        offset += self.position.serialize(buff)
        try:
            struct_scale = struct.Struct("<f")
            buff.write(struct_scale.pack(self.scale))
            offset += 4
        except struct.error as ex:
            print('Unable to serialize messages: %s'%str(ex))
        offset += self.outline_color.serialize(buff)
        try:
            struct_filled = struct.Struct("<B")
            buff.write(struct_filled.pack(self.filled))
            offset += 1
        except struct.error as ex:
            print('Unable to serialize messages: %s'%str(ex))
        offset += self.fill_color.serialize(buff)
        try:
            buff.write(_struct_I.pack(self.lifetime.sec))
            offset += 4
        except struct.error as ex:
            print('Unable to serialize messages: %s'%str(ex))
        try:
            buff.write(_struct_I.pack(self.lifetime.nsec))
            offset += 4
        except struct.error as ex:
            print('Unable to serialize messages: %s'%str(ex))
        try:
            points_length = len(self.points)
            buff.write(_struct_I.pack(points_length))
            offset += 4
            for i in range(0, points_length):
                offset += self.points[i].serialize(buff)
        except struct.error as ex:
            print('Unable to serialize messages: %s'%str(ex))
        try:
            outline_colors_length = len(self.outline_colors)
            buff.write(_struct_I.pack(outline_colors_length))
            offset += 4
            for i in range(0, outline_colors_length):
                offset += self.outline_colors[i].serialize(buff)
        except struct.error as ex:
            print('Unable to serialize messages: %s'%str(ex))
        return offset

    def deserialize(self, buff):
        offset = 0
        offset += self.header.deserialize(buff[offset:])
        try:
            (length_ns,) = _struct_I.unpack(buff[offset:(offset + 4)])
            offset += 4
            if python3:
                self.ns = buff[offset:(offset + length_ns)].decode('utf-8')
            else:
                self.ns = buff[offset:(offset + length_ns)]
            offset += length_ns
        except struct.error as ex:
            print('Unable to deserialize messages: %s'%str(ex))
        try:
            struct_id = struct.Struct("<i")
            (self.id,) = struct_id.unpack(buff[offset:(offset + 4)])
            offset += 4
        except struct.error as ex:
            print('Unable to deserialize messages: %s'%str(ex))
        try:
            struct_type = struct.Struct("<i")
            (self.type,) = struct_type.unpack(buff[offset:(offset + 4)])
            offset += 4
        except struct.error as ex:
            print('Unable to deserialize messages: %s'%str(ex))
        try:
            struct_action = struct.Struct("<i")
            (self.action,) = struct_action.unpack(buff[offset:(offset + 4)])
            offset += 4
        except struct.error as ex:
            print('Unable to deserialize messages: %s'%str(ex))
        offset += self.position.deserialize(buff[offset:])
        try:
            struct_scale = struct.Struct("<f")
            (self.scale,) = struct_scale.unpack(buff[offset:(offset + 4)])
            offset += 4
        except struct.error as ex:
            print('Unable to deserialize messages: %s'%str(ex))
        offset += self.outline_color.deserialize(buff[offset:])
        try:
            struct_filled = struct.Struct("<B")
            (self.filled,) = struct_filled.unpack(buff[offset:(offset + 1)])
            offset += 1
        except struct.error as ex:
            print('Unable to deserialize messages: %s'%str(ex))
        offset += self.fill_color.deserialize(buff[offset:])
        try:
            (self.lifetime.sec,) = _struct_I.unpack(buff[offset:(offset + 4)])
            offset += 4
        except struct.error as ex:
            print('Unable to deserialize messages: %s'%str(ex))
        try:
            (self.lifetime.nsec,) = _struct_I.unpack(buff[offset:(offset + 4)])
            offset += 4
        except struct.error as ex:
            print('Unable to deserialize messages: %s'%str(ex))
        try:
            (points_length,) = _struct_I.unpack(buff[offset:(offset + 4)])
            self.points = [geometry_msgs.msg.Point() for x in range(0, points_length)]
            offset += 4
            for i in range(0, points_length):
                offset += self.points[i].deserialize(buff[offset:])
        except struct.error as ex:
            print('Unable to deserialize messages: %s'%str(ex))
        try:
            (outline_colors_length,) = _struct_I.unpack(buff[offset:(offset + 4)])
            self.outline_colors = [std_msgs.msg.ColorRGBA() for x in range(0, outline_colors_length)]
            offset += 4
            for i in range(0, outline_colors_length):
                offset += self.outline_colors[i].deserialize(buff[offset:])
        except struct.error as ex:
            print('Unable to deserialize messages: %s'%str(ex))
        return offset

    def serializedLength(self):
        length = 0
        length += self.header.serializedLength()
        ns_x = self.ns
        ns_length = len(ns_x)
        if python3 or type(ns_x) == unicode:
            ns_x = ns_x.encode('utf-8')
            ns_length = len(ns_x)
        length += 4
        length += ns_length
        length += 4
        length += 4
        length += 4
        length += self.position.serializedLength()
        length += 4
        length += self.outline_color.serializedLength()
        length += 1
        length += self.fill_color.serializedLength()
        length += 4
        length += 4
        points_length = len(self.points)
        length += 4
        for i in range(0, points_length):
            length += self.points[i].serializedLength()
        outline_colors_length = len(self.outline_colors)
        length += 4
        for i in range(0, outline_colors_length):
            length += self.outline_colors[i].serializedLength()
        return length

    def echo(self):
        string_echo = '{'
        string_echo += '"header": {"'
        string_echo += self.header.echo()
        string_echo += '}, '
        string_echo += '"ns": "%s"'%ns
        string_echo += '", '
        string_echo += '"id": %s'%id
        string_echo += ', '
        string_echo += '"type": %s'%type
        string_echo += ', '
        string_echo += '"action": %s'%action
        string_echo += ', '
        string_echo += '"position": {"'
        string_echo += self.position.echo()
        string_echo += '}, '
        string_echo += '"scale": %s'%scale
        string_echo += ', '
        string_echo += '"outline_color": {"'
        string_echo += self.outline_color.echo()
        string_echo += '}, '
        string_echo += '"filled": %s'%filled
        string_echo += ', '
        string_echo += '"fill_color": {"'
        string_echo += self.fill_color.echo()
        string_echo += '}, '
        string_echo += '"lifetime.sec": %s, '%lifetime.sec
        string_echo += '"lifetime.nsec": %s'%lifetime.nsec
        string_echo += ', '
        string_echo += '"points": ['
        points_length = len(self.points)
        for i in range(0, points_length):
            if i == (points_length - 1): 
                string_echo += '{"points%s": {'%i
                string_echo += self.points[i].echo()
                string_echo += '}}'
            else:
                string_echo += '{"points%s": {'%i
                string_echo += self.points[i].echo()
                string_echo += '}}, '
        string_echo += '], '
        string_echo += '"outline_colors": ['
        outline_colors_length = len(self.outline_colors)
        for i in range(0, outline_colors_length):
            if i == (outline_colors_length - 1): 
                string_echo += '{"outline_colors%s": {'%i
                string_echo += self.outline_colors[i].echo()
                string_echo += '}}'
            else:
                string_echo += '{"outline_colors%s": {'%i
                string_echo += self.outline_colors[i].echo()
                string_echo += '}}, '
        string_echo += ']'
        string_echo += '}'
        return string_echo

    def getType(self):
        return "visualization_msgs/ImageMarker"

    def getMD5(self):
        return "453bce92c8194bc4489b79af1cdf861e"

_struct_I = struct.Struct('<I')

