;; Auto-generated. Do not edit!


(when (boundp 'kocheng::drone_kocheng)
  (if (not (find-package "KOCHENG"))
    (make-package "KOCHENG"))
  (shadow 'drone_kocheng (find-package "KOCHENG")))
(unless (find-package "KOCHENG::DRONE_KOCHENG")
  (make-package "KOCHENG::DRONE_KOCHENG"))

(in-package "ROS")
;;//! \htmlinclude drone_kocheng.msg.html


(defclass kocheng::drone_kocheng
  :super ros::object
  :slots (_drone_status ))

(defmethod kocheng::drone_kocheng
  (:init
   (&key
    ((:drone_status __drone_status) "")
    )
   (send-super :init)
   (setq _drone_status (string __drone_status))
   self)
  (:drone_status
   (&optional __drone_status)
   (if __drone_status (setq _drone_status __drone_status)) _drone_status)
  (:serialization-length
   ()
   (+
    ;; string _drone_status
    4 (length _drone_status)
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; string _drone_status
       (write-long (length _drone_status) s) (princ _drone_status s)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; string _drone_status
     (let (n) (setq n (sys::peek buf ptr- :integer)) (incf ptr- 4) (setq _drone_status (subseq buf ptr- (+ ptr- n))) (incf ptr- n))
   ;;
   self)
  )

(setf (get kocheng::drone_kocheng :md5sum-) "2c7c5edf7dfbe4935f6f975fe743924d")
(setf (get kocheng::drone_kocheng :datatype-) "kocheng/drone_kocheng")
(setf (get kocheng::drone_kocheng :definition-)
      "string drone_status

")



(provide :kocheng/drone_kocheng "2c7c5edf7dfbe4935f6f975fe743924d")


