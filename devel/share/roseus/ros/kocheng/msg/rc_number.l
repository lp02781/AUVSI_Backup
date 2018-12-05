;; Auto-generated. Do not edit!


(when (boundp 'kocheng::rc_number)
  (if (not (find-package "KOCHENG"))
    (make-package "KOCHENG"))
  (shadow 'rc_number (find-package "KOCHENG")))
(unless (find-package "KOCHENG::RC_NUMBER")
  (make-package "KOCHENG::RC_NUMBER"))

(in-package "ROS")
;;//! \htmlinclude rc_number.msg.html


(defclass kocheng::rc_number
  :super ros::object
  :slots (_override_status _rc_number ))

(defmethod kocheng::rc_number
  (:init
   (&key
    ((:override_status __override_status) nil)
    ((:rc_number __rc_number) 0)
    )
   (send-super :init)
   (setq _override_status __override_status)
   (setq _rc_number (round __rc_number))
   self)
  (:override_status
   (&optional __override_status)
   (if __override_status (setq _override_status __override_status)) _override_status)
  (:rc_number
   (&optional __rc_number)
   (if __rc_number (setq _rc_number __rc_number)) _rc_number)
  (:serialization-length
   ()
   (+
    ;; bool _override_status
    1
    ;; int16 _rc_number
    2
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; bool _override_status
       (if _override_status (write-byte -1 s) (write-byte 0 s))
     ;; int16 _rc_number
       (write-word _rc_number s)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; bool _override_status
     (setq _override_status (not (= 0 (sys::peek buf ptr- :char)))) (incf ptr- 1)
   ;; int16 _rc_number
     (setq _rc_number (sys::peek buf ptr- :short)) (incf ptr- 2)
   ;;
   self)
  )

(setf (get kocheng::rc_number :md5sum-) "245976b4840f71d588f1be6b4dde93f8")
(setf (get kocheng::rc_number :datatype-) "kocheng/rc_number")
(setf (get kocheng::rc_number :definition-)
      "bool override_status
int16 rc_number

")



(provide :kocheng/rc_number "245976b4840f71d588f1be6b4dde93f8")


