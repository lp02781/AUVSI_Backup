;; Auto-generated. Do not edit!


(when (boundp 'kocheng::com_auvsi)
  (if (not (find-package "KOCHENG"))
    (make-package "KOCHENG"))
  (shadow 'com_auvsi (find-package "KOCHENG")))
(unless (find-package "KOCHENG::COM_AUVSI")
  (make-package "KOCHENG::COM_AUVSI"))

(in-package "ROS")
;;//! \htmlinclude com_auvsi.msg.html


(defclass kocheng::com_auvsi
  :super ros::object
  :slots (_mission_makara ))

(defmethod kocheng::com_auvsi
  (:init
   (&key
    ((:mission_makara __mission_makara) "")
    )
   (send-super :init)
   (setq _mission_makara (string __mission_makara))
   self)
  (:mission_makara
   (&optional __mission_makara)
   (if __mission_makara (setq _mission_makara __mission_makara)) _mission_makara)
  (:serialization-length
   ()
   (+
    ;; string _mission_makara
    4 (length _mission_makara)
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; string _mission_makara
       (write-long (length _mission_makara) s) (princ _mission_makara s)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; string _mission_makara
     (let (n) (setq n (sys::peek buf ptr- :integer)) (incf ptr- 4) (setq _mission_makara (subseq buf ptr- (+ ptr- n))) (incf ptr- n))
   ;;
   self)
  )

(setf (get kocheng::com_auvsi :md5sum-) "2e7801e6e1d9e6d8720e1966e071032b")
(setf (get kocheng::com_auvsi :datatype-) "kocheng/com_auvsi")
(setf (get kocheng::com_auvsi :definition-)
      "string mission_makara

")



(provide :kocheng/com_auvsi "2e7801e6e1d9e6d8720e1966e071032b")


