; Auto-generated. Do not edit!


(cl:in-package roboboat-msg)


;//! \htmlinclude node_status.msg.html

(cl:defclass <node_status> (roslisp-msg-protocol:ros-message)
  ((override_status
    :reader override_status
    :initarg :override_status
    :type cl:boolean
    :initform cl:nil)
   (image_front_status
    :reader image_front_status
    :initarg :image_front_status
    :type cl:boolean
    :initform cl:nil)
   (image_back_status
    :reader image_back_status
    :initarg :image_back_status
    :type cl:boolean
    :initform cl:nil)
   (green_hough_status
    :reader green_hough_status
    :initarg :green_hough_status
    :type cl:boolean
    :initform cl:nil)
   (red_hough_status
    :reader red_hough_status
    :initarg :red_hough_status
    :type cl:boolean
    :initform cl:nil)
   (blue_hough_status
    :reader blue_hough_status
    :initarg :blue_hough_status
    :type cl:boolean
    :initform cl:nil))
)

(cl:defclass node_status (<node_status>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <node_status>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'node_status)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name roboboat-msg:<node_status> is deprecated: use roboboat-msg:node_status instead.")))

(cl:ensure-generic-function 'override_status-val :lambda-list '(m))
(cl:defmethod override_status-val ((m <node_status>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader roboboat-msg:override_status-val is deprecated.  Use roboboat-msg:override_status instead.")
  (override_status m))

(cl:ensure-generic-function 'image_front_status-val :lambda-list '(m))
(cl:defmethod image_front_status-val ((m <node_status>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader roboboat-msg:image_front_status-val is deprecated.  Use roboboat-msg:image_front_status instead.")
  (image_front_status m))

(cl:ensure-generic-function 'image_back_status-val :lambda-list '(m))
(cl:defmethod image_back_status-val ((m <node_status>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader roboboat-msg:image_back_status-val is deprecated.  Use roboboat-msg:image_back_status instead.")
  (image_back_status m))

(cl:ensure-generic-function 'green_hough_status-val :lambda-list '(m))
(cl:defmethod green_hough_status-val ((m <node_status>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader roboboat-msg:green_hough_status-val is deprecated.  Use roboboat-msg:green_hough_status instead.")
  (green_hough_status m))

(cl:ensure-generic-function 'red_hough_status-val :lambda-list '(m))
(cl:defmethod red_hough_status-val ((m <node_status>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader roboboat-msg:red_hough_status-val is deprecated.  Use roboboat-msg:red_hough_status instead.")
  (red_hough_status m))

(cl:ensure-generic-function 'blue_hough_status-val :lambda-list '(m))
(cl:defmethod blue_hough_status-val ((m <node_status>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader roboboat-msg:blue_hough_status-val is deprecated.  Use roboboat-msg:blue_hough_status instead.")
  (blue_hough_status m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <node_status>) ostream)
  "Serializes a message object of type '<node_status>"
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:if (cl:slot-value msg 'override_status) 1 0)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:if (cl:slot-value msg 'image_front_status) 1 0)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:if (cl:slot-value msg 'image_back_status) 1 0)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:if (cl:slot-value msg 'green_hough_status) 1 0)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:if (cl:slot-value msg 'red_hough_status) 1 0)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:if (cl:slot-value msg 'blue_hough_status) 1 0)) ostream)
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <node_status>) istream)
  "Deserializes a message object of type '<node_status>"
    (cl:setf (cl:slot-value msg 'override_status) (cl:not (cl:zerop (cl:read-byte istream))))
    (cl:setf (cl:slot-value msg 'image_front_status) (cl:not (cl:zerop (cl:read-byte istream))))
    (cl:setf (cl:slot-value msg 'image_back_status) (cl:not (cl:zerop (cl:read-byte istream))))
    (cl:setf (cl:slot-value msg 'green_hough_status) (cl:not (cl:zerop (cl:read-byte istream))))
    (cl:setf (cl:slot-value msg 'red_hough_status) (cl:not (cl:zerop (cl:read-byte istream))))
    (cl:setf (cl:slot-value msg 'blue_hough_status) (cl:not (cl:zerop (cl:read-byte istream))))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<node_status>)))
  "Returns string type for a message object of type '<node_status>"
  "roboboat/node_status")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'node_status)))
  "Returns string type for a message object of type 'node_status"
  "roboboat/node_status")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<node_status>)))
  "Returns md5sum for a message object of type '<node_status>"
  "d36a6a4442f3498759f12ca2b580445e")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'node_status)))
  "Returns md5sum for a message object of type 'node_status"
  "d36a6a4442f3498759f12ca2b580445e")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<node_status>)))
  "Returns full string definition for message of type '<node_status>"
  (cl:format cl:nil "bool override_status~%bool image_front_status~%bool image_back_status~%bool green_hough_status~%bool red_hough_status~%bool blue_hough_status~%~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'node_status)))
  "Returns full string definition for message of type 'node_status"
  (cl:format cl:nil "bool override_status~%bool image_front_status~%bool image_back_status~%bool green_hough_status~%bool red_hough_status~%bool blue_hough_status~%~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <node_status>))
  (cl:+ 0
     1
     1
     1
     1
     1
     1
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <node_status>))
  "Converts a ROS message object to a list"
  (cl:list 'node_status
    (cl:cons ':override_status (override_status msg))
    (cl:cons ':image_front_status (image_front_status msg))
    (cl:cons ':image_back_status (image_back_status msg))
    (cl:cons ':green_hough_status (green_hough_status msg))
    (cl:cons ':red_hough_status (red_hough_status msg))
    (cl:cons ':blue_hough_status (blue_hough_status msg))
))
