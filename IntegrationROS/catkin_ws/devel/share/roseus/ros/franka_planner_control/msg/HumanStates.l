;; Auto-generated. Do not edit!


(when (boundp 'franka_planner_control::HumanStates)
  (if (not (find-package "FRANKA_PLANNER_CONTROL"))
    (make-package "FRANKA_PLANNER_CONTROL"))
  (shadow 'HumanStates (find-package "FRANKA_PLANNER_CONTROL")))
(unless (find-package "FRANKA_PLANNER_CONTROL::HUMANSTATES")
  (make-package "FRANKA_PLANNER_CONTROL::HUMANSTATES"))

(in-package "ROS")
;;//! \htmlinclude HumanStates.msg.html
(if (not (find-package "GEOMETRY_MSGS"))
  (ros::roseus-add-msgs "geometry_msgs"))


(defclass franka_planner_control::HumanStates
  :super ros::object
  :slots (_time _lowerarm_startpoint _lowerarm_endpoint _lowerarm_center _quat_lowerarm2robot _upperarm_startpoint _upperarm_endpoint _upperarm_center _quat_upperarm2robot _head_center _quat_head2robot ))

(defmethod franka_planner_control::HumanStates
  (:init
   (&key
    ((:time __time) 0.0)
    ((:lowerarm_startpoint __lowerarm_startpoint) (instance geometry_msgs::Point :init))
    ((:lowerarm_endpoint __lowerarm_endpoint) (instance geometry_msgs::Point :init))
    ((:lowerarm_center __lowerarm_center) (instance geometry_msgs::Point :init))
    ((:quat_lowerarm2robot __quat_lowerarm2robot) (instance geometry_msgs::Quaternion :init))
    ((:upperarm_startpoint __upperarm_startpoint) (instance geometry_msgs::Point :init))
    ((:upperarm_endpoint __upperarm_endpoint) (instance geometry_msgs::Point :init))
    ((:upperarm_center __upperarm_center) (instance geometry_msgs::Point :init))
    ((:quat_upperarm2robot __quat_upperarm2robot) (instance geometry_msgs::Quaternion :init))
    ((:head_center __head_center) (instance geometry_msgs::Point :init))
    ((:quat_head2robot __quat_head2robot) (instance geometry_msgs::Quaternion :init))
    )
   (send-super :init)
   (setq _time (float __time))
   (setq _lowerarm_startpoint __lowerarm_startpoint)
   (setq _lowerarm_endpoint __lowerarm_endpoint)
   (setq _lowerarm_center __lowerarm_center)
   (setq _quat_lowerarm2robot __quat_lowerarm2robot)
   (setq _upperarm_startpoint __upperarm_startpoint)
   (setq _upperarm_endpoint __upperarm_endpoint)
   (setq _upperarm_center __upperarm_center)
   (setq _quat_upperarm2robot __quat_upperarm2robot)
   (setq _head_center __head_center)
   (setq _quat_head2robot __quat_head2robot)
   self)
  (:time
   (&optional __time)
   (if __time (setq _time __time)) _time)
  (:lowerarm_startpoint
   (&rest __lowerarm_startpoint)
   (if (keywordp (car __lowerarm_startpoint))
       (send* _lowerarm_startpoint __lowerarm_startpoint)
     (progn
       (if __lowerarm_startpoint (setq _lowerarm_startpoint (car __lowerarm_startpoint)))
       _lowerarm_startpoint)))
  (:lowerarm_endpoint
   (&rest __lowerarm_endpoint)
   (if (keywordp (car __lowerarm_endpoint))
       (send* _lowerarm_endpoint __lowerarm_endpoint)
     (progn
       (if __lowerarm_endpoint (setq _lowerarm_endpoint (car __lowerarm_endpoint)))
       _lowerarm_endpoint)))
  (:lowerarm_center
   (&rest __lowerarm_center)
   (if (keywordp (car __lowerarm_center))
       (send* _lowerarm_center __lowerarm_center)
     (progn
       (if __lowerarm_center (setq _lowerarm_center (car __lowerarm_center)))
       _lowerarm_center)))
  (:quat_lowerarm2robot
   (&rest __quat_lowerarm2robot)
   (if (keywordp (car __quat_lowerarm2robot))
       (send* _quat_lowerarm2robot __quat_lowerarm2robot)
     (progn
       (if __quat_lowerarm2robot (setq _quat_lowerarm2robot (car __quat_lowerarm2robot)))
       _quat_lowerarm2robot)))
  (:upperarm_startpoint
   (&rest __upperarm_startpoint)
   (if (keywordp (car __upperarm_startpoint))
       (send* _upperarm_startpoint __upperarm_startpoint)
     (progn
       (if __upperarm_startpoint (setq _upperarm_startpoint (car __upperarm_startpoint)))
       _upperarm_startpoint)))
  (:upperarm_endpoint
   (&rest __upperarm_endpoint)
   (if (keywordp (car __upperarm_endpoint))
       (send* _upperarm_endpoint __upperarm_endpoint)
     (progn
       (if __upperarm_endpoint (setq _upperarm_endpoint (car __upperarm_endpoint)))
       _upperarm_endpoint)))
  (:upperarm_center
   (&rest __upperarm_center)
   (if (keywordp (car __upperarm_center))
       (send* _upperarm_center __upperarm_center)
     (progn
       (if __upperarm_center (setq _upperarm_center (car __upperarm_center)))
       _upperarm_center)))
  (:quat_upperarm2robot
   (&rest __quat_upperarm2robot)
   (if (keywordp (car __quat_upperarm2robot))
       (send* _quat_upperarm2robot __quat_upperarm2robot)
     (progn
       (if __quat_upperarm2robot (setq _quat_upperarm2robot (car __quat_upperarm2robot)))
       _quat_upperarm2robot)))
  (:head_center
   (&rest __head_center)
   (if (keywordp (car __head_center))
       (send* _head_center __head_center)
     (progn
       (if __head_center (setq _head_center (car __head_center)))
       _head_center)))
  (:quat_head2robot
   (&rest __quat_head2robot)
   (if (keywordp (car __quat_head2robot))
       (send* _quat_head2robot __quat_head2robot)
     (progn
       (if __quat_head2robot (setq _quat_head2robot (car __quat_head2robot)))
       _quat_head2robot)))
  (:serialization-length
   ()
   (+
    ;; float64 _time
    8
    ;; geometry_msgs/Point _lowerarm_startpoint
    (send _lowerarm_startpoint :serialization-length)
    ;; geometry_msgs/Point _lowerarm_endpoint
    (send _lowerarm_endpoint :serialization-length)
    ;; geometry_msgs/Point _lowerarm_center
    (send _lowerarm_center :serialization-length)
    ;; geometry_msgs/Quaternion _quat_lowerarm2robot
    (send _quat_lowerarm2robot :serialization-length)
    ;; geometry_msgs/Point _upperarm_startpoint
    (send _upperarm_startpoint :serialization-length)
    ;; geometry_msgs/Point _upperarm_endpoint
    (send _upperarm_endpoint :serialization-length)
    ;; geometry_msgs/Point _upperarm_center
    (send _upperarm_center :serialization-length)
    ;; geometry_msgs/Quaternion _quat_upperarm2robot
    (send _quat_upperarm2robot :serialization-length)
    ;; geometry_msgs/Point _head_center
    (send _head_center :serialization-length)
    ;; geometry_msgs/Quaternion _quat_head2robot
    (send _quat_head2robot :serialization-length)
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; float64 _time
       (sys::poke _time (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;; geometry_msgs/Point _lowerarm_startpoint
       (send _lowerarm_startpoint :serialize s)
     ;; geometry_msgs/Point _lowerarm_endpoint
       (send _lowerarm_endpoint :serialize s)
     ;; geometry_msgs/Point _lowerarm_center
       (send _lowerarm_center :serialize s)
     ;; geometry_msgs/Quaternion _quat_lowerarm2robot
       (send _quat_lowerarm2robot :serialize s)
     ;; geometry_msgs/Point _upperarm_startpoint
       (send _upperarm_startpoint :serialize s)
     ;; geometry_msgs/Point _upperarm_endpoint
       (send _upperarm_endpoint :serialize s)
     ;; geometry_msgs/Point _upperarm_center
       (send _upperarm_center :serialize s)
     ;; geometry_msgs/Quaternion _quat_upperarm2robot
       (send _quat_upperarm2robot :serialize s)
     ;; geometry_msgs/Point _head_center
       (send _head_center :serialize s)
     ;; geometry_msgs/Quaternion _quat_head2robot
       (send _quat_head2robot :serialize s)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; float64 _time
     (setq _time (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; geometry_msgs/Point _lowerarm_startpoint
     (send _lowerarm_startpoint :deserialize buf ptr-) (incf ptr- (send _lowerarm_startpoint :serialization-length))
   ;; geometry_msgs/Point _lowerarm_endpoint
     (send _lowerarm_endpoint :deserialize buf ptr-) (incf ptr- (send _lowerarm_endpoint :serialization-length))
   ;; geometry_msgs/Point _lowerarm_center
     (send _lowerarm_center :deserialize buf ptr-) (incf ptr- (send _lowerarm_center :serialization-length))
   ;; geometry_msgs/Quaternion _quat_lowerarm2robot
     (send _quat_lowerarm2robot :deserialize buf ptr-) (incf ptr- (send _quat_lowerarm2robot :serialization-length))
   ;; geometry_msgs/Point _upperarm_startpoint
     (send _upperarm_startpoint :deserialize buf ptr-) (incf ptr- (send _upperarm_startpoint :serialization-length))
   ;; geometry_msgs/Point _upperarm_endpoint
     (send _upperarm_endpoint :deserialize buf ptr-) (incf ptr- (send _upperarm_endpoint :serialization-length))
   ;; geometry_msgs/Point _upperarm_center
     (send _upperarm_center :deserialize buf ptr-) (incf ptr- (send _upperarm_center :serialization-length))
   ;; geometry_msgs/Quaternion _quat_upperarm2robot
     (send _quat_upperarm2robot :deserialize buf ptr-) (incf ptr- (send _quat_upperarm2robot :serialization-length))
   ;; geometry_msgs/Point _head_center
     (send _head_center :deserialize buf ptr-) (incf ptr- (send _head_center :serialization-length))
   ;; geometry_msgs/Quaternion _quat_head2robot
     (send _quat_head2robot :deserialize buf ptr-) (incf ptr- (send _quat_head2robot :serialization-length))
   ;;
   self)
  )

(setf (get franka_planner_control::HumanStates :md5sum-) "ad7042df2f9df072f398637da6be578c")
(setf (get franka_planner_control::HumanStates :datatype-) "franka_planner_control/HumanStates")
(setf (get franka_planner_control::HumanStates :definition-)
      "float64 time
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

")



(provide :franka_planner_control/HumanStates "ad7042df2f9df072f398637da6be578c")


