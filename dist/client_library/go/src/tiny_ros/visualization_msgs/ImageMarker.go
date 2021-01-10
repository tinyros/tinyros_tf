package visualization_msgs

import (
    "encoding/json"
    "tiny_ros/std_msgs"
    "tiny_ros/geometry_msgs"
    "encoding/binary"
    "math"
    "tiny_ros/tinyros/time"
)

func Go_CIRCLE() (uint8) { return 0 }
func Go_LINE_STRIP() (uint8) { return 1 }
func Go_LINE_LIST() (uint8) { return 2 }
func Go_POLYGON() (uint8) { return 3 }
func Go_POINTS() (uint8) { return 4 }
func Go_ADD() (uint8) { return 0 }
func Go_REMOVE() (uint8) { return 1 }

type ImageMarker struct {
    Go_header *std_msgs.Header `json:"header"`
    Go_ns string `json:"ns"`
    Go_id int32 `json:"id"`
    Go_type int32 `json:"type"`
    Go_action int32 `json:"action"`
    Go_position *geometry_msgs.Point `json:"position"`
    Go_scale float32 `json:"scale"`
    Go_outline_color *std_msgs.ColorRGBA `json:"outline_color"`
    Go_filled uint8 `json:"filled"`
    Go_fill_color *std_msgs.ColorRGBA `json:"fill_color"`
    Go_lifetime *rostime.Duration `json:"lifetime"`
    Go_points []*geometry_msgs.Point `json:"points"`
    Go_outline_colors []*std_msgs.ColorRGBA `json:"outline_colors"`
}

func NewImageMarker() (*ImageMarker) {
    newImageMarker := new(ImageMarker)
    newImageMarker.Go_header = std_msgs.NewHeader()
    newImageMarker.Go_ns = ""
    newImageMarker.Go_id = 0
    newImageMarker.Go_type = 0
    newImageMarker.Go_action = 0
    newImageMarker.Go_position = geometry_msgs.NewPoint()
    newImageMarker.Go_scale = 0.0
    newImageMarker.Go_outline_color = std_msgs.NewColorRGBA()
    newImageMarker.Go_filled = 0
    newImageMarker.Go_fill_color = std_msgs.NewColorRGBA()
    newImageMarker.Go_lifetime = rostime.NewDuration()
    newImageMarker.Go_points = []*geometry_msgs.Point{}
    newImageMarker.Go_outline_colors = []*std_msgs.ColorRGBA{}
    return newImageMarker
}

func (self *ImageMarker) Go_initialize() {
    self.Go_header = std_msgs.NewHeader()
    self.Go_ns = ""
    self.Go_id = 0
    self.Go_type = 0
    self.Go_action = 0
    self.Go_position = geometry_msgs.NewPoint()
    self.Go_scale = 0.0
    self.Go_outline_color = std_msgs.NewColorRGBA()
    self.Go_filled = 0
    self.Go_fill_color = std_msgs.NewColorRGBA()
    self.Go_lifetime = rostime.NewDuration()
    self.Go_points = []*geometry_msgs.Point{}
    self.Go_outline_colors = []*std_msgs.ColorRGBA{}
}

func (self *ImageMarker) Go_serialize(buff []byte) (int) {
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
    offset += self.Go_position.Go_serialize(buff[offset:])
    bits_scale := math.Float32bits(self.Go_scale)
    binary.LittleEndian.PutUint32(buff[offset:], bits_scale)
    offset += 4
    offset += self.Go_outline_color.Go_serialize(buff[offset:])
    buff[offset + 0] = byte((self.Go_filled >> (8 * 0)) & 0xFF)
    offset += 1
    offset += self.Go_fill_color.Go_serialize(buff[offset:])
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
    length_points := len(self.Go_points)
    buff[offset + 0] = byte((length_points >> (8 * 0)) & 0xFF)
    buff[offset + 1] = byte((length_points >> (8 * 1)) & 0xFF)
    buff[offset + 2] = byte((length_points >> (8 * 2)) & 0xFF)
    buff[offset + 3] = byte((length_points >> (8 * 3)) & 0xFF)
    offset += 4
    for i := 0; i < length_points; i++ {
        offset += self.Go_points[i].Go_serialize(buff[offset:])
    }
    length_outline_colors := len(self.Go_outline_colors)
    buff[offset + 0] = byte((length_outline_colors >> (8 * 0)) & 0xFF)
    buff[offset + 1] = byte((length_outline_colors >> (8 * 1)) & 0xFF)
    buff[offset + 2] = byte((length_outline_colors >> (8 * 2)) & 0xFF)
    buff[offset + 3] = byte((length_outline_colors >> (8 * 3)) & 0xFF)
    offset += 4
    for i := 0; i < length_outline_colors; i++ {
        offset += self.Go_outline_colors[i].Go_serialize(buff[offset:])
    }
    return offset
}

func (self *ImageMarker) Go_deserialize(buff []byte) (int) {
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
    offset += self.Go_position.Go_deserialize(buff[offset:])
    bits_scale := binary.LittleEndian.Uint32(buff[offset:])
    self.Go_scale = math.Float32frombits(bits_scale)
    offset += 4
    offset += self.Go_outline_color.Go_deserialize(buff[offset:])
    self.Go_filled = uint8(buff[offset + 0] & 0xFF) << (8 * 0)
    offset += 1
    offset += self.Go_fill_color.Go_deserialize(buff[offset:])
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
    length_outline_colors := int(buff[offset + 0] & 0xFF) << (8 * 0)
    length_outline_colors |= int(buff[offset + 1] & 0xFF) << (8 * 1)
    length_outline_colors |= int(buff[offset + 2] & 0xFF) << (8 * 2)
    length_outline_colors |= int(buff[offset + 3] & 0xFF) << (8 * 3)
    offset += 4
    self.Go_outline_colors = make([]*std_msgs.ColorRGBA, length_outline_colors)
    for i := 0; i < length_outline_colors; i++ {
        self.Go_outline_colors[i] = std_msgs.NewColorRGBA()
    }
    for i := 0; i < length_outline_colors; i++ {
        offset += self.Go_outline_colors[i].Go_deserialize(buff[offset:])
    }
    return offset
}

func (self *ImageMarker) Go_serializedLength() (int) {
    length := 0
    length += self.Go_header.Go_serializedLength()
    length_ns := len(self.Go_ns)
    length += 4
    length += length_ns
    length += 4
    length += 4
    length += 4
    length += self.Go_position.Go_serializedLength()
    length += 4
    length += self.Go_outline_color.Go_serializedLength()
    length += 1
    length += self.Go_fill_color.Go_serializedLength()
    length += 4
    length += 4
    length += 4
    length_points := len(self.Go_points)
    for i := 0; i < length_points; i++ {
        length += self.Go_points[i].Go_serializedLength()
    }
    length += 4
    length_outline_colors := len(self.Go_outline_colors)
    for i := 0; i < length_outline_colors; i++ {
        length += self.Go_outline_colors[i].Go_serializedLength()
    }
    return length
}

func (self *ImageMarker) Go_echo() (string) { 
    data, _ := json.Marshal(self)
    return string(data)
}

func (self *ImageMarker) Go_getType() (string) { return "visualization_msgs/ImageMarker" }
func (self *ImageMarker) Go_getMD5() (string) { return "453bce92c8194bc4489b79af1cdf861e" }
func (self *ImageMarker) Go_getID() (uint32) { return 0 }
func (self *ImageMarker) Go_setID(id uint32) { }

