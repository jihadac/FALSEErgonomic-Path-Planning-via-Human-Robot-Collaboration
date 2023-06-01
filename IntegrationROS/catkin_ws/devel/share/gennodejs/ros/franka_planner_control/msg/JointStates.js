// Auto-generated. Do not edit!

// (in-package franka_planner_control.msg)


"use strict";

const _serializer = _ros_msg_utils.Serialize;
const _arraySerializer = _serializer.Array;
const _deserializer = _ros_msg_utils.Deserialize;
const _arrayDeserializer = _deserializer.Array;
const _finder = _ros_msg_utils.Find;
const _getByteLength = _ros_msg_utils.getByteLength;
let geometry_msgs = _finder('geometry_msgs');

//-----------------------------------------------------------

class JointStates {
  constructor(initObj={}) {
    if (initObj === null) {
      // initObj === null is a special case for deserialization where we don't initialize fields
      this.time = null;
      this.xe_r = null;
      this.xe_v = null;
      this.xe = null;
      this.q_r = null;
      this.q_v = null;
      this.q = null;
      this.dotq = null;
      this.tau_commanded = null;
      this.tau_desired_g = null;
      this.tau_desired_full = null;
      this.tau_measured = null;
    }
    else {
      if (initObj.hasOwnProperty('time')) {
        this.time = initObj.time
      }
      else {
        this.time = 0.0;
      }
      if (initObj.hasOwnProperty('xe_r')) {
        this.xe_r = initObj.xe_r
      }
      else {
        this.xe_r = new geometry_msgs.msg.Pose();
      }
      if (initObj.hasOwnProperty('xe_v')) {
        this.xe_v = initObj.xe_v
      }
      else {
        this.xe_v = new geometry_msgs.msg.Pose();
      }
      if (initObj.hasOwnProperty('xe')) {
        this.xe = initObj.xe
      }
      else {
        this.xe = new geometry_msgs.msg.Pose();
      }
      if (initObj.hasOwnProperty('q_r')) {
        this.q_r = initObj.q_r
      }
      else {
        this.q_r = new Array(7).fill(0);
      }
      if (initObj.hasOwnProperty('q_v')) {
        this.q_v = initObj.q_v
      }
      else {
        this.q_v = new Array(7).fill(0);
      }
      if (initObj.hasOwnProperty('q')) {
        this.q = initObj.q
      }
      else {
        this.q = new Array(7).fill(0);
      }
      if (initObj.hasOwnProperty('dotq')) {
        this.dotq = initObj.dotq
      }
      else {
        this.dotq = new Array(7).fill(0);
      }
      if (initObj.hasOwnProperty('tau_commanded')) {
        this.tau_commanded = initObj.tau_commanded
      }
      else {
        this.tau_commanded = new Array(7).fill(0);
      }
      if (initObj.hasOwnProperty('tau_desired_g')) {
        this.tau_desired_g = initObj.tau_desired_g
      }
      else {
        this.tau_desired_g = new Array(7).fill(0);
      }
      if (initObj.hasOwnProperty('tau_desired_full')) {
        this.tau_desired_full = initObj.tau_desired_full
      }
      else {
        this.tau_desired_full = new Array(7).fill(0);
      }
      if (initObj.hasOwnProperty('tau_measured')) {
        this.tau_measured = initObj.tau_measured
      }
      else {
        this.tau_measured = new Array(7).fill(0);
      }
    }
  }

