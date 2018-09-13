; Auto-generated. Do not edit!


(cl:in-package roboboat-msg)


;//! \htmlinclude image_process.msg.html

(cl:defclass <image_process> (roslisp-msg-protocol:ros-message)
  ((buoy_red
    :reader buoy_red
    :initarg :buoy_red
    :type cl:fixnum
    :initform 0)
   (buoy_green
    :reader buoy_green
    :initarg :buoy_green
    :type cl:fixnum
    :initform 0)
   (buoy_blue
    :reader buoy_blue
    :initarg :buoy_blue
    :type cl:fixnum
    :initform 0)
   (gate_red
    :reader gate_red
    :initarg :gate_red
    :type cl:fixnum
    :initform 0)
   (gate_green
    :reader gate_green
    :initarg :gate_green
    :type cl:fixnum
    :initform 0)
   (x_flag
    :reader x_flag
    :initarg :x_flag
    :type cl:fixnum
    :initform 0)
   (y_flag
    :reader y_flag
    :initarg :y_flag
    :type cl:fixnum
    :initform 0)
   (dock_one
    :reader dock_one
    :initarg :dock_one
    :type cl:fixnum
    :initform 0)
   (dock_two
    :reader dock_two
    :initarg :dock_two
    :type cl:fixnum
    :initform 0)
   (dock_three
    :reader dock_three
    :initarg :dock_three
    :type cl:fixnum
    :initform 0))
)

