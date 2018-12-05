; Auto-generated. Do not edit!


(cl:in-package kocheng-msg)


;//! \htmlinclude nav_msgs.msg.html

(cl:defclass <nav_msgs> (roslisp-msg-protocol:ros-message)
  ((setpoint
    :reader setpoint
    :initarg :setpoint
    :type cl:fixnum
    :initform 0)
   (state
    :reader state
    :initarg :state
    :type cl:fixnum
    :initform 0)
   (effort
    :reader effort
    :initarg :effort
    :type cl:fixnum
    :initform 0))
)

(cl:defclass nav_msgs (<nav_msgs>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <nav_msgs>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'nav_msgs)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name kocheng-msg:<nav_msgs> is deprecated: use kocheng-msg:nav_msgs instead.")))

(cl:ensure-generic-function 'setpoint-val :lambda-list '(m))
(cl:defmethod setpoint-val ((m <nav_msgs>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader kocheng-msg:setpoint-val is deprecated.  Use kocheng-msg:setpoint instead.")
  (setpoint m))

(cl:ensure-generic-function 'state-val :lambda-list '(m))
(cl:defmethod state-val ((m <nav_msgs>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader kocheng-msg:state-val is deprecated.  Use kocheng-msg:state instead.")
  (state m))

(cl:ensure-generic-function 'effort-val :lambda-list '(m))
(cl:defmethod effort-val ((m <nav_msgs>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader kocheng-msg:effort-val is deprecated.  Use kocheng-msg:effort instead.")
  (effort m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <nav_msgs>) ostream)
  "Serializes a message object of type '<nav_msgs>"
  (cl:let* ((signed (cl:slot-value msg 'setpoint)) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 65536) signed)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) unsigned) ostream)
    )
  (cl:let* ((signed (cl:slot-value msg 'state)) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 65536) signed)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) unsigned) ostream)
    )
  (cl:let* ((signed (cl:slot-value msg 'effort)) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 65536) signed)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) unsigned) ostream)
    )
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <nav_msgs>) istream)
  "Deserializes a message object of type '<nav_msgs>"
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) unsigned) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'setpoint) (cl:if (cl:< unsigned 32768) unsigned (cl:- unsigned 65536))))
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) unsigned) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'state) (cl:if (cl:< unsigned 32768) unsigned (cl:- unsigned 65536))))
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) unsigned) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'effort) (cl:if (cl:< unsigned 32768) unsigned (cl:- unsigned 65536))))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<nav_msgs>)))
  "Returns string type for a message object of type '<nav_msgs>"
  "kocheng/nav_msgs")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'nav_msgs)))
  "Returns string type for a message object of type 'nav_msgs"
  "kocheng/nav_msgs")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<nav_msgs>)))
  "Returns md5sum for a message object of type '<nav_msgs>"
  "8ea1d017b4a253e899268e6002fac34d")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'nav_msgs)))
  "Returns md5sum for a message object of type 'nav_msgs"
  "8ea1d017b4a253e899268e6002fac34d")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<nav_msgs>)))
  "Returns full string definition for message of type '<nav_msgs>"
  (cl:format cl:nil "int16 setpoint~%int16 state~%int16 effort~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'nav_msgs)))
  "Returns full string definition for message of type 'nav_msgs"
  (cl:format cl:nil "int16 setpoint~%int16 state~%int16 effort~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <nav_msgs>))
  (cl:+ 0
     2
     2
     2
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <nav_msgs>))
  "Converts a ROS message object to a list"
  (cl:list 'nav_msgs
    (cl:cons ':setpoint (setpoint msg))
    (cl:cons ':state (state msg))
    (cl:cons ':effort (effort msg))
))
