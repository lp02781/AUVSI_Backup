// Auto-generated. Do not edit!

// (in-package roboboat.msg)


"use strict";

const _serializer = _ros_msg_utils.Serialize;
const _arraySerializer = _serializer.Array;
const _deserializer = _ros_msg_utils.Deserialize;
const _arrayDeserializer = _deserializer.Array;
const _finder = _ros_msg_utils.Find;
const _getByteLength = _ros_msg_utils.getByteLength;

//-----------------------------------------------------------

class node_status {
  constructor(initObj={}) {
    if (initObj === null) {
      // initObj === null is a special case for deserialization where we don't initialize fields
      this.override_status = null;
      this.image_front_status = null;
      this.image_back_status = null;
      this.green_hough_status = null;
      this.red_hough_status = null;
      this.blue_hough_status = null;
    }
    else {
      if (initObj.hasOwnProperty('override_status')) {
        this.override_status = initObj.override_status
      }
      else {
        this.override_status = false;
      }
      if (initObj.hasOwnProperty('image_front_status')) {
        this.image_front_status = initObj.image_front_status
      }
      else {
        this.image_front_status = false;
      }
      if (initObj.hasOwnProperty('image_back_status')) {
        this.image_back_status = initObj.image_back_status
      }
      else {
        this.image_back_status = false;
      }
      if (initObj.hasOwnProperty('green_hough_status')) {
        this.green_hough_status = initObj.green_hough_status
      }
      else {
        this.green_hough_status = false;
      }
      if (initObj.hasOwnProperty('red_hough_status')) {
        this.red_hough_status = initObj.red_hough_status
      }
      else {
        this.red_hough_status = false;
      }
      if (initObj.hasOwnProperty('blue_hough_status')) {
        this.blue_hough_status = initObj.blue_hough_status
      }
      else {
        this.blue_hough_status = false;
      }
    }
  }

  static serialize(obj, buffer, bufferOffset) {
    // Serializes a message object of type node_status
    // Serialize message field [override_status]
    bufferOffset = _serializer.bool(obj.override_status, buffer, bufferOffset);
    // Serialize message field [image_front_status]
    bufferOffset = _serializer.bool(obj.image_front_status, buffer, bufferOffset);
    // Serialize message field [image_back_status]
    bufferOffset = _serializer.bool(obj.image_back_status, buffer, bufferOffset);
    // Serialize message field [green_hough_status]
    bufferOffset = _serializer.bool(obj.green_hough_status, buffer, bufferOffset);
    // Serialize message field [red_hough_status]
    bufferOffset = _serializer.bool(obj.red_hough_status, buffer, bufferOffset);
    // Serialize message field [blue_hough_status]
    bufferOffset = _serializer.bool(obj.blue_hough_status, buffer, bufferOffset);
    return bufferOffset;
  }

  static deserialize(buffer, bufferOffset=[0]) {
    //deserializes a message object of type node_status
    let len;
    let data = new node_status(null);
    // Deserialize message field [override_status]
    data.override_status = _deserializer.bool(buffer, bufferOffset);
    // Deserialize message field [image_front_status]
    data.image_front_status = _deserializer.bool(buffer, bufferOffset);
    // Deserialize message field [image_back_status]
    data.image_back_status = _deserializer.bool(buffer, bufferOffset);
    // Deserialize message field [green_hough_status]
    data.green_hough_status = _deserializer.bool(buffer, bufferOffset);
    // Deserialize message field [red_hough_status]
    data.red_hough_status = _deserializer.bool(buffer, bufferOffset);
    // Deserialize message field [blue_hough_status]
    data.blue_hough_status = _deserializer.bool(buffer, bufferOffset);
    return data;
  }

  static getMessageSize(object) {
    return 6;
  }

  static datatype() {
    // Returns string type for a message object
    return 'roboboat/node_status';
  }

  static md5sum() {
    //Returns md5sum for a message object
    return 'd36a6a4442f3498759f12ca2b580445e';
  }

  static messageDefinition() {
    // Returns full string definition for message
    return `
    bool override_status
    bool image_front_status
    bool image_back_status
    bool green_hough_status
    bool red_hough_status
    bool blue_hough_status
    
    
    `;
  }

  static Resolve(msg) {
    // deep-construct a valid message object instance of whatever was passed in
    if (typeof msg !== 'object' || msg === null) {
      msg = {};
    }
    const resolved = new node_status(null);
    if (msg.override_status !== undefined) {
      resolved.override_status = msg.override_status;
    }
    else {
      resolved.override_status = false
    }

    if (msg.image_front_status !== undefined) {
      resolved.image_front_status = msg.image_front_status;
    }
    else {
      resolved.image_front_status = false
    }

    if (msg.image_back_status !== undefined) {
      resolved.image_back_status = msg.image_back_status;
    }
    else {
      resolved.image_back_status = false
    }

    if (msg.green_hough_status !== undefined) {
      resolved.green_hough_status = msg.green_hough_status;
    }
    else {
      resolved.green_hough_status = false
    }

    if (msg.red_hough_status !== undefined) {
      resolved.red_hough_status = msg.red_hough_status;
    }
    else {
      resolved.red_hough_status = false
    }

    if (msg.blue_hough_status !== undefined) {
      resolved.blue_hough_status = msg.blue_hough_status;
    }
    else {
      resolved.blue_hough_status = false
    }

    return resolved;
    }
};

module.exports = node_status;
