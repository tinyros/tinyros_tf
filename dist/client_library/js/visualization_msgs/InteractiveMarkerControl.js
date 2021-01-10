(function(f){if(typeof exports==="object"&&typeof module!=="undefined"){module.exports=f();}else if(typeof define==="function"&&define.amd){define([],f);}else{var g;if(typeof window!=="undefined"){g=window;}else if(typeof global!=="undefined"){g=global;}else if(typeof self!=="undefined"){g=self;}else{g=this;}if(typeof g.visualization_msgs==="undefined"){g.visualization_msgs={};}g.visualization_msgs.InteractiveMarkerControl=f();}})(function(){var define,module,exports;'use strict';
const _CURRENT_PATH_ = document.currentScript.src.substring(0, document.currentScript.src.lastIndexOf("/"));
const _ROOT_PATH_ = _CURRENT_PATH_.substring(0, _CURRENT_PATH_.lastIndexOf("/"));
document.write("<script language=javascript src='"+_ROOT_PATH_+"/geometry_msgs/Quaternion.js'></script>");
document.write("<script language=javascript src='"+_ROOT_PATH_+"/visualization_msgs/Marker.js'></script>");

function InteractiveMarkerControl() {
    this.name = "";
    this.orientation = geometry_msgs.Quaternion();
    this.orientation_mode = 0;
    this.interaction_mode = 0;
    this.always_visible = false;
    this.markers = new Array();
    this.independent_marker_orientation = false;
    this.description = "";

    // ENUM{
    this.INHERIT =  0;
    this.FIXED =  1;
    this.VIEW_FACING =  2;
    this.NONE =  0;
    this.MENU =  1;
    this.BUTTON =  2;
    this.MOVE_AXIS =  3;
    this.MOVE_PLANE =  4;
    this.ROTATE_AXIS =  5;
    this.MOVE_ROTATE =  6;
    this.MOVE_3D =  7;
    this.ROTATE_3D =  8;
    this.MOVE_ROTATE_3D =  9;
    // }ENUM
};

InteractiveMarkerControl.prototype.serialize = function(buff, idx) {
    var offset = idx;
    var encoder_name = new TextEncoder('utf8');
    var utf8array_name = encoder_name.encode(this.name);
    buff[offset + 0] = (utf8array_name.length >> (8 * 0)) & 0xFF;
    buff[offset + 1] = (utf8array_name.length >> (8 * 1)) & 0xFF;
    buff[offset + 2] = (utf8array_name.length >> (8 * 2)) & 0xFF;
    buff[offset + 3] = (utf8array_name.length >> (8 * 3)) & 0xFF;
    offset += 4;
    for (var i = 0; i < utf8array_name.length; i++) {
        buff[offset + i] = utf8array_name[i];
    }
    offset += utf8array_name.length;
    offset = this.orientation.serialize(buff, offset);
    buff[offset + 0] = ((+this.orientation_mode) >> (8 * 0)) & 0xFF;
    offset += 1;
    buff[offset + 0] = ((+this.interaction_mode) >> (8 * 0)) & 0xFF;
    offset += 1;
    buff[offset] = this.always_visible === false ? 0 : 1;
    offset += 1;
    var length_markers = this.markers.length;
    buff[offset + 0] = (length_markers >> (8 * 0)) & 0xFF;
    buff[offset + 1] = (length_markers >> (8 * 1)) & 0xFF;
    buff[offset + 2] = (length_markers >> (8 * 2)) & 0xFF;
    buff[offset + 3] = (length_markers >> (8 * 3)) & 0xFF;
    offset += 4;
    for (var i = 0; i < length_markers; i++) {
        offset = this.markers[i].serialize(buff, offset);
    }
    buff[offset] = this.independent_marker_orientation === false ? 0 : 1;
    offset += 1;
    var encoder_description = new TextEncoder('utf8');
    var utf8array_description = encoder_description.encode(this.description);
    buff[offset + 0] = (utf8array_description.length >> (8 * 0)) & 0xFF;
    buff[offset + 1] = (utf8array_description.length >> (8 * 1)) & 0xFF;
    buff[offset + 2] = (utf8array_description.length >> (8 * 2)) & 0xFF;
    buff[offset + 3] = (utf8array_description.length >> (8 * 3)) & 0xFF;
    offset += 4;
    for (var i = 0; i < utf8array_description.length; i++) {
        buff[offset + i] = utf8array_description[i];
    }
    offset += utf8array_description.length;
    return offset;
};

InteractiveMarkerControl.prototype.deserialize = function(buff, idx) {
    var offset = idx;
    var length_name = +((buff[offset + 0] & 0xFF) << (8 * 0));
    length_name |= +((buff[offset + 1] & 0xFF) << (8 * 1));
    length_name |= +((buff[offset + 2] & 0xFF) << (8 * 2));
    length_name |= +((buff[offset + 3] & 0xFF) << (8 * 3))
    offset += 4;
    var decoder_name = new TextDecoder('utf8');
    this.name = decoder_name.decode(buff.slice(offset, offset + length_name));
    offset += length_name;
    offset = this.orientation.deserialize(buff, offset);
    this.orientation_mode = +((buff[offset + 0] & 0xFF) << (8 * 0));
    offset += 1;
    this.interaction_mode = +((buff[offset + 0] & 0xFF) << (8 * 0));
    offset += 1;
    this.always_visible = buff[offset] !== 0 ? true : false;
    offset += 1;
    var length_markers = +((buff[offset + 0] & 0xFF) << (8 * 0));
    length_markers |= +((buff[offset + 1] & 0xFF) << (8 * 1));
    length_markers |= +((buff[offset + 2] & 0xFF) << (8 * 2));
    length_markers |= +((buff[offset + 3] & 0xFF) << (8 * 3));
    offset += 4;
    this.markers = new Array(length_markers);
    for (var i = 0; i < length_markers; i++) {
        this.markers[i] = visualization_msgs.Marker();
        offset = this.markers[i].deserialize(buff, offset);
    }
    this.independent_marker_orientation = buff[offset] !== 0 ? true : false;
    offset += 1;
    var length_description = +((buff[offset + 0] & 0xFF) << (8 * 0));
    length_description |= +((buff[offset + 1] & 0xFF) << (8 * 1));
    length_description |= +((buff[offset + 2] & 0xFF) << (8 * 2));
    length_description |= +((buff[offset + 3] & 0xFF) << (8 * 3))
    offset += 4;
    var decoder_description = new TextDecoder('utf8');
    this.description = decoder_description.decode(buff.slice(offset, offset + length_description));
    offset += length_description;
    return offset;
};

InteractiveMarkerControl.prototype.serializedLength = function() {
    var length = 0;
    var encoder_name = new TextEncoder('utf8');
    var utf8array_name = encoder_name.encode(this.name);
    length += 4;
    length += utf8array_name.length;
    length += this.orientation.serializedLength();
    length += 1
    length += 1
    length += 1
    var length_markers = this.markers.length;
    length += 4;
    for (var i = 0; i < length_markers; i++) {
        length += this.markers[i].serializedLength();
    }
    length += 1
    var encoder_description = new TextEncoder('utf8');
    var utf8array_description = encoder_description.encode(this.description);
    length += 4;
    length += utf8array_description.length;
    return length;
};

InteractiveMarkerControl.prototype.echo = function() { return ""; };

InteractiveMarkerControl.prototype.getType = function() { return "visualization_msgs/InteractiveMarkerControl"; };

InteractiveMarkerControl.prototype.getMD5 = function() { return "22b3d411f6992b5b98c859d9077512ba"; };

InteractiveMarkerControl.prototype.getID = function() { return 0; };

InteractiveMarkerControl.prototype.setID = function(id) { };

return function() { return new InteractiveMarkerControl(); };

});
