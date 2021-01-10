package visualization_msgs

import (
    "encoding/json"
    "tiny_ros/std_msgs"
    "tiny_ros/geometry_msgs"
)

func Go_KEEP_ALIVE() (uint8) { return  0 }
func Go_POSE_UPDATE() (uint8) { return  1 }
func Go_MENU_SELECT() (uint8) { return  2 }
func Go_BUTTON_CLICK() (uint8) { return  3 }
func Go_MOUSE_DOWN() (uint8) { return  4 }
func Go_MOUSE_UP() (uint8) { return  5 }

type InteractiveMarkerFeedback struct {
    Go_header *std_msgs.Header `json:"header"`
    Go_client_id string `json:"client_id"`
    Go_marker_name string `json:"marker_name"`
    Go_control_name string `json:"control_name"`
    Go_event_type uint8 `json:"event_type"`
    Go_pose *geometry_msgs.Pose `json:"pose"`
    Go_menu_entry_id uint32 `json:"menu_entry_id"`
    Go_mouse_point *geometry_msgs.Point `json:"mouse_point"`
    Go_mouse_point_valid bool `json:"mouse_point_valid"`
}

func NewInteractiveMarkerFeedback() (*InteractiveMarkerFeedback) {
    newInteractiveMarkerFeedback := new(InteractiveMarkerFeedback)
    newInteractiveMarkerFeedback.Go_header = std_msgs.NewHeader()
    newInteractiveMarkerFeedback.Go_client_id = ""
    newInteractiveMarkerFeedback.Go_marker_name = ""
    newInteractiveMarkerFeedback.Go_control_name = ""
    newInteractiveMarkerFeedback.Go_event_type = 0
    newInteractiveMarkerFeedback.Go_pose = geometry_msgs.NewPose()
    newInteractiveMarkerFeedback.Go_menu_entry_id = 0
    newInteractiveMarkerFeedback.Go_mouse_point = geometry_msgs.NewPoint()
    newInteractiveMarkerFeedback.Go_mouse_point_valid = false
    return newInteractiveMarkerFeedback
}

func (self *InteractiveMarkerFeedback) Go_initialize() {
    self.Go_header = std_msgs.NewHeader()
    self.Go_client_id = ""
    self.Go_marker_name = ""
    self.Go_control_name = ""
    self.Go_event_type = 0
    self.Go_pose = geometry_msgs.NewPose()
    self.Go_menu_entry_id = 0
    self.Go_mouse_point = geometry_msgs.NewPoint()
    self.Go_mouse_point_valid = false
}

func (self *InteractiveMarkerFeedback) Go_serialize(buff []byte) (int) {
    offset := 0
    offset += self.Go_header.Go_serialize(buff[offset:])
    length_client_id := len(self.Go_client_id)
    buff[offset + 0] = byte((length_client_id >> (8 * 0)) & 0xFF)
    buff[offset + 1] = byte((length_client_id >> (8 * 1)) & 0xFF)
    buff[offset + 2] = byte((length_client_id >> (8 * 2)) & 0xFF)
    buff[offset + 3] = byte((length_client_id >> (8 * 3)) & 0xFF)
    offset += 4
    copy(buff[offset:(offset+length_client_id)], self.Go_client_id)
    offset += length_client_id
    length_marker_name := len(self.Go_marker_name)
    buff[offset + 0] = byte((length_marker_name >> (8 * 0)) & 0xFF)
    buff[offset + 1] = byte((length_marker_name >> (8 * 1)) & 0xFF)
    buff[offset + 2] = byte((length_marker_name >> (8 * 2)) & 0xFF)
    buff[offset + 3] = byte((length_marker_name >> (8 * 3)) & 0xFF)
    offset += 4
    copy(buff[offset:(offset+length_marker_name)], self.Go_marker_name)
    offset += length_marker_name
    length_control_name := len(self.Go_control_name)
    buff[offset + 0] = byte((length_control_name >> (8 * 0)) & 0xFF)
    buff[offset + 1] = byte((length_control_name >> (8 * 1)) & 0xFF)
    buff[offset + 2] = byte((length_control_name >> (8 * 2)) & 0xFF)
    buff[offset + 3] = byte((length_control_name >> (8 * 3)) & 0xFF)
    offset += 4
    copy(buff[offset:(offset+length_control_name)], self.Go_control_name)
    offset += length_control_name
    buff[offset + 0] = byte((self.Go_event_type >> (8 * 0)) & 0xFF)
    offset += 1
    offset += self.Go_pose.Go_serialize(buff[offset:])
    buff[offset + 0] = byte((self.Go_menu_entry_id >> (8 * 0)) & 0xFF)
    buff[offset + 1] = byte((self.Go_menu_entry_id >> (8 * 1)) & 0xFF)
    buff[offset + 2] = byte((self.Go_menu_entry_id >> (8 * 2)) & 0xFF)
    buff[offset + 3] = byte((self.Go_menu_entry_id >> (8 * 3)) & 0xFF)
    offset += 4
    offset += self.Go_mouse_point.Go_serialize(buff[offset:])
    if self.Go_mouse_point_valid {
        buff[offset] = byte(0x01)
    } else {
        buff[offset] = byte(0x00)
    }
    offset += 1
    return offset
}

