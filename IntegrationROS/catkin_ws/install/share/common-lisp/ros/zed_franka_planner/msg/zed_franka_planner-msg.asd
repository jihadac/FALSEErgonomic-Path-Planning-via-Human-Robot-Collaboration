
(cl:in-package :asdf)

(defsystem "zed_franka_planner-msg"
  :depends-on (:roslisp-msg-protocol :roslisp-utils )
  :components ((:file "_package")
    (:file "JointTorqueComparison" :depends-on ("_package_JointTorqueComparison"))
    (:file "_package_JointTorqueComparison" :depends-on ("_package"))
  ))