(cl:defclass image_process (<image_process>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <image_process>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'image_process)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name roboboat-msg:<image_process> is deprecated: use roboboat-msg:image_process instead.")))

(cl:ensure-generic-function 'buoy_red-val :lambda-list '(m))
(cl:defmethod buoy_red-val ((m <image_process>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader roboboat-msg:buoy_red-val is deprecated.  Use roboboat-msg:buoy_red instead.")
  (buoy_red m))

(cl:ensure-generic-function 'buoy_green-val :lambda-list '(m))
(cl:defmethod buoy_green-val ((m <image_process>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader roboboat-msg:buoy_green-val is deprecated.  Use roboboat-msg:buoy_green instead.")
  (buoy_green m))

(cl:ensure-generic-function 'buoy_blue-val :lambda-list '(m))
(cl:defmethod buoy_blue-val ((m <image_process>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader roboboat-msg:buoy_blue-val is deprecated.  Use roboboat-msg:buoy_blue instead.")
  (buoy_blue m))

(cl:ensure-generic-function 'gate_red-val :lambda-list '(m))
(cl:defmethod gate_red-val ((m <image_process>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader roboboat-msg:gate_red-val is deprecated.  Use roboboat-msg:gate_red instead.")
  (gate_red m))

(cl:ensure-generic-function 'gate_green-val :lambda-list '(m))
(cl:defmethod gate_green-val ((m <image_process>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader roboboat-msg:gate_green-val is deprecated.  Use roboboat-msg:gate_green instead.")
  (gate_green m))

(cl:ensure-generic-function 'x_flag-val :lambda-list '(m))
(cl:defmethod x_flag-val ((m <image_process>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader roboboat-msg:x_flag-val is deprecated.  Use roboboat-msg:x_flag instead.")
  (x_flag m))

(cl:ensure-generic-function 'y_flag-val :lambda-list '(m))
(cl:defmethod y_flag-val ((m <image_process>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader roboboat-msg:y_flag-val is deprecated.  Use roboboat-msg:y_flag instead.")
  (y_flag m))

(cl:ensure-generic-function 'dock_one-val :lambda-list '(m))
(cl:defmethod dock_one-val ((m <image_process>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader roboboat-msg:dock_one-val is deprecated.  Use roboboat-msg:dock_one instead.")
  (dock_one m))

(cl:ensure-generic-function 'dock_two-val :lambda-list '(m))
(cl:defmethod dock_two-val ((m <image_process>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader roboboat-msg:dock_two-val is deprecated.  Use roboboat-msg:dock_two instead.")
  (dock_two m))

(cl:ensure-generic-function 'dock_three-val :lambda-list '(m))
(cl:defmethod dock_three-val ((m <image_process>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader roboboat-msg:dock_three-val is deprecated.  Use roboboat-msg:dock_three instead.")
  (dock_three m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <image_process>) ostream)
  "Serializes a message object of type '<image_process>"
  (cl:let* ((signed (cl:slot-value msg 'buoy_red)) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 65536) signed)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) unsigned) ostream)
    )
  (cl:let* ((signed (cl:slot-value msg 'buoy_green)) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 65536) signed)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) unsigned) ostream)
    )
  (cl:let* ((signed (cl:slot-value msg 'buoy_blue)) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 65536) signed)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) unsigned) ostream)
    )
  (cl:let* ((signed (cl:slot-value msg 'gate_red)) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 65536) signed)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) unsigned) ostream)
    )
  (cl:let* ((signed (cl:slot-value msg 'gate_green)) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 65536) signed)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) unsigned) ostream)
    )
  (cl:let* ((signed (cl:slot-value msg 'x_flag)) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 65536) signed)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) unsigned) ostream)
    )
  (cl:let* ((signed (cl:slot-value msg 'y_flag)) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 65536) signed)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) unsigned) ostream)
    )
  (cl:let* ((signed (cl:slot-value msg 'dock_one)) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 65536) signed)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) unsigned) ostream)
    )
  (cl:let* ((signed (cl:slot-value msg 'dock_two)) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 65536) signed)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) unsigned) ostream)
    )
  (cl:let* ((signed (cl:slot-value msg 'dock_three)) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 65536) signed)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) unsigned) ostream)
    )
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <image_process>) istream)
  "Deserializes a message object of type '<image_process>"
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) unsigned) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'buoy_red) (cl:if (cl:< unsigned 32768) unsigned (cl:- unsigned 65536))))
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) unsigned) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'buoy_green) (cl:if (cl:< unsigned 32768) unsigned (cl:- unsigned 65536))))
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) unsigned) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'buoy_blue) (cl:if (cl:< unsigned 32768) unsigned (cl:- unsigned 65536))))
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) unsigned) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'gate_red) (cl:if (cl:< unsigned 32768) unsigned (cl:- unsigned 65536))))
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) unsigned) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'gate_green) (cl:if (cl:< unsigned 32768) unsigned (cl:- unsigned 65536))))
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) unsigned) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'x_flag) (cl:if (cl:< unsigned 32768) unsigned (cl:- unsigned 65536))))
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) unsigned) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'y_flag) (cl:if (cl:< unsigned 32768) unsigned (cl:- unsigned 65536))))
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) unsigned) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'dock_one) (cl:if (cl:< unsigned 32768) unsigned (cl:- unsigned 65536))))
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) unsigned) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'dock_two) (cl:if (cl:< unsigned 32768) unsigned (cl:- unsigned 65536))))
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) unsigned) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'dock_three) (cl:if (cl:< unsigned 32768) unsigned (cl:- unsigned 65536))))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<image_process>)))
  "Returns string type for a message object of type '<image_process>"
  "roboboat/image_process")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'image_process)))
  "Returns string type for a message object of type 'image_process"
  "roboboat/image_process")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<image_process>)))
  "Returns md5sum for a message object of type '<image_process>"
  "f2466f92f806c6e64e91ea6278fe0b11")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'image_process)))
  "Returns md5sum for a message object of type 'image_process"
  "f2466f92f806c6e64e91ea6278fe0b11")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<image_process>)))
  "Returns full string definition for message of type '<image_process>"
  (cl:format cl:nil "int16 buoy_red~%int16 buoy_green~%int16 buoy_blue~%int16 gate_red~%int16 gate_green~%int16 x_flag~%int16 y_flag~%int16 dock_one~%int16 dock_two~%int16 dock_three~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'image_process)))
  "Returns full string definition for message of type 'image_process"
  (cl:format cl:nil "int16 buoy_red~%int16 buoy_green~%int16 buoy_blue~%int16 gate_red~%int16 gate_green~%int16 x_flag~%int16 y_flag~%int16 dock_one~%int16 dock_two~%int16 dock_three~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <image_process>))
  (cl:+ 0
     2
     2
     2
     2
     2
     2
     2
     2
     2
     2
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <image_process>))
  "Converts a ROS message object to a list"
  (cl:list 'image_process
    (cl:cons ':buoy_red (buoy_red msg))
    (cl:cons ':buoy_green (buoy_green msg))
    (cl:cons ':buoy_blue (buoy_blue msg))
    (cl:cons ':gate_red (gate_red msg))
    (cl:cons ':gate_green (gate_green msg))
    (cl:cons ':x_flag (x_flag msg))
    (cl:cons ':y_flag (y_flag msg))
    (cl:cons ':dock_one (dock_one msg))
    (cl:cons ':dock_two (dock_two msg))
    (cl:cons ':dock_three (dock_three msg))
))
