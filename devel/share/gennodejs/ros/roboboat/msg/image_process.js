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

class image_process {
  constructor(initObj={}) {
    if (initObj === null) {
      // initObj === null is a special case for deserialization where we don't initialize fields
      this.buoy_red = null;
      this.buoy_green = null;
      this.buoy_blue = null;
      this.gate_red = null;
      this.gate_green = null;
      this.x_flag = null;
      this.y_flag = null;
      this.dock_one = null;
      this.dock_two = null;
      this.dock_three = null;
    }
    else {
      if (initObj.hasOwnProperty('buoy_red')) {
        this.buoy_red = initObj.buoy_red
      }
      else {
        this.buoy_red = 0;
      }
      if (initObj.hasOwnProperty('buoy_green')) {
        this.buoy_green = initObj.buoy_green
      }
      else {
        this.buoy_green = 0;
      }
      if (initObj.hasOwnProperty('buoy_blue')) {
        this.buoy_blue = initObj.buoy_blue
      }
      else {
        this.buoy_blue = 0;
      }
      if (initObj.hasOwnProperty('gate_red')) {
        this.gate_red = initObj.gate_red
      }
      else {
        this.gate_red = 0;
      }
      if (initObj.hasOwnProperty('gate_green')) {
        this.gate_green = initObj.gate_green
      }
      else {
        this.gate_green = 0;
      }
      if (initObj.hasOwnProperty('x_flag')) {
        this.x_flag = initObj.x_flag
      }
      else {
        this.x_flag = 0;
      }
      if (initObj.hasOwnProperty('y_flag')) {
        this.y_flag = initObj.y_flag
      }
      else {
        this.y_flag = 0;
      }
      if (initObj.hasOwnProperty('dock_one')) {
        this.dock_one = initObj.dock_one
      }
      else {
        this.dock_one = 0;
      }
      if (initObj.hasOwnProperty('dock_two')) {
        this.dock_two = initObj.dock_two
      }
      else {
        this.dock_two = 0;
      }
      if (initObj.hasOwnProperty('dock_three')) {
        this.dock_three = initObj.dock_three
      }
      else {
        this.dock_three = 0;
      }
    }
  }

  static serialize(obj, buffer, bufferOffset) {
    // Serializes a message object of type image_process
    // Serialize message field [buoy_red]
    bufferOffset = _serializer.int16(obj.buoy_red, buffer, bufferOffset);
    // Serialize message field [buoy_green]
    bufferOffset = _serializer.int16(obj.buoy_green, buffer, bufferOffset);
    // Serialize message field [buoy_blue]
    bufferOffset = _serializer.int16(obj.buoy_blue, buffer, bufferOffset);
    // Serialize message field [gate_red]
    bufferOffset = _serializer.int16(obj.gate_red, buffer, bufferOffset);
    // Serialize message field [gate_green]
    bufferOffset = _serializer.int16(obj.gate_green, buffer, bufferOffset);
    // Serialize message field [x_flag]
    bufferOffset = _serializer.int16(obj.x_flag, buffer, bufferOffset);
    // Serialize message field [y_flag]
    bufferOffset = _serializer.int16(obj.y_flag, buffer, bufferOffset);
    // Serialize message field [dock_one]
    bufferOffset = _serializer.int16(obj.dock_one, buffer, bufferOffset);
    // Serialize message field [dock_two]
    bufferOffset = _serializer.int16(obj.dock_two, buffer, bufferOffset);
    // Serialize message field [dock_three]
    bufferOffset = _serializer.int16(obj.dock_three, buffer, bufferOffset);
    return bufferOffset;
  }

  static deserialize(buffer, bufferOffset=[0]) {
    //deserializes a message object of type image_process
    let len;
    let data = new image_process(null);
    // Deserialize message field [buoy_red]
    data.buoy_red = _deserializer.int16(buffer, bufferOffset);
    // Deserialize message field [buoy_green]
    data.buoy_green = _deserializer.int16(buffer, bufferOffset);
    // Deserialize message field [buoy_blue]
    data.buoy_blue = _deserializer.int16(buffer, bufferOffset);
    // Deserialize message field [gate_red]
    data.gate_red = _deserializer.int16(buffer, bufferOffset);
    // Deserialize message field [gate_green]
    data.gate_green = _deserializer.int16(buffer, bufferOffset);
    // Deserialize message field [x_flag]
    data.x_flag = _deserializer.int16(buffer, bufferOffset);
    // Deserialize message field [y_flag]
    data.y_flag = _deserializer.int16(buffer, bufferOffset);
    // Deserialize message field [dock_one]
    data.dock_one = _deserializer.int16(buffer, bufferOffset);
    // Deserialize message field [dock_two]
    data.dock_two = _deserializer.int16(buffer, bufferOffset);
    // Deserialize message field [dock_three]
    data.dock_three = _deserializer.int16(buffer, bufferOffset);
    return data;
  }

  static getMessageSize(object) {
    return 20;
  }

  static datatype() {
    // Returns string type for a message object
    return 'roboboat/image_process';
  }

  static md5sum() {
    //Returns md5sum for a message object
    return 'f2466f92f806c6e64e91ea6278fe0b11';
  }

  static messageDefinition() {
    // Returns full string definition for message
    return `
    int16 buoy_red
    int16 buoy_green
    int16 buoy_blue
    int16 gate_red
    int16 gate_green
    int16 x_flag
    int16 y_flag
    int16 dock_one
    int16 dock_two
    int16 dock_three
    
    `;
  }

  static Resolve(msg) {
    // deep-construct a valid message object instance of whatever was passed in
    if (typeof msg !== 'object' || msg === null) {
      msg = {};
    }
    const resolved = new image_process(null);
    if (msg.buoy_red !== undefined) {
      resolved.buoy_red = msg.buoy_red;
    }
    else {
      resolved.buoy_red = 0
    }

    if (msg.buoy_green !== undefined) {
      resolved.buoy_green = msg.buoy_green;
    }
    else {
      resolved.buoy_green = 0
    }

    if (msg.buoy_blue !== undefined) {
      resolved.buoy_blue = msg.buoy_blue;
    }
    else {
      resolved.buoy_blue = 0
    }

    if (msg.gate_red !== undefined) {
      resolved.gate_red = msg.gate_red;
    }
    else {
      resolved.gate_red = 0
    }

    if (msg.gate_green !== undefined) {
      resolved.gate_green = msg.gate_green;
    }
    else {
      resolved.gate_green = 0
    }

    if (msg.x_flag !== undefined) {
      resolved.x_flag = msg.x_flag;
    }
    else {
      resolved.x_flag = 0
    }

    if (msg.y_flag !== undefined) {
      resolved.y_flag = msg.y_flag;
    }
    else {
      resolved.y_flag = 0
    }

    if (msg.dock_one !== undefined) {
      resolved.dock_one = msg.dock_one;
    }
    else {
      resolved.dock_one = 0
    }

    if (msg.dock_two !== undefined) {
      resolved.dock_two = msg.dock_two;
    }
    else {
      resolved.dock_two = 0
    }

    if (msg.dock_three !== undefined) {
      resolved.dock_three = msg.dock_three;
    }
    else {
      resolved.dock_three = 0
    }

    return resolved;
    }
};

module.exports = image_process;
