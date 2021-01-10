package visualization_msgs

import (
    "encoding/json"
)

func Go_FEEDBACK() (uint8) { return 0 }
func Go_ROSRUN() (uint8) { return 1 }
func Go_ROSLAUNCH() (uint8) { return 2 }

type MenuEntry struct {
    Go_id uint32 `json:"id"`
    Go_parent_id uint32 `json:"parent_id"`
    Go_title string `json:"title"`
    Go_command string `json:"command"`
    Go_command_type uint8 `json:"command_type"`
}

func NewMenuEntry() (*MenuEntry) {
    newMenuEntry := new(MenuEntry)
    newMenuEntry.Go_id = 0
    newMenuEntry.Go_parent_id = 0
    newMenuEntry.Go_title = ""
    newMenuEntry.Go_command = ""
    newMenuEntry.Go_command_type = 0
    return newMenuEntry
}

func (self *MenuEntry) Go_initialize() {
    self.Go_id = 0
    self.Go_parent_id = 0
    self.Go_title = ""
    self.Go_command = ""
    self.Go_command_type = 0
}

func (self *MenuEntry) Go_serialize(buff []byte) (int) {
    offset := 0
    buff[offset + 0] = byte((self.Go_id >> (8 * 0)) & 0xFF)
    buff[offset + 1] = byte((self.Go_id >> (8 * 1)) & 0xFF)
    buff[offset + 2] = byte((self.Go_id >> (8 * 2)) & 0xFF)
    buff[offset + 3] = byte((self.Go_id >> (8 * 3)) & 0xFF)
    offset += 4
    buff[offset + 0] = byte((self.Go_parent_id >> (8 * 0)) & 0xFF)
    buff[offset + 1] = byte((self.Go_parent_id >> (8 * 1)) & 0xFF)
    buff[offset + 2] = byte((self.Go_parent_id >> (8 * 2)) & 0xFF)
    buff[offset + 3] = byte((self.Go_parent_id >> (8 * 3)) & 0xFF)
    offset += 4
    length_title := len(self.Go_title)
    buff[offset + 0] = byte((length_title >> (8 * 0)) & 0xFF)
    buff[offset + 1] = byte((length_title >> (8 * 1)) & 0xFF)
    buff[offset + 2] = byte((length_title >> (8 * 2)) & 0xFF)
    buff[offset + 3] = byte((length_title >> (8 * 3)) & 0xFF)
    offset += 4
    copy(buff[offset:(offset+length_title)], self.Go_title)
    offset += length_title
    length_command := len(self.Go_command)
    buff[offset + 0] = byte((length_command >> (8 * 0)) & 0xFF)
    buff[offset + 1] = byte((length_command >> (8 * 1)) & 0xFF)
    buff[offset + 2] = byte((length_command >> (8 * 2)) & 0xFF)
    buff[offset + 3] = byte((length_command >> (8 * 3)) & 0xFF)
    offset += 4
    copy(buff[offset:(offset+length_command)], self.Go_command)
    offset += length_command
    buff[offset + 0] = byte((self.Go_command_type >> (8 * 0)) & 0xFF)
    offset += 1
    return offset
}

func (self *MenuEntry) Go_deserialize(buff []byte) (int) {
    offset := 0
    self.Go_id = uint32(buff[offset + 0] & 0xFF) << (8 * 0)
    self.Go_id |= uint32(buff[offset + 1] & 0xFF) << (8 * 1)
    self.Go_id |= uint32(buff[offset + 2] & 0xFF) << (8 * 2)
    self.Go_id |= uint32(buff[offset + 3] & 0xFF) << (8 * 3)
    offset += 4
    self.Go_parent_id = uint32(buff[offset + 0] & 0xFF) << (8 * 0)
    self.Go_parent_id |= uint32(buff[offset + 1] & 0xFF) << (8 * 1)
    self.Go_parent_id |= uint32(buff[offset + 2] & 0xFF) << (8 * 2)
    self.Go_parent_id |= uint32(buff[offset + 3] & 0xFF) << (8 * 3)
    offset += 4
    length_title := int(buff[offset + 0] & 0xFF) << (8 * 0)
    length_title |= int(buff[offset + 1] & 0xFF) << (8 * 1)
    length_title |= int(buff[offset + 2] & 0xFF) << (8 * 2)
    length_title |= int(buff[offset + 3] & 0xFF) << (8 * 3)
    offset += 4
    self.Go_title = string(buff[offset:(offset+length_title)])
    offset += length_title
    length_command := int(buff[offset + 0] & 0xFF) << (8 * 0)
    length_command |= int(buff[offset + 1] & 0xFF) << (8 * 1)
    length_command |= int(buff[offset + 2] & 0xFF) << (8 * 2)
    length_command |= int(buff[offset + 3] & 0xFF) << (8 * 3)
    offset += 4
    self.Go_command = string(buff[offset:(offset+length_command)])
    offset += length_command
    self.Go_command_type = uint8(buff[offset + 0] & 0xFF) << (8 * 0)
    offset += 1
    return offset
}

func (self *MenuEntry) Go_serializedLength() (int) {
    length := 0
    length += 4
    length += 4
    length_title := len(self.Go_title)
    length += 4
    length += length_title
    length_command := len(self.Go_command)
    length += 4
    length += length_command
    length += 1
    return length
}

func (self *MenuEntry) Go_echo() (string) { 
    data, _ := json.Marshal(self)
    return string(data)
}

func (self *MenuEntry) Go_getType() (string) { return "visualization_msgs/MenuEntry" }
func (self *MenuEntry) Go_getMD5() (string) { return "09ef68f346107bee9bb8f9c6b994b413" }
func (self *MenuEntry) Go_getID() (uint32) { return 0 }
func (self *MenuEntry) Go_setID(id uint32) { }

