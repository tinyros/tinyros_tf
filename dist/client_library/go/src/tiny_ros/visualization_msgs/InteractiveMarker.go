package visualization_msgs

import (
    "encoding/json"
    "tiny_ros/std_msgs"
    "tiny_ros/geometry_msgs"
    "encoding/binary"
    "math"
)


type InteractiveMarker struct {
    Go_header *std_msgs.Header `json:"header"`
    Go_pose *geometry_msgs.Pose `json:"pose"`
    Go_name string `json:"name"`
    Go_description string `json:"description"`
    Go_scale float32 `json:"scale"`
    Go_menu_entries []*MenuEntry `json:"menu_entries"`
    Go_controls []*InteractiveMarkerControl `json:"controls"`
}

func NewInteractiveMarker() (*InteractiveMarker) {
    newInteractiveMarker := new(InteractiveMarker)
    newInteractiveMarker.Go_header = std_msgs.NewHeader()
    newInteractiveMarker.Go_pose = geometry_msgs.NewPose()
    newInteractiveMarker.Go_name = ""
    newInteractiveMarker.Go_description = ""
    newInteractiveMarker.Go_scale = 0.0
    newInteractiveMarker.Go_menu_entries = []*MenuEntry{}
    newInteractiveMarker.Go_controls = []*InteractiveMarkerControl{}
    return newInteractiveMarker
}

func (self *InteractiveMarker) Go_initialize() {
    self.Go_header = std_msgs.NewHeader()
    self.Go_pose = geometry_msgs.NewPose()
    self.Go_name = ""
    self.Go_description = ""
    self.Go_scale = 0.0
    self.Go_menu_entries = []*MenuEntry{}
    self.Go_controls = []*InteractiveMarkerControl{}
}

func (self *InteractiveMarker) Go_serialize(buff []byte) (int) {
    offset := 0
    offset += self.Go_header.Go_serialize(buff[offset:])
    offset += self.Go_pose.Go_serialize(buff[offset:])
    length_name := len(self.Go_name)
    buff[offset + 0] = byte((length_name >> (8 * 0)) & 0xFF)
    buff[offset + 1] = byte((length_name >> (8 * 1)) & 0xFF)
    buff[offset + 2] = byte((length_name >> (8 * 2)) & 0xFF)
    buff[offset + 3] = byte((length_name >> (8 * 3)) & 0xFF)
    offset += 4
    copy(buff[offset:(offset+length_name)], self.Go_name)
    offset += length_name
    length_description := len(self.Go_description)
    buff[offset + 0] = byte((length_description >> (8 * 0)) & 0xFF)
    buff[offset + 1] = byte((length_description >> (8 * 1)) & 0xFF)
    buff[offset + 2] = byte((length_description >> (8 * 2)) & 0xFF)
    buff[offset + 3] = byte((length_description >> (8 * 3)) & 0xFF)
    offset += 4
    copy(buff[offset:(offset+length_description)], self.Go_description)
    offset += length_description
    bits_scale := math.Float32bits(self.Go_scale)
    binary.LittleEndian.PutUint32(buff[offset:], bits_scale)
    offset += 4
    length_menu_entries := len(self.Go_menu_entries)
    buff[offset + 0] = byte((length_menu_entries >> (8 * 0)) & 0xFF)
    buff[offset + 1] = byte((length_menu_entries >> (8 * 1)) & 0xFF)
    buff[offset + 2] = byte((length_menu_entries >> (8 * 2)) & 0xFF)
    buff[offset + 3] = byte((length_menu_entries >> (8 * 3)) & 0xFF)
    offset += 4
    for i := 0; i < length_menu_entries; i++ {
        offset += self.Go_menu_entries[i].Go_serialize(buff[offset:])
    }
    length_controls := len(self.Go_controls)
    buff[offset + 0] = byte((length_controls >> (8 * 0)) & 0xFF)
    buff[offset + 1] = byte((length_controls >> (8 * 1)) & 0xFF)
    buff[offset + 2] = byte((length_controls >> (8 * 2)) & 0xFF)
    buff[offset + 3] = byte((length_controls >> (8 * 3)) & 0xFF)
    offset += 4
    for i := 0; i < length_controls; i++ {
        offset += self.Go_controls[i].Go_serialize(buff[offset:])
    }
    return offset
}

