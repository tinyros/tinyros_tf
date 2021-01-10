import sys
python3 = True if sys.hexversion > 0x03000000 else False
import struct
import tinyros
import visualization_msgs.msg

class MenuEntry(tinyros.Message):
    __slots__ = ['id','parent_id','title','command','command_type']
    _slot_types = ['uint32','uint32','string','string','uint8']

    FEEDBACK = 0
    ROSRUN = 1
    ROSLAUNCH = 2

    def __init__(self):
        super(MenuEntry, self).__init__()
        self.id = 0
        self.parent_id = 0
        self.title = ''
        self.command = ''
        self.command_type = 0

    def serialize(self, buff):
        offset = 0
        try:
            buff.write(_struct_I.pack(self.id))
            offset += 4
        except struct.error as ex:
            print('Unable to serialize messages: %s'%str(ex))
        try:
            buff.write(_struct_I.pack(self.parent_id))
            offset += 4
        except struct.error as ex:
            print('Unable to serialize messages: %s'%str(ex))
        try:
            _x = self.title
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
            _x = self.command
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
            struct_command_type = struct.Struct("<B")
            buff.write(struct_command_type.pack(self.command_type))
            offset += 1
        except struct.error as ex:
            print('Unable to serialize messages: %s'%str(ex))
        return offset

    def deserialize(self, buff):
        offset = 0
        try:
            (self.id,) = _struct_I.unpack(buff[offset:(offset + 4)])
            offset += 4
        except struct.error as ex:
            print('Unable to deserialize messages: %s'%str(ex))
        try:
            (self.parent_id,) = _struct_I.unpack(buff[offset:(offset + 4)])
            offset += 4
        except struct.error as ex:
            print('Unable to deserialize messages: %s'%str(ex))
        try:
            (length_title,) = _struct_I.unpack(buff[offset:(offset + 4)])
            offset += 4
            if python3:
                self.title = buff[offset:(offset + length_title)].decode('utf-8')
            else:
                self.title = buff[offset:(offset + length_title)]
            offset += length_title
        except struct.error as ex:
            print('Unable to deserialize messages: %s'%str(ex))
        try:
            (length_command,) = _struct_I.unpack(buff[offset:(offset + 4)])
            offset += 4
            if python3:
                self.command = buff[offset:(offset + length_command)].decode('utf-8')
            else:
                self.command = buff[offset:(offset + length_command)]
            offset += length_command
        except struct.error as ex:
            print('Unable to deserialize messages: %s'%str(ex))
        try:
            struct_command_type = struct.Struct("<B")
            (self.command_type,) = struct_command_type.unpack(buff[offset:(offset + 1)])
            offset += 1
        except struct.error as ex:
            print('Unable to deserialize messages: %s'%str(ex))
        return offset

    def serializedLength(self):
        length = 0
        length += 4
        length += 4
        title_x = self.title
        title_length = len(title_x)
        if python3 or type(title_x) == unicode:
            title_x = title_x.encode('utf-8')
            title_length = len(title_x)
        length += 4
        length += title_length
        command_x = self.command
        command_length = len(command_x)
        if python3 or type(command_x) == unicode:
            command_x = command_x.encode('utf-8')
            command_length = len(command_x)
        length += 4
        length += command_length
        length += 1
        return length

    def echo(self):
        string_echo = '{'
        string_echo += '"id": %s'%id
        string_echo += ', '
        string_echo += '"parent_id": %s'%parent_id
        string_echo += ', '
        string_echo += '"title": "%s"'%title
        string_echo += '", '
        string_echo += '"command": "%s"'%command
        string_echo += '", '
        string_echo += '"command_type": %s'%command_type
        string_echo += ''
        string_echo += '}'
        return string_echo

    def getType(self):
        return "visualization_msgs/MenuEntry"

    def getMD5(self):
        return "09ef68f346107bee9bb8f9c6b994b413"

_struct_I = struct.Struct('<I')

