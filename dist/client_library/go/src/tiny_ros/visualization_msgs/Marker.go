package visualization_msgs

import (
    "encoding/json"
    "tiny_ros/std_msgs"
    "tiny_ros/geometry_msgs"
    "tiny_ros/tinyros/time"
)

func Go_ARROW() (uint8) { return 0 }
func Go_CUBE() (uint8) { return 1 }
func Go_SPHERE() (uint8) { return 2 }
func Go_CYLINDER() (uint8) { return 3 }
func Go_LINE_STRIP() (uint8) { return 4 }
func Go_LINE_LIST() (uint8) { return 5 }
func Go_CUBE_LIST() (uint8) { return 6 }
func Go_SPHERE_LIST() (uint8) { return 7 }
func Go_POINTS() (uint8) { return 8 }
func Go_TEXT_VIEW_FACING() (uint8) { return 9 }
func Go_MESH_RESOURCE() (uint8) { return 10 }
func Go_TRIANGLE_LIST() (uint8) { return 11 }
func Go_ADD() (uint8) { return 0 }
func Go_MODIFY() (uint8) { return 0 }
func Go_DELETE() (uint8) { return 2 }

type Marker struct {
    Go_header *std_msgs.Header `json:"header"`
    Go_ns string `json:"ns"`
    Go_id int32 `json:"id"`
    Go_type int32 `json:"type"`
    Go_action int32 `json:"action"`
    Go_pose *geometry_msgs.Pose `json:"pose"`
    Go_scale *geometry_msgs.Vector3 `json:"scale"`
    Go_color *std_msgs.ColorRGBA `json:"color"`
    Go_lifetime *rostime.Duration `json:"lifetime"`
    Go_frame_locked bool `json:"frame_locked"`
    Go_points []*geometry_msgs.Point `json:"points"`
    Go_colors []*std_msgs.ColorRGBA `json:"colors"`
    Go_text string `json:"text"`
    Go_mesh_resource string `json:"mesh_resource"`
    Go_mesh_use_embedded_materials bool `json:"mesh_use_embedded_materials"`
}

func NewMarker() (*Marker) {
    newMarker := new(Marker)
    newMarker.Go_header = std_msgs.NewHeader()
    newMarker.Go_ns = ""
    newMarker.Go_id = 0
    newMarker.Go_type = 0
    newMarker.Go_action = 0
    newMarker.Go_pose = geometry_msgs.NewPose()
    newMarker.Go_scale = geometry_msgs.NewVector3()
    newMarker.Go_color = std_msgs.NewColorRGBA()
    newMarker.Go_lifetime = rostime.NewDuration()
    newMarker.Go_frame_locked = false
    newMarker.Go_points = []*geometry_msgs.Point{}
    newMarker.Go_colors = []*std_msgs.ColorRGBA{}
    newMarker.Go_text = ""
    newMarker.Go_mesh_resource = ""
    newMarker.Go_mesh_use_embedded_materials = false
    return newMarker
}

func (self *Marker) Go_initialize() {
    self.Go_header = std_msgs.NewHeader()
    self.Go_ns = ""
    self.Go_id = 0
    self.Go_type = 0
    self.Go_action = 0
    self.Go_pose = geometry_msgs.NewPose()
    self.Go_scale = geometry_msgs.NewVector3()
    self.Go_color = std_msgs.NewColorRGBA()
    self.Go_lifetime = rostime.NewDuration()
    self.Go_frame_locked = false
    self.Go_points = []*geometry_msgs.Point{}
    self.Go_colors = []*std_msgs.ColorRGBA{}
    self.Go_text = ""
    self.Go_mesh_resource = ""
    self.Go_mesh_use_embedded_materials = false
}

