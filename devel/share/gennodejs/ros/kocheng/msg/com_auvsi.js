// Auto-generated. Do not edit!

// (in-package kocheng.msg)


"use strict";

const _serializer = _ros_msg_utils.Serialize;
const _arraySerializer = _serializer.Array;
const _deserializer = _ros_msg_utils.Deserialize;
const _arrayDeserializer = _deserializer.Array;
const _finder = _ros_msg_utils.Find;
const _getByteLength = _ros_msg_utils.getByteLength;

//-----------------------------------------------------------

class com_auvsi {
  constructor(initObj={}) {
    if (initObj === null) {
      // initObj === null is a special case for deserialization where we don't initialize fields
      this.mission_makara = null;
    }
    else {
      if (initObj.hasOwnProperty('mission_makara')) {
        this.mission_makara = initObj.mission_makara
      }
      else {
        this.mission_makara = '';
      }
    }
  }

  static serialize(obj, buffer, bufferOffset) {
    // Serializes a message object of type com_auvsi
    // Serialize message field [mission_makara]
    bufferOffset = _serializer.string(obj.mission_makara, buffer, bufferOffset);
    return bufferOffset;
  }

  static deserialize(buffer, bufferOffset=[0]) {
    //deserializes a message object of type com_auvsi
    let len;
    let data = new com_auvsi(null);
    // Deserialize message field [mission_makara]
    data.mission_makara = _deserializer.string(buffer, bufferOffset);
    return data;
  }

  static getMessageSize(object) {
    let length = 0;
    length += object.mission_makara.length;
    return length + 4;
  }

  static datatype() {
    // Returns string type for a message object
    return 'kocheng/com_auvsi';
  }

  static md5sum() {
    //Returns md5sum for a message object
    return '2e7801e6e1d9e6d8720e1966e071032b';
  }

  static messageDefinition() {
    // Returns full string definition for message
    return `
    string mission_makara
    
    `;
  }

  static Resolve(msg) {
    // deep-construct a valid message object instance of whatever was passed in
    if (typeof msg !== 'object' || msg === null) {
      msg = {};
    }
    const resolved = new com_auvsi(null);
    if (msg.mission_makara !== undefined) {
      resolved.mission_makara = msg.mission_makara;
    }
    else {
      resolved.mission_makara = ''
    }

    return resolved;
    }
};

module.exports = com_auvsi;
