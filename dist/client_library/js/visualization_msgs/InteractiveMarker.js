(function(f){if(typeof exports==="object"&&typeof module!=="undefined"){module.exports=f();}else if(typeof define==="function"&&define.amd){define([],f);}else{var g;if(typeof window!=="undefined"){g=window;}else if(typeof global!=="undefined"){g=global;}else if(typeof self!=="undefined"){g=self;}else{g=this;}if(typeof g.visualization_msgs==="undefined"){g.visualization_msgs={};}g.visualization_msgs.InteractiveMarker=f();}})(function(){var define,module,exports;'use strict';
const _CURRENT_PATH_ = document.currentScript.src.substring(0, document.currentScript.src.lastIndexOf("/"));
const _ROOT_PATH_ = _CURRENT_PATH_.substring(0, _CURRENT_PATH_.lastIndexOf("/"));
document.write("<script language=javascript src='"+_ROOT_PATH_+"/std_msgs/Header.js'></script>");
document.write("<script language=javascript src='"+_ROOT_PATH_+"/geometry_msgs/Pose.js'></script>");
document.write("<script language=javascript src='"+_ROOT_PATH_+"/visualization_msgs/MenuEntry.js'></script>");
document.write("<script language=javascript src='"+_ROOT_PATH_+"/visualization_msgs/InteractiveMarkerControl.js'></script>");

function InteractiveMarker() {
    this.header = std_msgs.Header();
    this.pose = geometry_msgs.Pose();
    this.name = "";
    this.description = "";
    this.scale = 0.0;
    this.menu_entries = new Array();
    this.controls = new Array();
};

InteractiveMarker.prototype.serialize = function(buff, idx) {
    var offset = idx;
    offset = this.header.serialize(buff, offset);
    offset = this.pose.serialize(buff, offset);
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
    var float32Array_scale = new Float32Array(1);
    var uInt8Float32Array_scale = new Uint8Array(float32Array_scale.buffer);
    float32Array_scale[0] = +this.scale;
    buff[offset + 0] = uInt8Float32Array_scale[0];
    buff[offset + 1] = uInt8Float32Array_scale[1];
    buff[offset + 2] = uInt8Float32Array_scale[2];
    buff[offset + 3] = uInt8Float32Array_scale[3];
    offset += 4;
    var length_menu_entries = this.menu_entries.length;
    buff[offset + 0] = (length_menu_entries >> (8 * 0)) & 0xFF;
    buff[offset + 1] = (length_menu_entries >> (8 * 1)) & 0xFF;
    buff[offset + 2] = (length_menu_entries >> (8 * 2)) & 0xFF;
    buff[offset + 3] = (length_menu_entries >> (8 * 3)) & 0xFF;
    offset += 4;
    for (var i = 0; i < length_menu_entries; i++) {
        offset = this.menu_entries[i].serialize(buff, offset);
    }
    var length_controls = this.controls.length;
    buff[offset + 0] = (length_controls >> (8 * 0)) & 0xFF;
    buff[offset + 1] = (length_controls >> (8 * 1)) & 0xFF;
    buff[offset + 2] = (length_controls >> (8 * 2)) & 0xFF;
    buff[offset + 3] = (length_controls >> (8 * 3)) & 0xFF;
    offset += 4;
    for (var i = 0; i < length_controls; i++) {
        offset = this.controls[i].serialize(buff, offset);
    }
    return offset;
};

InteractiveMarker.prototype.deserialize = function(buff, idx) {
    var offset = idx;
    offset = this.header.deserialize(buff, offset);
    offset = this.pose.deserialize(buff, offset);
    var length_name = +((buff[offset + 0] & 0xFF) << (8 * 0));
    length_name |= +((buff[offset + 1] & 0xFF) << (8 * 1));
    length_name |= +((buff[offset + 2] & 0xFF) << (8 * 2));
    length_name |= +((buff[offset + 3] & 0xFF) << (8 * 3))
    offset += 4;
    var decoder_name = new TextDecoder('utf8');
    this.name = decoder_name.decode(buff.slice(offset, offset + length_name));
    offset += length_name;
    var length_description = +((buff[offset + 0] & 0xFF) << (8 * 0));
    length_description |= +((buff[offset + 1] & 0xFF) << (8 * 1));
    length_description |= +((buff[offset + 2] & 0xFF) << (8 * 2));
    length_description |= +((buff[offset + 3] & 0xFF) << (8 * 3))
    offset += 4;
    var decoder_description = new TextDecoder('utf8');
    this.description = decoder_description.decode(buff.slice(offset, offset + length_description));
    offset += length_description;
    var float32Array_scale = new Float32Array(1);
    var uInt8Float32Array_scale = new Uint8Array(float32Array_scale.buffer);
    uInt8Float32Array_scale[0] = buff[offset + 0];
    uInt8Float32Array_scale[1] = buff[offset + 1];
    uInt8Float32Array_scale[2] = buff[offset + 2];
    uInt8Float32Array_scale[3] = buff[offset + 3];
    this.scale = float32Array_scale[0];
    offset += 4;
    var length_menu_entries = +((buff[offset + 0] & 0xFF) << (8 * 0));
    length_menu_entries |= +((buff[offset + 1] & 0xFF) << (8 * 1));
    length_menu_entries |= +((buff[offset + 2] & 0xFF) << (8 * 2));
    length_menu_entries |= +((buff[offset + 3] & 0xFF) << (8 * 3));
    offset += 4;
    this.menu_entries = new Array(length_menu_entries);
    for (var i = 0; i < length_menu_entries; i++) {
        this.menu_entries[i] = visualization_msgs.MenuEntry();
        offset = this.menu_entries[i].deserialize(buff, offset);
    }
    var length_controls = +((buff[offset + 0] & 0xFF) << (8 * 0));
    length_controls |= +((buff[offset + 1] & 0xFF) << (8 * 1));
    length_controls |= +((buff[offset + 2] & 0xFF) << (8 * 2));
    length_controls |= +((buff[offset + 3] & 0xFF) << (8 * 3));
    offset += 4;
    this.controls = new Array(length_controls);
    for (var i = 0; i < length_controls; i++) {
        this.controls[i] = visualization_msgs.InteractiveMarkerControl();
        offset = this.controls[i].deserialize(buff, offset);
    }
    return offset;
};

InteractiveMarker.prototype.serializedLength = function() {
    var length = 0;
    length += this.header.serializedLength();
    length += this.pose.serializedLength();
    var encoder_name = new TextEncoder('utf8');
    var utf8array_name = encoder_name.encode(this.name);
    length += 4;
    length += utf8array_name.length;
    var encoder_description = new TextEncoder('utf8');
    var utf8array_description = encoder_description.encode(this.description);
    length += 4;
    length += utf8array_description.length;
    length += 4
    var length_menu_entries = this.menu_entries.length;
    length += 4;
    for (var i = 0; i < length_menu_entries; i++) {
        length += this.menu_entries[i].serializedLength();
    }
    var length_controls = this.controls.length;
    length += 4;
    for (var i = 0; i < length_controls; i++) {
        length += this.controls[i].serializedLength();
    }
    return length;
};

InteractiveMarker.prototype.echo = function() { return ""; };

InteractiveMarker.prototype.getType = function() { return "visualization_msgs/InteractiveMarker"; };

InteractiveMarker.prototype.getMD5 = function() { return "9ebcf376fedf5708487702be1923ba61"; };

InteractiveMarker.prototype.getID = function() { return 0; };

InteractiveMarker.prototype.setID = function(id) { };

return function() { return new InteractiveMarker(); };

});