func (self *Marker) Go_serialize(buff []byte) (int) {
    offset := 0
    offset += self.Go_header.Go_serialize(buff[offset:])
    length_ns := len(self.Go_ns)
    buff[offset + 0] = byte((length_ns >> (8 * 0)) & 0xFF)
    buff[offset + 1] = byte((length_ns >> (8 * 1)) & 0xFF)
    buff[offset + 2] = byte((length_ns >> (8 * 2)) & 0xFF)
    buff[offset + 3] = byte((length_ns >> (8 * 3)) & 0xFF)
    offset += 4
    copy(buff[offset:(offset+length_ns)], self.Go_ns)
    offset += length_ns
    buff[offset + 0] = byte((self.Go_id >> (8 * 0)) & 0xFF)
    buff[offset + 1] = byte((self.Go_id >> (8 * 1)) & 0xFF)
    buff[offset + 2] = byte((self.Go_id >> (8 * 2)) & 0xFF)
    buff[offset + 3] = byte((self.Go_id >> (8 * 3)) & 0xFF)
    offset += 4
    buff[offset + 0] = byte((self.Go_type >> (8 * 0)) & 0xFF)
    buff[offset + 1] = byte((self.Go_type >> (8 * 1)) & 0xFF)
    buff[offset + 2] = byte((self.Go_type >> (8 * 2)) & 0xFF)
    buff[offset + 3] = byte((self.Go_type >> (8 * 3)) & 0xFF)
    offset += 4
    buff[offset + 0] = byte((self.Go_action >> (8 * 0)) & 0xFF)
    buff[offset + 1] = byte((self.Go_action >> (8 * 1)) & 0xFF)
    buff[offset + 2] = byte((self.Go_action >> (8 * 2)) & 0xFF)
    buff[offset + 3] = byte((self.Go_action >> (8 * 3)) & 0xFF)
    offset += 4
    offset += self.Go_pose.Go_serialize(buff[offset:])
    offset += self.Go_scale.Go_serialize(buff[offset:])
    offset += self.Go_color.Go_serialize(buff[offset:])
    buff[offset + 0] = byte((self.Go_lifetime.Go_sec >> (8 * 0)) & 0xFF)
    buff[offset + 1] = byte((self.Go_lifetime.Go_sec >> (8 * 1)) & 0xFF)
    buff[offset + 2] = byte((self.Go_lifetime.Go_sec >> (8 * 2)) & 0xFF)
    buff[offset + 3] = byte((self.Go_lifetime.Go_sec >> (8 * 3)) & 0xFF)
    offset += 4
    buff[offset + 0] = byte((self.Go_lifetime.Go_nsec >> (8 * 0)) & 0xFF)
    buff[offset + 1] = byte((self.Go_lifetime.Go_nsec >> (8 * 1)) & 0xFF)
    buff[offset + 2] = byte((self.Go_lifetime.Go_nsec >> (8 * 2)) & 0xFF)
    buff[offset + 3] = byte((self.Go_lifetime.Go_nsec >> (8 * 3)) & 0xFF)
    offset += 4
    if self.Go_frame_locked {
        buff[offset] = byte(0x01)
    } else {
        buff[offset] = byte(0x00)
    }
    offset += 1
    length_points := len(self.Go_points)
    buff[offset + 0] = byte((length_points >> (8 * 0)) & 0xFF)
    buff[offset + 1] = byte((length_points >> (8 * 1)) & 0xFF)
    buff[offset + 2] = byte((length_points >> (8 * 2)) & 0xFF)
    buff[offset + 3] = byte((length_points >> (8 * 3)) & 0xFF)
    offset += 4
    for i := 0; i < length_points; i++ {
        offset += self.Go_points[i].Go_serialize(buff[offset:])
    }
    length_colors := len(self.Go_colors)
    buff[offset + 0] = byte((length_colors >> (8 * 0)) & 0xFF)
    buff[offset + 1] = byte((length_colors >> (8 * 1)) & 0xFF)
    buff[offset + 2] = byte((length_colors >> (8 * 2)) & 0xFF)
    buff[offset + 3] = byte((length_colors >> (8 * 3)) & 0xFF)
    offset += 4
    for i := 0; i < length_colors; i++ {
        offset += self.Go_colors[i].Go_serialize(buff[offset:])
    }
    length_text := len(self.Go_text)
    buff[offset + 0] = byte((length_text >> (8 * 0)) & 0xFF)
    buff[offset + 1] = byte((length_text >> (8 * 1)) & 0xFF)
    buff[offset + 2] = byte((length_text >> (8 * 2)) & 0xFF)
    buff[offset + 3] = byte((length_text >> (8 * 3)) & 0xFF)
    offset += 4
    copy(buff[offset:(offset+length_text)], self.Go_text)
    offset += length_text
    length_mesh_resource := len(self.Go_mesh_resource)
    buff[offset + 0] = byte((length_mesh_resource >> (8 * 0)) & 0xFF)
    buff[offset + 1] = byte((length_mesh_resource >> (8 * 1)) & 0xFF)
    buff[offset + 2] = byte((length_mesh_resource >> (8 * 2)) & 0xFF)
    buff[offset + 3] = byte((length_mesh_resource >> (8 * 3)) & 0xFF)
    offset += 4
    copy(buff[offset:(offset+length_mesh_resource)], self.Go_mesh_resource)
    offset += length_mesh_resource
    if self.Go_mesh_use_embedded_materials {
        buff[offset] = byte(0x01)
    } else {
        buff[offset] = byte(0x00)
    }
    offset += 1
    return offset
}

