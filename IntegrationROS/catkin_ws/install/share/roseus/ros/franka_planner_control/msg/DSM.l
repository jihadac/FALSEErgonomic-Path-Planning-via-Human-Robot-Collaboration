;; Auto-generated. Do not edit!


(when (boundp 'franka_planner_control::DSM)
  (if (not (find-package "FRANKA_PLANNER_CONTROL"))
    (make-package "FRANKA_PLANNER_CONTROL"))
  (shadow 'DSM (find-package "FRANKA_PLANNER_CONTROL")))
(unless (find-package "FRANKA_PLANNER_CONTROL::DSM")
  (make-package "FRANKA_PLANNER_CONTROL::DSM"))

(in-package "ROS")
;;//! \htmlinclude DSM.msg.html


(defclass franka_planner_control::DSM
  :super ros::object
  :slots (_time _DSM _tau _dotq _q _dotp_EE _terminalenergy _sphere _cylinder _wall ))

(defmethod franka_planner_control::DSM
  (:init
   (&key
    ((:time __time) 0.0)
    ((:DSM __DSM) 0.0)
    ((:tau __tau) 0.0)
    ((:dotq __dotq) 0.0)
    ((:q __q) 0.0)
    ((:dotp_EE __dotp_EE) 0.0)
    ((:terminalenergy __terminalenergy) 0.0)
    ((:sphere __sphere) 0.0)
    ((:cylinder __cylinder) 0.0)
    ((:wall __wall) 0.0)
    )
   (send-super :init)
   (setq _time (float __time))
   (setq _DSM (float __DSM))
   (setq _tau (float __tau))
   (setq _dotq (float __dotq))
   (setq _q (float __q))
   (setq _dotp_EE (float __dotp_EE))
   (setq _terminalenergy (float __terminalenergy))
   (setq _sphere (float __sphere))
   (setq _cylinder (float __cylinder))
   (setq _wall (float __wall))
   self)
  (:time
   (&optional __time)
   (if __time (setq _time __time)) _time)
  (:DSM
   (&optional __DSM)
   (if __DSM (setq _DSM __DSM)) _DSM)
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
  (:terminalenergy
   (&optional __terminalenergy)
   (if __terminalenergy (setq _terminalenergy __terminalenergy)) _terminalenergy)
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
    ;; float64 _DSM
    8
    ;; float64 _tau
    8
    ;; float64 _dotq
    8
    ;; float64 _q
    8
    ;; float64 _dotp_EE
    8
    ;; float64 _terminalenergy
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
     ;; float64 _DSM
       (sys::poke _DSM (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;; float64 _tau
       (sys::poke _tau (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;; float64 _dotq
       (sys::poke _dotq (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;; float64 _q
       (sys::poke _q (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;; float64 _dotp_EE
       (sys::poke _dotp_EE (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;; float64 _terminalenergy
       (sys::poke _terminalenergy (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
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
   ;; float64 _DSM
     (setq _DSM (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; float64 _tau
     (setq _tau (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; float64 _dotq
     (setq _dotq (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; float64 _q
     (setq _q (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; float64 _dotp_EE
     (setq _dotp_EE (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; float64 _terminalenergy
     (setq _terminalenergy (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; float64 _sphere
     (setq _sphere (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; float64 _cylinder
     (setq _cylinder (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; float64 _wall
     (setq _wall (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;;
   self)
  )

(setf (get franka_planner_control::DSM :md5sum-) "b450392d56d2a24eb5c7559f486528c5")
(setf (get franka_planner_control::DSM :datatype-) "franka_planner_control/DSM")
(setf (get franka_planner_control::DSM :definition-)
      "float64 time
float64 DSM
float64 tau
float64 dotq
float64 q
float64 dotp_EE
float64 terminalenergy
float64 sphere
float64 cylinder
float64 wall
")



(provide :franka_planner_control/DSM "b450392d56d2a24eb5c7559f486528c5")


