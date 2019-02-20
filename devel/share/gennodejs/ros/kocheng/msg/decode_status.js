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

class decode_status {
  constructor(initObj={}) {
    if (initObj === null) {
      // initObj === null is a special case for deserialization where we don't initialize fields
      this.run_course_status = null;
      this.heartbeat_status = null;
      this.follow_status = null;
      this.docking_status = null;
      this.flag_status = null;
    }
    else {
      if (initObj.hasOwnProperty('run_course_status')) {
        this.run_course_status = initObj.run_course_status
      }
      else {
        this.run_course_status = 0;
      }
      if (initObj.hasOwnProperty('heartbeat_status')) {
        this.heartbeat_status = initObj.heartbeat_status
      }
      else {
        this.heartbeat_status = 0;
      }
      if (initObj.hasOwnProperty('follow_status')) {
        this.follow_status = initObj.follow_status
      }
      else {
        this.follow_status = 0;
      }
      if (initObj.hasOwnProperty('docking_status')) {
        this.docking_status = initObj.docking_status
      }
      else {
        this.docking_status = 0;
      }
      if (initObj.hasOwnProperty('flag_status')) {
        this.flag_status = initObj.flag_status
      }
      else {
        this.flag_status = 0;
      }
    }
  }

  static serialize(obj, buffer, bufferOffset) {
    // Serializes a message object of type decode_status
    // Serialize message field [run_course_status]
    bufferOffset = _serializer.int32(obj.run_course_status, buffer, bufferOffset);
    // Serialize message field [heartbeat_status]
    bufferOffset = _serializer.int32(obj.heartbeat_status, buffer, bufferOffset);
    // Serialize message field [follow_status]
    bufferOffset = _serializer.int32(obj.follow_status, buffer, bufferOffset);
    // Serialize message field [docking_status]
    bufferOffset = _serializer.int32(obj.docking_status, buffer, bufferOffset);
    // Serialize message field [flag_status]
    bufferOffset = _serializer.int32(obj.flag_status, buffer, bufferOffset);
    return bufferOffset;
  }

  static deserialize(buffer, bufferOffset=[0]) {
    //deserializes a message object of type decode_status
    let len;
    let data = new decode_status(null);
    // Deserialize message field [run_course_status]
    data.run_course_status = _deserializer.int32(buffer, bufferOffset);
    // Deserialize message field [heartbeat_status]
    data.heartbeat_status = _deserializer.int32(buffer, bufferOffset);
    // Deserialize message field [follow_status]
    data.follow_status = _deserializer.int32(buffer, bufferOffset);
    // Deserialize message field [docking_status]
    data.docking_status = _deserializer.int32(buffer, bufferOffset);
    // Deserialize message field [flag_status]
    data.flag_status = _deserializer.int32(buffer, bufferOffset);
    return data;
  }

  static getMessageSize(object) {
    return 20;
  }

  static datatype() {
    // Returns string type for a message object
    return 'kocheng/decode_status';
  }

  static md5sum() {
    //Returns md5sum for a message object
    return '39541b4d1e52937d3a67a84020aded6d';
  }

  static messageDefinition() {
    // Returns full string definition for message
    return `
    int32 run_course_status
    int32 heartbeat_status
    int32 follow_status
    int32 docking_status
    int32 flag_status
    
    `;
  }

  static Resolve(msg) {
    // deep-construct a valid message object instance of whatever was passed in
    if (typeof msg !== 'object' || msg === null) {
      msg = {};
    }
    const resolved = new decode_status(null);
    if (msg.run_course_status !== undefined) {
      resolved.run_course_status = msg.run_course_status;
    }
    else {
      resolved.run_course_status = 0
    }

    if (msg.heartbeat_status !== undefined) {
      resolved.heartbeat_status = msg.heartbeat_status;
    }
    else {
      resolved.heartbeat_status = 0
    }

    if (msg.follow_status !== undefined) {
      resolved.follow_status = msg.follow_status;
    }
    else {
      resolved.follow_status = 0
    }

    if (msg.docking_status !== undefined) {
      resolved.docking_status = msg.docking_status;
    }
    else {
      resolved.docking_status = 0
    }

    if (msg.flag_status !== undefined) {
      resolved.flag_status = msg.flag_status;
    }
    else {
      resolved.flag_status = 0
    }

    return resolved;
    }
};

module.exports = decode_status;
