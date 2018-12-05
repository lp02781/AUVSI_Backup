;; Auto-generated. Do not edit!


(when (boundp 'kocheng::nav_msgs)
  (if (not (find-package "KOCHENG"))
    (make-package "KOCHENG"))
  (shadow 'nav_msgs (find-package "KOCHENG")))
(unless (find-package "KOCHENG::NAV_MSGS")
  (make-package "KOCHENG::NAV_MSGS"))

(in-package "ROS")
;;//! \htmlinclude nav_msgs.msg.html


(defclass kocheng::nav_msgs
  :super ros::object
  :slots (_setpoint _state _effort ))

(defmethod kocheng::nav_msgs
  (:init
   (&key
    ((:setpoint __setpoint) 0)
    ((:state __state) 0)
    ((:effort __effort) 0)
    )
   (send-super :init)
   (setq _setpoint (round __setpoint))
   (setq _state (round __state))
   (setq _effort (round __effort))
   self)
  (:setpoint
   (&optional __setpoint)
   (if __setpoint (setq _setpoint __setpoint)) _setpoint)
  (:state
   (&optional __state)
   (if __state (setq _state __state)) _state)
  (:effort
   (&optional __effort)
   (if __effort (setq _effort __effort)) _effort)
  (:serialization-length
   ()
   (+
    ;; int16 _setpoint
    2
    ;; int16 _state
    2
    ;; int16 _effort
    2
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; int16 _setpoint
       (write-word _setpoint s)
     ;; int16 _state
       (write-word _state s)
     ;; int16 _effort
       (write-word _effort s)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; int16 _setpoint
     (setq _setpoint (sys::peek buf ptr- :short)) (incf ptr- 2)
   ;; int16 _state
     (setq _state (sys::peek buf ptr- :short)) (incf ptr- 2)
   ;; int16 _effort
     (setq _effort (sys::peek buf ptr- :short)) (incf ptr- 2)
   ;;
   self)
  )

(setf (get kocheng::nav_msgs :md5sum-) "8ea1d017b4a253e899268e6002fac34d")
(setf (get kocheng::nav_msgs :datatype-) "kocheng/nav_msgs")
(setf (get kocheng::nav_msgs :definition-)
      "int16 setpoint
int16 state
int16 effort

")



(provide :kocheng/nav_msgs "8ea1d017b4a253e899268e6002fac34d")


