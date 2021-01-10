(function(f){if(typeof exports==="object"&&typeof module!=="undefined"){module.exports=f();}else if(typeof define==="function"&&define.amd){define([],f);}else{var g;if(typeof window!=="undefined"){g=window;}else if(typeof global!=="undefined"){g=global;}else if(typeof self!=="undefined"){g=self;}else{g=this;}if(typeof g.visualization_msgs==="undefined"){g.visualization_msgs={};}g.visualization_msgs.InteractiveMarkerPose=f();}})(function(){var define,module,exports;'use strict';
const _CURRENT_PATH_ = document.currentScript.src.substring(0, document.currentScript.src.lastIndexOf("/"));
const _ROOT_PATH_ = _CURRENT_PATH_.substring(0, _CURRENT_PATH_.lastIndexOf("/"));
document.write("<script language=javascript src='"+_ROOT_PATH_+"/std_msgs/Header.js'></script>");
document.write("<script language=javascript src='"+_ROOT_PATH_+"/geometry_msgs/Pose.js'></script>");

function InteractiveMarkerPose() {
    this.header = std_msgs.Header();
    this.pose = geometry_msgs.Pose();
    this.name = "";
};

InteractiveMarkerPose.prototype.serialize = function(buff, idx) {
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
    return offset;
};

InteractiveMarkerPose.prototype.deserialize = function(buff, idx) {
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
    return offset;
};

InteractiveMarkerPose.prototype.serializedLength = function() {
    var length = 0;
    length += this.header.serializedLength();
    length += this.pose.serializedLength();
    var encoder_name = new TextEncoder('utf8');
    var utf8array_name = encoder_name.encode(this.name);
    length += 4;
    length += utf8array_name.length;
    return length;
};

InteractiveMarkerPose.prototype.echo = function() { return ""; };

InteractiveMarkerPose.prototype.getType = function() { return "visualization_msgs/InteractiveMarkerPose"; };

InteractiveMarkerPose.prototype.getMD5 = function() { return "d719f99881759f7a03f9f5411bdb7074"; };

InteractiveMarkerPose.prototype.getID = function() { return 0; };

InteractiveMarkerPose.prototype.setID = function(id) { };

return function() { return new InteractiveMarkerPose(); };

});
