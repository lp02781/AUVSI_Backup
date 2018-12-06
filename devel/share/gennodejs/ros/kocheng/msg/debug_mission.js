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

class debug_mission {
  constructor(initObj={}) {
    if (initObj === null) {
      // initObj === null is a special case for deserialization where we don't initialize fields
      this.setpoint = null;
      this.state = null;
      this.effort = null;
      this.longitude = null;
      this.latitude = null;
    }
    else {
      if (initObj.hasOwnProperty('setpoint')) {
        this.setpoint = initObj.setpoint
      }
      else {
        this.setpoint = 0;
      }
      if (initObj.hasOwnProperty('state')) {
        this.state = initObj.state
      }
      else {
        this.state = 0;
      }
      if (initObj.hasOwnProperty('effort')) {
        this.effort = initObj.effort
      }
      else {
        this.effort = 0;
      }
      if (initObj.hasOwnProperty('longitude')) {
        this.longitude = initObj.longitude
      }
      else {
        this.longitude = 0.0;
      }
      if (initObj.hasOwnProperty('latitude')) {
        this.latitude = initObj.latitude
      }
      else {
        this.latitude = 0.0;
      }
    }
  }

  static serialize(obj, buffer, bufferOffset) {
    // Serializes a message object of type debug_mission
    // Serialize message field [setpoint]
    bufferOffset = _serializer.int16(obj.setpoint, buffer, bufferOffset);
    // Serialize message field [state]
    bufferOffset = _serializer.int16(obj.state, buffer, bufferOffset);
    // Serialize message field [effort]
    bufferOffset = _serializer.int16(obj.effort, buffer, bufferOffset);
    // Serialize message field [longitude]
    bufferOffset = _serializer.float32(obj.longitude, buffer, bufferOffset);
    // Serialize message field [latitude]
    bufferOffset = _serializer.float32(obj.latitude, buffer, bufferOffset);
    return bufferOffset;
  }

  static deserialize(buffer, bufferOffset=[0]) {
    //deserializes a message object of type debug_mission
    let len;
    let data = new debug_mission(null);
    // Deserialize message field [setpoint]
    data.setpoint = _deserializer.int16(buffer, bufferOffset);
    // Deserialize message field [state]
    data.state = _deserializer.int16(buffer, bufferOffset);
    // Deserialize message field [effort]
    data.effort = _deserializer.int16(buffer, bufferOffset);
    // Deserialize message field [longitude]
    data.longitude = _deserializer.float32(buffer, bufferOffset);
    // Deserialize message field [latitude]
    data.latitude = _deserializer.float32(buffer, bufferOffset);
    return data;
  }

  static getMessageSize(object) {
    return 14;
  }

  static datatype() {
    // Returns string type for a message object
    return 'kocheng/debug_mission';
  }

  static md5sum() {
    //Returns md5sum for a message object
    return '5ca02c94f587bbdb18e5bb5621c35260';
  }

  static messageDefinition() {
    // Returns full string definition for message
    return `
    int16 setpoint
    int16 state
    int16 effort
    float32 longitude
    float32 latitude
    
    `;
  }

  static Resolve(msg) {
    // deep-construct a valid message object instance of whatever was passed in
    if (typeof msg !== 'object' || msg === null) {
      msg = {};
    }
    const resolved = new debug_mission(null);
    if (msg.setpoint !== undefined) {
      resolved.setpoint = msg.setpoint;
    }
    else {
      resolved.setpoint = 0
    }

    if (msg.state !== undefined) {
      resolved.state = msg.state;
    }
    else {
      resolved.state = 0
    }

    if (msg.effort !== undefined) {
      resolved.effort = msg.effort;
    }
    else {
      resolved.effort = 0
    }

    if (msg.longitude !== undefined) {
      resolved.longitude = msg.longitude;
    }
    else {
      resolved.longitude = 0.0
    }

    if (msg.latitude !== undefined) {
      resolved.latitude = msg.latitude;
    }
    else {
      resolved.latitude = 0.0
    }

    return resolved;
    }
};

module.exports = debug_mission;