func (self *InteractiveMarkerFeedback) Go_deserialize(buff []byte) (int) {
    offset := 0
    offset += self.Go_header.Go_deserialize(buff[offset:])
    length_client_id := int(buff[offset + 0] & 0xFF) << (8 * 0)
    length_client_id |= int(buff[offset + 1] & 0xFF) << (8 * 1)
    length_client_id |= int(buff[offset + 2] & 0xFF) << (8 * 2)
    length_client_id |= int(buff[offset + 3] & 0xFF) << (8 * 3)
    offset += 4
    self.Go_client_id = string(buff[offset:(offset+length_client_id)])
    offset += length_client_id
    length_marker_name := int(buff[offset + 0] & 0xFF) << (8 * 0)
    length_marker_name |= int(buff[offset + 1] & 0xFF) << (8 * 1)
    length_marker_name |= int(buff[offset + 2] & 0xFF) << (8 * 2)
    length_marker_name |= int(buff[offset + 3] & 0xFF) << (8 * 3)
    offset += 4
    self.Go_marker_name = string(buff[offset:(offset+length_marker_name)])
    offset += length_marker_name
    length_control_name := int(buff[offset + 0] & 0xFF) << (8 * 0)
    length_control_name |= int(buff[offset + 1] & 0xFF) << (8 * 1)
    length_control_name |= int(buff[offset + 2] & 0xFF) << (8 * 2)
    length_control_name |= int(buff[offset + 3] & 0xFF) << (8 * 3)
    offset += 4
    self.Go_control_name = string(buff[offset:(offset+length_control_name)])
    offset += length_control_name
    self.Go_event_type = uint8(buff[offset + 0] & 0xFF) << (8 * 0)
    offset += 1
    offset += self.Go_pose.Go_deserialize(buff[offset:])
    self.Go_menu_entry_id = uint32(buff[offset + 0] & 0xFF) << (8 * 0)
    self.Go_menu_entry_id |= uint32(buff[offset + 1] & 0xFF) << (8 * 1)
    self.Go_menu_entry_id |= uint32(buff[offset + 2] & 0xFF) << (8 * 2)
    self.Go_menu_entry_id |= uint32(buff[offset + 3] & 0xFF) << (8 * 3)
    offset += 4
    offset += self.Go_mouse_point.Go_deserialize(buff[offset:])
    if (buff[offset] & 0xFF) != 0 {
        self.Go_mouse_point_valid = true
    } else {
        self.Go_mouse_point_valid = false
    }
    offset += 1
    return offset
}

func (self *InteractiveMarkerFeedback) Go_serializedLength() (int) {
    length := 0
    length += self.Go_header.Go_serializedLength()
    length_client_id := len(self.Go_client_id)
    length += 4
    length += length_client_id
    length_marker_name := len(self.Go_marker_name)
    length += 4
    length += length_marker_name
    length_control_name := len(self.Go_control_name)
    length += 4
    length += length_control_name
    length += 1
    length += self.Go_pose.Go_serializedLength()
    length += 4
    length += self.Go_mouse_point.Go_serializedLength()
    length += 1
    return length
}

func (self *InteractiveMarkerFeedback) Go_echo() (string) { 
    data, _ := json.Marshal(self)
    return string(data)
}

func (self *InteractiveMarkerFeedback) Go_getType() (string) { return "visualization_msgs/InteractiveMarkerFeedback" }
func (self *InteractiveMarkerFeedback) Go_getMD5() (string) { return "2b2c717ae73a04857e91f4992896e58f" }
func (self *InteractiveMarkerFeedback) Go_getID() (uint32) { return 0 }
func (self *InteractiveMarkerFeedback) Go_setID(id uint32) { }

