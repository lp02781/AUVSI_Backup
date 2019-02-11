; Auto-generated. Do not edit!


(cl:in-package kocheng-msg)


;//! \htmlinclude com_auvsi.msg.html

(cl:defclass <com_auvsi> (roslisp-msg-protocol:ros-message)
  ((mission_makara
    :reader mission_makara
    :initarg :mission_makara
    :type cl:string
    :initform ""))
)

(cl:defclass com_auvsi (<com_auvsi>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <com_auvsi>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'com_auvsi)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name kocheng-msg:<com_auvsi> is deprecated: use kocheng-msg:com_auvsi instead.")))

(cl:ensure-generic-function 'mission_makara-val :lambda-list '(m))
(cl:defmethod mission_makara-val ((m <com_auvsi>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader kocheng-msg:mission_makara-val is deprecated.  Use kocheng-msg:mission_makara instead.")
  (mission_makara m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <com_auvsi>) ostream)
  "Serializes a message object of type '<com_auvsi>"
  (cl:let ((__ros_str_len (cl:length (cl:slot-value msg 'mission_makara))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) __ros_str_len) ostream))
  (cl:map cl:nil #'(cl:lambda (c) (cl:write-byte (cl:char-code c) ostream)) (cl:slot-value msg 'mission_makara))
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <com_auvsi>) istream)
  "Deserializes a message object of type '<com_auvsi>"
    (cl:let ((__ros_str_len 0))
      (cl:setf (cl:ldb (cl:byte 8 0) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'mission_makara) (cl:make-string __ros_str_len))
      (cl:dotimes (__ros_str_idx __ros_str_len msg)
        (cl:setf (cl:char (cl:slot-value msg 'mission_makara) __ros_str_idx) (cl:code-char (cl:read-byte istream)))))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<com_auvsi>)))
  "Returns string type for a message object of type '<com_auvsi>"
  "kocheng/com_auvsi")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'com_auvsi)))
  "Returns string type for a message object of type 'com_auvsi"
  "kocheng/com_auvsi")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<com_auvsi>)))
  "Returns md5sum for a message object of type '<com_auvsi>"
  "2e7801e6e1d9e6d8720e1966e071032b")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'com_auvsi)))
  "Returns md5sum for a message object of type 'com_auvsi"
  "2e7801e6e1d9e6d8720e1966e071032b")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<com_auvsi>)))
  "Returns full string definition for message of type '<com_auvsi>"
  (cl:format cl:nil "string mission_makara~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'com_auvsi)))
  "Returns full string definition for message of type 'com_auvsi"
  (cl:format cl:nil "string mission_makara~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <com_auvsi>))
  (cl:+ 0
     4 (cl:length (cl:slot-value msg 'mission_makara))
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <com_auvsi>))
  "Converts a ROS message object to a list"
  (cl:list 'com_auvsi
    (cl:cons ':mission_makara (mission_makara msg))
))
