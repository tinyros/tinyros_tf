(function(f){if(typeof exports==="object"&&typeof module!=="undefined"){module.exports=f();}else if(typeof define==="function"&&define.amd){define([],f);}else{var g;if(typeof window!=="undefined"){g=window;}else if(typeof global!=="undefined"){g=global;}else if(typeof self!=="undefined"){g=self;}else{g=this;}if(typeof g.visualization_msgs==="undefined"){g.visualization_msgs={};}g.visualization_msgs.InteractiveMarkerFeedback=f();}})(function(){var define,module,exports;'use strict';
const _CURRENT_PATH_ = document.currentScript.src.substring(0, document.currentScript.src.lastIndexOf("/"));
const _ROOT_PATH_ = _CURRENT_PATH_.substring(0, _CURRENT_PATH_.lastIndexOf("/"));
document.write("<script language=javascript src='"+_ROOT_PATH_+"/std_msgs/Header.js'></script>");
document.write("<script language=javascript src='"+_ROOT_PATH_+"/geometry_msgs/Pose.js'></script>");
document.write("<script language=javascript src='"+_ROOT_PATH_+"/geometry_msgs/Point.js'></script>");

function InteractiveMarkerFeedback() {
    this.header = std_msgs.Header();
    this.client_id = "";
    this.marker_name = "";
    this.control_name = "";
    this.event_type = 0;
    this.pose = geometry_msgs.Pose();
    this.menu_entry_id = 0;
    this.mouse_point = geometry_msgs.Point();
    this.mouse_point_valid = false;

    // ENUM{
    this.KEEP_ALIVE =  0;
    this.POSE_UPDATE =  1;
    this.MENU_SELECT =  2;
    this.BUTTON_CLICK =  3;
    this.MOUSE_DOWN =  4;
    this.MOUSE_UP =  5;
    // }ENUM
};

InteractiveMarkerFeedback.prototype.serialize = function(buff, idx) {
    var offset = idx;
    offset = this.header.serialize(buff, offset);
    var encoder_client_id = new TextEncoder('utf8');
    var utf8array_client_id = encoder_client_id.encode(this.client_id);
    buff[offset + 0] = (utf8array_client_id.length >> (8 * 0)) & 0xFF;
    buff[offset + 1] = (utf8array_client_id.length >> (8 * 1)) & 0xFF;
    buff[offset + 2] = (utf8array_client_id.length >> (8 * 2)) & 0xFF;
    buff[offset + 3] = (utf8array_client_id.length >> (8 * 3)) & 0xFF;
    offset += 4;
    for (var i = 0; i < utf8array_client_id.length; i++) {
        buff[offset + i] = utf8array_client_id[i];
    }
    offset += utf8array_client_id.length;
    var encoder_marker_name = new TextEncoder('utf8');
    var utf8array_marker_name = encoder_marker_name.encode(this.marker_name);
    buff[offset + 0] = (utf8array_marker_name.length >> (8 * 0)) & 0xFF;
    buff[offset + 1] = (utf8array_marker_name.length >> (8 * 1)) & 0xFF;
    buff[offset + 2] = (utf8array_marker_name.length >> (8 * 2)) & 0xFF;
    buff[offset + 3] = (utf8array_marker_name.length >> (8 * 3)) & 0xFF;
    offset += 4;
    for (var i = 0; i < utf8array_marker_name.length; i++) {
        buff[offset + i] = utf8array_marker_name[i];
    }
    offset += utf8array_marker_name.length;
    var encoder_control_name = new TextEncoder('utf8');
    var utf8array_control_name = encoder_control_name.encode(this.control_name);
    buff[offset + 0] = (utf8array_control_name.length >> (8 * 0)) & 0xFF;
    buff[offset + 1] = (utf8array_control_name.length >> (8 * 1)) & 0xFF;
    buff[offset + 2] = (utf8array_control_name.length >> (8 * 2)) & 0xFF;
    buff[offset + 3] = (utf8array_control_name.length >> (8 * 3)) & 0xFF;
    offset += 4;
    for (var i = 0; i < utf8array_control_name.length; i++) {
        buff[offset + i] = utf8array_control_name[i];
    }
    offset += utf8array_control_name.length;
    buff[offset + 0] = ((+this.event_type) >> (8 * 0)) & 0xFF;
    offset += 1;
    offset = this.pose.serialize(buff, offset);
    buff[offset + 0] = ((+this.menu_entry_id) >> (8 * 0)) & 0xFF;
    buff[offset + 1] = ((+this.menu_entry_id) >> (8 * 1)) & 0xFF;
    buff[offset + 2] = ((+this.menu_entry_id) >> (8 * 2)) & 0xFF;
    buff[offset + 3] = ((+this.menu_entry_id) >> (8 * 3)) & 0xFF;
    offset += 4;
    offset = this.mouse_point.serialize(buff, offset);
    buff[offset] = this.mouse_point_valid === false ? 0 : 1;
    offset += 1;
    return offset;
};

InteractiveMarkerFeedback.prototype.deserialize = function(buff, idx) {
    var offset = idx;
    offset = this.header.deserialize(buff, offset);
    var length_client_id = +((buff[offset + 0] & 0xFF) << (8 * 0));
    length_client_id |= +((buff[offset + 1] & 0xFF) << (8 * 1));
    length_client_id |= +((buff[offset + 2] & 0xFF) << (8 * 2));
    length_client_id |= +((buff[offset + 3] & 0xFF) << (8 * 3))
    offset += 4;
    var decoder_client_id = new TextDecoder('utf8');
    this.client_id = decoder_client_id.decode(buff.slice(offset, offset + length_client_id));
    offset += length_client_id;
    var length_marker_name = +((buff[offset + 0] & 0xFF) << (8 * 0));
    length_marker_name |= +((buff[offset + 1] & 0xFF) << (8 * 1));
    length_marker_name |= +((buff[offset + 2] & 0xFF) << (8 * 2));
    length_marker_name |= +((buff[offset + 3] & 0xFF) << (8 * 3))
    offset += 4;
    var decoder_marker_name = new TextDecoder('utf8');
    this.marker_name = decoder_marker_name.decode(buff.slice(offset, offset + length_marker_name));
    offset += length_marker_name;
    var length_control_name = +((buff[offset + 0] & 0xFF) << (8 * 0));
    length_control_name |= +((buff[offset + 1] & 0xFF) << (8 * 1));
    length_control_name |= +((buff[offset + 2] & 0xFF) << (8 * 2));
    length_control_name |= +((buff[offset + 3] & 0xFF) << (8 * 3))
    offset += 4;
    var decoder_control_name = new TextDecoder('utf8');
    this.control_name = decoder_control_name.decode(buff.slice(offset, offset + length_control_name));
    offset += length_control_name;
    this.event_type = +((buff[offset + 0] & 0xFF) << (8 * 0));
    offset += 1;
    offset = this.pose.deserialize(buff, offset);
    this.menu_entry_id = +((buff[offset + 0] & 0xFF) << (8 * 0));
    this.menu_entry_id |= +((buff[offset + 1] & 0xFF) << (8 * 1));
    this.menu_entry_id |= +((buff[offset + 2] & 0xFF) << (8 * 2));
    this.menu_entry_id |= +((buff[offset + 3] & 0xFF) << (8 * 3));
    offset += 4;
    offset = this.mouse_point.deserialize(buff, offset);
    this.mouse_point_valid = buff[offset] !== 0 ? true : false;
    offset += 1;
    return offset;
};

InteractiveMarkerFeedback.prototype.serializedLength = function() {
    var length = 0;
    length += this.header.serializedLength();
    var encoder_client_id = new TextEncoder('utf8');
    var utf8array_client_id = encoder_client_id.encode(this.client_id);
    length += 4;
    length += utf8array_client_id.length;
    var encoder_marker_name = new TextEncoder('utf8');
    var utf8array_marker_name = encoder_marker_name.encode(this.marker_name);
    length += 4;
    length += utf8array_marker_name.length;
    var encoder_control_name = new TextEncoder('utf8');
    var utf8array_control_name = encoder_control_name.encode(this.control_name);
    length += 4;
    length += utf8array_control_name.length;
    length += 1
    length += this.pose.serializedLength();
    length += 4
    length += this.mouse_point.serializedLength();
    length += 1
    return length;
};

InteractiveMarkerFeedback.prototype.echo = function() { return ""; };

InteractiveMarkerFeedback.prototype.getType = function() { return "visualization_msgs/InteractiveMarkerFeedback"; };

InteractiveMarkerFeedback.prototype.getMD5 = function() { return "2b2c717ae73a04857e91f4992896e58f"; };

InteractiveMarkerFeedback.prototype.getID = function() { return 0; };

InteractiveMarkerFeedback.prototype.setID = function(id) { };

return function() { return new InteractiveMarkerFeedback(); };

});
