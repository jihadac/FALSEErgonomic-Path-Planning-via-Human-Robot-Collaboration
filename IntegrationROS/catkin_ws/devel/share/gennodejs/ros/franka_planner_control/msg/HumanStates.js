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

class HumanStates {
  constructor(initObj={}) {
    if (initObj === null) {
      // initObj === null is a special case for deserialization where we don't initialize fields
      this.time = null;
      this.lowerarm_startpoint = null;
      this.lowerarm_endpoint = null;
      this.lowerarm_center = null;
      this.quat_lowerarm2robot = null;
      this.upperarm_startpoint = null;
      this.upperarm_endpoint = null;
      this.upperarm_center = null;
      this.quat_upperarm2robot = null;
      this.head_center = null;
      this.quat_head2robot = null;
    }
    else {
      if (initObj.hasOwnProperty('time')) {
        this.time = initObj.time
      }
      else {
        this.time = 0.0;
      }
      if (initObj.hasOwnProperty('lowerarm_startpoint')) {
        this.lowerarm_startpoint = initObj.lowerarm_startpoint
      }
      else {
        this.lowerarm_startpoint = new geometry_msgs.msg.Point();
      }
      if (initObj.hasOwnProperty('lowerarm_endpoint')) {
        this.lowerarm_endpoint = initObj.lowerarm_endpoint
      }
      else {
        this.lowerarm_endpoint = new geometry_msgs.msg.Point();
      }
      if (initObj.hasOwnProperty('lowerarm_center')) {
        this.lowerarm_center = initObj.lowerarm_center
      }
      else {
        this.lowerarm_center = new geometry_msgs.msg.Point();
      }
      if (initObj.hasOwnProperty('quat_lowerarm2robot')) {
        this.quat_lowerarm2robot = initObj.quat_lowerarm2robot
      }
      else {
        this.quat_lowerarm2robot = new geometry_msgs.msg.Quaternion();
      }
      if (initObj.hasOwnProperty('upperarm_startpoint')) {
        this.upperarm_startpoint = initObj.upperarm_startpoint
      }
      else {
        this.upperarm_startpoint = new geometry_msgs.msg.Point();
      }
      if (initObj.hasOwnProperty('upperarm_endpoint')) {
        this.upperarm_endpoint = initObj.upperarm_endpoint
      }
      else {
        this.upperarm_endpoint = new geometry_msgs.msg.Point();
      }
      if (initObj.hasOwnProperty('upperarm_center')) {
        this.upperarm_center = initObj.upperarm_center
      }
      else {
        this.upperarm_center = new geometry_msgs.msg.Point();
      }
      if (initObj.hasOwnProperty('quat_upperarm2robot')) {
        this.quat_upperarm2robot = initObj.quat_upperarm2robot
      }
      else {
        this.quat_upperarm2robot = new geometry_msgs.msg.Quaternion();
      }
      if (initObj.hasOwnProperty('head_center')) {
        this.head_center = initObj.head_center
      }
      else {
        this.head_center = new geometry_msgs.msg.Point();
      }
      if (initObj.hasOwnProperty('quat_head2robot')) {
        this.quat_head2robot = initObj.quat_head2robot
      }
      else {
        this.quat_head2robot = new geometry_msgs.msg.Quaternion();
      }
    }
  }

  static serialize(obj, buffer, bufferOffset) {
    // Serializes a message object of type HumanStates
    // Serialize message field [time]
    bufferOffset = _serializer.float64(obj.time, buffer, bufferOffset);
    // Serialize message field [lowerarm_startpoint]
    bufferOffset = geometry_msgs.msg.Point.serialize(obj.lowerarm_startpoint, buffer, bufferOffset);
    // Serialize message field [lowerarm_endpoint]
    bufferOffset = geometry_msgs.msg.Point.serialize(obj.lowerarm_endpoint, buffer, bufferOffset);
    // Serialize message field [lowerarm_center]
    bufferOffset = geometry_msgs.msg.Point.serialize(obj.lowerarm_center, buffer, bufferOffset);
    // Serialize message field [quat_lowerarm2robot]
    bufferOffset = geometry_msgs.msg.Quaternion.serialize(obj.quat_lowerarm2robot, buffer, bufferOffset);
    // Serialize message field [upperarm_startpoint]
    bufferOffset = geometry_msgs.msg.Point.serialize(obj.upperarm_startpoint, buffer, bufferOffset);
    // Serialize message field [upperarm_endpoint]
    bufferOffset = geometry_msgs.msg.Point.serialize(obj.upperarm_endpoint, buffer, bufferOffset);
    // Serialize message field [upperarm_center]
    bufferOffset = geometry_msgs.msg.Point.serialize(obj.upperarm_center, buffer, bufferOffset);
    // Serialize message field [quat_upperarm2robot]
    bufferOffset = geometry_msgs.msg.Quaternion.serialize(obj.quat_upperarm2robot, buffer, bufferOffset);
    // Serialize message field [head_center]
    bufferOffset = geometry_msgs.msg.Point.serialize(obj.head_center, buffer, bufferOffset);
    // Serialize message field [quat_head2robot]
    bufferOffset = geometry_msgs.msg.Quaternion.serialize(obj.quat_head2robot, buffer, bufferOffset);
    return bufferOffset;
  }

