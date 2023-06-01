// Auto-generated. Do not edit!

// (in-package franka_planner_control.msg)


"use strict";

const _serializer = _ros_msg_utils.Serialize;
const _arraySerializer = _serializer.Array;
const _deserializer = _ros_msg_utils.Deserialize;
const _arrayDeserializer = _deserializer.Array;
const _finder = _ros_msg_utils.Find;
const _getByteLength = _ros_msg_utils.getByteLength;

//-----------------------------------------------------------

class DSM {
  constructor(initObj={}) {
    if (initObj === null) {
      // initObj === null is a special case for deserialization where we don't initialize fields
      this.time = null;
      this.DSM = null;
      this.tau = null;
      this.dotq = null;
      this.q = null;
      this.dotp_EE = null;
      this.terminalenergy = null;
      this.sphere = null;
      this.cylinder = null;
      this.wall = null;
    }
    else {
      if (initObj.hasOwnProperty('time')) {
        this.time = initObj.time
      }
      else {
        this.time = 0.0;
      }
      if (initObj.hasOwnProperty('DSM')) {
        this.DSM = initObj.DSM
      }
      else {
        this.DSM = 0.0;
      }
      if (initObj.hasOwnProperty('tau')) {
        this.tau = initObj.tau
      }
      else {
        this.tau = 0.0;
      }
      if (initObj.hasOwnProperty('dotq')) {
        this.dotq = initObj.dotq
      }
      else {
        this.dotq = 0.0;
      }
      if (initObj.hasOwnProperty('q')) {
        this.q = initObj.q
      }
      else {
        this.q = 0.0;
      }
      if (initObj.hasOwnProperty('dotp_EE')) {
        this.dotp_EE = initObj.dotp_EE
      }
      else {
        this.dotp_EE = 0.0;
      }
      if (initObj.hasOwnProperty('terminalenergy')) {
        this.terminalenergy = initObj.terminalenergy
      }
      else {
        this.terminalenergy = 0.0;
      }
      if (initObj.hasOwnProperty('sphere')) {
        this.sphere = initObj.sphere
      }
      else {
        this.sphere = 0.0;
      }
      if (initObj.hasOwnProperty('cylinder')) {
        this.cylinder = initObj.cylinder
      }
      else {
        this.cylinder = 0.0;
      }
      if (initObj.hasOwnProperty('wall')) {
        this.wall = initObj.wall
      }
      else {
        this.wall = 0.0;
      }
    }
  }

  static serialize(obj, buffer, bufferOffset) {
    // Serializes a message object of type DSM
    // Serialize message field [time]
    bufferOffset = _serializer.float64(obj.time, buffer, bufferOffset);
    // Serialize message field [DSM]
    bufferOffset = _serializer.float64(obj.DSM, buffer, bufferOffset);
    // Serialize message field [tau]
    bufferOffset = _serializer.float64(obj.tau, buffer, bufferOffset);
    // Serialize message field [dotq]
    bufferOffset = _serializer.float64(obj.dotq, buffer, bufferOffset);
    // Serialize message field [q]
    bufferOffset = _serializer.float64(obj.q, buffer, bufferOffset);
    // Serialize message field [dotp_EE]
    bufferOffset = _serializer.float64(obj.dotp_EE, buffer, bufferOffset);
    // Serialize message field [terminalenergy]
    bufferOffset = _serializer.float64(obj.terminalenergy, buffer, bufferOffset);
    // Serialize message field [sphere]
    bufferOffset = _serializer.float64(obj.sphere, buffer, bufferOffset);
    // Serialize message field [cylinder]
    bufferOffset = _serializer.float64(obj.cylinder, buffer, bufferOffset);
    // Serialize message field [wall]
    bufferOffset = _serializer.float64(obj.wall, buffer, bufferOffset);
    return bufferOffset;
  }

  static deserialize(buffer, bufferOffset=[0]) {
    //deserializes a message object of type DSM
    let len;
    let data = new DSM(null);
    // Deserialize message field [time]
    data.time = _deserializer.float64(buffer, bufferOffset);
    // Deserialize message field [DSM]
    data.DSM = _deserializer.float64(buffer, bufferOffset);
    // Deserialize message field [tau]
    data.tau = _deserializer.float64(buffer, bufferOffset);
    // Deserialize message field [dotq]
    data.dotq = _deserializer.float64(buffer, bufferOffset);
    // Deserialize message field [q]
    data.q = _deserializer.float64(buffer, bufferOffset);
    // Deserialize message field [dotp_EE]
    data.dotp_EE = _deserializer.float64(buffer, bufferOffset);
    // Deserialize message field [terminalenergy]
    data.terminalenergy = _deserializer.float64(buffer, bufferOffset);
    // Deserialize message field [sphere]
    data.sphere = _deserializer.float64(buffer, bufferOffset);
    // Deserialize message field [cylinder]
    data.cylinder = _deserializer.float64(buffer, bufferOffset);
    // Deserialize message field [wall]
    data.wall = _deserializer.float64(buffer, bufferOffset);
    return data;
  }

  static getMessageSize(object) {
    return 80;
  }

  static datatype() {
    // Returns string type for a message object
    return 'franka_planner_control/DSM';
  }

  static md5sum() {
    //Returns md5sum for a message object
    return 'b450392d56d2a24eb5c7559f486528c5';
  }

  static messageDefinition() {
    // Returns full string definition for message
    return `
    float64 time
    float64 DSM
    float64 tau
    float64 dotq
    float64 q
    float64 dotp_EE
    float64 terminalenergy
    float64 sphere
    float64 cylinder
    float64 wall
    `;
  }

  static Resolve(msg) {
    // deep-construct a valid message object instance of whatever was passed in
    if (typeof msg !== 'object' || msg === null) {
      msg = {};
    }
    const resolved = new DSM(null);
    if (msg.time !== undefined) {
      resolved.time = msg.time;
    }
    else {
      resolved.time = 0.0
    }

    if (msg.DSM !== undefined) {
      resolved.DSM = msg.DSM;
    }
    else {
      resolved.DSM = 0.0
    }

    if (msg.tau !== undefined) {
      resolved.tau = msg.tau;
    }
    else {
      resolved.tau = 0.0
    }

    if (msg.dotq !== undefined) {
      resolved.dotq = msg.dotq;
    }
    else {
      resolved.dotq = 0.0
    }

    if (msg.q !== undefined) {
      resolved.q = msg.q;
    }
    else {
      resolved.q = 0.0
    }

    if (msg.dotp_EE !== undefined) {
      resolved.dotp_EE = msg.dotp_EE;
    }
    else {
      resolved.dotp_EE = 0.0
    }

    if (msg.terminalenergy !== undefined) {
      resolved.terminalenergy = msg.terminalenergy;
    }
    else {
      resolved.terminalenergy = 0.0
    }

    if (msg.sphere !== undefined) {
      resolved.sphere = msg.sphere;
    }
    else {
      resolved.sphere = 0.0
    }

    if (msg.cylinder !== undefined) {
      resolved.cylinder = msg.cylinder;
    }
    else {
      resolved.cylinder = 0.0
    }

    if (msg.wall !== undefined) {
      resolved.wall = msg.wall;
    }
    else {
      resolved.wall = 0.0
    }

    return resolved;
    }
};

module.exports = DSM;
