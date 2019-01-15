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

class image_in {
  constructor(initObj={}) {
    if (initObj === null) {
      // initObj === null is a special case for deserialization where we don't initialize fields
      this.x_init = null;
      this.y_init = null;
      this.width = null;
      this.height = null;
      this.LowH = null;
      this.HighH = null;
      this.LowS = null;
      this.HighS = null;
      this.LowV = null;
      this.HighV = null;
      this.Noise = null;
    }
    else {
      if (initObj.hasOwnProperty('x_init')) {
        this.x_init = initObj.x_init
      }
      else {
        this.x_init = 0;
      }
      if (initObj.hasOwnProperty('y_init')) {
        this.y_init = initObj.y_init
      }
      else {
        this.y_init = 0;
      }
      if (initObj.hasOwnProperty('width')) {
        this.width = initObj.width
      }
      else {
        this.width = 0;
      }
      if (initObj.hasOwnProperty('height')) {
        this.height = initObj.height
      }
      else {
        this.height = 0;
      }
      if (initObj.hasOwnProperty('LowH')) {
        this.LowH = initObj.LowH
      }
      else {
        this.LowH = 0;
      }
      if (initObj.hasOwnProperty('HighH')) {
        this.HighH = initObj.HighH
      }
      else {
        this.HighH = 0;
      }
      if (initObj.hasOwnProperty('LowS')) {
        this.LowS = initObj.LowS
      }
      else {
        this.LowS = 0;
      }
      if (initObj.hasOwnProperty('HighS')) {
        this.HighS = initObj.HighS
      }
      else {
        this.HighS = 0;
      }
      if (initObj.hasOwnProperty('LowV')) {
        this.LowV = initObj.LowV
      }
      else {
        this.LowV = 0;
      }
      if (initObj.hasOwnProperty('HighV')) {
        this.HighV = initObj.HighV
      }
      else {
        this.HighV = 0;
      }
      if (initObj.hasOwnProperty('Noise')) {
        this.Noise = initObj.Noise
      }
      else {
        this.Noise = 0;
      }
    }
  }

  static serialize(obj, buffer, bufferOffset) {
    // Serializes a message object of type image_in
    // Serialize message field [x_init]
    bufferOffset = _serializer.int32(obj.x_init, buffer, bufferOffset);
    // Serialize message field [y_init]
    bufferOffset = _serializer.int32(obj.y_init, buffer, bufferOffset);
    // Serialize message field [width]
    bufferOffset = _serializer.int32(obj.width, buffer, bufferOffset);
    // Serialize message field [height]
    bufferOffset = _serializer.int32(obj.height, buffer, bufferOffset);
    // Serialize message field [LowH]
    bufferOffset = _serializer.int32(obj.LowH, buffer, bufferOffset);
    // Serialize message field [HighH]
    bufferOffset = _serializer.int32(obj.HighH, buffer, bufferOffset);
    // Serialize message field [LowS]
    bufferOffset = _serializer.int32(obj.LowS, buffer, bufferOffset);
    // Serialize message field [HighS]
    bufferOffset = _serializer.int32(obj.HighS, buffer, bufferOffset);
    // Serialize message field [LowV]
    bufferOffset = _serializer.int32(obj.LowV, buffer, bufferOffset);
    // Serialize message field [HighV]
    bufferOffset = _serializer.int32(obj.HighV, buffer, bufferOffset);
    // Serialize message field [Noise]
    bufferOffset = _serializer.int32(obj.Noise, buffer, bufferOffset);
    return bufferOffset;
  }

  static deserialize(buffer, bufferOffset=[0]) {
    //deserializes a message object of type image_in
    let len;
    let data = new image_in(null);
    // Deserialize message field [x_init]
    data.x_init = _deserializer.int32(buffer, bufferOffset);
    // Deserialize message field [y_init]
    data.y_init = _deserializer.int32(buffer, bufferOffset);
    // Deserialize message field [width]
    data.width = _deserializer.int32(buffer, bufferOffset);
    // Deserialize message field [height]
    data.height = _deserializer.int32(buffer, bufferOffset);
    // Deserialize message field [LowH]
    data.LowH = _deserializer.int32(buffer, bufferOffset);
    // Deserialize message field [HighH]
    data.HighH = _deserializer.int32(buffer, bufferOffset);
    // Deserialize message field [LowS]
    data.LowS = _deserializer.int32(buffer, bufferOffset);
    // Deserialize message field [HighS]
    data.HighS = _deserializer.int32(buffer, bufferOffset);
    // Deserialize message field [LowV]
    data.LowV = _deserializer.int32(buffer, bufferOffset);
    // Deserialize message field [HighV]
    data.HighV = _deserializer.int32(buffer, bufferOffset);
    // Deserialize message field [Noise]
    data.Noise = _deserializer.int32(buffer, bufferOffset);
    return data;
  }

  static getMessageSize(object) {
    return 44;
  }

  static datatype() {
    // Returns string type for a message object
    return 'kocheng/image_in';
  }

  static md5sum() {
    //Returns md5sum for a message object
    return '98a894c5a1e69900105970008d648417';
  }

  static messageDefinition() {
    // Returns full string definition for message
    return `
    int32 x_init
    int32 y_init
    int32 width
    int32 height
    int32 LowH 
    int32 HighH
    int32 LowS
    int32 HighS
    int32 LowV
    int32 HighV
    int32 Noise
    
    `;
  }

  static Resolve(msg) {
    // deep-construct a valid message object instance of whatever was passed in
    if (typeof msg !== 'object' || msg === null) {
      msg = {};
    }
    const resolved = new image_in(null);
    if (msg.x_init !== undefined) {
      resolved.x_init = msg.x_init;
    }
    else {
      resolved.x_init = 0
    }

    if (msg.y_init !== undefined) {
      resolved.y_init = msg.y_init;
    }
    else {
      resolved.y_init = 0
    }

    if (msg.width !== undefined) {
      resolved.width = msg.width;
    }
    else {
      resolved.width = 0
    }

    if (msg.height !== undefined) {
      resolved.height = msg.height;
    }
    else {
      resolved.height = 0
    }

    if (msg.LowH !== undefined) {
      resolved.LowH = msg.LowH;
    }
    else {
      resolved.LowH = 0
    }

    if (msg.HighH !== undefined) {
      resolved.HighH = msg.HighH;
    }
    else {
      resolved.HighH = 0
    }

    if (msg.LowS !== undefined) {
      resolved.LowS = msg.LowS;
    }
    else {
      resolved.LowS = 0
    }

    if (msg.HighS !== undefined) {
      resolved.HighS = msg.HighS;
    }
    else {
      resolved.HighS = 0
    }

    if (msg.LowV !== undefined) {
      resolved.LowV = msg.LowV;
    }
    else {
      resolved.LowV = 0
    }

    if (msg.HighV !== undefined) {
      resolved.HighV = msg.HighV;
    }
    else {
      resolved.HighV = 0
    }

    if (msg.Noise !== undefined) {
      resolved.Noise = msg.Noise;
    }
    else {
      resolved.Noise = 0
    }

    return resolved;
    }
};

module.exports = image_in;
