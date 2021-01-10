package visualization_msgs

import (
    "encoding/json"
)

func Go_KEEP_ALIVE() (uint8) { return  0 }
func Go_UPDATE() (uint8) { return  1 }

type InteractiveMarkerUpdate struct {
    Go_server_id string `json:"server_id"`
    Go_seq_num uint64 `json:"seq_num"`
    Go_type uint8 `json:"type"`
    Go_markers []*InteractiveMarker `json:"markers"`
    Go_poses []*InteractiveMarkerPose `json:"poses"`
    Go_erases []string `json:"erases"`
}

func NewInteractiveMarkerUpdate() (*InteractiveMarkerUpdate) {
    newInteractiveMarkerUpdate := new(InteractiveMarkerUpdate)
    newInteractiveMarkerUpdate.Go_server_id = ""
    newInteractiveMarkerUpdate.Go_seq_num = 0
    newInteractiveMarkerUpdate.Go_type = 0
    newInteractiveMarkerUpdate.Go_markers = []*InteractiveMarker{}
    newInteractiveMarkerUpdate.Go_poses = []*InteractiveMarkerPose{}
    newInteractiveMarkerUpdate.Go_erases = []string{}
    return newInteractiveMarkerUpdate
}

func (self *InteractiveMarkerUpdate) Go_initialize() {
    self.Go_server_id = ""
    self.Go_seq_num = 0
    self.Go_type = 0
    self.Go_markers = []*InteractiveMarker{}
    self.Go_poses = []*InteractiveMarkerPose{}
    self.Go_erases = []string{}
}

func (self *InteractiveMarkerUpdate) Go_serialize(buff []byte) (int) {
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
    buff[offset + 0] = byte((self.Go_type >> (8 * 0)) & 0xFF)
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
    length_poses := len(self.Go_poses)
    buff[offset + 0] = byte((length_poses >> (8 * 0)) & 0xFF)
    buff[offset + 1] = byte((length_poses >> (8 * 1)) & 0xFF)
    buff[offset + 2] = byte((length_poses >> (8 * 2)) & 0xFF)
    buff[offset + 3] = byte((length_poses >> (8 * 3)) & 0xFF)
    offset += 4
    for i := 0; i < length_poses; i++ {
        offset += self.Go_poses[i].Go_serialize(buff[offset:])
    }
    length_erases := len(self.Go_erases)
    buff[offset + 0] = byte((length_erases >> (8 * 0)) & 0xFF)
    buff[offset + 1] = byte((length_erases >> (8 * 1)) & 0xFF)
    buff[offset + 2] = byte((length_erases >> (8 * 2)) & 0xFF)
    buff[offset + 3] = byte((length_erases >> (8 * 3)) & 0xFF)
    offset += 4
    for i := 0; i < length_erases; i++ {
        length_erasesi := len(self.Go_erases[i])
        buff[offset + 0] = byte((length_erasesi >> (8 * 0)) & 0xFF)
        buff[offset + 1] = byte((length_erasesi >> (8 * 1)) & 0xFF)
        buff[offset + 2] = byte((length_erasesi >> (8 * 2)) & 0xFF)
        buff[offset + 3] = byte((length_erasesi >> (8 * 3)) & 0xFF)
        offset += 4
        copy(buff[offset:(offset+length_erasesi)], self.Go_erases[i])
        offset += length_erasesi
    }
    return offset
}

func (self *InteractiveMarkerUpdate) Go_deserialize(buff []byte) (int) {
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
    self.Go_type = uint8(buff[offset + 0] & 0xFF) << (8 * 0)
    offset += 1
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
    length_poses := int(buff[offset + 0] & 0xFF) << (8 * 0)
    length_poses |= int(buff[offset + 1] & 0xFF) << (8 * 1)
    length_poses |= int(buff[offset + 2] & 0xFF) << (8 * 2)
    length_poses |= int(buff[offset + 3] & 0xFF) << (8 * 3)
    offset += 4
    self.Go_poses = make([]*InteractiveMarkerPose, length_poses)
    for i := 0; i < length_poses; i++ {
        self.Go_poses[i] = NewInteractiveMarkerPose()
    }
    for i := 0; i < length_poses; i++ {
        offset += self.Go_poses[i].Go_deserialize(buff[offset:])
    }
    length_erases := int(buff[offset + 0] & 0xFF) << (8 * 0)
    length_erases |= int(buff[offset + 1] & 0xFF) << (8 * 1)
    length_erases |= int(buff[offset + 2] & 0xFF) << (8 * 2)
    length_erases |= int(buff[offset + 3] & 0xFF) << (8 * 3)
    offset += 4
    self.Go_erases = make([]string, length_erases)
    for i := 0; i < length_erases; i++ {
        length_erasesi := int(buff[offset + 0] & 0xFF) << (8 * 0)
        length_erasesi |= int(buff[offset + 1] & 0xFF) << (8 * 1)
        length_erasesi |= int(buff[offset + 2] & 0xFF) << (8 * 2)
        length_erasesi |= int(buff[offset + 3] & 0xFF) << (8 * 3)
        offset += 4
        self.Go_erases[i] = string(buff[offset:(offset+length_erasesi)])
        offset += length_erasesi
    }
    return offset
}

func (self *InteractiveMarkerUpdate) Go_serializedLength() (int) {
    length := 0
    length_server_id := len(self.Go_server_id)
    length += 4
    length += length_server_id
    length += 8
    length += 1
    length += 4
    length_markers := len(self.Go_markers)
    for i := 0; i < length_markers; i++ {
        length += self.Go_markers[i].Go_serializedLength()
    }
    length += 4
    length_poses := len(self.Go_poses)
    for i := 0; i < length_poses; i++ {
        length += self.Go_poses[i].Go_serializedLength()
    }
    length += 4
    length_erases := len(self.Go_erases)
    for i := 0; i < length_erases; i++ {
        length_erasesi := len(self.Go_erases[i])
        length += 4
        length += length_erasesi
    }
    return length
}

func (self *InteractiveMarkerUpdate) Go_echo() (string) { 
    data, _ := json.Marshal(self)
    return string(data)
}

func (self *InteractiveMarkerUpdate) Go_getType() (string) { return "visualization_msgs/InteractiveMarkerUpdate" }
func (self *InteractiveMarkerUpdate) Go_getMD5() (string) { return "ae37189a6cc8de1bae3ccd7710af4288" }
func (self *InteractiveMarkerUpdate) Go_getID() (uint32) { return 0 }
func (self *InteractiveMarkerUpdate) Go_setID(id uint32) { }

