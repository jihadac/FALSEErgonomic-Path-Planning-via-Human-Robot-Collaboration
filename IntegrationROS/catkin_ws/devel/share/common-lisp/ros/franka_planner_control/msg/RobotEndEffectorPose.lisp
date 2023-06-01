; Auto-generated. Do not edit!


(cl:in-package franka_planner_control-msg)


;//! \htmlinclude RobotEndEffectorPose.msg.html

(cl:defclass <RobotEndEffectorPose> (roslisp-msg-protocol:ros-message)
  ((rviz_orientation_problem
    :reader rviz_orientation_problem
    :initarg :rviz_orientation_problem
    :type cl:boolean
    :initform cl:nil)
   (xe_r
    :reader xe_r
    :initarg :xe_r
    :type geometry_msgs-msg:Pose
    :initform (cl:make-instance 'geometry_msgs-msg:Pose)))
)

(cl:defclass RobotEndEffectorPose (<RobotEndEffectorPose>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <RobotEndEffectorPose>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'RobotEndEffectorPose)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name franka_planner_control-msg:<RobotEndEffectorPose> is deprecated: use franka_planner_control-msg:RobotEndEffectorPose instead.")))

(cl:ensure-generic-function 'rviz_orientation_problem-val :lambda-list '(m))
(cl:defmethod rviz_orientation_problem-val ((m <RobotEndEffectorPose>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader franka_planner_control-msg:rviz_orientation_problem-val is deprecated.  Use franka_planner_control-msg:rviz_orientation_problem instead.")
  (rviz_orientation_problem m))

(cl:ensure-generic-function 'xe_r-val :lambda-list '(m))
(cl:defmethod xe_r-val ((m <RobotEndEffectorPose>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader franka_planner_control-msg:xe_r-val is deprecated.  Use franka_planner_control-msg:xe_r instead.")
  (xe_r m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <RobotEndEffectorPose>) ostream)
  "Serializes a message object of type '<RobotEndEffectorPose>"
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:if (cl:slot-value msg 'rviz_orientation_problem) 1 0)) ostream)
  (roslisp-msg-protocol:serialize (cl:slot-value msg 'xe_r) ostream)
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <RobotEndEffectorPose>) istream)
  "Deserializes a message object of type '<RobotEndEffectorPose>"
    (cl:setf (cl:slot-value msg 'rviz_orientation_problem) (cl:not (cl:zerop (cl:read-byte istream))))
  (roslisp-msg-protocol:deserialize (cl:slot-value msg 'xe_r) istream)
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<RobotEndEffectorPose>)))
  "Returns string type for a message object of type '<RobotEndEffectorPose>"
  "franka_planner_control/RobotEndEffectorPose")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'RobotEndEffectorPose)))
  "Returns string type for a message object of type 'RobotEndEffectorPose"
  "franka_planner_control/RobotEndEffectorPose")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<RobotEndEffectorPose>)))
  "Returns md5sum for a message object of type '<RobotEndEffectorPose>"
  "08713e20671c442197b0728d63307e52")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'RobotEndEffectorPose)))
  "Returns md5sum for a message object of type 'RobotEndEffectorPose"
  "08713e20671c442197b0728d63307e52")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<RobotEndEffectorPose>)))
  "Returns full string definition for message of type '<RobotEndEffectorPose>"
  (cl:format cl:nil "bool rviz_orientation_problem~%geometry_msgs/Pose xe_r~%~%================================================================================~%MSG: geometry_msgs/Pose~%# A representation of pose in free space, composed of position and orientation. ~%Point position~%Quaternion orientation~%~%================================================================================~%MSG: geometry_msgs/Point~%# This contains the position of a point in free space~%float64 x~%float64 y~%float64 z~%~%================================================================================~%MSG: geometry_msgs/Quaternion~%# This represents an orientation in free space in quaternion form.~%~%float64 x~%float64 y~%float64 z~%float64 w~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'RobotEndEffectorPose)))
  "Returns full string definition for message of type 'RobotEndEffectorPose"
  (cl:format cl:nil "bool rviz_orientation_problem~%geometry_msgs/Pose xe_r~%~%================================================================================~%MSG: geometry_msgs/Pose~%# A representation of pose in free space, composed of position and orientation. ~%Point position~%Quaternion orientation~%~%================================================================================~%MSG: geometry_msgs/Point~%# This contains the position of a point in free space~%float64 x~%float64 y~%float64 z~%~%================================================================================~%MSG: geometry_msgs/Quaternion~%# This represents an orientation in free space in quaternion form.~%~%float64 x~%float64 y~%float64 z~%float64 w~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <RobotEndEffectorPose>))
  (cl:+ 0
     1
     (roslisp-msg-protocol:serialization-length (cl:slot-value msg 'xe_r))
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <RobotEndEffectorPose>))
  "Converts a ROS message object to a list"
  (cl:list 'RobotEndEffectorPose
    (cl:cons ':rviz_orientation_problem (rviz_orientation_problem msg))
    (cl:cons ':xe_r (xe_r msg))
))
