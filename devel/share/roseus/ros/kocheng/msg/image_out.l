;; Auto-generated. Do not edit!


(when (boundp 'kocheng::image_out)
  (if (not (find-package "KOCHENG"))
    (make-package "KOCHENG"))
  (shadow 'image_out (find-package "KOCHENG")))
(unless (find-package "KOCHENG::IMAGE_OUT")
  (make-package "KOCHENG::IMAGE_OUT"))

(in-package "ROS")
;;//! \htmlinclude image_out.msg.html


(defclass kocheng::image_out
  :super ros::object
  :slots (_state_x _state_y _count ))

(defmethod kocheng::image_out
  (:init
   (&key
    ((:state_x __state_x) 0)
    ((:state_y __state_y) 0)
    ((:count __count) 0)
    )
   (send-super :init)
   (setq _state_x (round __state_x))
   (setq _state_y (round __state_y))
   (setq _count (round __count))
   self)
  (:state_x
   (&optional __state_x)
   (if __state_x (setq _state_x __state_x)) _state_x)
  (:state_y
   (&optional __state_y)
   (if __state_y (setq _state_y __state_y)) _state_y)
  (:count
   (&optional __count)
   (if __count (setq _count __count)) _count)
  (:serialization-length
   ()
   (+
    ;; int32 _state_x
    4
    ;; int32 _state_y
    4
    ;; int32 _count
    4
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; int32 _state_x
       (write-long _state_x s)
     ;; int32 _state_y
       (write-long _state_y s)
     ;; int32 _count
       (write-long _count s)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; int32 _state_x
     (setq _state_x (sys::peek buf ptr- :integer)) (incf ptr- 4)
   ;; int32 _state_y
     (setq _state_y (sys::peek buf ptr- :integer)) (incf ptr- 4)
   ;; int32 _count
     (setq _count (sys::peek buf ptr- :integer)) (incf ptr- 4)
   ;;
   self)
  )

(setf (get kocheng::image_out :md5sum-) "46ace0b0293b73ffe37427e1226523ef")
(setf (get kocheng::image_out :datatype-) "kocheng/image_out")
(setf (get kocheng::image_out :definition-)
      "int32 state_x
int32 state_y
int32 count

")



(provide :kocheng/image_out "46ace0b0293b73ffe37427e1226523ef")


