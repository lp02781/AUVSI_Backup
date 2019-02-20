; Auto-generated. Do not edit!


(cl:in-package kocheng-msg)


;//! \htmlinclude communication.msg.html

(cl:defclass <communication> (roslisp-msg-protocol:ros-message)
  ((heartbeat_payload
    :reader heartbeat_payload
    :initarg :heartbeat_payload
    :type cl:string
    :initform "")
   (run_course_payload
    :reader run_course_payload
    :initarg :run_course_payload
    :type cl:string
    :initform "")
   (follow_payload
    :reader follow_payload
    :initarg :follow_payload
    :type cl:string
    :initform "")
   (docking_payload
    :reader docking_payload
    :initarg :docking_payload
    :type cl:string
    :initform "")
   (flag_payload
    :reader flag_payload
    :initarg :flag_payload
    :type cl:string
    :initform ""))
)

(cl:defclass communication (<communication>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <communication>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'communication)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name kocheng-msg:<communication> is deprecated: use kocheng-msg:communication instead.")))

(cl:ensure-generic-function 'heartbeat_payload-val :lambda-list '(m))
(cl:defmethod heartbeat_payload-val ((m <communication>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader kocheng-msg:heartbeat_payload-val is deprecated.  Use kocheng-msg:heartbeat_payload instead.")
  (heartbeat_payload m))

(cl:ensure-generic-function 'run_course_payload-val :lambda-list '(m))
(cl:defmethod run_course_payload-val ((m <communication>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader kocheng-msg:run_course_payload-val is deprecated.  Use kocheng-msg:run_course_payload instead.")
  (run_course_payload m))

(cl:ensure-generic-function 'follow_payload-val :lambda-list '(m))
(cl:defmethod follow_payload-val ((m <communication>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader kocheng-msg:follow_payload-val is deprecated.  Use kocheng-msg:follow_payload instead.")
  (follow_payload m))

(cl:ensure-generic-function 'docking_payload-val :lambda-list '(m))
(cl:defmethod docking_payload-val ((m <communication>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader kocheng-msg:docking_payload-val is deprecated.  Use kocheng-msg:docking_payload instead.")
  (docking_payload m))

(cl:ensure-generic-function 'flag_payload-val :lambda-list '(m))
(cl:defmethod flag_payload-val ((m <communication>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader kocheng-msg:flag_payload-val is deprecated.  Use kocheng-msg:flag_payload instead.")
  (flag_payload m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <communication>) ostream)
  "Serializes a message object of type '<communication>"
  (cl:let ((__ros_str_len (cl:length (cl:slot-value msg 'heartbeat_payload))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) __ros_str_len) ostream))
  (cl:map cl:nil #'(cl:lambda (c) (cl:write-byte (cl:char-code c) ostream)) (cl:slot-value msg 'heartbeat_payload))
  (cl:let ((__ros_str_len (cl:length (cl:slot-value msg 'run_course_payload))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) __ros_str_len) ostream))
  (cl:map cl:nil #'(cl:lambda (c) (cl:write-byte (cl:char-code c) ostream)) (cl:slot-value msg 'run_course_payload))
  (cl:let ((__ros_str_len (cl:length (cl:slot-value msg 'follow_payload))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) __ros_str_len) ostream))
  (cl:map cl:nil #'(cl:lambda (c) (cl:write-byte (cl:char-code c) ostream)) (cl:slot-value msg 'follow_payload))
  (cl:let ((__ros_str_len (cl:length (cl:slot-value msg 'docking_payload))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) __ros_str_len) ostream))
  (cl:map cl:nil #'(cl:lambda (c) (cl:write-byte (cl:char-code c) ostream)) (cl:slot-value msg 'docking_payload))
  (cl:let ((__ros_str_len (cl:length (cl:slot-value msg 'flag_payload))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) __ros_str_len) ostream))
  (cl:map cl:nil #'(cl:lambda (c) (cl:write-byte (cl:char-code c) ostream)) (cl:slot-value msg 'flag_payload))
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <communication>) istream)
  "Deserializes a message object of type '<communication>"
    (cl:let ((__ros_str_len 0))
      (cl:setf (cl:ldb (cl:byte 8 0) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'heartbeat_payload) (cl:make-string __ros_str_len))
      (cl:dotimes (__ros_str_idx __ros_str_len msg)
        (cl:setf (cl:char (cl:slot-value msg 'heartbeat_payload) __ros_str_idx) (cl:code-char (cl:read-byte istream)))))
    (cl:let ((__ros_str_len 0))
      (cl:setf (cl:ldb (cl:byte 8 0) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'run_course_payload) (cl:make-string __ros_str_len))
      (cl:dotimes (__ros_str_idx __ros_str_len msg)
        (cl:setf (cl:char (cl:slot-value msg 'run_course_payload) __ros_str_idx) (cl:code-char (cl:read-byte istream)))))
    (cl:let ((__ros_str_len 0))
      (cl:setf (cl:ldb (cl:byte 8 0) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'follow_payload) (cl:make-string __ros_str_len))
      (cl:dotimes (__ros_str_idx __ros_str_len msg)
        (cl:setf (cl:char (cl:slot-value msg 'follow_payload) __ros_str_idx) (cl:code-char (cl:read-byte istream)))))
    (cl:let ((__ros_str_len 0))
      (cl:setf (cl:ldb (cl:byte 8 0) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'docking_payload) (cl:make-string __ros_str_len))
      (cl:dotimes (__ros_str_idx __ros_str_len msg)
        (cl:setf (cl:char (cl:slot-value msg 'docking_payload) __ros_str_idx) (cl:code-char (cl:read-byte istream)))))
    (cl:let ((__ros_str_len 0))
      (cl:setf (cl:ldb (cl:byte 8 0) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'flag_payload) (cl:make-string __ros_str_len))
      (cl:dotimes (__ros_str_idx __ros_str_len msg)
        (cl:setf (cl:char (cl:slot-value msg 'flag_payload) __ros_str_idx) (cl:code-char (cl:read-byte istream)))))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<communication>)))
  "Returns string type for a message object of type '<communication>"
  "kocheng/communication")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'communication)))
  "Returns string type for a message object of type 'communication"
  "kocheng/communication")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<communication>)))
  "Returns md5sum for a message object of type '<communication>"
  "892ce67e7b2f9ec2fb90e613344b9551")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'communication)))
  "Returns md5sum for a message object of type 'communication"
  "892ce67e7b2f9ec2fb90e613344b9551")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<communication>)))
  "Returns full string definition for message of type '<communication>"
  (cl:format cl:nil "string heartbeat_payload~%string run_course_payload~%string follow_payload~%string docking_payload~%string flag_payload~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'communication)))
  "Returns full string definition for message of type 'communication"
  (cl:format cl:nil "string heartbeat_payload~%string run_course_payload~%string follow_payload~%string docking_payload~%string flag_payload~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <communication>))
  (cl:+ 0
     4 (cl:length (cl:slot-value msg 'heartbeat_payload))
     4 (cl:length (cl:slot-value msg 'run_course_payload))
     4 (cl:length (cl:slot-value msg 'follow_payload))
     4 (cl:length (cl:slot-value msg 'docking_payload))
     4 (cl:length (cl:slot-value msg 'flag_payload))
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <communication>))
  "Converts a ROS message object to a list"
  (cl:list 'communication
    (cl:cons ':heartbeat_payload (heartbeat_payload msg))
    (cl:cons ':run_course_payload (run_course_payload msg))
    (cl:cons ':follow_payload (follow_payload msg))
    (cl:cons ':docking_payload (docking_payload msg))
    (cl:cons ':flag_payload (flag_payload msg))
))
