;; Auto-generated. Do not edit!


(when (boundp 'kocheng::override_value)
  (if (not (find-package "KOCHENG"))
    (make-package "KOCHENG"))
  (shadow 'override_value (find-package "KOCHENG")))
(unless (find-package "KOCHENG::OVERRIDE_VALUE")
  (make-package "KOCHENG::OVERRIDE_VALUE"))

(in-package "ROS")
;;//! \htmlinclude override_value.msg.html


(defclass kocheng::override_value
  :super ros::object
  :slots (_steering _throttle _camera_servo ))

(defmethod kocheng::override_value
  (:init
   (&key
    ((:steering __steering) 0)
    ((:throttle __throttle) 0)
    ((:camera_servo __camera_servo) 0)
    )
   (send-super :init)
   (setq _steering (round __steering))
   (setq _throttle (round __throttle))
   (setq _camera_servo (round __camera_servo))
   self)
  (:steering
   (&optional __steering)
   (if __steering (setq _steering __steering)) _steering)
  (:throttle
   (&optional __throttle)
   (if __throttle (setq _throttle __throttle)) _throttle)
  (:camera_servo
   (&optional __camera_servo)
   (if __camera_servo (setq _camera_servo __camera_servo)) _camera_servo)
  (:serialization-length
   ()
   (+
    ;; int16 _steering
    2
    ;; int16 _throttle
    2
    ;; int16 _camera_servo
    2
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; int16 _steering
       (write-word _steering s)
     ;; int16 _throttle
       (write-word _throttle s)
     ;; int16 _camera_servo
       (write-word _camera_servo s)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; int16 _steering
     (setq _steering (sys::peek buf ptr- :short)) (incf ptr- 2)
   ;; int16 _throttle
     (setq _throttle (sys::peek buf ptr- :short)) (incf ptr- 2)
   ;; int16 _camera_servo
     (setq _camera_servo (sys::peek buf ptr- :short)) (incf ptr- 2)
   ;;
   self)
  )

(setf (get kocheng::override_value :md5sum-) "8b817f7d8452ec829c7dc50e436e6bd8")
(setf (get kocheng::override_value :datatype-) "kocheng/override_value")
(setf (get kocheng::override_value :definition-)
      "int16 steering
int16 throttle
int16 camera_servo

")



(provide :kocheng/override_value "8b817f7d8452ec829c7dc50e436e6bd8")