  static deserialize(buffer, bufferOffset=[0]) {
    //deserializes a message object of type HumanStates
    let len;
    let data = new HumanStates(null);
    // Deserialize message field [time]
    data.time = _deserializer.float64(buffer, bufferOffset);
    // Deserialize message field [lowerarm_startpoint]
    data.lowerarm_startpoint = geometry_msgs.msg.Point.deserialize(buffer, bufferOffset);
    // Deserialize message field [lowerarm_endpoint]
    data.lowerarm_endpoint = geometry_msgs.msg.Point.deserialize(buffer, bufferOffset);
    // Deserialize message field [lowerarm_center]
    data.lowerarm_center = geometry_msgs.msg.Point.deserialize(buffer, bufferOffset);
    // Deserialize message field [quat_lowerarm2robot]
    data.quat_lowerarm2robot = geometry_msgs.msg.Quaternion.deserialize(buffer, bufferOffset);
    // Deserialize message field [upperarm_startpoint]
    data.upperarm_startpoint = geometry_msgs.msg.Point.deserialize(buffer, bufferOffset);
    // Deserialize message field [upperarm_endpoint]
    data.upperarm_endpoint = geometry_msgs.msg.Point.deserialize(buffer, bufferOffset);
    // Deserialize message field [upperarm_center]
    data.upperarm_center = geometry_msgs.msg.Point.deserialize(buffer, bufferOffset);
    // Deserialize message field [quat_upperarm2robot]
    data.quat_upperarm2robot = geometry_msgs.msg.Quaternion.deserialize(buffer, bufferOffset);
    // Deserialize message field [head_center]
    data.head_center = geometry_msgs.msg.Point.deserialize(buffer, bufferOffset);
    // Deserialize message field [quat_head2robot]
    data.quat_head2robot = geometry_msgs.msg.Quaternion.deserialize(buffer, bufferOffset);
    return data;
  }

  static getMessageSize(object) {
    return 272;
  }

  static datatype() {
    // Returns string type for a message object
    return 'franka_planner_control/HumanStates';
  }

  static md5sum() {
    //Returns md5sum for a message object
    return 'ad7042df2f9df072f398637da6be578c';
  }

  static messageDefinition() {
    // Returns full string definition for message
    return `
    float64 time
    geometry_msgs/Point lowerarm_startpoint
    geometry_msgs/Point lowerarm_endpoint
    geometry_msgs/Point lowerarm_center
    geometry_msgs/Quaternion quat_lowerarm2robot
    geometry_msgs/Point upperarm_startpoint
    geometry_msgs/Point upperarm_endpoint
    geometry_msgs/Point upperarm_center
    geometry_msgs/Quaternion quat_upperarm2robot
    geometry_msgs/Point head_center
    geometry_msgs/Quaternion quat_head2robot
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
    const resolved = new HumanStates(null);
    if (msg.time !== undefined) {
      resolved.time = msg.time;
    }
    else {
      resolved.time = 0.0
    }

    if (msg.lowerarm_startpoint !== undefined) {
      resolved.lowerarm_startpoint = geometry_msgs.msg.Point.Resolve(msg.lowerarm_startpoint)
    }
    else {
      resolved.lowerarm_startpoint = new geometry_msgs.msg.Point()
    }

    if (msg.lowerarm_endpoint !== undefined) {
      resolved.lowerarm_endpoint = geometry_msgs.msg.Point.Resolve(msg.lowerarm_endpoint)
    }
    else {
      resolved.lowerarm_endpoint = new geometry_msgs.msg.Point()
    }

    if (msg.lowerarm_center !== undefined) {
      resolved.lowerarm_center = geometry_msgs.msg.Point.Resolve(msg.lowerarm_center)
    }
    else {
      resolved.lowerarm_center = new geometry_msgs.msg.Point()
    }

    if (msg.quat_lowerarm2robot !== undefined) {
      resolved.quat_lowerarm2robot = geometry_msgs.msg.Quaternion.Resolve(msg.quat_lowerarm2robot)
    }
    else {
      resolved.quat_lowerarm2robot = new geometry_msgs.msg.Quaternion()
    }

    if (msg.upperarm_startpoint !== undefined) {
      resolved.upperarm_startpoint = geometry_msgs.msg.Point.Resolve(msg.upperarm_startpoint)
    }
    else {
      resolved.upperarm_startpoint = new geometry_msgs.msg.Point()
    }

    if (msg.upperarm_endpoint !== undefined) {
      resolved.upperarm_endpoint = geometry_msgs.msg.Point.Resolve(msg.upperarm_endpoint)
    }
    else {
      resolved.upperarm_endpoint = new geometry_msgs.msg.Point()
    }

    if (msg.upperarm_center !== undefined) {
      resolved.upperarm_center = geometry_msgs.msg.Point.Resolve(msg.upperarm_center)
    }
    else {
      resolved.upperarm_center = new geometry_msgs.msg.Point()
    }

    if (msg.quat_upperarm2robot !== undefined) {
      resolved.quat_upperarm2robot = geometry_msgs.msg.Quaternion.Resolve(msg.quat_upperarm2robot)
    }
    else {
      resolved.quat_upperarm2robot = new geometry_msgs.msg.Quaternion()
    }

    if (msg.head_center !== undefined) {
      resolved.head_center = geometry_msgs.msg.Point.Resolve(msg.head_center)
    }
    else {
      resolved.head_center = new geometry_msgs.msg.Point()
    }

    if (msg.quat_head2robot !== undefined) {
      resolved.quat_head2robot = geometry_msgs.msg.Quaternion.Resolve(msg.quat_head2robot)
    }
    else {
      resolved.quat_head2robot = new geometry_msgs.msg.Quaternion()
    }

    return resolved;
    }
};

module.exports = HumanStates;
