;; Auto-generated. Do not edit!


(when (boundp 'franka_planner_control::TrajectoryPredictions)
  (if (not (find-package "FRANKA_PLANNER_CONTROL"))
    (make-package "FRANKA_PLANNER_CONTROL"))
  (shadow 'TrajectoryPredictions (find-package "FRANKA_PLANNER_CONTROL")))
(unless (find-package "FRANKA_PLANNER_CONTROL::TRAJECTORYPREDICTIONS")
  (make-package "FRANKA_PLANNER_CONTROL::TRAJECTORYPREDICTIONS"))

(in-package "ROS")
;;//! \htmlinclude TrajectoryPredictions.msg.html


(defclass franka_planner_control::TrajectoryPredictions
  :super ros::object
  :slots (_time _q_pred _dotq_pred _ddotq_pred _tau_pred ))

(defmethod franka_planner_control::TrajectoryPredictions
  (:init
   (&key
    ((:time __time) 0.0)
    ((:q_pred __q_pred) (make-array 700 :initial-element 0.0 :element-type :float))
    ((:dotq_pred __dotq_pred) (make-array 700 :initial-element 0.0 :element-type :float))
    ((:ddotq_pred __ddotq_pred) (make-array 700 :initial-element 0.0 :element-type :float))
    ((:tau_pred __tau_pred) (make-array 700 :initial-element 0.0 :element-type :float))
    )
   (send-super :init)
   (setq _time (float __time))
   (setq _q_pred __q_pred)
   (setq _dotq_pred __dotq_pred)
   (setq _ddotq_pred __ddotq_pred)
   (setq _tau_pred __tau_pred)
   self)
  (:time
   (&optional __time)
   (if __time (setq _time __time)) _time)
  (:q_pred
   (&optional __q_pred)
   (if __q_pred (setq _q_pred __q_pred)) _q_pred)
  (:dotq_pred
   (&optional __dotq_pred)
   (if __dotq_pred (setq _dotq_pred __dotq_pred)) _dotq_pred)
  (:ddotq_pred
   (&optional __ddotq_pred)
   (if __ddotq_pred (setq _ddotq_pred __ddotq_pred)) _ddotq_pred)
  (:tau_pred
   (&optional __tau_pred)
   (if __tau_pred (setq _tau_pred __tau_pred)) _tau_pred)
  (:serialization-length
   ()
   (+
    ;; float64 _time
    8
    ;; float64[700] _q_pred
    (* 8    700)
    ;; float64[700] _dotq_pred
    (* 8    700)
    ;; float64[700] _ddotq_pred
    (* 8    700)
    ;; float64[700] _tau_pred
    (* 8    700)
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; float64 _time
       (sys::poke _time (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;; float64[700] _q_pred
     (dotimes (i 700)
       (sys::poke (elt _q_pred i) (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
       )
     ;; float64[700] _dotq_pred
     (dotimes (i 700)
       (sys::poke (elt _dotq_pred i) (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
       )
     ;; float64[700] _ddotq_pred
     (dotimes (i 700)
       (sys::poke (elt _ddotq_pred i) (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
       )
     ;; float64[700] _tau_pred
     (dotimes (i 700)
       (sys::poke (elt _tau_pred i) (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
       )
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; float64 _time
     (setq _time (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; float64[700] _q_pred
   (dotimes (i (length _q_pred))
     (setf (elt _q_pred i) (sys::peek buf ptr- :double)) (incf ptr- 8)
     )
   ;; float64[700] _dotq_pred
   (dotimes (i (length _dotq_pred))
     (setf (elt _dotq_pred i) (sys::peek buf ptr- :double)) (incf ptr- 8)
     )
   ;; float64[700] _ddotq_pred
   (dotimes (i (length _ddotq_pred))
     (setf (elt _ddotq_pred i) (sys::peek buf ptr- :double)) (incf ptr- 8)
     )
   ;; float64[700] _tau_pred
   (dotimes (i (length _tau_pred))
     (setf (elt _tau_pred i) (sys::peek buf ptr- :double)) (incf ptr- 8)
     )
   ;;
   self)
  )

(setf (get franka_planner_control::TrajectoryPredictions :md5sum-) "899976afaf40b6f4e6d8c2730905b6af")
(setf (get franka_planner_control::TrajectoryPredictions :datatype-) "franka_planner_control/TrajectoryPredictions")
(setf (get franka_planner_control::TrajectoryPredictions :definition-)
      "float64 time
float64[700] q_pred
float64[700] dotq_pred
float64[700] ddotq_pred
float64[700] tau_pred
")



(provide :franka_planner_control/TrajectoryPredictions "899976afaf40b6f4e6d8c2730905b6af")