func (self *Marker) Go_deserialize(buff []byte) (int) {
    offset := 0
    offset += self.Go_header.Go_deserialize(buff[offset:])
    length_ns := int(buff[offset + 0] & 0xFF) << (8 * 0)
    length_ns |= int(buff[offset + 1] & 0xFF) << (8 * 1)
    length_ns |= int(buff[offset + 2] & 0xFF) << (8 * 2)
    length_ns |= int(buff[offset + 3] & 0xFF) << (8 * 3)
    offset += 4
    self.Go_ns = string(buff[offset:(offset+length_ns)])
    offset += length_ns
    self.Go_id = int32(buff[offset + 0] & 0xFF) << (8 * 0)
    self.Go_id |= int32(buff[offset + 1] & 0xFF) << (8 * 1)
    self.Go_id |= int32(buff[offset + 2] & 0xFF) << (8 * 2)
    self.Go_id |= int32(buff[offset + 3] & 0xFF) << (8 * 3)
    offset += 4
    self.Go_type = int32(buff[offset + 0] & 0xFF) << (8 * 0)
    self.Go_type |= int32(buff[offset + 1] & 0xFF) << (8 * 1)
    self.Go_type |= int32(buff[offset + 2] & 0xFF) << (8 * 2)
    self.Go_type |= int32(buff[offset + 3] & 0xFF) << (8 * 3)
    offset += 4
    self.Go_action = int32(buff[offset + 0] & 0xFF) << (8 * 0)
    self.Go_action |= int32(buff[offset + 1] & 0xFF) << (8 * 1)
    self.Go_action |= int32(buff[offset + 2] & 0xFF) << (8 * 2)
    self.Go_action |= int32(buff[offset + 3] & 0xFF) << (8 * 3)
    offset += 4
    offset += self.Go_pose.Go_deserialize(buff[offset:])
    offset += self.Go_scale.Go_deserialize(buff[offset:])
    offset += self.Go_color.Go_deserialize(buff[offset:])
    self.Go_lifetime.Go_sec = uint32(buff[offset + 0] & 0xFF) << (8 * 0)
    self.Go_lifetime.Go_sec |= uint32(buff[offset + 1] & 0xFF) << (8 * 1)
    self.Go_lifetime.Go_sec |= uint32(buff[offset + 2] & 0xFF) << (8 * 2)
    self.Go_lifetime.Go_sec |= uint32(buff[offset + 3] & 0xFF) << (8 * 3)
    offset += 4
    self.Go_lifetime.Go_nsec = uint32(buff[offset + 0] & 0xFF) << (8 * 0)
    self.Go_lifetime.Go_nsec |= uint32(buff[offset + 1] & 0xFF) << (8 * 1)
    self.Go_lifetime.Go_nsec |= uint32(buff[offset + 2] & 0xFF) << (8 * 2)
    self.Go_lifetime.Go_nsec |= uint32(buff[offset + 3] & 0xFF) << (8 * 3)
    offset += 4
    if (buff[offset] & 0xFF) != 0 {
        self.Go_frame_locked = true
    } else {
        self.Go_frame_locked = false
    }
    offset += 1
    length_points := int(buff[offset + 0] & 0xFF) << (8 * 0)
    length_points |= int(buff[offset + 1] & 0xFF) << (8 * 1)
    length_points |= int(buff[offset + 2] & 0xFF) << (8 * 2)
    length_points |= int(buff[offset + 3] & 0xFF) << (8 * 3)
    offset += 4
    self.Go_points = make([]*geometry_msgs.Point, length_points)
    for i := 0; i < length_points; i++ {
        self.Go_points[i] = geometry_msgs.NewPoint()
    }
    for i := 0; i < length_points; i++ {
        offset += self.Go_points[i].Go_deserialize(buff[offset:])
    }
    length_colors := int(buff[offset + 0] & 0xFF) << (8 * 0)
    length_colors |= int(buff[offset + 1] & 0xFF) << (8 * 1)
    length_colors |= int(buff[offset + 2] & 0xFF) << (8 * 2)
    length_colors |= int(buff[offset + 3] & 0xFF) << (8 * 3)
    offset += 4
    self.Go_colors = make([]*std_msgs.ColorRGBA, length_colors)
    for i := 0; i < length_colors; i++ {
        self.Go_colors[i] = std_msgs.NewColorRGBA()
    }
    for i := 0; i < length_colors; i++ {
        offset += self.Go_colors[i].Go_deserialize(buff[offset:])
    }
    length_text := int(buff[offset + 0] & 0xFF) << (8 * 0)
    length_text |= int(buff[offset + 1] & 0xFF) << (8 * 1)
    length_text |= int(buff[offset + 2] & 0xFF) << (8 * 2)
    length_text |= int(buff[offset + 3] & 0xFF) << (8 * 3)
    offset += 4
    self.Go_text = string(buff[offset:(offset+length_text)])
    offset += length_text
    length_mesh_resource := int(buff[offset + 0] & 0xFF) << (8 * 0)
    length_mesh_resource |= int(buff[offset + 1] & 0xFF) << (8 * 1)
    length_mesh_resource |= int(buff[offset + 2] & 0xFF) << (8 * 2)
    length_mesh_resource |= int(buff[offset + 3] & 0xFF) << (8 * 3)
    offset += 4
    self.Go_mesh_resource = string(buff[offset:(offset+length_mesh_resource)])
    offset += length_mesh_resource
    if (buff[offset] & 0xFF) != 0 {
        self.Go_mesh_use_embedded_materials = true
    } else {
        self.Go_mesh_use_embedded_materials = false
    }
    offset += 1
    return offset
}

