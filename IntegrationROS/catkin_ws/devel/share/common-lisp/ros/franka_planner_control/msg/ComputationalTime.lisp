; Auto-generated. Do not edit!


(cl:in-package franka_planner_control-msg)


;//! \htmlinclude ComputationalTime.msg.html

(cl:defclass <ComputationalTime> (roslisp-msg-protocol:ros-message)
  ((time
    :reader time
    :initarg :time
    :type cl:float
    :initform 0.0)
   (NF
    :reader NF
    :initarg :NF
    :type cl:float
    :initform 0.0)
   (DSM
    :reader DSM
    :initarg :DSM
    :type cl:float
    :initform 0.0)
   (trajectory_predictions
    :reader trajectory_predictions
    :initarg :trajectory_predictions
    :type cl:float
    :initform 0.0)
   (ERG
    :reader ERG
    :initarg :ERG
    :type cl:float
    :initform 0.0))
)

(cl:defclass ComputationalTime (<ComputationalTime>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <ComputationalTime>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'ComputationalTime)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name franka_planner_control-msg:<ComputationalTime> is deprecated: use franka_planner_control-msg:ComputationalTime instead.")))

(cl:ensure-generic-function 'time-val :lambda-list '(m))
(cl:defmethod time-val ((m <ComputationalTime>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader franka_planner_control-msg:time-val is deprecated.  Use franka_planner_control-msg:time instead.")
  (time m))

(cl:ensure-generic-function 'NF-val :lambda-list '(m))
(cl:defmethod NF-val ((m <ComputationalTime>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader franka_planner_control-msg:NF-val is deprecated.  Use franka_planner_control-msg:NF instead.")
  (NF m))

(cl:ensure-generic-function 'DSM-val :lambda-list '(m))
(cl:defmethod DSM-val ((m <ComputationalTime>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader franka_planner_control-msg:DSM-val is deprecated.  Use franka_planner_control-msg:DSM instead.")
  (DSM m))

(cl:ensure-generic-function 'trajectory_predictions-val :lambda-list '(m))
(cl:defmethod trajectory_predictions-val ((m <ComputationalTime>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader franka_planner_control-msg:trajectory_predictions-val is deprecated.  Use franka_planner_control-msg:trajectory_predictions instead.")
  (trajectory_predictions m))

(cl:ensure-generic-function 'ERG-val :lambda-list '(m))
(cl:defmethod ERG-val ((m <ComputationalTime>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader franka_planner_control-msg:ERG-val is deprecated.  Use franka_planner_control-msg:ERG instead.")
  (ERG m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <ComputationalTime>) ostream)
  "Serializes a message object of type '<ComputationalTime>"
  (cl:let ((bits (roslisp-utils:encode-double-float-bits (cl:slot-value msg 'time))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 32) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 40) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 48) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 56) bits) ostream))
  (cl:let ((bits (roslisp-utils:encode-double-float-bits (cl:slot-value msg 'NF))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 32) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 40) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 48) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 56) bits) ostream))
  (cl:let ((bits (roslisp-utils:encode-double-float-bits (cl:slot-value msg 'DSM))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 32) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 40) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 48) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 56) bits) ostream))
  (cl:let ((bits (roslisp-utils:encode-double-float-bits (cl:slot-value msg 'trajectory_predictions))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 32) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 40) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 48) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 56) bits) ostream))
  (cl:let ((bits (roslisp-utils:encode-double-float-bits (cl:slot-value msg 'ERG))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 32) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 40) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 48) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 56) bits) ostream))
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <ComputationalTime>) istream)
  "Deserializes a message object of type '<ComputationalTime>"
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
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 32) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 40) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 48) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 56) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'NF) (roslisp-utils:decode-double-float-bits bits)))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 32) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 40) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 48) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 56) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'DSM) (roslisp-utils:decode-double-float-bits bits)))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 32) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 40) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 48) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 56) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'trajectory_predictions) (roslisp-utils:decode-double-float-bits bits)))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 32) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 40) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 48) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 56) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'ERG) (roslisp-utils:decode-double-float-bits bits)))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<ComputationalTime>)))
  "Returns string type for a message object of type '<ComputationalTime>"
  "franka_planner_control/ComputationalTime")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'ComputationalTime)))
  "Returns string type for a message object of type 'ComputationalTime"
  "franka_planner_control/ComputationalTime")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<ComputationalTime>)))
  "Returns md5sum for a message object of type '<ComputationalTime>"
  "88eb9a619c00c3079c22019ebb22fa32")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'ComputationalTime)))
  "Returns md5sum for a message object of type 'ComputationalTime"
  "88eb9a619c00c3079c22019ebb22fa32")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<ComputationalTime>)))
  "Returns full string definition for message of type '<ComputationalTime>"
  (cl:format cl:nil "float64 time~%float64 NF~%float64 DSM~%float64 trajectory_predictions~%float64 ERG~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'ComputationalTime)))
  "Returns full string definition for message of type 'ComputationalTime"
  (cl:format cl:nil "float64 time~%float64 NF~%float64 DSM~%float64 trajectory_predictions~%float64 ERG~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <ComputationalTime>))
  (cl:+ 0
     8
     8
     8
     8
     8
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <ComputationalTime>))
  "Converts a ROS message object to a list"
  (cl:list 'ComputationalTime
    (cl:cons ':time (time msg))
    (cl:cons ':NF (NF msg))
    (cl:cons ':DSM (DSM msg))
    (cl:cons ':trajectory_predictions (trajectory_predictions msg))
    (cl:cons ':ERG (ERG msg))
))
