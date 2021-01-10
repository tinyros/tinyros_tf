package visualization_msgs

import (
    "encoding/json"
    "tiny_ros/geometry_msgs"
)

func Go_INHERIT() (uint8) { return  0 }
func Go_FIXED() (uint8) { return  1 }
func Go_VIEW_FACING() (uint8) { return  2 }
func Go_NONE() (uint8) { return  0 }
func Go_MENU() (uint8) { return  1 }
func Go_BUTTON() (uint8) { return  2 }
func Go_MOVE_AXIS() (uint8) { return  3 }
func Go_MOVE_PLANE() (uint8) { return  4 }
func Go_ROTATE_AXIS() (uint8) { return  5 }
func Go_MOVE_ROTATE() (uint8) { return  6 }
func Go_MOVE_3D() (uint8) { return  7 }
func Go_ROTATE_3D() (uint8) { return  8 }
func Go_MOVE_ROTATE_3D() (uint8) { return  9 }

type InteractiveMarkerControl struct {
    Go_name string `json:"name"`
    Go_orientation *geometry_msgs.Quaternion `json:"orientation"`
    Go_orientation_mode uint8 `json:"orientation_mode"`
    Go_interaction_mode uint8 `json:"interaction_mode"`
    Go_always_visible bool `json:"always_visible"`
    Go_markers []*Marker `json:"markers"`
    Go_independent_marker_orientation bool `json:"independent_marker_orientation"`
    Go_description string `json:"description"`
}

func NewInteractiveMarkerControl() (*InteractiveMarkerControl) {
    newInteractiveMarkerControl := new(InteractiveMarkerControl)
    newInteractiveMarkerControl.Go_name = ""
    newInteractiveMarkerControl.Go_orientation = geometry_msgs.NewQuaternion()
    newInteractiveMarkerControl.Go_orientation_mode = 0
    newInteractiveMarkerControl.Go_interaction_mode = 0
    newInteractiveMarkerControl.Go_always_visible = false
    newInteractiveMarkerControl.Go_markers = []*Marker{}
    newInteractiveMarkerControl.Go_independent_marker_orientation = false
    newInteractiveMarkerControl.Go_description = ""
    return newInteractiveMarkerControl
}

func (self *InteractiveMarkerControl) Go_initialize() {
    self.Go_name = ""
    self.Go_orientation = geometry_msgs.NewQuaternion()
    self.Go_orientation_mode = 0
    self.Go_interaction_mode = 0
    self.Go_always_visible = false
    self.Go_markers = []*Marker{}
    self.Go_independent_marker_orientation = false
    self.Go_description = ""
}

func (self *InteractiveMarkerControl) Go_serialize(buff []byte) (int) {
    offset := 0
    length_name := len(self.Go_name)
    buff[offset + 0] = byte((length_name >> (8 * 0)) & 0xFF)
    buff[offset + 1] = byte((length_name >> (8 * 1)) & 0xFF)
    buff[offset + 2] = byte((length_name >> (8 * 2)) & 0xFF)
    buff[offset + 3] = byte((length_name >> (8 * 3)) & 0xFF)
    offset += 4
    copy(buff[offset:(offset+length_name)], self.Go_name)
    offset += length_name
    offset += self.Go_orientation.Go_serialize(buff[offset:])
    buff[offset + 0] = byte((self.Go_orientation_mode >> (8 * 0)) & 0xFF)
    offset += 1
    buff[offset + 0] = byte((self.Go_interaction_mode >> (8 * 0)) & 0xFF)
    offset += 1
    if self.Go_always_visible {
        buff[offset] = byte(0x01)
    } else {
        buff[offset] = byte(0x00)
    }
    offset += 1
    length_markers := len(self.Go_markers)
    buff[offset + 0] = byte((length_markers >> (8 * 0)) & 0xFF)
    buff[offset + 1] = byte((length_markers >> (8 * 1)) & 0xFF)
    buff[offset + 2] = byte((length_markers >> (8 * 2)) & 0xFF)
    buff[offset + 3] = byte((length_markers >> (8 * 3)) & 0xFF)
    offset += 4
    for i := 0; i < length_markers; i++ {
        offset += self.Go_markers[i].Go_serialize(buff[offset:])
    }
    if self.Go_independent_marker_orientation {
        buff[offset] = byte(0x01)
    } else {
        buff[offset] = byte(0x00)
    }
    offset += 1
    length_description := len(self.Go_description)
    buff[offset + 0] = byte((length_description >> (8 * 0)) & 0xFF)
    buff[offset + 1] = byte((length_description >> (8 * 1)) & 0xFF)
    buff[offset + 2] = byte((length_description >> (8 * 2)) & 0xFF)
    buff[offset + 3] = byte((length_description >> (8 * 3)) & 0xFF)
    offset += 4
    copy(buff[offset:(offset+length_description)], self.Go_description)
    offset += length_description
    return offset
}

