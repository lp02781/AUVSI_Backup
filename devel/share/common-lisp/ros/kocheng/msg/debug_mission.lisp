; Auto-generated. Do not edit!


(cl:in-package kocheng-msg)


;//! \htmlinclude debug_mission.msg.html

(cl:defclass <debug_mission> (roslisp-msg-protocol:ros-message)
  ((longitude
    :reader longitude
    :initarg :longitude
    :type cl:float
    :initform 0.0)
   (latitude
    :reader latitude
    :initarg :latitude
    :type cl:float
    :initform 0.0))
)

(cl:defclass debug_mission (<debug_mission>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <debug_mission>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'debug_mission)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name kocheng-msg:<debug_mission> is deprecated: use kocheng-msg:debug_mission instead.")))

(cl:ensure-generic-function 'longitude-val :lambda-list '(m))
(cl:defmethod longitude-val ((m <debug_mission>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader kocheng-msg:longitude-val is deprecated.  Use kocheng-msg:longitude instead.")
  (longitude m))

(cl:ensure-generic-function 'latitude-val :lambda-list '(m))
(cl:defmethod latitude-val ((m <debug_mission>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader kocheng-msg:latitude-val is deprecated.  Use kocheng-msg:latitude instead.")
  (latitude m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <debug_mission>) ostream)
  "Serializes a message object of type '<debug_mission>"
  (cl:let ((bits (roslisp-utils:encode-single-float-bits (cl:slot-value msg 'longitude))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream))
  (cl:let ((bits (roslisp-utils:encode-single-float-bits (cl:slot-value msg 'latitude))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream))
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <debug_mission>) istream)
  "Deserializes a message object of type '<debug_mission>"
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'longitude) (roslisp-utils:decode-single-float-bits bits)))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'latitude) (roslisp-utils:decode-single-float-bits bits)))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<debug_mission>)))
  "Returns string type for a message object of type '<debug_mission>"
  "kocheng/debug_mission")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'debug_mission)))
  "Returns string type for a message object of type 'debug_mission"
  "kocheng/debug_mission")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<debug_mission>)))
  "Returns md5sum for a message object of type '<debug_mission>"
  "826f8fcadfa8742a6495798d3978624a")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'debug_mission)))
  "Returns md5sum for a message object of type 'debug_mission"
  "826f8fcadfa8742a6495798d3978624a")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<debug_mission>)))
  "Returns full string definition for message of type '<debug_mission>"
  (cl:format cl:nil "float32 longitude~%float32 latitude~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'debug_mission)))
  "Returns full string definition for message of type 'debug_mission"
  (cl:format cl:nil "float32 longitude~%float32 latitude~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <debug_mission>))
  (cl:+ 0
     4
     4
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <debug_mission>))
  "Converts a ROS message object to a list"
  (cl:list 'debug_mission
    (cl:cons ':longitude (longitude msg))
    (cl:cons ':latitude (latitude msg))
))
