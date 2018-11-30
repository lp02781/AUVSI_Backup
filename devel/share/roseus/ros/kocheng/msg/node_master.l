;; Auto-generated. Do not edit!


(when (boundp 'kocheng::node_master)
  (if (not (find-package "KOCHENG"))
    (make-package "KOCHENG"))
  (shadow 'node_master (find-package "KOCHENG")))
(unless (find-package "KOCHENG::NODE_MASTER")
  (make-package "KOCHENG::NODE_MASTER"))

(in-package "ROS")
;;//! \htmlinclude node_master.msg.html


(defclass kocheng::node_master
  :super ros::object
  :slots (_override_status ))

(defmethod kocheng::node_master
  (:init
   (&key
    ((:override_status __override_status) nil)
    )
   (send-super :init)
   (setq _override_status __override_status)
   self)
  (:override_status
   (&optional __override_status)
   (if __override_status (setq _override_status __override_status)) _override_status)
  (:serialization-length
   ()
   (+
    ;; bool _override_status
    1
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; bool _override_status
       (if _override_status (write-byte -1 s) (write-byte 0 s))
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; bool _override_status
     (setq _override_status (not (= 0 (sys::peek buf ptr- :char)))) (incf ptr- 1)
   ;;
   self)
  )

(setf (get kocheng::node_master :md5sum-) "4dd85ad23193e9f5e96775d4f377d490")
(setf (get kocheng::node_master :datatype-) "kocheng/node_master")
(setf (get kocheng::node_master :definition-)
      "bool override_status

")



(provide :kocheng/node_master "4dd85ad23193e9f5e96775d4f377d490")