func (self *InteractiveMarkerControl) Go_deserialize(buff []byte) (int) {
    offset := 0
    length_name := int(buff[offset + 0] & 0xFF) << (8 * 0)
    length_name |= int(buff[offset + 1] & 0xFF) << (8 * 1)
    length_name |= int(buff[offset + 2] & 0xFF) << (8 * 2)
    length_name |= int(buff[offset + 3] & 0xFF) << (8 * 3)
    offset += 4
    self.Go_name = string(buff[offset:(offset+length_name)])
    offset += length_name
    offset += self.Go_orientation.Go_deserialize(buff[offset:])
    self.Go_orientation_mode = uint8(buff[offset + 0] & 0xFF) << (8 * 0)
    offset += 1
    self.Go_interaction_mode = uint8(buff[offset + 0] & 0xFF) << (8 * 0)
    offset += 1
    if (buff[offset] & 0xFF) != 0 {
        self.Go_always_visible = true
    } else {
        self.Go_always_visible = false
    }
    offset += 1
    length_markers := int(buff[offset + 0] & 0xFF) << (8 * 0)
    length_markers |= int(buff[offset + 1] & 0xFF) << (8 * 1)
    length_markers |= int(buff[offset + 2] & 0xFF) << (8 * 2)
    length_markers |= int(buff[offset + 3] & 0xFF) << (8 * 3)
    offset += 4
    self.Go_markers = make([]*Marker, length_markers)
    for i := 0; i < length_markers; i++ {
        self.Go_markers[i] = NewMarker()
    }
    for i := 0; i < length_markers; i++ {
        offset += self.Go_markers[i].Go_deserialize(buff[offset:])
    }
    if (buff[offset] & 0xFF) != 0 {
        self.Go_independent_marker_orientation = true
    } else {
        self.Go_independent_marker_orientation = false
    }
    offset += 1
    length_description := int(buff[offset + 0] & 0xFF) << (8 * 0)
    length_description |= int(buff[offset + 1] & 0xFF) << (8 * 1)
    length_description |= int(buff[offset + 2] & 0xFF) << (8 * 2)
    length_description |= int(buff[offset + 3] & 0xFF) << (8 * 3)
    offset += 4
    self.Go_description = string(buff[offset:(offset+length_description)])
    offset += length_description
    return offset
}

func (self *InteractiveMarkerControl) Go_serializedLength() (int) {
    length := 0
    length_name := len(self.Go_name)
    length += 4
    length += length_name
    length += self.Go_orientation.Go_serializedLength()
    length += 1
    length += 1
    length += 1
    length += 4
    length_markers := len(self.Go_markers)
    for i := 0; i < length_markers; i++ {
        length += self.Go_markers[i].Go_serializedLength()
    }
    length += 1
    length_description := len(self.Go_description)
    length += 4
    length += length_description
    return length
}

func (self *InteractiveMarkerControl) Go_echo() (string) { 
    data, _ := json.Marshal(self)
    return string(data)
}

func (self *InteractiveMarkerControl) Go_getType() (string) { return "visualization_msgs/InteractiveMarkerControl" }
func (self *InteractiveMarkerControl) Go_getMD5() (string) { return "22b3d411f6992b5b98c859d9077512ba" }
func (self *InteractiveMarkerControl) Go_getID() (uint32) { return 0 }
func (self *InteractiveMarkerControl) Go_setID(id uint32) { }

