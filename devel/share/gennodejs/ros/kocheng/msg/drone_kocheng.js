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

class drone_kocheng {
  constructor(initObj={}) {
    if (initObj === null) {
      // initObj === null is a special case for deserialization where we don't initialize fields
      this.drone_status = null;
    }
    else {
      if (initObj.hasOwnProperty('drone_status')) {
        this.drone_status = initObj.drone_status
      }
      else {
        this.drone_status = '';
      }
    }
  }

  static serialize(obj, buffer, bufferOffset) {
    // Serializes a message object of type drone_kocheng
    // Serialize message field [drone_status]
    bufferOffset = _serializer.string(obj.drone_status, buffer, bufferOffset);
    return bufferOffset;
  }

  static deserialize(buffer, bufferOffset=[0]) {
    //deserializes a message object of type drone_kocheng
    let len;
    let data = new drone_kocheng(null);
    // Deserialize message field [drone_status]
    data.drone_status = _deserializer.string(buffer, bufferOffset);
    return data;
  }

  static getMessageSize(object) {
    let length = 0;
    length += object.drone_status.length;
    return length + 4;
  }

  static datatype() {
    // Returns string type for a message object
    return 'kocheng/drone_kocheng';
  }

  static md5sum() {
    //Returns md5sum for a message object
    return '2c7c5edf7dfbe4935f6f975fe743924d';
  }

  static messageDefinition() {
    // Returns full string definition for message
    return `
    string drone_status
    
    `;
  }

  static Resolve(msg) {
    // deep-construct a valid message object instance of whatever was passed in
    if (typeof msg !== 'object' || msg === null) {
      msg = {};
    }
    const resolved = new drone_kocheng(null);
    if (msg.drone_status !== undefined) {
      resolved.drone_status = msg.drone_status;
    }
    else {
      resolved.drone_status = ''
    }

    return resolved;
    }
};

module.exports = drone_kocheng;
