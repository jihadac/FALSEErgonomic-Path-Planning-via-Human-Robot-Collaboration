;; Auto-generated. Do not edit!


(when (boundp 'franka_planner_control::MoveItTime)
  (if (not (find-package "FRANKA_PLANNER_CONTROL"))
    (make-package "FRANKA_PLANNER_CONTROL"))
  (shadow 'MoveItTime (find-package "FRANKA_PLANNER_CONTROL")))
(unless (find-package "FRANKA_PLANNER_CONTROL::MOVEITTIME")
  (make-package "FRANKA_PLANNER_CONTROL::MOVEITTIME"))

(in-package "ROS")
;;//! \htmlinclude MoveItTime.msg.html


(defclass franka_planner_control::MoveItTime
  :super ros::object
  :slots (_time _planning_time _execution_time ))

(defmethod franka_planner_control::MoveItTime
  (:init
   (&key
    ((:time __time) 0.0)
    ((:planning_time __planning_time) 0.0)
    ((:execution_time __execution_time) 0.0)
    )
   (send-super :init)
   (setq _time (float __time))
   (setq _planning_time (float __planning_time))
   (setq _execution_time (float __execution_time))
   self)
  (:time
   (&optional __time)
   (if __time (setq _time __time)) _time)
  (:planning_time
   (&optional __planning_time)
   (if __planning_time (setq _planning_time __planning_time)) _planning_time)
  (:execution_time
   (&optional __execution_time)
   (if __execution_time (setq _execution_time __execution_time)) _execution_time)
  (:serialization-length
   ()
   (+
    ;; float64 _time
    8
    ;; float64 _planning_time
    8
    ;; float64 _execution_time
    8
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; float64 _time
       (sys::poke _time (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;; float64 _planning_time
       (sys::poke _planning_time (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;; float64 _execution_time
       (sys::poke _execution_time (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; float64 _time
     (setq _time (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; float64 _planning_time
     (setq _planning_time (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; float64 _execution_time
     (setq _execution_time (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;;
   self)
  )

(setf (get franka_planner_control::MoveItTime :md5sum-) "d94af49849121fe51add0cc4fc4d2503")
(setf (get franka_planner_control::MoveItTime :datatype-) "franka_planner_control/MoveItTime")
(setf (get franka_planner_control::MoveItTime :definition-)
      "float64 time
float64 planning_time
float64 execution_time
")



(provide :franka_planner_control/MoveItTime "d94af49849121fe51add0cc4fc4d2503")


