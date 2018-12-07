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
  :slots (_longitude _latitude ))

(defmethod kocheng::debug_mission
  (:init
   (&key
    ((:longitude __longitude) 0.0)
    ((:latitude __latitude) 0.0)
    )
   (send-super :init)
   (setq _longitude (float __longitude))
   (setq _latitude (float __latitude))
   self)
  (:longitude
   (&optional __longitude)
   (if __longitude (setq _longitude __longitude)) _longitude)
  (:latitude
   (&optional __latitude)
   (if __latitude (setq _latitude __latitude)) _latitude)
  (:serialization-length
   ()
   (+
    ;; float32 _longitude
    4
    ;; float32 _latitude
    4
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; float32 _longitude
       (sys::poke _longitude (send s :buffer) (send s :count) :float) (incf (stream-count s) 4)
     ;; float32 _latitude
       (sys::poke _latitude (send s :buffer) (send s :count) :float) (incf (stream-count s) 4)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; float32 _longitude
     (setq _longitude (sys::peek buf ptr- :float)) (incf ptr- 4)
   ;; float32 _latitude
     (setq _latitude (sys::peek buf ptr- :float)) (incf ptr- 4)
   ;;
   self)
  )

(setf (get kocheng::debug_mission :md5sum-) "826f8fcadfa8742a6495798d3978624a")
(setf (get kocheng::debug_mission :datatype-) "kocheng/debug_mission")
(setf (get kocheng::debug_mission :definition-)
      "float32 longitude
float32 latitude

")



(provide :kocheng/debug_mission "826f8fcadfa8742a6495798d3978624a")


