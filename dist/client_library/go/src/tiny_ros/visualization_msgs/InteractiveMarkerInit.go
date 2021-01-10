package visualization_msgs

import (
    "encoding/json"
)


type InteractiveMarkerInit struct {
    Go_server_id string `json:"server_id"`
    Go_seq_num uint64 `json:"seq_num"`
    Go_markers []*InteractiveMarker `json:"markers"`
}

func NewInteractiveMarkerInit() (*InteractiveMarkerInit) {
    newInteractiveMarkerInit := new(InteractiveMarkerInit)
    newInteractiveMarkerInit.Go_server_id = ""
    newInteractiveMarkerInit.Go_seq_num = 0
    newInteractiveMarkerInit.Go_markers = []*InteractiveMarker{}
    return newInteractiveMarkerInit
}

func (self *InteractiveMarkerInit) Go_initialize() {
    self.Go_server_id = ""
    self.Go_seq_num = 0
    self.Go_markers = []*InteractiveMarker{}
}

func (self *InteractiveMarkerInit) Go_serialize(buff []byte) (int) {
    offset := 0
    length_server_id := len(self.Go_server_id)
    buff[offset + 0] = byte((length_server_id >> (8 * 0)) & 0xFF)
    buff[offset + 1] = byte((length_server_id >> (8 * 1)) & 0xFF)
    buff[offset + 2] = byte((length_server_id >> (8 * 2)) & 0xFF)
    buff[offset + 3] = byte((length_server_id >> (8 * 3)) & 0xFF)
    offset += 4
    copy(buff[offset:(offset+length_server_id)], self.Go_server_id)
    offset += length_server_id
    buff[offset + 0] = byte((self.Go_seq_num >> (8 * 0)) & 0xFF)
    buff[offset + 1] = byte((self.Go_seq_num >> (8 * 1)) & 0xFF)
    buff[offset + 2] = byte((self.Go_seq_num >> (8 * 2)) & 0xFF)
    buff[offset + 3] = byte((self.Go_seq_num >> (8 * 3)) & 0xFF)
    buff[offset + 4] = byte((self.Go_seq_num >> (8 * 4)) & 0xFF)
    buff[offset + 5] = byte((self.Go_seq_num >> (8 * 5)) & 0xFF)
    buff[offset + 6] = byte((self.Go_seq_num >> (8 * 6)) & 0xFF)
    buff[offset + 7] = byte((self.Go_seq_num >> (8 * 7)) & 0xFF)
    offset += 8
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

func (self *InteractiveMarkerInit) Go_deserialize(buff []byte) (int) {
    offset := 0
    length_server_id := int(buff[offset + 0] & 0xFF) << (8 * 0)
    length_server_id |= int(buff[offset + 1] & 0xFF) << (8 * 1)
    length_server_id |= int(buff[offset + 2] & 0xFF) << (8 * 2)
    length_server_id |= int(buff[offset + 3] & 0xFF) << (8 * 3)
    offset += 4
    self.Go_server_id = string(buff[offset:(offset+length_server_id)])
    offset += length_server_id
    self.Go_seq_num = uint64(buff[offset + 0] & 0xFF) << (8 * 0)
    self.Go_seq_num |= uint64(buff[offset + 1] & 0xFF) << (8 * 1)
    self.Go_seq_num |= uint64(buff[offset + 2] & 0xFF) << (8 * 2)
    self.Go_seq_num |= uint64(buff[offset + 3] & 0xFF) << (8 * 3)
    self.Go_seq_num |= uint64(buff[offset + 4] & 0xFF) << (8 * 4)
    self.Go_seq_num |= uint64(buff[offset + 5] & 0xFF) << (8 * 5)
    self.Go_seq_num |= uint64(buff[offset + 6] & 0xFF) << (8 * 6)
    self.Go_seq_num |= uint64(buff[offset + 7] & 0xFF) << (8 * 7)
    offset += 8
    length_markers := int(buff[offset + 0] & 0xFF) << (8 * 0)
    length_markers |= int(buff[offset + 1] & 0xFF) << (8 * 1)
    length_markers |= int(buff[offset + 2] & 0xFF) << (8 * 2)
    length_markers |= int(buff[offset + 3] & 0xFF) << (8 * 3)
    offset += 4
    self.Go_markers = make([]*InteractiveMarker, length_markers)
    for i := 0; i < length_markers; i++ {
        self.Go_markers[i] = NewInteractiveMarker()
    }
    for i := 0; i < length_markers; i++ {
        offset += self.Go_markers[i].Go_deserialize(buff[offset:])
    }
    return offset
}

func (self *InteractiveMarkerInit) Go_serializedLength() (int) {
    length := 0
    length_server_id := len(self.Go_server_id)
    length += 4
    length += length_server_id
    length += 8
    length += 4
    length_markers := len(self.Go_markers)
    for i := 0; i < length_markers; i++ {
        length += self.Go_markers[i].Go_serializedLength()
    }
    return length
}

func (self *InteractiveMarkerInit) Go_echo() (string) { 
    data, _ := json.Marshal(self)
    return string(data)
}

func (self *InteractiveMarkerInit) Go_getType() (string) { return "visualization_msgs/InteractiveMarkerInit" }
func (self *InteractiveMarkerInit) Go_getMD5() (string) { return "b8259a8319519330ca4da698883a3e0e" }
func (self *InteractiveMarkerInit) Go_getID() (uint32) { return 0 }
func (self *InteractiveMarkerInit) Go_setID(id uint32) { }