func (self *InteractiveMarker) Go_deserialize(buff []byte) (int) {
    offset := 0
    offset += self.Go_header.Go_deserialize(buff[offset:])
    offset += self.Go_pose.Go_deserialize(buff[offset:])
    length_name := int(buff[offset + 0] & 0xFF) << (8 * 0)
    length_name |= int(buff[offset + 1] & 0xFF) << (8 * 1)
    length_name |= int(buff[offset + 2] & 0xFF) << (8 * 2)
    length_name |= int(buff[offset + 3] & 0xFF) << (8 * 3)
    offset += 4
    self.Go_name = string(buff[offset:(offset+length_name)])
    offset += length_name
    length_description := int(buff[offset + 0] & 0xFF) << (8 * 0)
    length_description |= int(buff[offset + 1] & 0xFF) << (8 * 1)
    length_description |= int(buff[offset + 2] & 0xFF) << (8 * 2)
    length_description |= int(buff[offset + 3] & 0xFF) << (8 * 3)
    offset += 4
    self.Go_description = string(buff[offset:(offset+length_description)])
    offset += length_description
    bits_scale := binary.LittleEndian.Uint32(buff[offset:])
    self.Go_scale = math.Float32frombits(bits_scale)
    offset += 4
    length_menu_entries := int(buff[offset + 0] & 0xFF) << (8 * 0)
    length_menu_entries |= int(buff[offset + 1] & 0xFF) << (8 * 1)
    length_menu_entries |= int(buff[offset + 2] & 0xFF) << (8 * 2)
    length_menu_entries |= int(buff[offset + 3] & 0xFF) << (8 * 3)
    offset += 4
    self.Go_menu_entries = make([]*MenuEntry, length_menu_entries)
    for i := 0; i < length_menu_entries; i++ {
        self.Go_menu_entries[i] = NewMenuEntry()
    }
    for i := 0; i < length_menu_entries; i++ {
        offset += self.Go_menu_entries[i].Go_deserialize(buff[offset:])
    }
    length_controls := int(buff[offset + 0] & 0xFF) << (8 * 0)
    length_controls |= int(buff[offset + 1] & 0xFF) << (8 * 1)
    length_controls |= int(buff[offset + 2] & 0xFF) << (8 * 2)
    length_controls |= int(buff[offset + 3] & 0xFF) << (8 * 3)
    offset += 4
    self.Go_controls = make([]*InteractiveMarkerControl, length_controls)
    for i := 0; i < length_controls; i++ {
        self.Go_controls[i] = NewInteractiveMarkerControl()
    }
    for i := 0; i < length_controls; i++ {
        offset += self.Go_controls[i].Go_deserialize(buff[offset:])
    }
    return offset
}

func (self *InteractiveMarker) Go_serializedLength() (int) {
    length := 0
    length += self.Go_header.Go_serializedLength()
    length += self.Go_pose.Go_serializedLength()
    length_name := len(self.Go_name)
    length += 4
    length += length_name
    length_description := len(self.Go_description)
    length += 4
    length += length_description
    length += 4
    length += 4
    length_menu_entries := len(self.Go_menu_entries)
    for i := 0; i < length_menu_entries; i++ {
        length += self.Go_menu_entries[i].Go_serializedLength()
    }
    length += 4
    length_controls := len(self.Go_controls)
    for i := 0; i < length_controls; i++ {
        length += self.Go_controls[i].Go_serializedLength()
    }
    return length
}

func (self *InteractiveMarker) Go_echo() (string) { 
    data, _ := json.Marshal(self)
    return string(data)
}

func (self *InteractiveMarker) Go_getType() (string) { return "visualization_msgs/InteractiveMarker" }
func (self *InteractiveMarker) Go_getMD5() (string) { return "9ebcf376fedf5708487702be1923ba61" }
func (self *InteractiveMarker) Go_getID() (uint32) { return 0 }
func (self *InteractiveMarker) Go_setID(id uint32) { }

