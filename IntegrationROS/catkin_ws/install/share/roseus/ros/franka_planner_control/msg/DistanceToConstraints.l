;; Auto-generated. Do not edit!


(when (boundp 'franka_planner_control::DistanceToConstraints)
  (if (not (find-package "FRANKA_PLANNER_CONTROL"))
    (make-package "FRANKA_PLANNER_CONTROL"))
  (shadow 'DistanceToConstraints (find-package "FRANKA_PLANNER_CONTROL")))
(unless (find-package "FRANKA_PLANNER_CONTROL::DISTANCETOCONSTRAINTS")
  (make-package "FRANKA_PLANNER_CONTROL::DISTANCETOCONSTRAINTS"))

(in-package "ROS")
;;//! \htmlinclude DistanceToConstraints.msg.html


(defclass franka_planner_control::DistanceToConstraints
  :super ros::object
  :slots (_time _tau _dotq _q _dotp_EE _terminal_energy _sphere _cylinder _wall ))

(defmethod franka_planner_control::DistanceToConstraints
  (:init
   (&key
    ((:time __time) 0.0)
    ((:tau __tau) 0.0)
    ((:dotq __dotq) 0.0)
    ((:q __q) 0.0)
    ((:dotp_EE __dotp_EE) 0.0)
    ((:terminal_energy __terminal_energy) 0.0)
    ((:sphere __sphere) 0.0)
    ((:cylinder __cylinder) 0.0)
    ((:wall __wall) 0.0)
    )
   (send-super :init)
   (setq _time (float __time))
   (setq _tau (float __tau))
   (setq _dotq (float __dotq))
   (setq _q (float __q))
   (setq _dotp_EE (float __dotp_EE))
   (setq _terminal_energy (float __terminal_energy))
   (setq _sphere (float __sphere))
   (setq _cylinder (float __cylinder))
   (setq _wall (float __wall))
   self)
  (:time
   (&optional __time)
   (if __time (setq _time __time)) _time)
  (:tau
   (&optional __tau)
   (if __tau (setq _tau __tau)) _tau)
  (:dotq
   (&optional __dotq)
   (if __dotq (setq _dotq __dotq)) _dotq)
  (:q
   (&optional __q)
   (if __q (setq _q __q)) _q)
  (:dotp_EE
   (&optional __dotp_EE)
   (if __dotp_EE (setq _dotp_EE __dotp_EE)) _dotp_EE)
  (:terminal_energy
   (&optional __terminal_energy)
   (if __terminal_energy (setq _terminal_energy __terminal_energy)) _terminal_energy)
  (:sphere
   (&optional __sphere)
   (if __sphere (setq _sphere __sphere)) _sphere)
  (:cylinder
   (&optional __cylinder)
   (if __cylinder (setq _cylinder __cylinder)) _cylinder)
  (:wall
   (&optional __wall)
   (if __wall (setq _wall __wall)) _wall)
  (:serialization-length
   ()
   (+
    ;; float64 _time
    8
    ;; float64 _tau
    8
    ;; float64 _dotq
    8
    ;; float64 _q
    8
    ;; float64 _dotp_EE
    8
    ;; float64 _terminal_energy
    8
    ;; float64 _sphere
    8
    ;; float64 _cylinder
    8
    ;; float64 _wall
    8
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; float64 _time
       (sys::poke _time (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;; float64 _tau
       (sys::poke _tau (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;; float64 _dotq
       (sys::poke _dotq (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;; float64 _q
       (sys::poke _q (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;; float64 _dotp_EE
       (sys::poke _dotp_EE (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;; float64 _terminal_energy
       (sys::poke _terminal_energy (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;; float64 _sphere
       (sys::poke _sphere (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;; float64 _cylinder
       (sys::poke _cylinder (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;; float64 _wall
       (sys::poke _wall (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; float64 _time
     (setq _time (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; float64 _tau
     (setq _tau (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; float64 _dotq
     (setq _dotq (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; float64 _q
     (setq _q (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; float64 _dotp_EE
     (setq _dotp_EE (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; float64 _terminal_energy
     (setq _terminal_energy (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; float64 _sphere
     (setq _sphere (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; float64 _cylinder
     (setq _cylinder (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; float64 _wall
     (setq _wall (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;;
   self)
  )

(setf (get franka_planner_control::DistanceToConstraints :md5sum-) "a849fb29c9c41af1ce04081a677e64dd")
(setf (get franka_planner_control::DistanceToConstraints :datatype-) "franka_planner_control/DistanceToConstraints")
(setf (get franka_planner_control::DistanceToConstraints :definition-)
      "float64 time
float64 tau
float64 dotq
float64 q
float64 dotp_EE
float64 terminal_energy
float64 sphere
float64 cylinder
float64 wall
")



(provide :franka_planner_control/DistanceToConstraints "a849fb29c9c41af1ce04081a677e64dd")


