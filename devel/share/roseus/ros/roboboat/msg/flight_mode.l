;; Auto-generated. Do not edit!


(when (boundp 'roboboat::flight_mode)
  (if (not (find-package "ROBOBOAT"))
    (make-package "ROBOBOAT"))
  (shadow 'flight_mode (find-package "ROBOBOAT")))
(unless (find-package "ROBOBOAT::FLIGHT_MODE")
  (make-package "ROBOBOAT::FLIGHT_MODE"))

(in-package "ROS")
;;//! \htmlinclude flight_mode.msg.html


(defclass roboboat::flight_mode
  :super ros::object
  :slots (_flight_mode ))

(defmethod roboboat::flight_mode
  (:init
   (&key
    ((:flight_mode __flight_mode) "")
    )
   (send-super :init)
   (setq _flight_mode (string __flight_mode))
   self)
  (:flight_mode
   (&optional __flight_mode)
   (if __flight_mode (setq _flight_mode __flight_mode)) _flight_mode)
  (:serialization-length
   ()
   (+
    ;; string _flight_mode
    4 (length _flight_mode)
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; string _flight_mode
       (write-long (length _flight_mode) s) (princ _flight_mode s)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; string _flight_mode
     (let (n) (setq n (sys::peek buf ptr- :integer)) (incf ptr- 4) (setq _flight_mode (subseq buf ptr- (+ ptr- n))) (incf ptr- n))
   ;;
   self)
  )

(setf (get roboboat::flight_mode :md5sum-) "0ec7751446dccbf592ba3e57dd292976")
(setf (get roboboat::flight_mode :datatype-) "roboboat/flight_mode")
(setf (get roboboat::flight_mode :definition-)
      "string flight_mode

")



(provide :roboboat/flight_mode "0ec7751446dccbf592ba3e57dd292976")


