;; Auto-generated. Do not edit!


(when (boundp 'roboboat::setpoint)
  (if (not (find-package "ROBOBOAT"))
    (make-package "ROBOBOAT"))
  (shadow 'setpoint (find-package "ROBOBOAT")))
(unless (find-package "ROBOBOAT::SETPOINT")
  (make-package "ROBOBOAT::SETPOINT"))

(in-package "ROS")
;;//! \htmlinclude setpoint.msg.html


(defclass roboboat::setpoint
  :super ros::object
  :slots (_setpoint ))

(defmethod roboboat::setpoint
  (:init
   (&key
    ((:setpoint __setpoint) 0)
    )
   (send-super :init)
   (setq _setpoint (round __setpoint))
   self)
  (:setpoint
   (&optional __setpoint)
   (if __setpoint (setq _setpoint __setpoint)) _setpoint)
  (:serialization-length
   ()
   (+
    ;; int16 _setpoint
    2
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; int16 _setpoint
       (write-word _setpoint s)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; int16 _setpoint
     (setq _setpoint (sys::peek buf ptr- :short)) (incf ptr- 2)
   ;;
   self)
  )

(setf (get roboboat::setpoint :md5sum-) "8ee399a1f7e5b4decdfc42e0ba4ab098")
(setf (get roboboat::setpoint :datatype-) "roboboat/setpoint")
(setf (get roboboat::setpoint :definition-)
      "int16 setpoint

")



(provide :roboboat/setpoint "8ee399a1f7e5b4decdfc42e0ba4ab098")


