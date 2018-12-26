; Auto-generated. Do not edit!


(cl:in-package kocheng-msg)


;//! \htmlinclude decode_status.msg.html

(cl:defclass <decode_status> (roslisp-msg-protocol:ros-message)
  ((run_course_status
    :reader run_course_status
    :initarg :run_course_status
    :type cl:integer
    :initform 0)
   (heartbeat_status
    :reader heartbeat_status
    :initarg :heartbeat_status
    :type cl:integer
    :initform 0)
   (follow_status
    :reader follow_status
    :initarg :follow_status
    :type cl:integer
    :initform 0)
   (docking_status
    :reader docking_status
    :initarg :docking_status
    :type cl:integer
    :initform 0))
)

(cl:defclass decode_status (<decode_status>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <decode_status>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'decode_status)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name kocheng-msg:<decode_status> is deprecated: use kocheng-msg:decode_status instead.")))

(cl:ensure-generic-function 'run_course_status-val :lambda-list '(m))
(cl:defmethod run_course_status-val ((m <decode_status>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader kocheng-msg:run_course_status-val is deprecated.  Use kocheng-msg:run_course_status instead.")
  (run_course_status m))

(cl:ensure-generic-function 'heartbeat_status-val :lambda-list '(m))
(cl:defmethod heartbeat_status-val ((m <decode_status>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader kocheng-msg:heartbeat_status-val is deprecated.  Use kocheng-msg:heartbeat_status instead.")
  (heartbeat_status m))

(cl:ensure-generic-function 'follow_status-val :lambda-list '(m))
(cl:defmethod follow_status-val ((m <decode_status>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader kocheng-msg:follow_status-val is deprecated.  Use kocheng-msg:follow_status instead.")
  (follow_status m))

(cl:ensure-generic-function 'docking_status-val :lambda-list '(m))
(cl:defmethod docking_status-val ((m <decode_status>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader kocheng-msg:docking_status-val is deprecated.  Use kocheng-msg:docking_status instead.")
  (docking_status m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <decode_status>) ostream)
  "Serializes a message object of type '<decode_status>"
  (cl:let* ((signed (cl:slot-value msg 'run_course_status)) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 4294967296) signed)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) unsigned) ostream)
    )
  (cl:let* ((signed (cl:slot-value msg 'heartbeat_status)) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 4294967296) signed)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) unsigned) ostream)
    )
  (cl:let* ((signed (cl:slot-value msg 'follow_status)) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 4294967296) signed)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) unsigned) ostream)
    )
  (cl:let* ((signed (cl:slot-value msg 'docking_status)) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 4294967296) signed)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) unsigned) ostream)
    )
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <decode_status>) istream)
  "Deserializes a message object of type '<decode_status>"
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) unsigned) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'run_course_status) (cl:if (cl:< unsigned 2147483648) unsigned (cl:- unsigned 4294967296))))
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) unsigned) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'heartbeat_status) (cl:if (cl:< unsigned 2147483648) unsigned (cl:- unsigned 4294967296))))
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) unsigned) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'follow_status) (cl:if (cl:< unsigned 2147483648) unsigned (cl:- unsigned 4294967296))))
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) unsigned) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'docking_status) (cl:if (cl:< unsigned 2147483648) unsigned (cl:- unsigned 4294967296))))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<decode_status>)))
  "Returns string type for a message object of type '<decode_status>"
  "kocheng/decode_status")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'decode_status)))
  "Returns string type for a message object of type 'decode_status"
  "kocheng/decode_status")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<decode_status>)))
  "Returns md5sum for a message object of type '<decode_status>"
  "a2ff2b7cd0443eeeee765956b8e698bf")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'decode_status)))
  "Returns md5sum for a message object of type 'decode_status"
  "a2ff2b7cd0443eeeee765956b8e698bf")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<decode_status>)))
  "Returns full string definition for message of type '<decode_status>"
  (cl:format cl:nil "int32 run_course_status~%int32 heartbeat_status~%int32 follow_status~%int32 docking_status~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'decode_status)))
  "Returns full string definition for message of type 'decode_status"
  (cl:format cl:nil "int32 run_course_status~%int32 heartbeat_status~%int32 follow_status~%int32 docking_status~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <decode_status>))
  (cl:+ 0
     4
     4
     4
     4
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <decode_status>))
  "Converts a ROS message object to a list"
  (cl:list 'decode_status
    (cl:cons ':run_course_status (run_course_status msg))
    (cl:cons ':heartbeat_status (heartbeat_status msg))
    (cl:cons ':follow_status (follow_status msg))
    (cl:cons ':docking_status (docking_status msg))
))
