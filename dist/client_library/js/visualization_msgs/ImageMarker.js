(function(f){if(typeof exports==="object"&&typeof module!=="undefined"){module.exports=f();}else if(typeof define==="function"&&define.amd){define([],f);}else{var g;if(typeof window!=="undefined"){g=window;}else if(typeof global!=="undefined"){g=global;}else if(typeof self!=="undefined"){g=self;}else{g=this;}if(typeof g.visualization_msgs==="undefined"){g.visualization_msgs={};}g.visualization_msgs.ImageMarker=f();}})(function(){var define,module,exports;'use strict';
const _CURRENT_PATH_ = document.currentScript.src.substring(0, document.currentScript.src.lastIndexOf("/"));
const _ROOT_PATH_ = _CURRENT_PATH_.substring(0, _CURRENT_PATH_.lastIndexOf("/"));
document.write("<script language=javascript src='"+_ROOT_PATH_+"/std_msgs/Header.js'></script>");
document.write("<script language=javascript src='"+_ROOT_PATH_+"/geometry_msgs/Point.js'></script>");
document.write("<script language=javascript src='"+_ROOT_PATH_+"/std_msgs/ColorRGBA.js'></script>");
document.write("<script language=javascript src='"+_ROOT_PATH_+"/tinyros/Duration.js'></script>");

function ImageMarker() {
    this.header = std_msgs.Header();
    this.ns = "";
    this.id = 0;
    this.type = 0;
    this.action = 0;
    this.position = geometry_msgs.Point();
    this.scale = 0.0;
    this.outline_color = std_msgs.ColorRGBA();
    this.filled = 0;
    this.fill_color = std_msgs.ColorRGBA();
    this.lifetime = tinyros.Duration();
    this.points = new Array();
    this.outline_colors = new Array();

    // ENUM{
    this.CIRCLE = 0;
    this.LINE_STRIP = 1;
    this.LINE_LIST = 2;
    this.POLYGON = 3;
    this.POINTS = 4;
    this.ADD = 0;
    this.REMOVE = 1;
    // }ENUM
};

ImageMarker.prototype.serialize = function(buff, idx) {
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
    offset = this.position.serialize(buff, offset);
    var float32Array_scale = new Float32Array(1);
    var uInt8Float32Array_scale = new Uint8Array(float32Array_scale.buffer);
    float32Array_scale[0] = +this.scale;
    buff[offset + 0] = uInt8Float32Array_scale[0];
    buff[offset + 1] = uInt8Float32Array_scale[1];
    buff[offset + 2] = uInt8Float32Array_scale[2];
    buff[offset + 3] = uInt8Float32Array_scale[3];
    offset += 4;
    offset = this.outline_color.serialize(buff, offset);
    buff[offset + 0] = ((+this.filled) >> (8 * 0)) & 0xFF;
    offset += 1;
    offset = this.fill_color.serialize(buff, offset);
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
    var length_points = this.points.length;
    buff[offset + 0] = (length_points >> (8 * 0)) & 0xFF;
    buff[offset + 1] = (length_points >> (8 * 1)) & 0xFF;
    buff[offset + 2] = (length_points >> (8 * 2)) & 0xFF;
    buff[offset + 3] = (length_points >> (8 * 3)) & 0xFF;
    offset += 4;
    for (var i = 0; i < length_points; i++) {
        offset = this.points[i].serialize(buff, offset);
    }
    var length_outline_colors = this.outline_colors.length;
    buff[offset + 0] = (length_outline_colors >> (8 * 0)) & 0xFF;
    buff[offset + 1] = (length_outline_colors >> (8 * 1)) & 0xFF;
    buff[offset + 2] = (length_outline_colors >> (8 * 2)) & 0xFF;
    buff[offset + 3] = (length_outline_colors >> (8 * 3)) & 0xFF;
    offset += 4;
    for (var i = 0; i < length_outline_colors; i++) {
        offset = this.outline_colors[i].serialize(buff, offset);
    }
    return offset;
};

ImageMarker.prototype.deserialize = function(buff, idx) {
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
    offset = this.position.deserialize(buff, offset);
    var float32Array_scale = new Float32Array(1);
    var uInt8Float32Array_scale = new Uint8Array(float32Array_scale.buffer);
    uInt8Float32Array_scale[0] = buff[offset + 0];
    uInt8Float32Array_scale[1] = buff[offset + 1];
    uInt8Float32Array_scale[2] = buff[offset + 2];
    uInt8Float32Array_scale[3] = buff[offset + 3];
    this.scale = float32Array_scale[0];
    offset += 4;
    offset = this.outline_color.deserialize(buff, offset);
    this.filled = +((buff[offset + 0] & 0xFF) << (8 * 0));
    offset += 1;
    offset = this.fill_color.deserialize(buff, offset);
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
    var length_outline_colors = +((buff[offset + 0] & 0xFF) << (8 * 0));
    length_outline_colors |= +((buff[offset + 1] & 0xFF) << (8 * 1));
    length_outline_colors |= +((buff[offset + 2] & 0xFF) << (8 * 2));
    length_outline_colors |= +((buff[offset + 3] & 0xFF) << (8 * 3));
    offset += 4;
    this.outline_colors = new Array(length_outline_colors);
    for (var i = 0; i < length_outline_colors; i++) {
        this.outline_colors[i] = std_msgs.ColorRGBA();
        offset = this.outline_colors[i].deserialize(buff, offset);
    }
    return offset;
};

ImageMarker.prototype.serializedLength = function() {
    var length = 0;
    length += this.header.serializedLength();
    var encoder_ns = new TextEncoder('utf8');
    var utf8array_ns = encoder_ns.encode(this.ns);
    length += 4;
    length += utf8array_ns.length;
    length += 4
    length += 4
    length += 4
    length += this.position.serializedLength();
    length += 4
    length += this.outline_color.serializedLength();
    length += 1
    length += this.fill_color.serializedLength();
    length += 4
    length += 4
    var length_points = this.points.length;
    length += 4;
    for (var i = 0; i < length_points; i++) {
        length += this.points[i].serializedLength();
    }
    var length_outline_colors = this.outline_colors.length;
    length += 4;
    for (var i = 0; i < length_outline_colors; i++) {
        length += this.outline_colors[i].serializedLength();
    }
    return length;
};

ImageMarker.prototype.echo = function() { return ""; };

ImageMarker.prototype.getType = function() { return "visualization_msgs/ImageMarker"; };

ImageMarker.prototype.getMD5 = function() { return "453bce92c8194bc4489b79af1cdf861e"; };

ImageMarker.prototype.getID = function() { return 0; };

ImageMarker.prototype.setID = function(id) { };

return function() { return new ImageMarker(); };

});
