;; Auto-generated. Do not edit!


(when (boundp 'kocheng::communication)
  (if (not (find-package "KOCHENG"))
    (make-package "KOCHENG"))
  (shadow 'communication (find-package "KOCHENG")))
(unless (find-package "KOCHENG::COMMUNICATION")
  (make-package "KOCHENG::COMMUNICATION"))

(in-package "ROS")
;;//! \htmlinclude communication.msg.html


(defclass kocheng::communication
  :super ros::object
  :slots (_heartbeat_payload _run_course_payload _follow_payload _docking_payload _flag_payload ))

(defmethod kocheng::communication
  (:init
   (&key
    ((:heartbeat_payload __heartbeat_payload) "")
    ((:run_course_payload __run_course_payload) "")
    ((:follow_payload __follow_payload) "")
    ((:docking_payload __docking_payload) "")
    ((:flag_payload __flag_payload) "")
    )
   (send-super :init)
   (setq _heartbeat_payload (string __heartbeat_payload))
   (setq _run_course_payload (string __run_course_payload))
   (setq _follow_payload (string __follow_payload))
   (setq _docking_payload (string __docking_payload))
   (setq _flag_payload (string __flag_payload))
   self)
  (:heartbeat_payload
   (&optional __heartbeat_payload)
   (if __heartbeat_payload (setq _heartbeat_payload __heartbeat_payload)) _heartbeat_payload)
  (:run_course_payload
   (&optional __run_course_payload)
   (if __run_course_payload (setq _run_course_payload __run_course_payload)) _run_course_payload)
  (:follow_payload
   (&optional __follow_payload)
   (if __follow_payload (setq _follow_payload __follow_payload)) _follow_payload)
  (:docking_payload
   (&optional __docking_payload)
   (if __docking_payload (setq _docking_payload __docking_payload)) _docking_payload)
  (:flag_payload
   (&optional __flag_payload)
   (if __flag_payload (setq _flag_payload __flag_payload)) _flag_payload)
  (:serialization-length
   ()
   (+
    ;; string _heartbeat_payload
    4 (length _heartbeat_payload)
    ;; string _run_course_payload
    4 (length _run_course_payload)
    ;; string _follow_payload
    4 (length _follow_payload)
    ;; string _docking_payload
    4 (length _docking_payload)
    ;; string _flag_payload
    4 (length _flag_payload)
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; string _heartbeat_payload
       (write-long (length _heartbeat_payload) s) (princ _heartbeat_payload s)
     ;; string _run_course_payload
       (write-long (length _run_course_payload) s) (princ _run_course_payload s)
     ;; string _follow_payload
       (write-long (length _follow_payload) s) (princ _follow_payload s)
     ;; string _docking_payload
       (write-long (length _docking_payload) s) (princ _docking_payload s)
     ;; string _flag_payload
       (write-long (length _flag_payload) s) (princ _flag_payload s)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; string _heartbeat_payload
     (let (n) (setq n (sys::peek buf ptr- :integer)) (incf ptr- 4) (setq _heartbeat_payload (subseq buf ptr- (+ ptr- n))) (incf ptr- n))
   ;; string _run_course_payload
     (let (n) (setq n (sys::peek buf ptr- :integer)) (incf ptr- 4) (setq _run_course_payload (subseq buf ptr- (+ ptr- n))) (incf ptr- n))
   ;; string _follow_payload
     (let (n) (setq n (sys::peek buf ptr- :integer)) (incf ptr- 4) (setq _follow_payload (subseq buf ptr- (+ ptr- n))) (incf ptr- n))
   ;; string _docking_payload
     (let (n) (setq n (sys::peek buf ptr- :integer)) (incf ptr- 4) (setq _docking_payload (subseq buf ptr- (+ ptr- n))) (incf ptr- n))
   ;; string _flag_payload
     (let (n) (setq n (sys::peek buf ptr- :integer)) (incf ptr- 4) (setq _flag_payload (subseq buf ptr- (+ ptr- n))) (incf ptr- n))
   ;;
   self)
  )

(setf (get kocheng::communication :md5sum-) "892ce67e7b2f9ec2fb90e613344b9551")
(setf (get kocheng::communication :datatype-) "kocheng/communication")
(setf (get kocheng::communication :definition-)
      "string heartbeat_payload
string run_course_payload
string follow_payload
string docking_payload
string flag_payload

")



(provide :kocheng/communication "892ce67e7b2f9ec2fb90e613344b9551")


