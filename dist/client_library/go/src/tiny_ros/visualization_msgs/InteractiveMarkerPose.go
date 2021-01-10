package visualization_msgs

import (
    "encoding/json"
    "tiny_ros/std_msgs"
    "tiny_ros/geometry_msgs"
)


type InteractiveMarkerPose struct {
    Go_header *std_msgs.Header `json:"header"`
    Go_pose *geometry_msgs.Pose `json:"pose"`
    Go_name string `json:"name"`
}

func NewInteractiveMarkerPose() (*InteractiveMarkerPose) {
    newInteractiveMarkerPose := new(InteractiveMarkerPose)
    newInteractiveMarkerPose.Go_header = std_msgs.NewHeader()
    newInteractiveMarkerPose.Go_pose = geometry_msgs.NewPose()
    newInteractiveMarkerPose.Go_name = ""
    return newInteractiveMarkerPose
}

func (self *InteractiveMarkerPose) Go_initialize() {
    self.Go_header = std_msgs.NewHeader()
    self.Go_pose = geometry_msgs.NewPose()
    self.Go_name = ""
}

func (self *InteractiveMarkerPose) Go_serialize(buff []byte) (int) {
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
    return offset
}

func (self *InteractiveMarkerPose) Go_deserialize(buff []byte) (int) {
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
    return offset
}

func (self *InteractiveMarkerPose) Go_serializedLength() (int) {
    length := 0
    length += self.Go_header.Go_serializedLength()
    length += self.Go_pose.Go_serializedLength()
    length_name := len(self.Go_name)
    length += 4
    length += length_name
    return length
}

func (self *InteractiveMarkerPose) Go_echo() (string) { 
    data, _ := json.Marshal(self)
    return string(data)
}

func (self *InteractiveMarkerPose) Go_getType() (string) { return "visualization_msgs/InteractiveMarkerPose" }
func (self *InteractiveMarkerPose) Go_getMD5() (string) { return "d719f99881759f7a03f9f5411bdb7074" }
func (self *InteractiveMarkerPose) Go_getID() (uint32) { return 0 }
func (self *InteractiveMarkerPose) Go_setID(id uint32) { }

