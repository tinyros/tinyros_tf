import sys
python3 = True if sys.hexversion > 0x03000000 else False
import struct
import tinyros
import visualization_msgs.msg
import std_msgs.msg
import geometry_msgs.msg
import tinyros

class Marker(tinyros.Message):
    __slots__ = ['header','ns','id','type','action','pose','scale','color','lifetime','frame_locked','points','colors','text','mesh_resource','mesh_use_embedded_materials']
    _slot_types = ['std_msgs.msg.Header','string','int32','int32','int32','geometry_msgs.msg.Pose','geometry_msgs.msg.Vector3','std_msgs.msg.ColorRGBA','tinyros.Duration','bool','geometry_msgs.msg.Point[]','std_msgs.msg.ColorRGBA[]','string','string','bool']

    ARROW = 0
    CUBE = 1
    SPHERE = 2
    CYLINDER = 3
    LINE_STRIP = 4
    LINE_LIST = 5
    CUBE_LIST = 6
    SPHERE_LIST = 7
    POINTS = 8
    TEXT_VIEW_FACING = 9
    MESH_RESOURCE = 10
    TRIANGLE_LIST = 11
    ADD = 0
    MODIFY = 0
    DELETE = 2

    def __init__(self):
        super(Marker, self).__init__()
        self.header = std_msgs.msg.Header()
        self.ns = ''
        self.id = 0
        self.type = 0
        self.action = 0
        self.pose = geometry_msgs.msg.Pose()
        self.scale = geometry_msgs.msg.Vector3()
        self.color = std_msgs.msg.ColorRGBA()
        self.lifetime = tinyros.Duration()
        self.frame_locked = False
        self.points = []
        self.colors = []
        self.text = ''
        self.mesh_resource = ''
        self.mesh_use_embedded_materials = False

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
        offset += self.pose.serialize(buff)
        offset += self.scale.serialize(buff)
        offset += self.color.serialize(buff)
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
            struct_frame_locked = struct.Struct("<B")
            buff.write(struct_frame_locked.pack(self.frame_locked))
            offset += 1
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
            colors_length = len(self.colors)
            buff.write(_struct_I.pack(colors_length))
            offset += 4
            for i in range(0, colors_length):
                offset += self.colors[i].serialize(buff)
        except struct.error as ex:
            print('Unable to serialize messages: %s'%str(ex))
        try:
            _x = self.text
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
            _x = self.mesh_resource
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
            struct_mesh_use_embedded_materials = struct.Struct("<B")
            buff.write(struct_mesh_use_embedded_materials.pack(self.mesh_use_embedded_materials))
            offset += 1
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
        offset += self.pose.deserialize(buff[offset:])
        offset += self.scale.deserialize(buff[offset:])
        offset += self.color.deserialize(buff[offset:])
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
            struct_frame_locked = struct.Struct("<B")
            (self.frame_locked,) = struct_frame_locked.unpack(buff[offset:(offset + 1)])
            self.frame_locked = bool(self.frame_locked)
            offset += 1
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
            (colors_length,) = _struct_I.unpack(buff[offset:(offset + 4)])
            self.colors = [std_msgs.msg.ColorRGBA() for x in range(0, colors_length)]
            offset += 4
            for i in range(0, colors_length):
                offset += self.colors[i].deserialize(buff[offset:])
        except struct.error as ex:
            print('Unable to deserialize messages: %s'%str(ex))
        try:
            (length_text,) = _struct_I.unpack(buff[offset:(offset + 4)])
            offset += 4
            if python3:
                self.text = buff[offset:(offset + length_text)].decode('utf-8')
            else:
                self.text = buff[offset:(offset + length_text)]
            offset += length_text
        except struct.error as ex:
            print('Unable to deserialize messages: %s'%str(ex))
        try:
            (length_mesh_resource,) = _struct_I.unpack(buff[offset:(offset + 4)])
            offset += 4
            if python3:
                self.mesh_resource = buff[offset:(offset + length_mesh_resource)].decode('utf-8')
            else:
                self.mesh_resource = buff[offset:(offset + length_mesh_resource)]
            offset += length_mesh_resource
        except struct.error as ex:
            print('Unable to deserialize messages: %s'%str(ex))
        try:
            struct_mesh_use_embedded_materials = struct.Struct("<B")
            (self.mesh_use_embedded_materials,) = struct_mesh_use_embedded_materials.unpack(buff[offset:(offset + 1)])
            self.mesh_use_embedded_materials = bool(self.mesh_use_embedded_materials)
            offset += 1
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
        length += self.pose.serializedLength()
        length += self.scale.serializedLength()
        length += self.color.serializedLength()
        length += 4
        length += 4
        length += 1
        points_length = len(self.points)
        length += 4
        for i in range(0, points_length):
            length += self.points[i].serializedLength()
        colors_length = len(self.colors)
        length += 4
        for i in range(0, colors_length):
            length += self.colors[i].serializedLength()
        text_x = self.text
        text_length = len(text_x)
        if python3 or type(text_x) == unicode:
            text_x = text_x.encode('utf-8')
            text_length = len(text_x)
        length += 4
        length += text_length
        mesh_resource_x = self.mesh_resource
        mesh_resource_length = len(mesh_resource_x)
        if python3 or type(mesh_resource_x) == unicode:
            mesh_resource_x = mesh_resource_x.encode('utf-8')
            mesh_resource_length = len(mesh_resource_x)
        length += 4
        length += mesh_resource_length
        length += 1
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
        string_echo += '"pose": {"'
        string_echo += self.pose.echo()
        string_echo += '}, '
        string_echo += '"scale": {"'
        string_echo += self.scale.echo()
        string_echo += '}, '
        string_echo += '"color": {"'
        string_echo += self.color.echo()
        string_echo += '}, '
        string_echo += '"lifetime.sec": %s, '%lifetime.sec
        string_echo += '"lifetime.nsec": %s'%lifetime.nsec
        string_echo += ', '
        string_echo += '"frame_locked": %s'%frame_locked
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
        string_echo += '"colors": ['
        colors_length = len(self.colors)
        for i in range(0, colors_length):
            if i == (colors_length - 1): 
                string_echo += '{"colors%s": {'%i
                string_echo += self.colors[i].echo()
                string_echo += '}}'
            else:
                string_echo += '{"colors%s": {'%i
                string_echo += self.colors[i].echo()
                string_echo += '}}, '
        string_echo += '], '
        string_echo += '"text": "%s"'%text
        string_echo += '", '
        string_echo += '"mesh_resource": "%s"'%mesh_resource
        string_echo += '", '
        string_echo += '"mesh_use_embedded_materials": %s'%mesh_use_embedded_materials
        string_echo += ''
        string_echo += '}'
        return string_echo

    def getType(self):
        return "visualization_msgs/Marker"

    def getMD5(self):
        return "666484e5c1e264d98a42c3b7c44c0ac3"

_struct_I = struct.Struct('<I')

