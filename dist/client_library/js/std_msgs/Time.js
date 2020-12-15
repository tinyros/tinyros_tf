(function(f){if(typeof exports==="object"&&typeof module!=="undefined"){module.exports=f();}else if(typeof define==="function"&&define.amd){define([],f);}else{var g;if(typeof window!=="undefined"){g=window;}else if(typeof global!=="undefined"){g=global;}else if(typeof self!=="undefined"){g=self;}else{g=this;}if(typeof g.std_msgs==="undefined"){g.std_msgs={};}g.std_msgs.Time=f();}})(function(){var define,module,exports;'use strict';
const _CURRENT_PATH_ = document.currentScript.src.substring(0, document.currentScript.src.lastIndexOf("/"));
const _ROOT_PATH_ = _CURRENT_PATH_.substring(0, _CURRENT_PATH_.lastIndexOf("/"));
document.write("<script language=javascript src='"+_ROOT_PATH_+"/tinyros/Time.js'></script>");

function Time() {
    this.data = tinyros.Time();
};

Time.prototype.serialize = function(buff, idx) {
    var offset = idx;
    buff[offset + 0] = ((+this.data.sec) >> (8 * 0)) & 0xFF;
    buff[offset + 1] = ((+this.data.sec) >> (8 * 1)) & 0xFF;
    buff[offset + 2] = ((+this.data.sec) >> (8 * 2)) & 0xFF;
    buff[offset + 3] = ((+this.data.sec) >> (8 * 3)) & 0xFF;
    offset += 4;
    buff[offset + 0] = ((+this.data.nsec) >> (8 * 0)) & 0xFF;
    buff[offset + 1] = ((+this.data.nsec) >> (8 * 1)) & 0xFF;
    buff[offset + 2] = ((+this.data.nsec) >> (8 * 2)) & 0xFF;
    buff[offset + 3] = ((+this.data.nsec) >> (8 * 3)) & 0xFF;
    offset += 4;
    return offset;
};

Time.prototype.deserialize = function(buff, idx) {
    var offset = idx;
    this.data.sec = +((buff[offset + 0] & 0xFF) << (8 * 0));
    this.data.sec |= +((buff[offset + 1] & 0xFF) << (8 * 1));
    this.data.sec |= +((buff[offset + 2] & 0xFF) << (8 * 2));
    this.data.sec |= +((buff[offset + 3] & 0xFF) << (8 * 3));
    offset += 4;
    this.data.nsec = +((buff[offset + 0] & 0xFF) << (8 * 0));
    this.data.nsec |= +((buff[offset + 1] & 0xFF) << (8 * 1));
    this.data.nsec |= +((buff[offset + 2] & 0xFF) << (8 * 2));
    this.data.nsec |= +((buff[offset + 3] & 0xFF) << (8 * 3));
    offset += 4;
    return offset;
};

Time.prototype.serializedLength = function() {
    var length = 0;
    length += 4
    length += 4
    return length;
};

Time.prototype.echo = function() { return ""; };

Time.prototype.getType = function() { return "std_msgs/Time"; };

Time.prototype.getMD5 = function() { return "64602ed67393e1e61260ab68d6fa2045"; };

Time.prototype.getID = function() { return 0; };

Time.prototype.setID = function(id) { };

return function() { return new Time(); };

});
