;; Auto-generated. Do not edit!


(when (boundp 'franka_planner_control::ComputationalTime)
  (if (not (find-package "FRANKA_PLANNER_CONTROL"))
    (make-package "FRANKA_PLANNER_CONTROL"))
  (shadow 'ComputationalTime (find-package "FRANKA_PLANNER_CONTROL")))
(unless (find-package "FRANKA_PLANNER_CONTROL::COMPUTATIONALTIME")
  (make-package "FRANKA_PLANNER_CONTROL::COMPUTATIONALTIME"))

(in-package "ROS")
;;//! \htmlinclude ComputationalTime.msg.html


(defclass franka_planner_control::ComputationalTime
  :super ros::object
  :slots (_time _NF _DSM _trajectory_predictions _ERG ))

(defmethod franka_planner_control::ComputationalTime
  (:init
   (&key
    ((:time __time) 0.0)
    ((:NF __NF) 0.0)
    ((:DSM __DSM) 0.0)
    ((:trajectory_predictions __trajectory_predictions) 0.0)
    ((:ERG __ERG) 0.0)
    )
   (send-super :init)
   (setq _time (float __time))
   (setq _NF (float __NF))
   (setq _DSM (float __DSM))
   (setq _trajectory_predictions (float __trajectory_predictions))
   (setq _ERG (float __ERG))
   self)
  (:time
   (&optional __time)
   (if __time (setq _time __time)) _time)
  (:NF
   (&optional __NF)
   (if __NF (setq _NF __NF)) _NF)
  (:DSM
   (&optional __DSM)
   (if __DSM (setq _DSM __DSM)) _DSM)
  (:trajectory_predictions
   (&optional __trajectory_predictions)
   (if __trajectory_predictions (setq _trajectory_predictions __trajectory_predictions)) _trajectory_predictions)
  (:ERG
   (&optional __ERG)
   (if __ERG (setq _ERG __ERG)) _ERG)
  (:serialization-length
   ()
   (+
    ;; float64 _time
    8
    ;; float64 _NF
    8
    ;; float64 _DSM
    8
    ;; float64 _trajectory_predictions
    8
    ;; float64 _ERG
    8
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; float64 _time
       (sys::poke _time (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;; float64 _NF
       (sys::poke _NF (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;; float64 _DSM
       (sys::poke _DSM (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;; float64 _trajectory_predictions
       (sys::poke _trajectory_predictions (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;; float64 _ERG
       (sys::poke _ERG (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; float64 _time
     (setq _time (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; float64 _NF
     (setq _NF (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; float64 _DSM
     (setq _DSM (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; float64 _trajectory_predictions
     (setq _trajectory_predictions (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; float64 _ERG
     (setq _ERG (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;;
   self)
  )

(setf (get franka_planner_control::ComputationalTime :md5sum-) "88eb9a619c00c3079c22019ebb22fa32")
(setf (get franka_planner_control::ComputationalTime :datatype-) "franka_planner_control/ComputationalTime")
(setf (get franka_planner_control::ComputationalTime :definition-)
      "float64 time
float64 NF
float64 DSM
float64 trajectory_predictions
float64 ERG
")



(provide :franka_planner_control/ComputationalTime "88eb9a619c00c3079c22019ebb22fa32")


