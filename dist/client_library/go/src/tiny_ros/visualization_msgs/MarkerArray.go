package visualization_msgs

import (
    "encoding/json"
)


type MarkerArray struct {
    Go_markers []*Marker `json:"markers"`
}

func NewMarkerArray() (*MarkerArray) {
    newMarkerArray := new(MarkerArray)
    newMarkerArray.Go_markers = []*Marker{}
    return newMarkerArray
}

func (self *MarkerArray) Go_initialize() {
    self.Go_markers = []*Marker{}
}

func (self *MarkerArray) Go_serialize(buff []byte) (int) {
    offset := 0
    length_markers := len(self.Go_markers)
    buff[offset + 0] = byte((length_markers >> (8 * 0)) & 0xFF)
    buff[offset + 1] = byte((length_markers >> (8 * 1)) & 0xFF)
    buff[offset + 2] = byte((length_markers >> (8 * 2)) & 0xFF)
    buff[offset + 3] = byte((length_markers >> (8 * 3)) & 0xFF)
    offset += 4
    for i := 0; i < length_markers; i++ {
        offset += self.Go_markers[i].Go_serialize(buff[offset:])
    }
    return offset
}

func (self *MarkerArray) Go_deserialize(buff []byte) (int) {
    offset := 0
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
    return offset
}

func (self *MarkerArray) Go_serializedLength() (int) {
    length := 0
    length += 4
    length_markers := len(self.Go_markers)
    for i := 0; i < length_markers; i++ {
        length += self.Go_markers[i].Go_serializedLength()
    }
    return length
}

func (self *MarkerArray) Go_echo() (string) { 
    data, _ := json.Marshal(self)
    return string(data)
}

func (self *MarkerArray) Go_getType() (string) { return "visualization_msgs/MarkerArray" }
func (self *MarkerArray) Go_getMD5() (string) { return "032534c86d6c02fcd8eb187cf568eb46" }
func (self *MarkerArray) Go_getID() (uint32) { return 0 }
func (self *MarkerArray) Go_setID(id uint32) { }

