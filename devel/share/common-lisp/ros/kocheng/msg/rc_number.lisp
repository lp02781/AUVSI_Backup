; Auto-generated. Do not edit!


(cl:in-package kocheng-msg)


;//! \htmlinclude rc_number.msg.html

(cl:defclass <rc_number> (roslisp-msg-protocol:ros-message)
  ((override_status
    :reader override_status
    :initarg :override_status
    :type cl:boolean
    :initform cl:nil)
   (rc_number
    :reader rc_number
    :initarg :rc_number
    :type cl:fixnum
    :initform 0))
)

(cl:defclass rc_number (<rc_number>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <rc_number>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'rc_number)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name kocheng-msg:<rc_number> is deprecated: use kocheng-msg:rc_number instead.")))

(cl:ensure-generic-function 'override_status-val :lambda-list '(m))
(cl:defmethod override_status-val ((m <rc_number>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader kocheng-msg:override_status-val is deprecated.  Use kocheng-msg:override_status instead.")
  (override_status m))

(cl:ensure-generic-function 'rc_number-val :lambda-list '(m))
(cl:defmethod rc_number-val ((m <rc_number>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader kocheng-msg:rc_number-val is deprecated.  Use kocheng-msg:rc_number instead.")
  (rc_number m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <rc_number>) ostream)
  "Serializes a message object of type '<rc_number>"
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:if (cl:slot-value msg 'override_status) 1 0)) ostream)
  (cl:let* ((signed (cl:slot-value msg 'rc_number)) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 65536) signed)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) unsigned) ostream)
    )
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <rc_number>) istream)
  "Deserializes a message object of type '<rc_number>"
    (cl:setf (cl:slot-value msg 'override_status) (cl:not (cl:zerop (cl:read-byte istream))))
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) unsigned) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'rc_number) (cl:if (cl:< unsigned 32768) unsigned (cl:- unsigned 65536))))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<rc_number>)))
  "Returns string type for a message object of type '<rc_number>"
  "kocheng/rc_number")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'rc_number)))
  "Returns string type for a message object of type 'rc_number"
  "kocheng/rc_number")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<rc_number>)))
  "Returns md5sum for a message object of type '<rc_number>"
  "245976b4840f71d588f1be6b4dde93f8")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'rc_number)))
  "Returns md5sum for a message object of type 'rc_number"
  "245976b4840f71d588f1be6b4dde93f8")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<rc_number>)))
  "Returns full string definition for message of type '<rc_number>"
  (cl:format cl:nil "bool override_status~%int16 rc_number~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'rc_number)))
  "Returns full string definition for message of type 'rc_number"
  (cl:format cl:nil "bool override_status~%int16 rc_number~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <rc_number>))
  (cl:+ 0
     1
     2
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <rc_number>))
  "Converts a ROS message object to a list"
  (cl:list 'rc_number
    (cl:cons ':override_status (override_status msg))
    (cl:cons ':rc_number (rc_number msg))
))
