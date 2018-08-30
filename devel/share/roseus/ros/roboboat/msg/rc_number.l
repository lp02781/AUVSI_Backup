;; Auto-generated. Do not edit!


(when (boundp 'roboboat::rc_number)
  (if (not (find-package "ROBOBOAT"))
    (make-package "ROBOBOAT"))
  (shadow 'rc_number (find-package "ROBOBOAT")))
(unless (find-package "ROBOBOAT::RC_NUMBER")
  (make-package "ROBOBOAT::RC_NUMBER"))

(in-package "ROS")
;;//! \htmlinclude rc_number.msg.html


(defclass roboboat::rc_number
  :super ros::object
  :slots (_rc_number ))

(defmethod roboboat::rc_number
  (:init
   (&key
    ((:rc_number __rc_number) 0)
    )
   (send-super :init)
   (setq _rc_number (round __rc_number))
   self)
  (:rc_number
   (&optional __rc_number)
   (if __rc_number (setq _rc_number __rc_number)) _rc_number)
  (:serialization-length
   ()
   (+
    ;; int16 _rc_number
    2
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; int16 _rc_number
       (write-word _rc_number s)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; int16 _rc_number
     (setq _rc_number (sys::peek buf ptr- :short)) (incf ptr- 2)
   ;;
   self)
  )

(setf (get roboboat::rc_number :md5sum-) "2244ae5f9aac7ce5c8daccbb71337be0")
(setf (get roboboat::rc_number :datatype-) "roboboat/rc_number")
(setf (get roboboat::rc_number :definition-)
      "int16 rc_number

")



(provide :roboboat/rc_number "2244ae5f9aac7ce5c8daccbb71337be0")


