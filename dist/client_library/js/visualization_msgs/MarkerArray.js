(function(f){if(typeof exports==="object"&&typeof module!=="undefined"){module.exports=f();}else if(typeof define==="function"&&define.amd){define([],f);}else{var g;if(typeof window!=="undefined"){g=window;}else if(typeof global!=="undefined"){g=global;}else if(typeof self!=="undefined"){g=self;}else{g=this;}if(typeof g.visualization_msgs==="undefined"){g.visualization_msgs={};}g.visualization_msgs.MarkerArray=f();}})(function(){var define,module,exports;'use strict';
const _CURRENT_PATH_ = document.currentScript.src.substring(0, document.currentScript.src.lastIndexOf("/"));
const _ROOT_PATH_ = _CURRENT_PATH_.substring(0, _CURRENT_PATH_.lastIndexOf("/"));
document.write("<script language=javascript src='"+_ROOT_PATH_+"/visualization_msgs/Marker.js'></script>");

function MarkerArray() {
    this.markers = new Array();
};

MarkerArray.prototype.serialize = function(buff, idx) {
    var offset = idx;
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

MarkerArray.prototype.deserialize = function(buff, idx) {
    var offset = idx;
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
    return offset;
};

MarkerArray.prototype.serializedLength = function() {
    var length = 0;
    var length_markers = this.markers.length;
    length += 4;
    for (var i = 0; i < length_markers; i++) {
        length += this.markers[i].serializedLength();
    }
    return length;
};

MarkerArray.prototype.echo = function() { return ""; };

MarkerArray.prototype.getType = function() { return "visualization_msgs/MarkerArray"; };

MarkerArray.prototype.getMD5 = function() { return "032534c86d6c02fcd8eb187cf568eb46"; };

MarkerArray.prototype.getID = function() { return 0; };

MarkerArray.prototype.setID = function(id) { };

return function() { return new MarkerArray(); };

});
