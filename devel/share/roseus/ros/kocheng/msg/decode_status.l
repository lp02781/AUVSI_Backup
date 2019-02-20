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
  :slots (_run_course_status _heartbeat_status _follow_status _docking_status _flag_status ))

(defmethod kocheng::decode_status
  (:init
   (&key
    ((:run_course_status __run_course_status) 0)
    ((:heartbeat_status __heartbeat_status) 0)
    ((:follow_status __follow_status) 0)
    ((:docking_status __docking_status) 0)
    ((:flag_status __flag_status) 0)
    )
   (send-super :init)
   (setq _run_course_status (round __run_course_status))
   (setq _heartbeat_status (round __heartbeat_status))
   (setq _follow_status (round __follow_status))
   (setq _docking_status (round __docking_status))
   (setq _flag_status (round __flag_status))
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
  (:flag_status
   (&optional __flag_status)
   (if __flag_status (setq _flag_status __flag_status)) _flag_status)
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
    ;; int32 _flag_status
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
     ;; int32 _flag_status
       (write-long _flag_status s)
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
   ;; int32 _flag_status
     (setq _flag_status (sys::peek buf ptr- :integer)) (incf ptr- 4)
   ;;
   self)
  )

(setf (get kocheng::decode_status :md5sum-) "39541b4d1e52937d3a67a84020aded6d")
(setf (get kocheng::decode_status :datatype-) "kocheng/decode_status")
(setf (get kocheng::decode_status :definition-)
      "int32 run_course_status
int32 heartbeat_status
int32 follow_status
int32 docking_status
int32 flag_status

")



(provide :kocheng/decode_status "39541b4d1e52937d3a67a84020aded6d")


