(function(f){if(typeof exports==="object"&&typeof module!=="undefined"){module.exports=f();}else if(typeof define==="function"&&define.amd){define([],f);}else{var g;if(typeof window!=="undefined"){g=window;}else if(typeof global!=="undefined"){g=global;}else if(typeof self!=="undefined"){g=self;}else{g=this;}if(typeof g.visualization_msgs==="undefined"){g.visualization_msgs={};}g.visualization_msgs.MenuEntry=f();}})(function(){var define,module,exports;'use strict';

function MenuEntry() {
    this.id = 0;
    this.parent_id = 0;
    this.title = "";
    this.command = "";
    this.command_type = 0;

    // ENUM{
    this.FEEDBACK = 0;
    this.ROSRUN = 1;
    this.ROSLAUNCH = 2;
    // }ENUM
};

MenuEntry.prototype.serialize = function(buff, idx) {
    var offset = idx;
    buff[offset + 0] = ((+this.id) >> (8 * 0)) & 0xFF;
    buff[offset + 1] = ((+this.id) >> (8 * 1)) & 0xFF;
    buff[offset + 2] = ((+this.id) >> (8 * 2)) & 0xFF;
    buff[offset + 3] = ((+this.id) >> (8 * 3)) & 0xFF;
    offset += 4;
    buff[offset + 0] = ((+this.parent_id) >> (8 * 0)) & 0xFF;
    buff[offset + 1] = ((+this.parent_id) >> (8 * 1)) & 0xFF;
    buff[offset + 2] = ((+this.parent_id) >> (8 * 2)) & 0xFF;
    buff[offset + 3] = ((+this.parent_id) >> (8 * 3)) & 0xFF;
    offset += 4;
    var encoder_title = new TextEncoder('utf8');
    var utf8array_title = encoder_title.encode(this.title);
    buff[offset + 0] = (utf8array_title.length >> (8 * 0)) & 0xFF;
    buff[offset + 1] = (utf8array_title.length >> (8 * 1)) & 0xFF;
    buff[offset + 2] = (utf8array_title.length >> (8 * 2)) & 0xFF;
    buff[offset + 3] = (utf8array_title.length >> (8 * 3)) & 0xFF;
    offset += 4;
    for (var i = 0; i < utf8array_title.length; i++) {
        buff[offset + i] = utf8array_title[i];
    }
    offset += utf8array_title.length;
    var encoder_command = new TextEncoder('utf8');
    var utf8array_command = encoder_command.encode(this.command);
    buff[offset + 0] = (utf8array_command.length >> (8 * 0)) & 0xFF;
    buff[offset + 1] = (utf8array_command.length >> (8 * 1)) & 0xFF;
    buff[offset + 2] = (utf8array_command.length >> (8 * 2)) & 0xFF;
    buff[offset + 3] = (utf8array_command.length >> (8 * 3)) & 0xFF;
    offset += 4;
    for (var i = 0; i < utf8array_command.length; i++) {
        buff[offset + i] = utf8array_command[i];
    }
    offset += utf8array_command.length;
    buff[offset + 0] = ((+this.command_type) >> (8 * 0)) & 0xFF;
    offset += 1;
    return offset;
};

MenuEntry.prototype.deserialize = function(buff, idx) {
    var offset = idx;
    this.id = +((buff[offset + 0] & 0xFF) << (8 * 0));
    this.id |= +((buff[offset + 1] & 0xFF) << (8 * 1));
    this.id |= +((buff[offset + 2] & 0xFF) << (8 * 2));
    this.id |= +((buff[offset + 3] & 0xFF) << (8 * 3));
    offset += 4;
    this.parent_id = +((buff[offset + 0] & 0xFF) << (8 * 0));
    this.parent_id |= +((buff[offset + 1] & 0xFF) << (8 * 1));
    this.parent_id |= +((buff[offset + 2] & 0xFF) << (8 * 2));
    this.parent_id |= +((buff[offset + 3] & 0xFF) << (8 * 3));
    offset += 4;
    var length_title = +((buff[offset + 0] & 0xFF) << (8 * 0));
    length_title |= +((buff[offset + 1] & 0xFF) << (8 * 1));
    length_title |= +((buff[offset + 2] & 0xFF) << (8 * 2));
    length_title |= +((buff[offset + 3] & 0xFF) << (8 * 3))
    offset += 4;
    var decoder_title = new TextDecoder('utf8');
    this.title = decoder_title.decode(buff.slice(offset, offset + length_title));
    offset += length_title;
    var length_command = +((buff[offset + 0] & 0xFF) << (8 * 0));
    length_command |= +((buff[offset + 1] & 0xFF) << (8 * 1));
    length_command |= +((buff[offset + 2] & 0xFF) << (8 * 2));
    length_command |= +((buff[offset + 3] & 0xFF) << (8 * 3))
    offset += 4;
    var decoder_command = new TextDecoder('utf8');
    this.command = decoder_command.decode(buff.slice(offset, offset + length_command));
    offset += length_command;
    this.command_type = +((buff[offset + 0] & 0xFF) << (8 * 0));
    offset += 1;
    return offset;
};

MenuEntry.prototype.serializedLength = function() {
    var length = 0;
    length += 4
    length += 4
    var encoder_title = new TextEncoder('utf8');
    var utf8array_title = encoder_title.encode(this.title);
    length += 4;
    length += utf8array_title.length;
    var encoder_command = new TextEncoder('utf8');
    var utf8array_command = encoder_command.encode(this.command);
    length += 4;
    length += utf8array_command.length;
    length += 1
    return length;
};

MenuEntry.prototype.echo = function() { return ""; };

MenuEntry.prototype.getType = function() { return "visualization_msgs/MenuEntry"; };

MenuEntry.prototype.getMD5 = function() { return "09ef68f346107bee9bb8f9c6b994b413"; };

MenuEntry.prototype.getID = function() { return 0; };

MenuEntry.prototype.setID = function(id) { };

return function() { return new MenuEntry(); };

});
