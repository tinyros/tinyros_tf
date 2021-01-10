(function(f){if(typeof exports==="object"&&typeof module!=="undefined"){module.exports=f();}else if(typeof define==="function"&&define.amd){define([],f);}else{var g;if(typeof window!=="undefined"){g=window;}else if(typeof global!=="undefined"){g=global;}else if(typeof self!=="undefined"){g=self;}else{g=this;}if(typeof g.visualization_msgs==="undefined"){g.visualization_msgs={};}g.visualization_msgs.InteractiveMarkerInit=f();}})(function(){var define,module,exports;'use strict';
const _CURRENT_PATH_ = document.currentScript.src.substring(0, document.currentScript.src.lastIndexOf("/"));
const _ROOT_PATH_ = _CURRENT_PATH_.substring(0, _CURRENT_PATH_.lastIndexOf("/"));
document.write("<script language=javascript src='"+_ROOT_PATH_+"/visualization_msgs/InteractiveMarker.js'></script>");

function InteractiveMarkerInit() {
    this.server_id = "";
    this.seq_num = 0;
    this.markers = new Array();
};

InteractiveMarkerInit.prototype.serialize = function(buff, idx) {
    var offset = idx;
    var encoder_server_id = new TextEncoder('utf8');
    var utf8array_server_id = encoder_server_id.encode(this.server_id);
    buff[offset + 0] = (utf8array_server_id.length >> (8 * 0)) & 0xFF;
    buff[offset + 1] = (utf8array_server_id.length >> (8 * 1)) & 0xFF;
    buff[offset + 2] = (utf8array_server_id.length >> (8 * 2)) & 0xFF;
    buff[offset + 3] = (utf8array_server_id.length >> (8 * 3)) & 0xFF;
    offset += 4;
    for (var i = 0; i < utf8array_server_id.length; i++) {
        buff[offset + i] = utf8array_server_id[i];
    }
    offset += utf8array_server_id.length;
    buff[offset + 0] = ((+this.seq_num) >> (8 * 0)) & 0xFF;
    buff[offset + 1] = ((+this.seq_num) >> (8 * 1)) & 0xFF;
    buff[offset + 2] = ((+this.seq_num) >> (8 * 2)) & 0xFF;
    buff[offset + 3] = ((+this.seq_num) >> (8 * 3)) & 0xFF;
    buff[offset + 4] = ((+this.seq_num) >> (8 * 4)) & 0xFF;
    buff[offset + 5] = ((+this.seq_num) >> (8 * 5)) & 0xFF;
    buff[offset + 6] = ((+this.seq_num) >> (8 * 6)) & 0xFF;
    buff[offset + 7] = ((+this.seq_num) >> (8 * 7)) & 0xFF;
    offset += 8;
    var length_markers = this.markers.length;
    buff[offset + 0] = (length_markers >> (8 * 0)) & 0xFF;
    buff[offset + 1] = (length_markers >> (8 * 1)) & 0xFF;
    buff[offset + 2] = (length_markers >> (8 * 2)) & 0xFF;
    buff[offset + 3] = (length_markers >> (8 * 3)) & 0xFF;
    offset += 4;
    for (var i = 0; i < length_markers; i++) {
        offset = this.markers[i].serialize(buff, offset);
    }
    return offset;
};

InteractiveMarkerInit.prototype.deserialize = function(buff, idx) {
    var offset = idx;
    var length_server_id = +((buff[offset + 0] & 0xFF) << (8 * 0));
    length_server_id |= +((buff[offset + 1] & 0xFF) << (8 * 1));
    length_server_id |= +((buff[offset + 2] & 0xFF) << (8 * 2));
    length_server_id |= +((buff[offset + 3] & 0xFF) << (8 * 3))
    offset += 4;
    var decoder_server_id = new TextDecoder('utf8');
    this.server_id = decoder_server_id.decode(buff.slice(offset, offset + length_server_id));
    offset += length_server_id;
    this.seq_num = +((buff[offset + 0] & 0xFF) << (8 * 0));
    this.seq_num |= +((buff[offset + 1] & 0xFF) << (8 * 1));
    this.seq_num |= +((buff[offset + 2] & 0xFF) << (8 * 2));
    this.seq_num |= +((buff[offset + 3] & 0xFF) << (8 * 3));
    this.seq_num |= +((buff[offset + 4] & 0xFF) << (8 * 4));
    this.seq_num |= +((buff[offset + 5] & 0xFF) << (8 * 5));
    this.seq_num |= +((buff[offset + 6] & 0xFF) << (8 * 6));
    this.seq_num |= +((buff[offset + 7] & 0xFF) << (8 * 7));
    offset += 8;
    var length_markers = +((buff[offset + 0] & 0xFF) << (8 * 0));
    length_markers |= +((buff[offset + 1] & 0xFF) << (8 * 1));
    length_markers |= +((buff[offset + 2] & 0xFF) << (8 * 2));
    length_markers |= +((buff[offset + 3] & 0xFF) << (8 * 3));
    offset += 4;
    this.markers = new Array(length_markers);
    for (var i = 0; i < length_markers; i++) {
        this.markers[i] = visualization_msgs.InteractiveMarker();
        offset = this.markers[i].deserialize(buff, offset);
    }
    return offset;
};

InteractiveMarkerInit.prototype.serializedLength = function() {
    var length = 0;
    var encoder_server_id = new TextEncoder('utf8');
    var utf8array_server_id = encoder_server_id.encode(this.server_id);
    length += 4;
    length += utf8array_server_id.length;
    length += 8
    var length_markers = this.markers.length;
    length += 4;
    for (var i = 0; i < length_markers; i++) {
        length += this.markers[i].serializedLength();
    }
    return length;
};

InteractiveMarkerInit.prototype.echo = function() { return ""; };

InteractiveMarkerInit.prototype.getType = function() { return "visualization_msgs/InteractiveMarkerInit"; };

InteractiveMarkerInit.prototype.getMD5 = function() { return "b8259a8319519330ca4da698883a3e0e"; };

InteractiveMarkerInit.prototype.getID = function() { return 0; };

InteractiveMarkerInit.prototype.setID = function(id) { };

return function() { return new InteractiveMarkerInit(); };

});
