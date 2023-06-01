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

class RobotEndEffectorPose {
  constructor(initObj={}) {
    if (initObj === null) {
      // initObj === null is a special case for deserialization where we don't initialize fields
      this.rviz_orientation_problem = null;
      this.xe_r = null;
    }
    else {
      if (initObj.hasOwnProperty('rviz_orientation_problem')) {
        this.rviz_orientation_problem = initObj.rviz_orientation_problem
      }
      else {
        this.rviz_orientation_problem = false;
      }
      if (initObj.hasOwnProperty('xe_r')) {
        this.xe_r = initObj.xe_r
      }
      else {
        this.xe_r = new geometry_msgs.msg.Pose();
      }
    }
  }

  static serialize(obj, buffer, bufferOffset) {
    // Serializes a message object of type RobotEndEffectorPose
    // Serialize message field [rviz_orientation_problem]
    bufferOffset = _serializer.bool(obj.rviz_orientation_problem, buffer, bufferOffset);
    // Serialize message field [xe_r]
    bufferOffset = geometry_msgs.msg.Pose.serialize(obj.xe_r, buffer, bufferOffset);
    return bufferOffset;
  }

  static deserialize(buffer, bufferOffset=[0]) {
    //deserializes a message object of type RobotEndEffectorPose
    let len;
    let data = new RobotEndEffectorPose(null);
    // Deserialize message field [rviz_orientation_problem]
    data.rviz_orientation_problem = _deserializer.bool(buffer, bufferOffset);
    // Deserialize message field [xe_r]
    data.xe_r = geometry_msgs.msg.Pose.deserialize(buffer, bufferOffset);
    return data;
  }

  static getMessageSize(object) {
    return 57;
  }

  static datatype() {
    // Returns string type for a message object
    return 'franka_planner_control/RobotEndEffectorPose';
  }

  static md5sum() {
    //Returns md5sum for a message object
    return '08713e20671c442197b0728d63307e52';
  }

  static messageDefinition() {
    // Returns full string definition for message
    return `
    bool rviz_orientation_problem
    geometry_msgs/Pose xe_r
    
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
    const resolved = new RobotEndEffectorPose(null);
    if (msg.rviz_orientation_problem !== undefined) {
      resolved.rviz_orientation_problem = msg.rviz_orientation_problem;
    }
    else {
      resolved.rviz_orientation_problem = false
    }

    if (msg.xe_r !== undefined) {
      resolved.xe_r = geometry_msgs.msg.Pose.Resolve(msg.xe_r)
    }
    else {
      resolved.xe_r = new geometry_msgs.msg.Pose()
    }

    return resolved;
    }
};

module.exports = RobotEndEffectorPose;
