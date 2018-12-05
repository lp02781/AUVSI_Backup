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

class rc_number {
  constructor(initObj={}) {
    if (initObj === null) {
      // initObj === null is a special case for deserialization where we don't initialize fields
      this.override_status = null;
      this.rc_number = null;
    }
    else {
      if (initObj.hasOwnProperty('override_status')) {
        this.override_status = initObj.override_status
      }
      else {
        this.override_status = false;
      }
      if (initObj.hasOwnProperty('rc_number')) {
        this.rc_number = initObj.rc_number
      }
      else {
        this.rc_number = 0;
      }
    }
  }

  static serialize(obj, buffer, bufferOffset) {
    // Serializes a message object of type rc_number
    // Serialize message field [override_status]
    bufferOffset = _serializer.bool(obj.override_status, buffer, bufferOffset);
    // Serialize message field [rc_number]
    bufferOffset = _serializer.int16(obj.rc_number, buffer, bufferOffset);
    return bufferOffset;
  }

  static deserialize(buffer, bufferOffset=[0]) {
    //deserializes a message object of type rc_number
    let len;
    let data = new rc_number(null);
    // Deserialize message field [override_status]
    data.override_status = _deserializer.bool(buffer, bufferOffset);
    // Deserialize message field [rc_number]
    data.rc_number = _deserializer.int16(buffer, bufferOffset);
    return data;
  }

  static getMessageSize(object) {
    return 3;
  }

  static datatype() {
    // Returns string type for a message object
    return 'kocheng/rc_number';
  }

  static md5sum() {
    //Returns md5sum for a message object
    return '245976b4840f71d588f1be6b4dde93f8';
  }

  static messageDefinition() {
    // Returns full string definition for message
    return `
    bool override_status
    int16 rc_number
    
    `;
  }

  static Resolve(msg) {
    // deep-construct a valid message object instance of whatever was passed in
    if (typeof msg !== 'object' || msg === null) {
      msg = {};
    }
    const resolved = new rc_number(null);
    if (msg.override_status !== undefined) {
      resolved.override_status = msg.override_status;
    }
    else {
      resolved.override_status = false
    }

    if (msg.rc_number !== undefined) {
      resolved.rc_number = msg.rc_number;
    }
    else {
      resolved.rc_number = 0
    }

    return resolved;
    }
};

module.exports = rc_number;
