;; Auto-generated. Do not edit!


(when (boundp 'kocheng::debug_mission)
  (if (not (find-package "KOCHENG"))
    (make-package "KOCHENG"))
  (shadow 'debug_mission (find-package "KOCHENG")))
(unless (find-package "KOCHENG::DEBUG_MISSION")
  (make-package "KOCHENG::DEBUG_MISSION"))

(in-package "ROS")
;;//! \htmlinclude debug_mission.msg.html


(defclass kocheng::debug_mission
  :super ros::object
  :slots (_setpoint _state _effort _longitude _latitude ))

(defmethod kocheng::debug_mission
  (:init
   (&key
    ((:setpoint __setpoint) 0)
    ((:state __state) 0)
    ((:effort __effort) 0)
    ((:longitude __longitude) 0.0)
    ((:latitude __latitude) 0.0)
    )
   (send-super :init)
   (setq _setpoint (round __setpoint))
   (setq _state (round __state))
   (setq _effort (round __effort))
   (setq _longitude (float __longitude))
   (setq _latitude (float __latitude))
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
  (:longitude
   (&optional __longitude)
   (if __longitude (setq _longitude __longitude)) _longitude)
  (:latitude
   (&optional __latitude)
   (if __latitude (setq _latitude __latitude)) _latitude)
  (:serialization-length
   ()
   (+
    ;; int16 _setpoint
    2
    ;; int16 _state
    2
    ;; int16 _effort
    2
    ;; float32 _longitude
    4
    ;; float32 _latitude
    4
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
     ;; float32 _longitude
       (sys::poke _longitude (send s :buffer) (send s :count) :float) (incf (stream-count s) 4)
     ;; float32 _latitude
       (sys::poke _latitude (send s :buffer) (send s :count) :float) (incf (stream-count s) 4)
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
   ;; float32 _longitude
     (setq _longitude (sys::peek buf ptr- :float)) (incf ptr- 4)
   ;; float32 _latitude
     (setq _latitude (sys::peek buf ptr- :float)) (incf ptr- 4)
   ;;
   self)
  )

(setf (get kocheng::debug_mission :md5sum-) "5ca02c94f587bbdb18e5bb5621c35260")
(setf (get kocheng::debug_mission :datatype-) "kocheng/debug_mission")
(setf (get kocheng::debug_mission :definition-)
      "int16 setpoint
int16 state
int16 effort
float32 longitude
float32 latitude

")



(provide :kocheng/debug_mission "5ca02c94f587bbdb18e5bb5621c35260")