func (self *Marker) Go_serializedLength() (int) {
    length := 0
    length += self.Go_header.Go_serializedLength()
    length_ns := len(self.Go_ns)
    length += 4
    length += length_ns
    length += 4
    length += 4
    length += 4
    length += self.Go_pose.Go_serializedLength()
    length += self.Go_scale.Go_serializedLength()
    length += self.Go_color.Go_serializedLength()
    length += 4
    length += 4
    length += 1
    length += 4
    length_points := len(self.Go_points)
    for i := 0; i < length_points; i++ {
        length += self.Go_points[i].Go_serializedLength()
    }
    length += 4
    length_colors := len(self.Go_colors)
    for i := 0; i < length_colors; i++ {
        length += self.Go_colors[i].Go_serializedLength()
    }
    length_text := len(self.Go_text)
    length += 4
    length += length_text
    length_mesh_resource := len(self.Go_mesh_resource)
    length += 4
    length += length_mesh_resource
    length += 1
    return length
}

func (self *Marker) Go_echo() (string) { 
    data, _ := json.Marshal(self)
    return string(data)
}

func (self *Marker) Go_getType() (string) { return "visualization_msgs/Marker" }
func (self *Marker) Go_getMD5() (string) { return "666484e5c1e264d98a42c3b7c44c0ac3" }
func (self *Marker) Go_getID() (uint32) { return 0 }
func (self *Marker) Go_setID(id uint32) { }

