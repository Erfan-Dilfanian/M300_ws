; Auto-generated. Do not edit!


(cl:in-package forest_fire_detection_system-msg)


;//! \htmlinclude SingleFireFuse.msg.html

(cl:defclass <SingleFireFuse> (roslisp-msg-protocol:ros-message)
  ((header
    :reader header
    :initarg :header
    :type std_msgs-msg:Header
    :initform (cl:make-instance 'std_msgs-msg:Header))
   (ir_img_width
    :reader ir_img_width
    :initarg :ir_img_width
    :type cl:fixnum
    :initform 0)
   (ir_img_height
    :reader ir_img_height
    :initarg :ir_img_height
    :type cl:fixnum
    :initform 0)
   (rgb_img_width
    :reader rgb_img_width
    :initarg :rgb_img_width
    :type cl:fixnum
    :initform 0)
   (rgb_img_height
    :reader rgb_img_height
    :initarg :rgb_img_height
    :type cl:fixnum
    :initform 0)
   (target_type
    :reader target_type
    :initarg :target_type
    :type cl:fixnum
    :initform 0)
   (focuse_mode
    :reader focuse_mode
    :initarg :focuse_mode
    :type cl:fixnum
    :initform 0)
   (ir_img_x
    :reader ir_img_x
    :initarg :ir_img_x
    :type cl:float
    :initform 0.0)
   (ir_img_y
    :reader ir_img_y
    :initarg :ir_img_y
    :type cl:float
    :initform 0.0)
   (rgb_img_x
    :reader rgb_img_x
    :initarg :rgb_img_x
    :type cl:float
    :initform 0.0)
   (rgb_img_y
    :reader rgb_img_y
    :initarg :rgb_img_y
    :type cl:float
    :initform 0.0)
   (scale
    :reader scale
    :initarg :scale
    :type cl:float
    :initform 0.0)
   (offset_x
    :reader offset_x
    :initarg :offset_x
    :type cl:float
    :initform 0.0)
   (offset_y
    :reader offset_y
    :initarg :offset_y
    :type cl:float
    :initform 0.0))
)

(cl:defclass SingleFireFuse (<SingleFireFuse>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <SingleFireFuse>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'SingleFireFuse)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name forest_fire_detection_system-msg:<SingleFireFuse> is deprecated: use forest_fire_detection_system-msg:SingleFireFuse instead.")))

(cl:ensure-generic-function 'header-val :lambda-list '(m))
(cl:defmethod header-val ((m <SingleFireFuse>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader forest_fire_detection_system-msg:header-val is deprecated.  Use forest_fire_detection_system-msg:header instead.")
  (header m))

(cl:ensure-generic-function 'ir_img_width-val :lambda-list '(m))
(cl:defmethod ir_img_width-val ((m <SingleFireFuse>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader forest_fire_detection_system-msg:ir_img_width-val is deprecated.  Use forest_fire_detection_system-msg:ir_img_width instead.")
  (ir_img_width m))

(cl:ensure-generic-function 'ir_img_height-val :lambda-list '(m))
(cl:defmethod ir_img_height-val ((m <SingleFireFuse>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader forest_fire_detection_system-msg:ir_img_height-val is deprecated.  Use forest_fire_detection_system-msg:ir_img_height instead.")
  (ir_img_height m))

(cl:ensure-generic-function 'rgb_img_width-val :lambda-list '(m))
(cl:defmethod rgb_img_width-val ((m <SingleFireFuse>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader forest_fire_detection_system-msg:rgb_img_width-val is deprecated.  Use forest_fire_detection_system-msg:rgb_img_width instead.")
  (rgb_img_width m))

(cl:ensure-generic-function 'rgb_img_height-val :lambda-list '(m))
(cl:defmethod rgb_img_height-val ((m <SingleFireFuse>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader forest_fire_detection_system-msg:rgb_img_height-val is deprecated.  Use forest_fire_detection_system-msg:rgb_img_height instead.")
  (rgb_img_height m))

(cl:ensure-generic-function 'target_type-val :lambda-list '(m))
(cl:defmethod target_type-val ((m <SingleFireFuse>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader forest_fire_detection_system-msg:target_type-val is deprecated.  Use forest_fire_detection_system-msg:target_type instead.")
  (target_type m))

(cl:ensure-generic-function 'focuse_mode-val :lambda-list '(m))
(cl:defmethod focuse_mode-val ((m <SingleFireFuse>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader forest_fire_detection_system-msg:focuse_mode-val is deprecated.  Use forest_fire_detection_system-msg:focuse_mode instead.")
  (focuse_mode m))

(cl:ensure-generic-function 'ir_img_x-val :lambda-list '(m))
(cl:defmethod ir_img_x-val ((m <SingleFireFuse>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader forest_fire_detection_system-msg:ir_img_x-val is deprecated.  Use forest_fire_detection_system-msg:ir_img_x instead.")
  (ir_img_x m))

(cl:ensure-generic-function 'ir_img_y-val :lambda-list '(m))
(cl:defmethod ir_img_y-val ((m <SingleFireFuse>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader forest_fire_detection_system-msg:ir_img_y-val is deprecated.  Use forest_fire_detection_system-msg:ir_img_y instead.")
  (ir_img_y m))

(cl:ensure-generic-function 'rgb_img_x-val :lambda-list '(m))
(cl:defmethod rgb_img_x-val ((m <SingleFireFuse>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader forest_fire_detection_system-msg:rgb_img_x-val is deprecated.  Use forest_fire_detection_system-msg:rgb_img_x instead.")
  (rgb_img_x m))

(cl:ensure-generic-function 'rgb_img_y-val :lambda-list '(m))
(cl:defmethod rgb_img_y-val ((m <SingleFireFuse>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader forest_fire_detection_system-msg:rgb_img_y-val is deprecated.  Use forest_fire_detection_system-msg:rgb_img_y instead.")
  (rgb_img_y m))

(cl:ensure-generic-function 'scale-val :lambda-list '(m))
(cl:defmethod scale-val ((m <SingleFireFuse>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader forest_fire_detection_system-msg:scale-val is deprecated.  Use forest_fire_detection_system-msg:scale instead.")
  (scale m))

(cl:ensure-generic-function 'offset_x-val :lambda-list '(m))
(cl:defmethod offset_x-val ((m <SingleFireFuse>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader forest_fire_detection_system-msg:offset_x-val is deprecated.  Use forest_fire_detection_system-msg:offset_x instead.")
  (offset_x m))

(cl:ensure-generic-function 'offset_y-val :lambda-list '(m))
(cl:defmethod offset_y-val ((m <SingleFireFuse>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader forest_fire_detection_system-msg:offset_y-val is deprecated.  Use forest_fire_detection_system-msg:offset_y instead.")
  (offset_y m))
(cl:defmethod roslisp-msg-protocol:symbol-codes ((msg-type (cl:eql '<SingleFireFuse>)))
    "Constants for message type '<SingleFireFuse>"
  '((:IS_BACKGROUND . 0)
    (:IS_TARGET . 1)
    (:IS_UNKNOWN . 255)
    (:USE_NONE . 0)
    (:USE_IR . 1)
    (:USE_RGB . 2))
)
(cl:defmethod roslisp-msg-protocol:symbol-codes ((msg-type (cl:eql 'SingleFireFuse)))
    "Constants for message type 'SingleFireFuse"
  '((:IS_BACKGROUND . 0)
    (:IS_TARGET . 1)
    (:IS_UNKNOWN . 255)
    (:USE_NONE . 0)
    (:USE_IR . 1)
    (:USE_RGB . 2))
)
(cl:defmethod roslisp-msg-protocol:serialize ((msg <SingleFireFuse>) ostream)
  "Serializes a message object of type '<SingleFireFuse>"
  (roslisp-msg-protocol:serialize (cl:slot-value msg 'header) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'ir_img_width)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 8) (cl:slot-value msg 'ir_img_width)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'ir_img_height)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 8) (cl:slot-value msg 'ir_img_height)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'rgb_img_width)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 8) (cl:slot-value msg 'rgb_img_width)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'rgb_img_height)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 8) (cl:slot-value msg 'rgb_img_height)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'target_type)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'focuse_mode)) ostream)
  (cl:let ((bits (roslisp-utils:encode-single-float-bits (cl:slot-value msg 'ir_img_x))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream))
  (cl:let ((bits (roslisp-utils:encode-single-float-bits (cl:slot-value msg 'ir_img_y))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream))
  (cl:let ((bits (roslisp-utils:encode-single-float-bits (cl:slot-value msg 'rgb_img_x))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream))
  (cl:let ((bits (roslisp-utils:encode-single-float-bits (cl:slot-value msg 'rgb_img_y))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream))
  (cl:let ((bits (roslisp-utils:encode-single-float-bits (cl:slot-value msg 'scale))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream))
  (cl:let ((bits (roslisp-utils:encode-single-float-bits (cl:slot-value msg 'offset_x))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream))
  (cl:let ((bits (roslisp-utils:encode-single-float-bits (cl:slot-value msg 'offset_y))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream))
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <SingleFireFuse>) istream)
  "Deserializes a message object of type '<SingleFireFuse>"
  (roslisp-msg-protocol:deserialize (cl:slot-value msg 'header) istream)
    (cl:setf (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'ir_img_width)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 8) (cl:slot-value msg 'ir_img_width)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'ir_img_height)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 8) (cl:slot-value msg 'ir_img_height)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'rgb_img_width)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 8) (cl:slot-value msg 'rgb_img_width)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'rgb_img_height)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 8) (cl:slot-value msg 'rgb_img_height)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'target_type)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'focuse_mode)) (cl:read-byte istream))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'ir_img_x) (roslisp-utils:decode-single-float-bits bits)))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'ir_img_y) (roslisp-utils:decode-single-float-bits bits)))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'rgb_img_x) (roslisp-utils:decode-single-float-bits bits)))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'rgb_img_y) (roslisp-utils:decode-single-float-bits bits)))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'scale) (roslisp-utils:decode-single-float-bits bits)))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'offset_x) (roslisp-utils:decode-single-float-bits bits)))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'offset_y) (roslisp-utils:decode-single-float-bits bits)))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<SingleFireFuse>)))
  "Returns string type for a message object of type '<SingleFireFuse>"
  "forest_fire_detection_system/SingleFireFuse")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'SingleFireFuse)))
  "Returns string type for a message object of type 'SingleFireFuse"
  "forest_fire_detection_system/SingleFireFuse")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<SingleFireFuse>)))
  "Returns md5sum for a message object of type '<SingleFireFuse>"
  "5acee9e57a872fd936b9b0d95ff37894")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'SingleFireFuse)))
  "Returns md5sum for a message object of type 'SingleFireFuse"
  "5acee9e57a872fd936b9b0d95ff37894")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<SingleFireFuse>)))
  "Returns full string definition for message of type '<SingleFireFuse>"
  (cl:format cl:nil "Header header~%~%# image detecting on info~%uint16 ir_img_width~%uint16 ir_img_height~%uint16 rgb_img_width~%uint16 rgb_img_height~%~%# target type~%uint8 IS_BACKGROUND = 0~%uint8 IS_TARGET = 1~%uint8 IS_UNKNOWN = 255~%~%uint8 target_type~%~%# focuse mode~%uint8 USE_NONE = 0~%uint8 USE_IR  = 1~%uint8 USE_RGB  = 2~%~%uint8 focuse_mode~%~%# the x and y pos (sub-pixel) of the single fire, opencv style coordinates~%float32 ir_img_x~%float32 ir_img_y~%float32 rgb_img_x~%float32 rgb_img_y~%~%# translation(ir->rgb)~%float32 scale~%float32 offset_x~%float32 offset_y~%~%================================================================================~%MSG: std_msgs/Header~%# Standard metadata for higher-level stamped data types.~%# This is generally used to communicate timestamped data ~%# in a particular coordinate frame.~%# ~%# sequence ID: consecutively increasing ID ~%uint32 seq~%#Two-integer timestamp that is expressed as:~%# * stamp.sec: seconds (stamp_secs) since epoch (in Python the variable is called 'secs')~%# * stamp.nsec: nanoseconds since stamp_secs (in Python the variable is called 'nsecs')~%# time-handling sugar is provided by the client library~%time stamp~%#Frame this data is associated with~%string frame_id~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'SingleFireFuse)))
  "Returns full string definition for message of type 'SingleFireFuse"
  (cl:format cl:nil "Header header~%~%# image detecting on info~%uint16 ir_img_width~%uint16 ir_img_height~%uint16 rgb_img_width~%uint16 rgb_img_height~%~%# target type~%uint8 IS_BACKGROUND = 0~%uint8 IS_TARGET = 1~%uint8 IS_UNKNOWN = 255~%~%uint8 target_type~%~%# focuse mode~%uint8 USE_NONE = 0~%uint8 USE_IR  = 1~%uint8 USE_RGB  = 2~%~%uint8 focuse_mode~%~%# the x and y pos (sub-pixel) of the single fire, opencv style coordinates~%float32 ir_img_x~%float32 ir_img_y~%float32 rgb_img_x~%float32 rgb_img_y~%~%# translation(ir->rgb)~%float32 scale~%float32 offset_x~%float32 offset_y~%~%================================================================================~%MSG: std_msgs/Header~%# Standard metadata for higher-level stamped data types.~%# This is generally used to communicate timestamped data ~%# in a particular coordinate frame.~%# ~%# sequence ID: consecutively increasing ID ~%uint32 seq~%#Two-integer timestamp that is expressed as:~%# * stamp.sec: seconds (stamp_secs) since epoch (in Python the variable is called 'secs')~%# * stamp.nsec: nanoseconds since stamp_secs (in Python the variable is called 'nsecs')~%# time-handling sugar is provided by the client library~%time stamp~%#Frame this data is associated with~%string frame_id~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <SingleFireFuse>))
  (cl:+ 0
     (roslisp-msg-protocol:serialization-length (cl:slot-value msg 'header))
     2
     2
     2
     2
     1
     1
     4
     4
     4
     4
     4
     4
     4
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <SingleFireFuse>))
  "Converts a ROS message object to a list"
  (cl:list 'SingleFireFuse
    (cl:cons ':header (header msg))
    (cl:cons ':ir_img_width (ir_img_width msg))
    (cl:cons ':ir_img_height (ir_img_height msg))
    (cl:cons ':rgb_img_width (rgb_img_width msg))
    (cl:cons ':rgb_img_height (rgb_img_height msg))
    (cl:cons ':target_type (target_type msg))
    (cl:cons ':focuse_mode (focuse_mode msg))
    (cl:cons ':ir_img_x (ir_img_x msg))
    (cl:cons ':ir_img_y (ir_img_y msg))
    (cl:cons ':rgb_img_x (rgb_img_x msg))
    (cl:cons ':rgb_img_y (rgb_img_y msg))
    (cl:cons ':scale (scale msg))
    (cl:cons ':offset_x (offset_x msg))
    (cl:cons ':offset_y (offset_y msg))
))
