(function(f){if(typeof exports==="object"&&typeof module!=="undefined"){module.exports=f();}else if(typeof define==="function"&&define.amd){define([],f);}else{var g;if(typeof window!=="undefined"){g=window;}else if(typeof global!=="undefined"){g=global;}else if(typeof self!=="undefined"){g=self;}else{g=this;}if(typeof g.visualization_msgs==="undefined"){g.visualization_msgs={};}g.visualization_msgs.InteractiveMarkerUpdate=f();}})(function(){var define,module,exports;'use strict';
const _CURRENT_PATH_ = document.currentScript.src.substring(0, document.currentScript.src.lastIndexOf("/"));
const _ROOT_PATH_ = _CURRENT_PATH_.substring(0, _CURRENT_PATH_.lastIndexOf("/"));
document.write("<script language=javascript src='"+_ROOT_PATH_+"/visualization_msgs/InteractiveMarker.js'></script>");
document.write("<script language=javascript src='"+_ROOT_PATH_+"/visualization_msgs/InteractiveMarkerPose.js'></script>");

function InteractiveMarkerUpdate() {
    this.server_id = "";
    this.seq_num = 0;
    this.type = 0;
    this.markers = new Array();
    this.poses = new Array();
    this.erases = new Array();

    // ENUM{
    this.KEEP_ALIVE =  0;
    this.UPDATE =  1;
    // }ENUM
};

InteractiveMarkerUpdate.prototype.serialize = function(buff, idx) {
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
    buff[offset + 0] = ((+this.type) >> (8 * 0)) & 0xFF;
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
    var length_poses = this.poses.length;
    buff[offset + 0] = (length_poses >> (8 * 0)) & 0xFF;
    buff[offset + 1] = (length_poses >> (8 * 1)) & 0xFF;
    buff[offset + 2] = (length_poses >> (8 * 2)) & 0xFF;
    buff[offset + 3] = (length_poses >> (8 * 3)) & 0xFF;
    offset += 4;
    for (var i = 0; i < length_poses; i++) {
        offset = this.poses[i].serialize(buff, offset);
    }
    var length_erases = this.erases.length;
    buff[offset + 0] = (length_erases >> (8 * 0)) & 0xFF;
    buff[offset + 1] = (length_erases >> (8 * 1)) & 0xFF;
    buff[offset + 2] = (length_erases >> (8 * 2)) & 0xFF;
    buff[offset + 3] = (length_erases >> (8 * 3)) & 0xFF;
    offset += 4;
    for (var i = 0; i < length_erases; i++) {
        var encoder_erasesi = new TextEncoder('utf8');
        var utf8array_erasesi = encoder_erasesi.encode(this.erases[i]);
        buff[offset + 0] = (utf8array_erasesi.length >> (8 * 0)) & 0xFF;
        buff[offset + 1] = (utf8array_erasesi.length >> (8 * 1)) & 0xFF;
        buff[offset + 2] = (utf8array_erasesi.length >> (8 * 2)) & 0xFF;
        buff[offset + 3] = (utf8array_erasesi.length >> (8 * 3)) & 0xFF;
        offset += 4;
        for (var i = 0; i < utf8array_erasesi.length; i++) {
            buff[offset + i] = utf8array_erasesi[i];
        }
        offset += utf8array_erasesi.length;
    }
    return offset;
};

InteractiveMarkerUpdate.prototype.deserialize = function(buff, idx) {
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
    this.type = +((buff[offset + 0] & 0xFF) << (8 * 0));
    offset += 1;
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
    var length_poses = +((buff[offset + 0] & 0xFF) << (8 * 0));
    length_poses |= +((buff[offset + 1] & 0xFF) << (8 * 1));
    length_poses |= +((buff[offset + 2] & 0xFF) << (8 * 2));
    length_poses |= +((buff[offset + 3] & 0xFF) << (8 * 3));
    offset += 4;
    this.poses = new Array(length_poses);
    for (var i = 0; i < length_poses; i++) {
        this.poses[i] = visualization_msgs.InteractiveMarkerPose();
        offset = this.poses[i].deserialize(buff, offset);
    }
    var length_erases = +((buff[offset + 0] & 0xFF) << (8 * 0));
    length_erases |= +((buff[offset + 1] & 0xFF) << (8 * 1));
    length_erases |= +((buff[offset + 2] & 0xFF) << (8 * 2));
    length_erases |= +((buff[offset + 3] & 0xFF) << (8 * 3));
    offset += 4;
    this.erases = new Array(length_erases);
    for (var i = 0; i < length_erases; i++) {
        var length_erasesi = +((buff[offset + 0] & 0xFF) << (8 * 0));
        length_erasesi |= +((buff[offset + 1] & 0xFF) << (8 * 1));
        length_erasesi |= +((buff[offset + 2] & 0xFF) << (8 * 2));
        length_erasesi |= +((buff[offset + 3] & 0xFF) << (8 * 3))
        offset += 4;
        var decoder_erasesi = new TextDecoder('utf8');
        this.erases[i] = decoder_erasesi.decode(buff.slice(offset, offset + length_erasesi));
        offset += length_erasesi;
    }
    return offset;
};

InteractiveMarkerUpdate.prototype.serializedLength = function() {
    var length = 0;
    var encoder_server_id = new TextEncoder('utf8');
    var utf8array_server_id = encoder_server_id.encode(this.server_id);
    length += 4;
    length += utf8array_server_id.length;
    length += 8
    length += 1
    var length_markers = this.markers.length;
    length += 4;
    for (var i = 0; i < length_markers; i++) {
        length += this.markers[i].serializedLength();
    }
    var length_poses = this.poses.length;
    length += 4;
    for (var i = 0; i < length_poses; i++) {
        length += this.poses[i].serializedLength();
    }
    var length_erases = this.erases.length;
    length += 4;
    for (var i = 0; i < length_erases; i++) {
        var encoder_erasesi = new TextEncoder('utf8');
        var utf8array_erasesi = encoder_erasesi.encode(this.erases[i]);
        length += 4;
        length += utf8array_erasesi.length;
    }
    return length;
};

InteractiveMarkerUpdate.prototype.echo = function() { return ""; };

InteractiveMarkerUpdate.prototype.getType = function() { return "visualization_msgs/InteractiveMarkerUpdate"; };

InteractiveMarkerUpdate.prototype.getMD5 = function() { return "ae37189a6cc8de1bae3ccd7710af4288"; };

InteractiveMarkerUpdate.prototype.getID = function() { return 0; };

InteractiveMarkerUpdate.prototype.setID = function(id) { };

return function() { return new InteractiveMarkerUpdate(); };

});
