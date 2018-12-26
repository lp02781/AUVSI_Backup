;; Auto-generated. Do not edit!


(when (boundp 'kocheng::decode_status)
  (if (not (find-package "KOCHENG"))
    (make-package "KOCHENG"))
  (shadow 'decode_status (find-package "KOCHENG")))
(unless (find-package "KOCHENG::DECODE_STATUS")
  (make-package "KOCHENG::DECODE_STATUS"))

(in-package "ROS")
;;//! \htmlinclude decode_status.msg.html


(defclass kocheng::decode_status
  :super ros::object
  :slots (_run_course_status _heartbeat_status _follow_status _docking_status ))

(defmethod kocheng::decode_status
  (:init
   (&key
    ((:run_course_status __run_course_status) 0)
    ((:heartbeat_status __heartbeat_status) 0)
    ((:follow_status __follow_status) 0)
    ((:docking_status __docking_status) 0)
    )
   (send-super :init)
   (setq _run_course_status (round __run_course_status))
   (setq _heartbeat_status (round __heartbeat_status))
   (setq _follow_status (round __follow_status))
   (setq _docking_status (round __docking_status))
   self)
  (:run_course_status
   (&optional __run_course_status)
   (if __run_course_status (setq _run_course_status __run_course_status)) _run_course_status)
  (:heartbeat_status
   (&optional __heartbeat_status)
   (if __heartbeat_status (setq _heartbeat_status __heartbeat_status)) _heartbeat_status)
  (:follow_status
   (&optional __follow_status)
   (if __follow_status (setq _follow_status __follow_status)) _follow_status)
  (:docking_status
   (&optional __docking_status)
   (if __docking_status (setq _docking_status __docking_status)) _docking_status)
  (:serialization-length
   ()
   (+
    ;; int32 _run_course_status
    4
    ;; int32 _heartbeat_status
    4
    ;; int32 _follow_status
    4
    ;; int32 _docking_status
    4
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; int32 _run_course_status
       (write-long _run_course_status s)
     ;; int32 _heartbeat_status
       (write-long _heartbeat_status s)
     ;; int32 _follow_status
       (write-long _follow_status s)
     ;; int32 _docking_status
       (write-long _docking_status s)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; int32 _run_course_status
     (setq _run_course_status (sys::peek buf ptr- :integer)) (incf ptr- 4)
   ;; int32 _heartbeat_status
     (setq _heartbeat_status (sys::peek buf ptr- :integer)) (incf ptr- 4)
   ;; int32 _follow_status
     (setq _follow_status (sys::peek buf ptr- :integer)) (incf ptr- 4)
   ;; int32 _docking_status
     (setq _docking_status (sys::peek buf ptr- :integer)) (incf ptr- 4)
   ;;
   self)
  )

(setf (get kocheng::decode_status :md5sum-) "a2ff2b7cd0443eeeee765956b8e698bf")
(setf (get kocheng::decode_status :datatype-) "kocheng/decode_status")
(setf (get kocheng::decode_status :definition-)
      "int32 run_course_status
int32 heartbeat_status
int32 follow_status
int32 docking_status

")



(provide :kocheng/decode_status "a2ff2b7cd0443eeeee765956b8e698bf")