  static serialize(obj, buffer, bufferOffset) {
    // Serializes a message object of type JointStates
    // Serialize message field [time]
    bufferOffset = _serializer.float64(obj.time, buffer, bufferOffset);
    // Serialize message field [xe_r]
    bufferOffset = geometry_msgs.msg.Pose.serialize(obj.xe_r, buffer, bufferOffset);
    // Serialize message field [xe_v]
    bufferOffset = geometry_msgs.msg.Pose.serialize(obj.xe_v, buffer, bufferOffset);
    // Serialize message field [xe]
    bufferOffset = geometry_msgs.msg.Pose.serialize(obj.xe, buffer, bufferOffset);
    // Check that the constant length array field [q_r] has the right length
    if (obj.q_r.length !== 7) {
      throw new Error('Unable to serialize array field q_r - length must be 7')
    }
    // Serialize message field [q_r]
    bufferOffset = _arraySerializer.float64(obj.q_r, buffer, bufferOffset, 7);
    // Check that the constant length array field [q_v] has the right length
    if (obj.q_v.length !== 7) {
      throw new Error('Unable to serialize array field q_v - length must be 7')
    }
    // Serialize message field [q_v]
    bufferOffset = _arraySerializer.float64(obj.q_v, buffer, bufferOffset, 7);
    // Check that the constant length array field [q] has the right length
    if (obj.q.length !== 7) {
      throw new Error('Unable to serialize array field q - length must be 7')
    }
    // Serialize message field [q]
    bufferOffset = _arraySerializer.float64(obj.q, buffer, bufferOffset, 7);
    // Check that the constant length array field [dotq] has the right length
    if (obj.dotq.length !== 7) {
      throw new Error('Unable to serialize array field dotq - length must be 7')
    }
    // Serialize message field [dotq]
    bufferOffset = _arraySerializer.float64(obj.dotq, buffer, bufferOffset, 7);
    // Check that the constant length array field [tau_commanded] has the right length
    if (obj.tau_commanded.length !== 7) {
      throw new Error('Unable to serialize array field tau_commanded - length must be 7')
    }
    // Serialize message field [tau_commanded]
    bufferOffset = _arraySerializer.float64(obj.tau_commanded, buffer, bufferOffset, 7);
    // Check that the constant length array field [tau_desired_g] has the right length
    if (obj.tau_desired_g.length !== 7) {
      throw new Error('Unable to serialize array field tau_desired_g - length must be 7')
    }
    // Serialize message field [tau_desired_g]
    bufferOffset = _arraySerializer.float64(obj.tau_desired_g, buffer, bufferOffset, 7);
    // Check that the constant length array field [tau_desired_full] has the right length
    if (obj.tau_desired_full.length !== 7) {
      throw new Error('Unable to serialize array field tau_desired_full - length must be 7')
    }
    // Serialize message field [tau_desired_full]
    bufferOffset = _arraySerializer.float64(obj.tau_desired_full, buffer, bufferOffset, 7);
    // Check that the constant length array field [tau_measured] has the right length
    if (obj.tau_measured.length !== 7) {
      throw new Error('Unable to serialize array field tau_measured - length must be 7')
    }
    // Serialize message field [tau_measured]
    bufferOffset = _arraySerializer.float64(obj.tau_measured, buffer, bufferOffset, 7);
    return bufferOffset;
  }

  static deserialize(buffer, bufferOffset=[0]) {
    //deserializes a message object of type JointStates
    let len;
    let data = new JointStates(null);
    // Deserialize message field [time]
    data.time = _deserializer.float64(buffer, bufferOffset);
    // Deserialize message field [xe_r]
    data.xe_r = geometry_msgs.msg.Pose.deserialize(buffer, bufferOffset);
    // Deserialize message field [xe_v]
    data.xe_v = geometry_msgs.msg.Pose.deserialize(buffer, bufferOffset);
    // Deserialize message field [xe]
    data.xe = geometry_msgs.msg.Pose.deserialize(buffer, bufferOffset);
    // Deserialize message field [q_r]
    data.q_r = _arrayDeserializer.float64(buffer, bufferOffset, 7)
    // Deserialize message field [q_v]
    data.q_v = _arrayDeserializer.float64(buffer, bufferOffset, 7)
    // Deserialize message field [q]
    data.q = _arrayDeserializer.float64(buffer, bufferOffset, 7)
    // Deserialize message field [dotq]
    data.dotq = _arrayDeserializer.float64(buffer, bufferOffset, 7)
    // Deserialize message field [tau_commanded]
    data.tau_commanded = _arrayDeserializer.float64(buffer, bufferOffset, 7)
    // Deserialize message field [tau_desired_g]
    data.tau_desired_g = _arrayDeserializer.float64(buffer, bufferOffset, 7)
    // Deserialize message field [tau_desired_full]
    data.tau_desired_full = _arrayDeserializer.float64(buffer, bufferOffset, 7)
    // Deserialize message field [tau_measured]
    data.tau_measured = _arrayDeserializer.float64(buffer, bufferOffset, 7)
    return data;
  }

