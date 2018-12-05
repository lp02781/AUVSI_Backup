
(cl:in-package :asdf)

(defsystem "kocheng-msg"
  :depends-on (:roslisp-msg-protocol :roslisp-utils )
  :components ((:file "_package")
    (:file "debug_mission" :depends-on ("_package_debug_mission"))
    (:file "_package_debug_mission" :depends-on ("_package"))
    (:file "mission_status" :depends-on ("_package_mission_status"))
    (:file "_package_mission_status" :depends-on ("_package"))
    (:file "override_motor" :depends-on ("_package_override_motor"))
    (:file "_package_override_motor" :depends-on ("_package"))
    (:file "rc_number" :depends-on ("_package_rc_number"))
    (:file "_package_rc_number" :depends-on ("_package"))
  ))