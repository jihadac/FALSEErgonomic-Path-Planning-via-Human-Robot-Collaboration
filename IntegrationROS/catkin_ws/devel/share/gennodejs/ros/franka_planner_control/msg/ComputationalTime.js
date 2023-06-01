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

class ComputationalTime {
  constructor(initObj={}) {
    if (initObj === null) {
      // initObj === null is a special case for deserialization where we don't initialize fields
      this.time = null;
      this.NF = null;
      this.DSM = null;
      this.trajectory_predictions = null;
      this.ERG = null;
    }
    else {
      if (initObj.hasOwnProperty('time')) {
        this.time = initObj.time
      }
      else {
        this.time = 0.0;
      }
      if (initObj.hasOwnProperty('NF')) {
        this.NF = initObj.NF
      }
      else {
        this.NF = 0.0;
      }
      if (initObj.hasOwnProperty('DSM')) {
        this.DSM = initObj.DSM
      }
      else {
        this.DSM = 0.0;
      }
      if (initObj.hasOwnProperty('trajectory_predictions')) {
        this.trajectory_predictions = initObj.trajectory_predictions
      }
      else {
        this.trajectory_predictions = 0.0;
      }
      if (initObj.hasOwnProperty('ERG')) {
        this.ERG = initObj.ERG
      }
      else {
        this.ERG = 0.0;
      }
    }
  }

  static serialize(obj, buffer, bufferOffset) {
    // Serializes a message object of type ComputationalTime
    // Serialize message field [time]
    bufferOffset = _serializer.float64(obj.time, buffer, bufferOffset);
    // Serialize message field [NF]
    bufferOffset = _serializer.float64(obj.NF, buffer, bufferOffset);
    // Serialize message field [DSM]
    bufferOffset = _serializer.float64(obj.DSM, buffer, bufferOffset);
    // Serialize message field [trajectory_predictions]
    bufferOffset = _serializer.float64(obj.trajectory_predictions, buffer, bufferOffset);
    // Serialize message field [ERG]
    bufferOffset = _serializer.float64(obj.ERG, buffer, bufferOffset);
    return bufferOffset;
  }

  static deserialize(buffer, bufferOffset=[0]) {
    //deserializes a message object of type ComputationalTime
    let len;
    let data = new ComputationalTime(null);
    // Deserialize message field [time]
    data.time = _deserializer.float64(buffer, bufferOffset);
    // Deserialize message field [NF]
    data.NF = _deserializer.float64(buffer, bufferOffset);
    // Deserialize message field [DSM]
    data.DSM = _deserializer.float64(buffer, bufferOffset);
    // Deserialize message field [trajectory_predictions]
    data.trajectory_predictions = _deserializer.float64(buffer, bufferOffset);
    // Deserialize message field [ERG]
    data.ERG = _deserializer.float64(buffer, bufferOffset);
    return data;
  }

  static getMessageSize(object) {
    return 40;
  }

  static datatype() {
    // Returns string type for a message object
    return 'franka_planner_control/ComputationalTime';
  }

  static md5sum() {
    //Returns md5sum for a message object
    return '88eb9a619c00c3079c22019ebb22fa32';
  }

  static messageDefinition() {
    // Returns full string definition for message
    return `
    float64 time
    float64 NF
    float64 DSM
    float64 trajectory_predictions
    float64 ERG
    `;
  }

  static Resolve(msg) {
    // deep-construct a valid message object instance of whatever was passed in
    if (typeof msg !== 'object' || msg === null) {
      msg = {};
    }
    const resolved = new ComputationalTime(null);
    if (msg.time !== undefined) {
      resolved.time = msg.time;
    }
    else {
      resolved.time = 0.0
    }

    if (msg.NF !== undefined) {
      resolved.NF = msg.NF;
    }
    else {
      resolved.NF = 0.0
    }

    if (msg.DSM !== undefined) {
      resolved.DSM = msg.DSM;
    }
    else {
      resolved.DSM = 0.0
    }

    if (msg.trajectory_predictions !== undefined) {
      resolved.trajectory_predictions = msg.trajectory_predictions;
    }
    else {
      resolved.trajectory_predictions = 0.0
    }

    if (msg.ERG !== undefined) {
      resolved.ERG = msg.ERG;
    }
    else {
      resolved.ERG = 0.0
    }

    return resolved;
    }
};

module.exports = ComputationalTime;
