;; Auto-generated. Do not edit!


(when (boundp 'kocheng::image_in)
  (if (not (find-package "KOCHENG"))
    (make-package "KOCHENG"))
  (shadow 'image_in (find-package "KOCHENG")))
(unless (find-package "KOCHENG::IMAGE_IN")
  (make-package "KOCHENG::IMAGE_IN"))

(in-package "ROS")
;;//! \htmlinclude image_in.msg.html


(defclass kocheng::image_in
  :super ros::object
  :slots (_x_init _y_init _width _height _LowH _HighH _LowS _HighS _LowV _HighV _Noise ))

(defmethod kocheng::image_in
  (:init
   (&key
    ((:x_init __x_init) 0)
    ((:y_init __y_init) 0)
    ((:width __width) 0)
    ((:height __height) 0)
    ((:LowH __LowH) 0)
    ((:HighH __HighH) 0)
    ((:LowS __LowS) 0)
    ((:HighS __HighS) 0)
    ((:LowV __LowV) 0)
    ((:HighV __HighV) 0)
    ((:Noise __Noise) 0)
    )
   (send-super :init)
   (setq _x_init (round __x_init))
   (setq _y_init (round __y_init))
   (setq _width (round __width))
   (setq _height (round __height))
   (setq _LowH (round __LowH))
   (setq _HighH (round __HighH))
   (setq _LowS (round __LowS))
   (setq _HighS (round __HighS))
   (setq _LowV (round __LowV))
   (setq _HighV (round __HighV))
   (setq _Noise (round __Noise))
   self)
  (:x_init
   (&optional __x_init)
   (if __x_init (setq _x_init __x_init)) _x_init)
  (:y_init
   (&optional __y_init)
   (if __y_init (setq _y_init __y_init)) _y_init)
  (:width
   (&optional __width)
   (if __width (setq _width __width)) _width)
  (:height
   (&optional __height)
   (if __height (setq _height __height)) _height)
  (:LowH
   (&optional __LowH)
   (if __LowH (setq _LowH __LowH)) _LowH)
  (:HighH
   (&optional __HighH)
   (if __HighH (setq _HighH __HighH)) _HighH)
  (:LowS
   (&optional __LowS)
   (if __LowS (setq _LowS __LowS)) _LowS)
  (:HighS
   (&optional __HighS)
   (if __HighS (setq _HighS __HighS)) _HighS)
  (:LowV
   (&optional __LowV)
   (if __LowV (setq _LowV __LowV)) _LowV)
  (:HighV
   (&optional __HighV)
   (if __HighV (setq _HighV __HighV)) _HighV)
  (:Noise
   (&optional __Noise)
   (if __Noise (setq _Noise __Noise)) _Noise)
  (:serialization-length
   ()
   (+
    ;; int32 _x_init
    4
    ;; int32 _y_init
    4
    ;; int32 _width
    4
    ;; int32 _height
    4
    ;; int32 _LowH
    4
    ;; int32 _HighH
    4
    ;; int32 _LowS
    4
    ;; int32 _HighS
    4
    ;; int32 _LowV
    4
    ;; int32 _HighV
    4
    ;; int32 _Noise
    4
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; int32 _x_init
       (write-long _x_init s)
     ;; int32 _y_init
       (write-long _y_init s)
     ;; int32 _width
       (write-long _width s)
     ;; int32 _height
       (write-long _height s)
     ;; int32 _LowH
       (write-long _LowH s)
     ;; int32 _HighH
       (write-long _HighH s)
     ;; int32 _LowS
       (write-long _LowS s)
     ;; int32 _HighS
       (write-long _HighS s)
     ;; int32 _LowV
       (write-long _LowV s)
     ;; int32 _HighV
       (write-long _HighV s)
     ;; int32 _Noise
       (write-long _Noise s)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; int32 _x_init
     (setq _x_init (sys::peek buf ptr- :integer)) (incf ptr- 4)
   ;; int32 _y_init
     (setq _y_init (sys::peek buf ptr- :integer)) (incf ptr- 4)
   ;; int32 _width
     (setq _width (sys::peek buf ptr- :integer)) (incf ptr- 4)
   ;; int32 _height
     (setq _height (sys::peek buf ptr- :integer)) (incf ptr- 4)
   ;; int32 _LowH
     (setq _LowH (sys::peek buf ptr- :integer)) (incf ptr- 4)
   ;; int32 _HighH
     (setq _HighH (sys::peek buf ptr- :integer)) (incf ptr- 4)
   ;; int32 _LowS
     (setq _LowS (sys::peek buf ptr- :integer)) (incf ptr- 4)
   ;; int32 _HighS
     (setq _HighS (sys::peek buf ptr- :integer)) (incf ptr- 4)
   ;; int32 _LowV
     (setq _LowV (sys::peek buf ptr- :integer)) (incf ptr- 4)
   ;; int32 _HighV
     (setq _HighV (sys::peek buf ptr- :integer)) (incf ptr- 4)
   ;; int32 _Noise
     (setq _Noise (sys::peek buf ptr- :integer)) (incf ptr- 4)
   ;;
   self)
  )

(setf (get kocheng::image_in :md5sum-) "98a894c5a1e69900105970008d648417")
(setf (get kocheng::image_in :datatype-) "kocheng/image_in")
(setf (get kocheng::image_in :definition-)
      "int32 x_init
int32 y_init
int32 width
int32 height
int32 LowH 
int32 HighH
int32 LowS
int32 HighS
int32 LowV
int32 HighV
int32 Noise

")



(provide :kocheng/image_in "98a894c5a1e69900105970008d648417")


