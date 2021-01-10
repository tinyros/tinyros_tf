(function(f){if(typeof exports==="object"&&typeof module!=="undefined"){module.exports=f();}else if(typeof define==="function"&&define.amd){define([],f);}else{var g;if(typeof window!=="undefined"){g=window;}else if(typeof global!=="undefined"){g=global;}else if(typeof self!=="undefined"){g=self;}else{g=this;}if(typeof g.visualization_msgs==="undefined"){g.visualization_msgs={};}g.visualization_msgs.Marker=f();}})(function(){var define,module,exports;'use strict';
const _CURRENT_PATH_ = document.currentScript.src.substring(0, document.currentScript.src.lastIndexOf("/"));
const _ROOT_PATH_ = _CURRENT_PATH_.substring(0, _CURRENT_PATH_.lastIndexOf("/"));
document.write("<script language=javascript src='"+_ROOT_PATH_+"/std_msgs/Header.js'></script>");
document.write("<script language=javascript src='"+_ROOT_PATH_+"/geometry_msgs/Pose.js'></script>");
document.write("<script language=javascript src='"+_ROOT_PATH_+"/geometry_msgs/Vector3.js'></script>");
document.write("<script language=javascript src='"+_ROOT_PATH_+"/std_msgs/ColorRGBA.js'></script>");
document.write("<script language=javascript src='"+_ROOT_PATH_+"/tinyros/Duration.js'></script>");
document.write("<script language=javascript src='"+_ROOT_PATH_+"/geometry_msgs/Point.js'></script>");

function Marker() {
    this.header = std_msgs.Header();
    this.ns = "";
    this.id = 0;
    this.type = 0;
    this.action = 0;
    this.pose = geometry_msgs.Pose();
    this.scale = geometry_msgs.Vector3();
    this.color = std_msgs.ColorRGBA();
    this.lifetime = tinyros.Duration();
    this.frame_locked = false;
    this.points = new Array();
    this.colors = new Array();
    this.text = "";
    this.mesh_resource = "";
    this.mesh_use_embedded_materials = false;

    // ENUM{
    this.ARROW = 0;
    this.CUBE = 1;
    this.SPHERE = 2;
    this.CYLINDER = 3;
    this.LINE_STRIP = 4;
    this.LINE_LIST = 5;
    this.CUBE_LIST = 6;
    this.SPHERE_LIST = 7;
    this.POINTS = 8;
    this.TEXT_VIEW_FACING = 9;
    this.MESH_RESOURCE = 10;
    this.TRIANGLE_LIST = 11;
    this.ADD = 0;
    this.MODIFY = 0;
    this.DELETE = 2;
    // }ENUM
};

Marker.prototype.serialize = function(buff, idx) {
    var offset = idx;
    offset = this.header.serialize(buff, offset);
    var encoder_ns = new TextEncoder('utf8');
    var utf8array_ns = encoder_ns.encode(this.ns);
    buff[offset + 0] = (utf8array_ns.length >> (8 * 0)) & 0xFF;
    buff[offset + 1] = (utf8array_ns.length >> (8 * 1)) & 0xFF;
    buff[offset + 2] = (utf8array_ns.length >> (8 * 2)) & 0xFF;
    buff[offset + 3] = (utf8array_ns.length >> (8 * 3)) & 0xFF;
    offset += 4;
    for (var i = 0; i < utf8array_ns.length; i++) {
        buff[offset + i] = utf8array_ns[i];
    }
    offset += utf8array_ns.length;
    buff[offset + 0] = ((+this.id) >> (8 * 0)) & 0xFF;
    buff[offset + 1] = ((+this.id) >> (8 * 1)) & 0xFF;
    buff[offset + 2] = ((+this.id) >> (8 * 2)) & 0xFF;
    buff[offset + 3] = ((+this.id) >> (8 * 3)) & 0xFF;
    offset += 4;
    buff[offset + 0] = ((+this.type) >> (8 * 0)) & 0xFF;
    buff[offset + 1] = ((+this.type) >> (8 * 1)) & 0xFF;
    buff[offset + 2] = ((+this.type) >> (8 * 2)) & 0xFF;
    buff[offset + 3] = ((+this.type) >> (8 * 3)) & 0xFF;
    offset += 4;
    buff[offset + 0] = ((+this.action) >> (8 * 0)) & 0xFF;
    buff[offset + 1] = ((+this.action) >> (8 * 1)) & 0xFF;
    buff[offset + 2] = ((+this.action) >> (8 * 2)) & 0xFF;
    buff[offset + 3] = ((+this.action) >> (8 * 3)) & 0xFF;
    offset += 4;
    offset = this.pose.serialize(buff, offset);
    offset = this.scale.serialize(buff, offset);
    offset = this.color.serialize(buff, offset);
    buff[offset + 0] = ((+this.lifetime.sec) >> (8 * 0)) & 0xFF;
    buff[offset + 1] = ((+this.lifetime.sec) >> (8 * 1)) & 0xFF;
    buff[offset + 2] = ((+this.lifetime.sec) >> (8 * 2)) & 0xFF;
    buff[offset + 3] = ((+this.lifetime.sec) >> (8 * 3)) & 0xFF;
    offset += 4;
    buff[offset + 0] = ((+this.lifetime.nsec) >> (8 * 0)) & 0xFF;
    buff[offset + 1] = ((+this.lifetime.nsec) >> (8 * 1)) & 0xFF;
    buff[offset + 2] = ((+this.lifetime.nsec) >> (8 * 2)) & 0xFF;
    buff[offset + 3] = ((+this.lifetime.nsec) >> (8 * 3)) & 0xFF;
    offset += 4;
    buff[offset] = this.frame_locked === false ? 0 : 1;
    offset += 1;
    var length_points = this.points.length;
    buff[offset + 0] = (length_points >> (8 * 0)) & 0xFF;
    buff[offset + 1] = (length_points >> (8 * 1)) & 0xFF;
    buff[offset + 2] = (length_points >> (8 * 2)) & 0xFF;
    buff[offset + 3] = (length_points >> (8 * 3)) & 0xFF;
    offset += 4;
    for (var i = 0; i < length_points; i++) {
        offset = this.points[i].serialize(buff, offset);
    }
    var length_colors = this.colors.length;
    buff[offset + 0] = (length_colors >> (8 * 0)) & 0xFF;
    buff[offset + 1] = (length_colors >> (8 * 1)) & 0xFF;
    buff[offset + 2] = (length_colors >> (8 * 2)) & 0xFF;
    buff[offset + 3] = (length_colors >> (8 * 3)) & 0xFF;
    offset += 4;
    for (var i = 0; i < length_colors; i++) {
        offset = this.colors[i].serialize(buff, offset);
    }
    var encoder_text = new TextEncoder('utf8');
    var utf8array_text = encoder_text.encode(this.text);
    buff[offset + 0] = (utf8array_text.length >> (8 * 0)) & 0xFF;
    buff[offset + 1] = (utf8array_text.length >> (8 * 1)) & 0xFF;
    buff[offset + 2] = (utf8array_text.length >> (8 * 2)) & 0xFF;
    buff[offset + 3] = (utf8array_text.length >> (8 * 3)) & 0xFF;
    offset += 4;
    for (var i = 0; i < utf8array_text.length; i++) {
        buff[offset + i] = utf8array_text[i];
    }
    offset += utf8array_text.length;
    var encoder_mesh_resource = new TextEncoder('utf8');
    var utf8array_mesh_resource = encoder_mesh_resource.encode(this.mesh_resource);
    buff[offset + 0] = (utf8array_mesh_resource.length >> (8 * 0)) & 0xFF;
    buff[offset + 1] = (utf8array_mesh_resource.length >> (8 * 1)) & 0xFF;
    buff[offset + 2] = (utf8array_mesh_resource.length >> (8 * 2)) & 0xFF;
    buff[offset + 3] = (utf8array_mesh_resource.length >> (8 * 3)) & 0xFF;
    offset += 4;
    for (var i = 0; i < utf8array_mesh_resource.length; i++) {
        buff[offset + i] = utf8array_mesh_resource[i];
    }
    offset += utf8array_mesh_resource.length;
    buff[offset] = this.mesh_use_embedded_materials === false ? 0 : 1;
    offset += 1;
    return offset;
};

Marker.prototype.deserialize = function(buff, idx) {
    var offset = idx;
    offset = this.header.deserialize(buff, offset);
    var length_ns = +((buff[offset + 0] & 0xFF) << (8 * 0));
    length_ns |= +((buff[offset + 1] & 0xFF) << (8 * 1));
    length_ns |= +((buff[offset + 2] & 0xFF) << (8 * 2));
    length_ns |= +((buff[offset + 3] & 0xFF) << (8 * 3))
    offset += 4;
    var decoder_ns = new TextDecoder('utf8');
    this.ns = decoder_ns.decode(buff.slice(offset, offset + length_ns));
    offset += length_ns;
    this.id = +((buff[offset + 0] & 0xFF) << (8 * 0));
    this.id |= +((buff[offset + 1] & 0xFF) << (8 * 1));
    this.id |= +((buff[offset + 2] & 0xFF) << (8 * 2));
    this.id |= +((buff[offset + 3] & 0xFF) << (8 * 3));
    offset += 4;
    this.type = +((buff[offset + 0] & 0xFF) << (8 * 0));
    this.type |= +((buff[offset + 1] & 0xFF) << (8 * 1));
    this.type |= +((buff[offset + 2] & 0xFF) << (8 * 2));
    this.type |= +((buff[offset + 3] & 0xFF) << (8 * 3));
    offset += 4;
    this.action = +((buff[offset + 0] & 0xFF) << (8 * 0));
    this.action |= +((buff[offset + 1] & 0xFF) << (8 * 1));
    this.action |= +((buff[offset + 2] & 0xFF) << (8 * 2));
    this.action |= +((buff[offset + 3] & 0xFF) << (8 * 3));
    offset += 4;
    offset = this.pose.deserialize(buff, offset);
    offset = this.scale.deserialize(buff, offset);
    offset = this.color.deserialize(buff, offset);
    this.lifetime.sec = +((buff[offset + 0] & 0xFF) << (8 * 0));
    this.lifetime.sec |= +((buff[offset + 1] & 0xFF) << (8 * 1));
    this.lifetime.sec |= +((buff[offset + 2] & 0xFF) << (8 * 2));
    this.lifetime.sec |= +((buff[offset + 3] & 0xFF) << (8 * 3));
    offset += 4;
    this.lifetime.nsec = +((buff[offset + 0] & 0xFF) << (8 * 0));
    this.lifetime.nsec |= +((buff[offset + 1] & 0xFF) << (8 * 1));
    this.lifetime.nsec |= +((buff[offset + 2] & 0xFF) << (8 * 2));
    this.lifetime.nsec |= +((buff[offset + 3] & 0xFF) << (8 * 3));
    offset += 4;
    this.frame_locked = buff[offset] !== 0 ? true : false;
    offset += 1;
    var length_points = +((buff[offset + 0] & 0xFF) << (8 * 0));
    length_points |= +((buff[offset + 1] & 0xFF) << (8 * 1));
    length_points |= +((buff[offset + 2] & 0xFF) << (8 * 2));
    length_points |= +((buff[offset + 3] & 0xFF) << (8 * 3));
    offset += 4;
    this.points = new Array(length_points);
    for (var i = 0; i < length_points; i++) {
        this.points[i] = geometry_msgs.Point();
        offset = this.points[i].deserialize(buff, offset);
    }
    var length_colors = +((buff[offset + 0] & 0xFF) << (8 * 0));
    length_colors |= +((buff[offset + 1] & 0xFF) << (8 * 1));
    length_colors |= +((buff[offset + 2] & 0xFF) << (8 * 2));
    length_colors |= +((buff[offset + 3] & 0xFF) << (8 * 3));
    offset += 4;
    this.colors = new Array(length_colors);
    for (var i = 0; i < length_colors; i++) {
        this.colors[i] = std_msgs.ColorRGBA();
        offset = this.colors[i].deserialize(buff, offset);
    }
    var length_text = +((buff[offset + 0] & 0xFF) << (8 * 0));
    length_text |= +((buff[offset + 1] & 0xFF) << (8 * 1));
    length_text |= +((buff[offset + 2] & 0xFF) << (8 * 2));
    length_text |= +((buff[offset + 3] & 0xFF) << (8 * 3))
    offset += 4;
    var decoder_text = new TextDecoder('utf8');
    this.text = decoder_text.decode(buff.slice(offset, offset + length_text));
    offset += length_text;
    var length_mesh_resource = +((buff[offset + 0] & 0xFF) << (8 * 0));
    length_mesh_resource |= +((buff[offset + 1] & 0xFF) << (8 * 1));
    length_mesh_resource |= +((buff[offset + 2] & 0xFF) << (8 * 2));
    length_mesh_resource |= +((buff[offset + 3] & 0xFF) << (8 * 3))
    offset += 4;
    var decoder_mesh_resource = new TextDecoder('utf8');
    this.mesh_resource = decoder_mesh_resource.decode(buff.slice(offset, offset + length_mesh_resource));
    offset += length_mesh_resource;
    this.mesh_use_embedded_materials = buff[offset] !== 0 ? true : false;
    offset += 1;
    return offset;
};

Marker.prototype.serializedLength = function() {
    var length = 0;
    length += this.header.serializedLength();
    var encoder_ns = new TextEncoder('utf8');
    var utf8array_ns = encoder_ns.encode(this.ns);
    length += 4;
    length += utf8array_ns.length;
    length += 4
    length += 4
    length += 4
    length += this.pose.serializedLength();
    length += this.scale.serializedLength();
    length += this.color.serializedLength();
    length += 4
    length += 4
    length += 1
    var length_points = this.points.length;
    length += 4;
    for (var i = 0; i < length_points; i++) {
        length += this.points[i].serializedLength();
    }
    var length_colors = this.colors.length;
    length += 4;
    for (var i = 0; i < length_colors; i++) {
        length += this.colors[i].serializedLength();
    }
    var encoder_text = new TextEncoder('utf8');
    var utf8array_text = encoder_text.encode(this.text);
    length += 4;
    length += utf8array_text.length;
    var encoder_mesh_resource = new TextEncoder('utf8');
    var utf8array_mesh_resource = encoder_mesh_resource.encode(this.mesh_resource);
    length += 4;
    length += utf8array_mesh_resource.length;
    length += 1
    return length;
};

Marker.prototype.echo = function() { return ""; };

Marker.prototype.getType = function() { return "visualization_msgs/Marker"; };

Marker.prototype.getMD5 = function() { return "666484e5c1e264d98a42c3b7c44c0ac3"; };

Marker.prototype.getID = function() { return 0; };

Marker.prototype.setID = function(id) { };

return function() { return new Marker(); };

});
