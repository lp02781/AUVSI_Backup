;; Auto-generated. Do not edit!


(when (boundp 'roboboat::node_status)
  (if (not (find-package "ROBOBOAT"))
    (make-package "ROBOBOAT"))
  (shadow 'node_status (find-package "ROBOBOAT")))
(unless (find-package "ROBOBOAT::NODE_STATUS")
  (make-package "ROBOBOAT::NODE_STATUS"))

(in-package "ROS")
;;//! \htmlinclude node_status.msg.html


(defclass roboboat::node_status
  :super ros::object
  :slots (_override_status _image_front_status _image_back_status _green_hough_status _red_hough_status _blue_hough_status ))

(defmethod roboboat::node_status
  (:init
   (&key
    ((:override_status __override_status) nil)
    ((:image_front_status __image_front_status) nil)
    ((:image_back_status __image_back_status) nil)
    ((:green_hough_status __green_hough_status) nil)
    ((:red_hough_status __red_hough_status) nil)
    ((:blue_hough_status __blue_hough_status) nil)
    )
   (send-super :init)
   (setq _override_status __override_status)
   (setq _image_front_status __image_front_status)
   (setq _image_back_status __image_back_status)
   (setq _green_hough_status __green_hough_status)
   (setq _red_hough_status __red_hough_status)
   (setq _blue_hough_status __blue_hough_status)
   self)
  (:override_status
   (&optional __override_status)
   (if __override_status (setq _override_status __override_status)) _override_status)
  (:image_front_status
   (&optional __image_front_status)
   (if __image_front_status (setq _image_front_status __image_front_status)) _image_front_status)
  (:image_back_status
   (&optional __image_back_status)
   (if __image_back_status (setq _image_back_status __image_back_status)) _image_back_status)
  (:green_hough_status
   (&optional __green_hough_status)
   (if __green_hough_status (setq _green_hough_status __green_hough_status)) _green_hough_status)
  (:red_hough_status
   (&optional __red_hough_status)
   (if __red_hough_status (setq _red_hough_status __red_hough_status)) _red_hough_status)
  (:blue_hough_status
   (&optional __blue_hough_status)
   (if __blue_hough_status (setq _blue_hough_status __blue_hough_status)) _blue_hough_status)
  (:serialization-length
   ()
   (+
    ;; bool _override_status
    1
    ;; bool _image_front_status
    1
    ;; bool _image_back_status
    1
    ;; bool _green_hough_status
    1
    ;; bool _red_hough_status
    1
    ;; bool _blue_hough_status
    1
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; bool _override_status
       (if _override_status (write-byte -1 s) (write-byte 0 s))
     ;; bool _image_front_status
       (if _image_front_status (write-byte -1 s) (write-byte 0 s))
     ;; bool _image_back_status
       (if _image_back_status (write-byte -1 s) (write-byte 0 s))
     ;; bool _green_hough_status
       (if _green_hough_status (write-byte -1 s) (write-byte 0 s))
     ;; bool _red_hough_status
       (if _red_hough_status (write-byte -1 s) (write-byte 0 s))
     ;; bool _blue_hough_status
       (if _blue_hough_status (write-byte -1 s) (write-byte 0 s))
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; bool _override_status
     (setq _override_status (not (= 0 (sys::peek buf ptr- :char)))) (incf ptr- 1)
   ;; bool _image_front_status
     (setq _image_front_status (not (= 0 (sys::peek buf ptr- :char)))) (incf ptr- 1)
   ;; bool _image_back_status
     (setq _image_back_status (not (= 0 (sys::peek buf ptr- :char)))) (incf ptr- 1)
   ;; bool _green_hough_status
     (setq _green_hough_status (not (= 0 (sys::peek buf ptr- :char)))) (incf ptr- 1)
   ;; bool _red_hough_status
     (setq _red_hough_status (not (= 0 (sys::peek buf ptr- :char)))) (incf ptr- 1)
   ;; bool _blue_hough_status
     (setq _blue_hough_status (not (= 0 (sys::peek buf ptr- :char)))) (incf ptr- 1)
   ;;
   self)
  )

(setf (get roboboat::node_status :md5sum-) "d36a6a4442f3498759f12ca2b580445e")
(setf (get roboboat::node_status :datatype-) "roboboat/node_status")
(setf (get roboboat::node_status :definition-)
      "bool override_status
bool image_front_status
bool image_back_status
bool green_hough_status
bool red_hough_status
bool blue_hough_status


")



(provide :roboboat/node_status "d36a6a4442f3498759f12ca2b580445e")


