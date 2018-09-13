;; Auto-generated. Do not edit!


(when (boundp 'roboboat::image_process)
  (if (not (find-package "ROBOBOAT"))
    (make-package "ROBOBOAT"))
  (shadow 'image_process (find-package "ROBOBOAT")))
(unless (find-package "ROBOBOAT::IMAGE_PROCESS")
  (make-package "ROBOBOAT::IMAGE_PROCESS"))

(in-package "ROS")
;;//! \htmlinclude image_process.msg.html


(defclass roboboat::image_process
  :super ros::object
  :slots (_buoy_red _buoy_green _buoy_blue _gate_red _gate_green _x_flag _y_flag _dock_one _dock_two _dock_three ))

(defmethod roboboat::image_process
  (:init
   (&key
    ((:buoy_red __buoy_red) 0)
    ((:buoy_green __buoy_green) 0)
    ((:buoy_blue __buoy_blue) 0)
    ((:gate_red __gate_red) 0)
    ((:gate_green __gate_green) 0)
    ((:x_flag __x_flag) 0)
    ((:y_flag __y_flag) 0)
    ((:dock_one __dock_one) 0)
    ((:dock_two __dock_two) 0)
    ((:dock_three __dock_three) 0)
    )
   (send-super :init)
   (setq _buoy_red (round __buoy_red))
   (setq _buoy_green (round __buoy_green))
   (setq _buoy_blue (round __buoy_blue))
   (setq _gate_red (round __gate_red))
   (setq _gate_green (round __gate_green))
   (setq _x_flag (round __x_flag))
   (setq _y_flag (round __y_flag))
   (setq _dock_one (round __dock_one))
   (setq _dock_two (round __dock_two))
   (setq _dock_three (round __dock_three))
   self)
  (:buoy_red
   (&optional __buoy_red)
   (if __buoy_red (setq _buoy_red __buoy_red)) _buoy_red)
  (:buoy_green
   (&optional __buoy_green)
   (if __buoy_green (setq _buoy_green __buoy_green)) _buoy_green)
  (:buoy_blue
   (&optional __buoy_blue)
   (if __buoy_blue (setq _buoy_blue __buoy_blue)) _buoy_blue)
  (:gate_red
   (&optional __gate_red)
   (if __gate_red (setq _gate_red __gate_red)) _gate_red)
  (:gate_green
   (&optional __gate_green)
   (if __gate_green (setq _gate_green __gate_green)) _gate_green)
  (:x_flag
   (&optional __x_flag)
   (if __x_flag (setq _x_flag __x_flag)) _x_flag)
  (:y_flag
   (&optional __y_flag)
   (if __y_flag (setq _y_flag __y_flag)) _y_flag)
  (:dock_one
   (&optional __dock_one)
   (if __dock_one (setq _dock_one __dock_one)) _dock_one)
  (:dock_two
   (&optional __dock_two)
   (if __dock_two (setq _dock_two __dock_two)) _dock_two)
  (:dock_three
   (&optional __dock_three)
   (if __dock_three (setq _dock_three __dock_three)) _dock_three)
  (:serialization-length
   ()
   (+
    ;; int16 _buoy_red
    2
    ;; int16 _buoy_green
    2
    ;; int16 _buoy_blue
    2
    ;; int16 _gate_red
    2
    ;; int16 _gate_green
    2
    ;; int16 _x_flag
    2
    ;; int16 _y_flag
    2
    ;; int16 _dock_one
    2
    ;; int16 _dock_two
    2
    ;; int16 _dock_three
    2
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; int16 _buoy_red
       (write-word _buoy_red s)
     ;; int16 _buoy_green
       (write-word _buoy_green s)
     ;; int16 _buoy_blue
       (write-word _buoy_blue s)
     ;; int16 _gate_red
       (write-word _gate_red s)
     ;; int16 _gate_green
       (write-word _gate_green s)
     ;; int16 _x_flag
       (write-word _x_flag s)
     ;; int16 _y_flag
       (write-word _y_flag s)
     ;; int16 _dock_one
       (write-word _dock_one s)
     ;; int16 _dock_two
       (write-word _dock_two s)
     ;; int16 _dock_three
       (write-word _dock_three s)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; int16 _buoy_red
     (setq _buoy_red (sys::peek buf ptr- :short)) (incf ptr- 2)
   ;; int16 _buoy_green
     (setq _buoy_green (sys::peek buf ptr- :short)) (incf ptr- 2)
   ;; int16 _buoy_blue
     (setq _buoy_blue (sys::peek buf ptr- :short)) (incf ptr- 2)
   ;; int16 _gate_red
     (setq _gate_red (sys::peek buf ptr- :short)) (incf ptr- 2)
   ;; int16 _gate_green
     (setq _gate_green (sys::peek buf ptr- :short)) (incf ptr- 2)
   ;; int16 _x_flag
     (setq _x_flag (sys::peek buf ptr- :short)) (incf ptr- 2)
   ;; int16 _y_flag
     (setq _y_flag (sys::peek buf ptr- :short)) (incf ptr- 2)
   ;; int16 _dock_one
     (setq _dock_one (sys::peek buf ptr- :short)) (incf ptr- 2)
   ;; int16 _dock_two
     (setq _dock_two (sys::peek buf ptr- :short)) (incf ptr- 2)
   ;; int16 _dock_three
     (setq _dock_three (sys::peek buf ptr- :short)) (incf ptr- 2)
   ;;
   self)
  )

(setf (get roboboat::image_process :md5sum-) "f2466f92f806c6e64e91ea6278fe0b11")
(setf (get roboboat::image_process :datatype-) "roboboat/image_process")
(setf (get roboboat::image_process :definition-)
      "int16 buoy_red
int16 buoy_green
int16 buoy_blue
int16 gate_red
int16 gate_green
int16 x_flag
int16 y_flag
int16 dock_one
int16 dock_two
int16 dock_three

")



(provide :roboboat/image_process "f2466f92f806c6e64e91ea6278fe0b11")