  static getMessageSize(object) {
    return 624;
  }

  static datatype() {
    // Returns string type for a message object
    return 'franka_planner_control/JointStates';
  }

  static md5sum() {
    //Returns md5sum for a message object
    return '3c8f4ba03149d875ee8618cf39cc73dc';
  }

  static messageDefinition() {
    // Returns full string definition for message
    return `
    float64 time
    geometry_msgs/Pose xe_r
    geometry_msgs/Pose xe_v
    geometry_msgs/Pose xe
    float64[7] q_r
    float64[7] q_v
    float64[7] q
    float64[7] dotq
    float64[7] tau_commanded
    float64[7] tau_desired_g
    float64[7] tau_desired_full
    float64[7] tau_measured
    ================================================================================
    MSG: geometry_msgs/Pose
    # A representation of pose in free space, composed of position and orientation. 
    Point position
    Quaternion orientation
    
    ================================================================================
    MSG: geometry_msgs/Point
    # This contains the position of a point in free space
    float64 x
    float64 y
    float64 z
    
    ================================================================================
    MSG: geometry_msgs/Quaternion
    # This represents an orientation in free space in quaternion form.
    
    float64 x
    float64 y
    float64 z
    float64 w
    
    `;
  }

  static Resolve(msg) {
    // deep-construct a valid message object instance of whatever was passed in
    if (typeof msg !== 'object' || msg === null) {
      msg = {};
    }
    const resolved = new JointStates(null);
    if (msg.time !== undefined) {
      resolved.time = msg.time;
    }
    else {
      resolved.time = 0.0
    }

    if (msg.xe_r !== undefined) {
      resolved.xe_r = geometry_msgs.msg.Pose.Resolve(msg.xe_r)
    }
    else {
      resolved.xe_r = new geometry_msgs.msg.Pose()
    }

    if (msg.xe_v !== undefined) {
      resolved.xe_v = geometry_msgs.msg.Pose.Resolve(msg.xe_v)
    }
    else {
      resolved.xe_v = new geometry_msgs.msg.Pose()
    }

    if (msg.xe !== undefined) {
      resolved.xe = geometry_msgs.msg.Pose.Resolve(msg.xe)
    }
    else {
      resolved.xe = new geometry_msgs.msg.Pose()
    }

    if (msg.q_r !== undefined) {
      resolved.q_r = msg.q_r;
    }
    else {
      resolved.q_r = new Array(7).fill(0)
    }

    if (msg.q_v !== undefined) {
      resolved.q_v = msg.q_v;
    }
    else {
      resolved.q_v = new Array(7).fill(0)
    }

    if (msg.q !== undefined) {
      resolved.q = msg.q;
    }
    else {
      resolved.q = new Array(7).fill(0)
    }

    if (msg.dotq !== undefined) {
      resolved.dotq = msg.dotq;
    }
    else {
      resolved.dotq = new Array(7).fill(0)
    }

    if (msg.tau_commanded !== undefined) {
      resolved.tau_commanded = msg.tau_commanded;
    }
    else {
      resolved.tau_commanded = new Array(7).fill(0)
    }

    if (msg.tau_desired_g !== undefined) {
      resolved.tau_desired_g = msg.tau_desired_g;
    }
    else {
      resolved.tau_desired_g = new Array(7).fill(0)
    }

    if (msg.tau_desired_full !== undefined) {
      resolved.tau_desired_full = msg.tau_desired_full;
    }
    else {
      resolved.tau_desired_full = new Array(7).fill(0)
    }

    if (msg.tau_measured !== undefined) {
      resolved.tau_measured = msg.tau_measured;
    }
    else {
      resolved.tau_measured = new Array(7).fill(0)
    }

    return resolved;
    }
};

module.exports = JointStates;
