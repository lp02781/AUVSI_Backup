; Auto-generated. Do not edit!


(cl:in-package kocheng-msg)


;//! \htmlinclude drone_kocheng.msg.html

(cl:defclass <drone_kocheng> (roslisp-msg-protocol:ros-message)
  ((drone_status
    :reader drone_status
    :initarg :drone_status
    :type cl:string
    :initform ""))
)

(cl:defclass drone_kocheng (<drone_kocheng>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <drone_kocheng>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'drone_kocheng)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name kocheng-msg:<drone_kocheng> is deprecated: use kocheng-msg:drone_kocheng instead.")))

(cl:ensure-generic-function 'drone_status-val :lambda-list '(m))
(cl:defmethod drone_status-val ((m <drone_kocheng>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader kocheng-msg:drone_status-val is deprecated.  Use kocheng-msg:drone_status instead.")
  (drone_status m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <drone_kocheng>) ostream)
  "Serializes a message object of type '<drone_kocheng>"
  (cl:let ((__ros_str_len (cl:length (cl:slot-value msg 'drone_status))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) __ros_str_len) ostream))
  (cl:map cl:nil #'(cl:lambda (c) (cl:write-byte (cl:char-code c) ostream)) (cl:slot-value msg 'drone_status))
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <drone_kocheng>) istream)
  "Deserializes a message object of type '<drone_kocheng>"
    (cl:let ((__ros_str_len 0))
      (cl:setf (cl:ldb (cl:byte 8 0) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'drone_status) (cl:make-string __ros_str_len))
      (cl:dotimes (__ros_str_idx __ros_str_len msg)
        (cl:setf (cl:char (cl:slot-value msg 'drone_status) __ros_str_idx) (cl:code-char (cl:read-byte istream)))))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<drone_kocheng>)))
  "Returns string type for a message object of type '<drone_kocheng>"
  "kocheng/drone_kocheng")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'drone_kocheng)))
  "Returns string type for a message object of type 'drone_kocheng"
  "kocheng/drone_kocheng")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<drone_kocheng>)))
  "Returns md5sum for a message object of type '<drone_kocheng>"
  "2c7c5edf7dfbe4935f6f975fe743924d")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'drone_kocheng)))
  "Returns md5sum for a message object of type 'drone_kocheng"
  "2c7c5edf7dfbe4935f6f975fe743924d")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<drone_kocheng>)))
  "Returns full string definition for message of type '<drone_kocheng>"
  (cl:format cl:nil "string drone_status~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'drone_kocheng)))
  "Returns full string definition for message of type 'drone_kocheng"
  (cl:format cl:nil "string drone_status~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <drone_kocheng>))
  (cl:+ 0
     4 (cl:length (cl:slot-value msg 'drone_status))
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <drone_kocheng>))
  "Converts a ROS message object to a list"
  (cl:list 'drone_kocheng
    (cl:cons ':drone_status (drone_status msg))
))
