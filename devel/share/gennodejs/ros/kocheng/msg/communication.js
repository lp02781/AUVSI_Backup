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

class communication {
  constructor(initObj={}) {
    if (initObj === null) {
      // initObj === null is a special case for deserialization where we don't initialize fields
      this.heartbeat_payload = null;
      this.run_course_payload = null;
      this.follow_payload = null;
      this.docking_payload = null;
    }
    else {
      if (initObj.hasOwnProperty('heartbeat_payload')) {
        this.heartbeat_payload = initObj.heartbeat_payload
      }
      else {
        this.heartbeat_payload = '';
      }
      if (initObj.hasOwnProperty('run_course_payload')) {
        this.run_course_payload = initObj.run_course_payload
      }
      else {
        this.run_course_payload = '';
      }
      if (initObj.hasOwnProperty('follow_payload')) {
        this.follow_payload = initObj.follow_payload
      }
      else {
        this.follow_payload = '';
      }
      if (initObj.hasOwnProperty('docking_payload')) {
        this.docking_payload = initObj.docking_payload
      }
      else {
        this.docking_payload = '';
      }
    }
  }

  static serialize(obj, buffer, bufferOffset) {
    // Serializes a message object of type communication
    // Serialize message field [heartbeat_payload]
    bufferOffset = _serializer.string(obj.heartbeat_payload, buffer, bufferOffset);
    // Serialize message field [run_course_payload]
    bufferOffset = _serializer.string(obj.run_course_payload, buffer, bufferOffset);
    // Serialize message field [follow_payload]
    bufferOffset = _serializer.string(obj.follow_payload, buffer, bufferOffset);
    // Serialize message field [docking_payload]
    bufferOffset = _serializer.string(obj.docking_payload, buffer, bufferOffset);
    return bufferOffset;
  }

  static deserialize(buffer, bufferOffset=[0]) {
    //deserializes a message object of type communication
    let len;
    let data = new communication(null);
    // Deserialize message field [heartbeat_payload]
    data.heartbeat_payload = _deserializer.string(buffer, bufferOffset);
    // Deserialize message field [run_course_payload]
    data.run_course_payload = _deserializer.string(buffer, bufferOffset);
    // Deserialize message field [follow_payload]
    data.follow_payload = _deserializer.string(buffer, bufferOffset);
    // Deserialize message field [docking_payload]
    data.docking_payload = _deserializer.string(buffer, bufferOffset);
    return data;
  }

  static getMessageSize(object) {
    let length = 0;
    length += object.heartbeat_payload.length;
    length += object.run_course_payload.length;
    length += object.follow_payload.length;
    length += object.docking_payload.length;
    return length + 16;
  }

  static datatype() {
    // Returns string type for a message object
    return 'kocheng/communication';
  }

  static md5sum() {
    //Returns md5sum for a message object
    return 'a4a71690d66d1b694fd29ac92ce201eb';
  }

  static messageDefinition() {
    // Returns full string definition for message
    return `
    string heartbeat_payload
    string run_course_payload
    string follow_payload
    string docking_payload
    
    `;
  }

  static Resolve(msg) {
    // deep-construct a valid message object instance of whatever was passed in
    if (typeof msg !== 'object' || msg === null) {
      msg = {};
    }
    const resolved = new communication(null);
    if (msg.heartbeat_payload !== undefined) {
      resolved.heartbeat_payload = msg.heartbeat_payload;
    }
    else {
      resolved.heartbeat_payload = ''
    }

    if (msg.run_course_payload !== undefined) {
      resolved.run_course_payload = msg.run_course_payload;
    }
    else {
      resolved.run_course_payload = ''
    }

    if (msg.follow_payload !== undefined) {
      resolved.follow_payload = msg.follow_payload;
    }
    else {
      resolved.follow_payload = ''
    }

    if (msg.docking_payload !== undefined) {
      resolved.docking_payload = msg.docking_payload;
    }
    else {
      resolved.docking_payload = ''
    }

    return resolved;
    }
};

module.exports = communication;
