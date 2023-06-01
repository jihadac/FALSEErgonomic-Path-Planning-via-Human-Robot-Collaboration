;; Auto-generated. Do not edit!


(when (boundp 'franka_planner_control::RobotEndEffectorPose)
  (if (not (find-package "FRANKA_PLANNER_CONTROL"))
    (make-package "FRANKA_PLANNER_CONTROL"))
  (shadow 'RobotEndEffectorPose (find-package "FRANKA_PLANNER_CONTROL")))
(unless (find-package "FRANKA_PLANNER_CONTROL::ROBOTENDEFFECTORPOSE")
  (make-package "FRANKA_PLANNER_CONTROL::ROBOTENDEFFECTORPOSE"))

(in-package "ROS")
;;//! \htmlinclude RobotEndEffectorPose.msg.html
(if (not (find-package "GEOMETRY_MSGS"))
  (ros::roseus-add-msgs "geometry_msgs"))


(defclass franka_planner_control::RobotEndEffectorPose
  :super ros::object
  :slots (_rviz_orientation_problem _xe_r ))

(defmethod franka_planner_control::RobotEndEffectorPose
  (:init
   (&key
    ((:rviz_orientation_problem __rviz_orientation_problem) nil)
    ((:xe_r __xe_r) (instance geometry_msgs::Pose :init))
    )
   (send-super :init)
   (setq _rviz_orientation_problem __rviz_orientation_problem)
   (setq _xe_r __xe_r)
   self)
  (:rviz_orientation_problem
   (&optional __rviz_orientation_problem)
   (if __rviz_orientation_problem (setq _rviz_orientation_problem __rviz_orientation_problem)) _rviz_orientation_problem)
  (:xe_r
   (&rest __xe_r)
   (if (keywordp (car __xe_r))
       (send* _xe_r __xe_r)
     (progn
       (if __xe_r (setq _xe_r (car __xe_r)))
       _xe_r)))
  (:serialization-length
   ()
   (+
    ;; bool _rviz_orientation_problem
    1
    ;; geometry_msgs/Pose _xe_r
    (send _xe_r :serialization-length)
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; bool _rviz_orientation_problem
       (if _rviz_orientation_problem (write-byte -1 s) (write-byte 0 s))
     ;; geometry_msgs/Pose _xe_r
       (send _xe_r :serialize s)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; bool _rviz_orientation_problem
     (setq _rviz_orientation_problem (not (= 0 (sys::peek buf ptr- :char)))) (incf ptr- 1)
   ;; geometry_msgs/Pose _xe_r
     (send _xe_r :deserialize buf ptr-) (incf ptr- (send _xe_r :serialization-length))
   ;;
   self)
  )

(setf (get franka_planner_control::RobotEndEffectorPose :md5sum-) "08713e20671c442197b0728d63307e52")
(setf (get franka_planner_control::RobotEndEffectorPose :datatype-) "franka_planner_control/RobotEndEffectorPose")
(setf (get franka_planner_control::RobotEndEffectorPose :definition-)
      "bool rviz_orientation_problem
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

")



(provide :franka_planner_control/RobotEndEffectorPose "08713e20671c442197b0728d63307e52")


