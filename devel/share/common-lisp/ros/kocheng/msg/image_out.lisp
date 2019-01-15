; Auto-generated. Do not edit!


(cl:in-package kocheng-msg)


;//! \htmlinclude image_out.msg.html

(cl:defclass <image_out> (roslisp-msg-protocol:ros-message)
  ((state_x
    :reader state_x
    :initarg :state_x
    :type cl:integer
    :initform 0)
   (state_y
    :reader state_y
    :initarg :state_y
    :type cl:integer
    :initform 0)
   (count
    :reader count
    :initarg :count
    :type cl:integer
    :initform 0))
)

(cl:defclass image_out (<image_out>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <image_out>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'image_out)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name kocheng-msg:<image_out> is deprecated: use kocheng-msg:image_out instead.")))

(cl:ensure-generic-function 'state_x-val :lambda-list '(m))
(cl:defmethod state_x-val ((m <image_out>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader kocheng-msg:state_x-val is deprecated.  Use kocheng-msg:state_x instead.")
  (state_x m))

(cl:ensure-generic-function 'state_y-val :lambda-list '(m))
(cl:defmethod state_y-val ((m <image_out>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader kocheng-msg:state_y-val is deprecated.  Use kocheng-msg:state_y instead.")
  (state_y m))

(cl:ensure-generic-function 'count-val :lambda-list '(m))
(cl:defmethod count-val ((m <image_out>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader kocheng-msg:count-val is deprecated.  Use kocheng-msg:count instead.")
  (count m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <image_out>) ostream)
  "Serializes a message object of type '<image_out>"
  (cl:let* ((signed (cl:slot-value msg 'state_x)) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 4294967296) signed)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) unsigned) ostream)
    )
  (cl:let* ((signed (cl:slot-value msg 'state_y)) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 4294967296) signed)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) unsigned) ostream)
    )
  (cl:let* ((signed (cl:slot-value msg 'count)) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 4294967296) signed)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) unsigned) ostream)
    )
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <image_out>) istream)
  "Deserializes a message object of type '<image_out>"
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) unsigned) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'state_x) (cl:if (cl:< unsigned 2147483648) unsigned (cl:- unsigned 4294967296))))
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) unsigned) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'state_y) (cl:if (cl:< unsigned 2147483648) unsigned (cl:- unsigned 4294967296))))
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) unsigned) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'count) (cl:if (cl:< unsigned 2147483648) unsigned (cl:- unsigned 4294967296))))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<image_out>)))
  "Returns string type for a message object of type '<image_out>"
  "kocheng/image_out")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'image_out)))
  "Returns string type for a message object of type 'image_out"
  "kocheng/image_out")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<image_out>)))
  "Returns md5sum for a message object of type '<image_out>"
  "46ace0b0293b73ffe37427e1226523ef")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'image_out)))
  "Returns md5sum for a message object of type 'image_out"
  "46ace0b0293b73ffe37427e1226523ef")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<image_out>)))
  "Returns full string definition for message of type '<image_out>"
  (cl:format cl:nil "int32 state_x~%int32 state_y~%int32 count~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'image_out)))
  "Returns full string definition for message of type 'image_out"
  (cl:format cl:nil "int32 state_x~%int32 state_y~%int32 count~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <image_out>))
  (cl:+ 0
     4
     4
     4
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <image_out>))
  "Converts a ROS message object to a list"
  (cl:list 'image_out
    (cl:cons ':state_x (state_x msg))
    (cl:cons ':state_y (state_y msg))
    (cl:cons ':count (count msg))
))
