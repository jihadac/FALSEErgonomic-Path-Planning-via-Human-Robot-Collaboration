; Auto-generated. Do not edit!


(cl:in-package franka_planner_control-msg)


;//! \htmlinclude HumanStates.msg.html

(cl:defclass <HumanStates> (roslisp-msg-protocol:ros-message)
  ((time
    :reader time
    :initarg :time
    :type cl:float
    :initform 0.0)
   (lowerarm_startpoint
    :reader lowerarm_startpoint
    :initarg :lowerarm_startpoint
    :type geometry_msgs-msg:Point
    :initform (cl:make-instance 'geometry_msgs-msg:Point))
   (lowerarm_endpoint
    :reader lowerarm_endpoint
    :initarg :lowerarm_endpoint
    :type geometry_msgs-msg:Point
    :initform (cl:make-instance 'geometry_msgs-msg:Point))
   (lowerarm_center
    :reader lowerarm_center
    :initarg :lowerarm_center
    :type geometry_msgs-msg:Point
    :initform (cl:make-instance 'geometry_msgs-msg:Point))
   (quat_lowerarm2robot
    :reader quat_lowerarm2robot
    :initarg :quat_lowerarm2robot
    :type geometry_msgs-msg:Quaternion
    :initform (cl:make-instance 'geometry_msgs-msg:Quaternion))
   (upperarm_startpoint
    :reader upperarm_startpoint
    :initarg :upperarm_startpoint
    :type geometry_msgs-msg:Point
    :initform (cl:make-instance 'geometry_msgs-msg:Point))
   (upperarm_endpoint
    :reader upperarm_endpoint
    :initarg :upperarm_endpoint
    :type geometry_msgs-msg:Point
    :initform (cl:make-instance 'geometry_msgs-msg:Point))
   (upperarm_center
    :reader upperarm_center
    :initarg :upperarm_center
    :type geometry_msgs-msg:Point
    :initform (cl:make-instance 'geometry_msgs-msg:Point))
   (quat_upperarm2robot
    :reader quat_upperarm2robot
    :initarg :quat_upperarm2robot
    :type geometry_msgs-msg:Quaternion
    :initform (cl:make-instance 'geometry_msgs-msg:Quaternion))
   (head_center
    :reader head_center
    :initarg :head_center
    :type geometry_msgs-msg:Point
    :initform (cl:make-instance 'geometry_msgs-msg:Point))
   (quat_head2robot
    :reader quat_head2robot
    :initarg :quat_head2robot
    :type geometry_msgs-msg:Quaternion
    :initform (cl:make-instance 'geometry_msgs-msg:Quaternion)))
)

(cl:defclass HumanStates (<HumanStates>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <HumanStates>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'HumanStates)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name franka_planner_control-msg:<HumanStates> is deprecated: use franka_planner_control-msg:HumanStates instead.")))

(cl:ensure-generic-function 'time-val :lambda-list '(m))
(cl:defmethod time-val ((m <HumanStates>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader franka_planner_control-msg:time-val is deprecated.  Use franka_planner_control-msg:time instead.")
  (time m))

(cl:ensure-generic-function 'lowerarm_startpoint-val :lambda-list '(m))
(cl:defmethod lowerarm_startpoint-val ((m <HumanStates>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader franka_planner_control-msg:lowerarm_startpoint-val is deprecated.  Use franka_planner_control-msg:lowerarm_startpoint instead.")
  (lowerarm_startpoint m))

(cl:ensure-generic-function 'lowerarm_endpoint-val :lambda-list '(m))
(cl:defmethod lowerarm_endpoint-val ((m <HumanStates>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader franka_planner_control-msg:lowerarm_endpoint-val is deprecated.  Use franka_planner_control-msg:lowerarm_endpoint instead.")
  (lowerarm_endpoint m))

(cl:ensure-generic-function 'lowerarm_center-val :lambda-list '(m))
(cl:defmethod lowerarm_center-val ((m <HumanStates>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader franka_planner_control-msg:lowerarm_center-val is deprecated.  Use franka_planner_control-msg:lowerarm_center instead.")
  (lowerarm_center m))

(cl:ensure-generic-function 'quat_lowerarm2robot-val :lambda-list '(m))
(cl:defmethod quat_lowerarm2robot-val ((m <HumanStates>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader franka_planner_control-msg:quat_lowerarm2robot-val is deprecated.  Use franka_planner_control-msg:quat_lowerarm2robot instead.")
  (quat_lowerarm2robot m))

(cl:ensure-generic-function 'upperarm_startpoint-val :lambda-list '(m))
(cl:defmethod upperarm_startpoint-val ((m <HumanStates>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader franka_planner_control-msg:upperarm_startpoint-val is deprecated.  Use franka_planner_control-msg:upperarm_startpoint instead.")
  (upperarm_startpoint m))

(cl:ensure-generic-function 'upperarm_endpoint-val :lambda-list '(m))
(cl:defmethod upperarm_endpoint-val ((m <HumanStates>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader franka_planner_control-msg:upperarm_endpoint-val is deprecated.  Use franka_planner_control-msg:upperarm_endpoint instead.")
  (upperarm_endpoint m))

(cl:ensure-generic-function 'upperarm_center-val :lambda-list '(m))
(cl:defmethod upperarm_center-val ((m <HumanStates>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader franka_planner_control-msg:upperarm_center-val is deprecated.  Use franka_planner_control-msg:upperarm_center instead.")
  (upperarm_center m))

(cl:ensure-generic-function 'quat_upperarm2robot-val :lambda-list '(m))
(cl:defmethod quat_upperarm2robot-val ((m <HumanStates>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader franka_planner_control-msg:quat_upperarm2robot-val is deprecated.  Use franka_planner_control-msg:quat_upperarm2robot instead.")
  (quat_upperarm2robot m))

(cl:ensure-generic-function 'head_center-val :lambda-list '(m))
(cl:defmethod head_center-val ((m <HumanStates>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader franka_planner_control-msg:head_center-val is deprecated.  Use franka_planner_control-msg:head_center instead.")
  (head_center m))

(cl:ensure-generic-function 'quat_head2robot-val :lambda-list '(m))
(cl:defmethod quat_head2robot-val ((m <HumanStates>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader franka_planner_control-msg:quat_head2robot-val is deprecated.  Use franka_planner_control-msg:quat_head2robot instead.")
  (quat_head2robot m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <HumanStates>) ostream)
  "Serializes a message object of type '<HumanStates>"
  (cl:let ((bits (roslisp-utils:encode-double-float-bits (cl:slot-value msg 'time))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 32) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 40) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 48) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 56) bits) ostream))
  (roslisp-msg-protocol:serialize (cl:slot-value msg 'lowerarm_startpoint) ostream)
  (roslisp-msg-protocol:serialize (cl:slot-value msg 'lowerarm_endpoint) ostream)
  (roslisp-msg-protocol:serialize (cl:slot-value msg 'lowerarm_center) ostream)
  (roslisp-msg-protocol:serialize (cl:slot-value msg 'quat_lowerarm2robot) ostream)
  (roslisp-msg-protocol:serialize (cl:slot-value msg 'upperarm_startpoint) ostream)
  (roslisp-msg-protocol:serialize (cl:slot-value msg 'upperarm_endpoint) ostream)
  (roslisp-msg-protocol:serialize (cl:slot-value msg 'upperarm_center) ostream)
  (roslisp-msg-protocol:serialize (cl:slot-value msg 'quat_upperarm2robot) ostream)
  (roslisp-msg-protocol:serialize (cl:slot-value msg 'head_center) ostream)
  (roslisp-msg-protocol:serialize (cl:slot-value msg 'quat_head2robot) ostream)
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <HumanStates>) istream)
  "Deserializes a message object of type '<HumanStates>"
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 32) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 40) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 48) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 56) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'time) (roslisp-utils:decode-double-float-bits bits)))
  (roslisp-msg-protocol:deserialize (cl:slot-value msg 'lowerarm_startpoint) istream)
  (roslisp-msg-protocol:deserialize (cl:slot-value msg 'lowerarm_endpoint) istream)
  (roslisp-msg-protocol:deserialize (cl:slot-value msg 'lowerarm_center) istream)
  (roslisp-msg-protocol:deserialize (cl:slot-value msg 'quat_lowerarm2robot) istream)
  (roslisp-msg-protocol:deserialize (cl:slot-value msg 'upperarm_startpoint) istream)
  (roslisp-msg-protocol:deserialize (cl:slot-value msg 'upperarm_endpoint) istream)
  (roslisp-msg-protocol:deserialize (cl:slot-value msg 'upperarm_center) istream)
  (roslisp-msg-protocol:deserialize (cl:slot-value msg 'quat_upperarm2robot) istream)
  (roslisp-msg-protocol:deserialize (cl:slot-value msg 'head_center) istream)
  (roslisp-msg-protocol:deserialize (cl:slot-value msg 'quat_head2robot) istream)
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<HumanStates>)))
  "Returns string type for a message object of type '<HumanStates>"
  "franka_planner_control/HumanStates")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'HumanStates)))
  "Returns string type for a message object of type 'HumanStates"
  "franka_planner_control/HumanStates")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<HumanStates>)))
  "Returns md5sum for a message object of type '<HumanStates>"
  "ad7042df2f9df072f398637da6be578c")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'HumanStates)))
  "Returns md5sum for a message object of type 'HumanStates"
  "ad7042df2f9df072f398637da6be578c")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<HumanStates>)))
  "Returns full string definition for message of type '<HumanStates>"
  (cl:format cl:nil "float64 time~%geometry_msgs/Point lowerarm_startpoint~%geometry_msgs/Point lowerarm_endpoint~%geometry_msgs/Point lowerarm_center~%geometry_msgs/Quaternion quat_lowerarm2robot~%geometry_msgs/Point upperarm_startpoint~%geometry_msgs/Point upperarm_endpoint~%geometry_msgs/Point upperarm_center~%geometry_msgs/Quaternion quat_upperarm2robot~%geometry_msgs/Point head_center~%geometry_msgs/Quaternion quat_head2robot~%================================================================================~%MSG: geometry_msgs/Point~%# This contains the position of a point in free space~%float64 x~%float64 y~%float64 z~%~%================================================================================~%MSG: geometry_msgs/Quaternion~%# This represents an orientation in free space in quaternion form.~%~%float64 x~%float64 y~%float64 z~%float64 w~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'HumanStates)))
  "Returns full string definition for message of type 'HumanStates"
  (cl:format cl:nil "float64 time~%geometry_msgs/Point lowerarm_startpoint~%geometry_msgs/Point lowerarm_endpoint~%geometry_msgs/Point lowerarm_center~%geometry_msgs/Quaternion quat_lowerarm2robot~%geometry_msgs/Point upperarm_startpoint~%geometry_msgs/Point upperarm_endpoint~%geometry_msgs/Point upperarm_center~%geometry_msgs/Quaternion quat_upperarm2robot~%geometry_msgs/Point head_center~%geometry_msgs/Quaternion quat_head2robot~%================================================================================~%MSG: geometry_msgs/Point~%# This contains the position of a point in free space~%float64 x~%float64 y~%float64 z~%~%================================================================================~%MSG: geometry_msgs/Quaternion~%# This represents an orientation in free space in quaternion form.~%~%float64 x~%float64 y~%float64 z~%float64 w~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <HumanStates>))
  (cl:+ 0
     8
     (roslisp-msg-protocol:serialization-length (cl:slot-value msg 'lowerarm_startpoint))
     (roslisp-msg-protocol:serialization-length (cl:slot-value msg 'lowerarm_endpoint))
     (roslisp-msg-protocol:serialization-length (cl:slot-value msg 'lowerarm_center))
     (roslisp-msg-protocol:serialization-length (cl:slot-value msg 'quat_lowerarm2robot))
     (roslisp-msg-protocol:serialization-length (cl:slot-value msg 'upperarm_startpoint))
     (roslisp-msg-protocol:serialization-length (cl:slot-value msg 'upperarm_endpoint))
     (roslisp-msg-protocol:serialization-length (cl:slot-value msg 'upperarm_center))
     (roslisp-msg-protocol:serialization-length (cl:slot-value msg 'quat_upperarm2robot))
     (roslisp-msg-protocol:serialization-length (cl:slot-value msg 'head_center))
     (roslisp-msg-protocol:serialization-length (cl:slot-value msg 'quat_head2robot))
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <HumanStates>))
  "Converts a ROS message object to a list"
  (cl:list 'HumanStates
    (cl:cons ':time (time msg))
    (cl:cons ':lowerarm_startpoint (lowerarm_startpoint msg))
    (cl:cons ':lowerarm_endpoint (lowerarm_endpoint msg))
    (cl:cons ':lowerarm_center (lowerarm_center msg))
    (cl:cons ':quat_lowerarm2robot (quat_lowerarm2robot msg))
    (cl:cons ':upperarm_startpoint (upperarm_startpoint msg))
    (cl:cons ':upperarm_endpoint (upperarm_endpoint msg))
    (cl:cons ':upperarm_center (upperarm_center msg))
    (cl:cons ':quat_upperarm2robot (quat_upperarm2robot msg))
    (cl:cons ':head_center (head_center msg))
    (cl:cons ':quat_head2robot (quat_head2robot msg))
))
