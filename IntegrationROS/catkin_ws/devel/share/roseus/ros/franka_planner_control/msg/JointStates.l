;; Auto-generated. Do not edit!


(when (boundp 'franka_planner_control::JointStates)
  (if (not (find-package "FRANKA_PLANNER_CONTROL"))
    (make-package "FRANKA_PLANNER_CONTROL"))
  (shadow 'JointStates (find-package "FRANKA_PLANNER_CONTROL")))
(unless (find-package "FRANKA_PLANNER_CONTROL::JOINTSTATES")
  (make-package "FRANKA_PLANNER_CONTROL::JOINTSTATES"))

(in-package "ROS")
;;//! \htmlinclude JointStates.msg.html
(if (not (find-package "GEOMETRY_MSGS"))
  (ros::roseus-add-msgs "geometry_msgs"))


(defclass franka_planner_control::JointStates
  :super ros::object
  :slots (_time _xe_r _xe_v _xe _q_r _q_v _q _dotq _tau_commanded _tau_desired_g _tau_desired_full _tau_measured ))

(defmethod franka_planner_control::JointStates
  (:init
   (&key
    ((:time __time) 0.0)
    ((:xe_r __xe_r) (instance geometry_msgs::Pose :init))
    ((:xe_v __xe_v) (instance geometry_msgs::Pose :init))
    ((:xe __xe) (instance geometry_msgs::Pose :init))
    ((:q_r __q_r) (make-array 7 :initial-element 0.0 :element-type :float))
    ((:q_v __q_v) (make-array 7 :initial-element 0.0 :element-type :float))
    ((:q __q) (make-array 7 :initial-element 0.0 :element-type :float))
    ((:dotq __dotq) (make-array 7 :initial-element 0.0 :element-type :float))
    ((:tau_commanded __tau_commanded) (make-array 7 :initial-element 0.0 :element-type :float))
    ((:tau_desired_g __tau_desired_g) (make-array 7 :initial-element 0.0 :element-type :float))
    ((:tau_desired_full __tau_desired_full) (make-array 7 :initial-element 0.0 :element-type :float))
    ((:tau_measured __tau_measured) (make-array 7 :initial-element 0.0 :element-type :float))
    )
   (send-super :init)
   (setq _time (float __time))
   (setq _xe_r __xe_r)
   (setq _xe_v __xe_v)
   (setq _xe __xe)
   (setq _q_r __q_r)
   (setq _q_v __q_v)
   (setq _q __q)
   (setq _dotq __dotq)
   (setq _tau_commanded __tau_commanded)
   (setq _tau_desired_g __tau_desired_g)
   (setq _tau_desired_full __tau_desired_full)
   (setq _tau_measured __tau_measured)
   self)
  (:time
   (&optional __time)
   (if __time (setq _time __time)) _time)
  (:xe_r
   (&rest __xe_r)
   (if (keywordp (car __xe_r))
       (send* _xe_r __xe_r)
     (progn
       (if __xe_r (setq _xe_r (car __xe_r)))
       _xe_r)))
  (:xe_v
   (&rest __xe_v)
   (if (keywordp (car __xe_v))
       (send* _xe_v __xe_v)
     (progn
       (if __xe_v (setq _xe_v (car __xe_v)))
       _xe_v)))
  (:xe
   (&rest __xe)
   (if (keywordp (car __xe))
       (send* _xe __xe)
     (progn
       (if __xe (setq _xe (car __xe)))
       _xe)))
  (:q_r
   (&optional __q_r)
   (if __q_r (setq _q_r __q_r)) _q_r)
  (:q_v
   (&optional __q_v)
   (if __q_v (setq _q_v __q_v)) _q_v)
  (:q
   (&optional __q)
   (if __q (setq _q __q)) _q)
  (:dotq
   (&optional __dotq)
   (if __dotq (setq _dotq __dotq)) _dotq)
  (:tau_commanded
   (&optional __tau_commanded)
   (if __tau_commanded (setq _tau_commanded __tau_commanded)) _tau_commanded)
  (:tau_desired_g
   (&optional __tau_desired_g)
   (if __tau_desired_g (setq _tau_desired_g __tau_desired_g)) _tau_desired_g)
  (:tau_desired_full
   (&optional __tau_desired_full)
   (if __tau_desired_full (setq _tau_desired_full __tau_desired_full)) _tau_desired_full)
  (:tau_measured
   (&optional __tau_measured)
   (if __tau_measured (setq _tau_measured __tau_measured)) _tau_measured)
  (:serialization-length
   ()
   (+
    ;; float64 _time
    8
    ;; geometry_msgs/Pose _xe_r
    (send _xe_r :serialization-length)
    ;; geometry_msgs/Pose _xe_v
    (send _xe_v :serialization-length)
    ;; geometry_msgs/Pose _xe
    (send _xe :serialization-length)
    ;; float64[7] _q_r
    (* 8    7)
    ;; float64[7] _q_v
    (* 8    7)
    ;; float64[7] _q
    (* 8    7)
    ;; float64[7] _dotq
    (* 8    7)
    ;; float64[7] _tau_commanded
    (* 8    7)
    ;; float64[7] _tau_desired_g
    (* 8    7)
    ;; float64[7] _tau_desired_full
    (* 8    7)
    ;; float64[7] _tau_measured
    (* 8    7)
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; float64 _time
       (sys::poke _time (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;; geometry_msgs/Pose _xe_r
       (send _xe_r :serialize s)
     ;; geometry_msgs/Pose _xe_v
       (send _xe_v :serialize s)
     ;; geometry_msgs/Pose _xe
       (send _xe :serialize s)
     ;; float64[7] _q_r
     (dotimes (i 7)
       (sys::poke (elt _q_r i) (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
       )
     ;; float64[7] _q_v
     (dotimes (i 7)
       (sys::poke (elt _q_v i) (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
       )
     ;; float64[7] _q
     (dotimes (i 7)
       (sys::poke (elt _q i) (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
       )
     ;; float64[7] _dotq
     (dotimes (i 7)
       (sys::poke (elt _dotq i) (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
       )
     ;; float64[7] _tau_commanded
     (dotimes (i 7)
       (sys::poke (elt _tau_commanded i) (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
       )
     ;; float64[7] _tau_desired_g
     (dotimes (i 7)
       (sys::poke (elt _tau_desired_g i) (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
       )
     ;; float64[7] _tau_desired_full
     (dotimes (i 7)
       (sys::poke (elt _tau_desired_full i) (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
       )
     ;; float64[7] _tau_measured
     (dotimes (i 7)
       (sys::poke (elt _tau_measured i) (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
       )
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; float64 _time
     (setq _time (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; geometry_msgs/Pose _xe_r
     (send _xe_r :deserialize buf ptr-) (incf ptr- (send _xe_r :serialization-length))
   ;; geometry_msgs/Pose _xe_v
     (send _xe_v :deserialize buf ptr-) (incf ptr- (send _xe_v :serialization-length))
   ;; geometry_msgs/Pose _xe
     (send _xe :deserialize buf ptr-) (incf ptr- (send _xe :serialization-length))
   ;; float64[7] _q_r
   (dotimes (i (length _q_r))
     (setf (elt _q_r i) (sys::peek buf ptr- :double)) (incf ptr- 8)
     )
   ;; float64[7] _q_v
   (dotimes (i (length _q_v))
     (setf (elt _q_v i) (sys::peek buf ptr- :double)) (incf ptr- 8)
     )
   ;; float64[7] _q
   (dotimes (i (length _q))
     (setf (elt _q i) (sys::peek buf ptr- :double)) (incf ptr- 8)
     )
   ;; float64[7] _dotq
   (dotimes (i (length _dotq))
     (setf (elt _dotq i) (sys::peek buf ptr- :double)) (incf ptr- 8)
     )
   ;; float64[7] _tau_commanded
   (dotimes (i (length _tau_commanded))
     (setf (elt _tau_commanded i) (sys::peek buf ptr- :double)) (incf ptr- 8)
     )
   ;; float64[7] _tau_desired_g
   (dotimes (i (length _tau_desired_g))
     (setf (elt _tau_desired_g i) (sys::peek buf ptr- :double)) (incf ptr- 8)
     )
   ;; float64[7] _tau_desired_full
   (dotimes (i (length _tau_desired_full))
     (setf (elt _tau_desired_full i) (sys::peek buf ptr- :double)) (incf ptr- 8)
     )
   ;; float64[7] _tau_measured
   (dotimes (i (length _tau_measured))
     (setf (elt _tau_measured i) (sys::peek buf ptr- :double)) (incf ptr- 8)
     )
   ;;
   self)
  )

(setf (get franka_planner_control::JointStates :md5sum-) "3c8f4ba03149d875ee8618cf39cc73dc")
(setf (get franka_planner_control::JointStates :datatype-) "franka_planner_control/JointStates")
(setf (get franka_planner_control::JointStates :definition-)
      "float64 time
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

")



(provide :franka_planner_control/JointStates "3c8f4ba03149d875ee8618cf39cc73dc")


