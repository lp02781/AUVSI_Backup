; Auto-generated. Do not edit!


(cl:in-package kocheng-msg)


;//! \htmlinclude override_value.msg.html

(cl:defclass <override_value> (roslisp-msg-protocol:ros-message)
  ((steering
    :reader steering
    :initarg :steering
    :type cl:fixnum
    :initform 0)
   (throttle
    :reader throttle
    :initarg :throttle
    :type cl:fixnum
    :initform 0)
   (camera_servo
    :reader camera_servo
    :initarg :camera_servo
    :type cl:fixnum
    :initform 0))
)

(cl:defclass override_value (<override_value>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <override_value>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'override_value)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name kocheng-msg:<override_value> is deprecated: use kocheng-msg:override_value instead.")))

(cl:ensure-generic-function 'steering-val :lambda-list '(m))
(cl:defmethod steering-val ((m <override_value>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader kocheng-msg:steering-val is deprecated.  Use kocheng-msg:steering instead.")
  (steering m))

(cl:ensure-generic-function 'throttle-val :lambda-list '(m))
(cl:defmethod throttle-val ((m <override_value>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader kocheng-msg:throttle-val is deprecated.  Use kocheng-msg:throttle instead.")
  (throttle m))

(cl:ensure-generic-function 'camera_servo-val :lambda-list '(m))
(cl:defmethod camera_servo-val ((m <override_value>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader kocheng-msg:camera_servo-val is deprecated.  Use kocheng-msg:camera_servo instead.")
  (camera_servo m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <override_value>) ostream)
  "Serializes a message object of type '<override_value>"
  (cl:let* ((signed (cl:slot-value msg 'steering)) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 65536) signed)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) unsigned) ostream)
    )
  (cl:let* ((signed (cl:slot-value msg 'throttle)) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 65536) signed)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) unsigned) ostream)
    )
  (cl:let* ((signed (cl:slot-value msg 'camera_servo)) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 65536) signed)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) unsigned) ostream)
    )
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <override_value>) istream)
  "Deserializes a message object of type '<override_value>"
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) unsigned) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'steering) (cl:if (cl:< unsigned 32768) unsigned (cl:- unsigned 65536))))
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) unsigned) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'throttle) (cl:if (cl:< unsigned 32768) unsigned (cl:- unsigned 65536))))
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) unsigned) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'camera_servo) (cl:if (cl:< unsigned 32768) unsigned (cl:- unsigned 65536))))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<override_value>)))
  "Returns string type for a message object of type '<override_value>"
  "kocheng/override_value")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'override_value)))
  "Returns string type for a message object of type 'override_value"
  "kocheng/override_value")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<override_value>)))
  "Returns md5sum for a message object of type '<override_value>"
  "8b817f7d8452ec829c7dc50e436e6bd8")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'override_value)))
  "Returns md5sum for a message object of type 'override_value"
  "8b817f7d8452ec829c7dc50e436e6bd8")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<override_value>)))
  "Returns full string definition for message of type '<override_value>"
  (cl:format cl:nil "int16 steering~%int16 throttle~%int16 camera_servo~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'override_value)))
  "Returns full string definition for message of type 'override_value"
  (cl:format cl:nil "int16 steering~%int16 throttle~%int16 camera_servo~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <override_value>))
  (cl:+ 0
     2
     2
     2
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <override_value>))
  "Converts a ROS message object to a list"
  (cl:list 'override_value
    (cl:cons ':steering (steering msg))
    (cl:cons ':throttle (throttle msg))
    (cl:cons ':camera_servo (camera_servo msg))
))
