; Auto-generated. Do not edit!


(cl:in-package forest_fire_detection_system-msg)


;//! \htmlinclude SingleFireRGB.msg.html

(cl:defclass <SingleFireRGB> (roslisp-msg-protocol:ros-message)
  ((header
    :reader header
    :initarg :header
    :type std_msgs-msg:Header
    :initform (cl:make-instance 'std_msgs-msg:Header))
   (img_width
    :reader img_width
    :initarg :img_width
    :type cl:fixnum
    :initform 0)
   (img_height
    :reader img_height
    :initarg :img_height
    :type cl:fixnum
    :initform 0)
   (resize_img_width
    :reader resize_img_width
    :initarg :resize_img_width
    :type cl:fixnum
    :initform 0)
   (resize_img_height
    :reader resize_img_height
    :initarg :resize_img_height
    :type cl:fixnum
    :initform 0)
   (target_type
    :reader target_type
    :initarg :target_type
    :type cl:fixnum
    :initform 0)
   (img_x
    :reader img_x
    :initarg :img_x
    :type cl:float
    :initform 0.0)
   (img_y
    :reader img_y
    :initarg :img_y
    :type cl:float
    :initform 0.0))
)

(cl:defclass SingleFireRGB (<SingleFireRGB>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <SingleFireRGB>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'SingleFireRGB)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name forest_fire_detection_system-msg:<SingleFireRGB> is deprecated: use forest_fire_detection_system-msg:SingleFireRGB instead.")))

(cl:ensure-generic-function 'header-val :lambda-list '(m))
(cl:defmethod header-val ((m <SingleFireRGB>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader forest_fire_detection_system-msg:header-val is deprecated.  Use forest_fire_detection_system-msg:header instead.")
  (header m))

(cl:ensure-generic-function 'img_width-val :lambda-list '(m))
(cl:defmethod img_width-val ((m <SingleFireRGB>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader forest_fire_detection_system-msg:img_width-val is deprecated.  Use forest_fire_detection_system-msg:img_width instead.")
  (img_width m))

(cl:ensure-generic-function 'img_height-val :lambda-list '(m))
(cl:defmethod img_height-val ((m <SingleFireRGB>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader forest_fire_detection_system-msg:img_height-val is deprecated.  Use forest_fire_detection_system-msg:img_height instead.")
  (img_height m))

(cl:ensure-generic-function 'resize_img_width-val :lambda-list '(m))
(cl:defmethod resize_img_width-val ((m <SingleFireRGB>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader forest_fire_detection_system-msg:resize_img_width-val is deprecated.  Use forest_fire_detection_system-msg:resize_img_width instead.")
  (resize_img_width m))

(cl:ensure-generic-function 'resize_img_height-val :lambda-list '(m))
(cl:defmethod resize_img_height-val ((m <SingleFireRGB>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader forest_fire_detection_system-msg:resize_img_height-val is deprecated.  Use forest_fire_detection_system-msg:resize_img_height instead.")
  (resize_img_height m))

(cl:ensure-generic-function 'target_type-val :lambda-list '(m))
(cl:defmethod target_type-val ((m <SingleFireRGB>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader forest_fire_detection_system-msg:target_type-val is deprecated.  Use forest_fire_detection_system-msg:target_type instead.")
  (target_type m))

(cl:ensure-generic-function 'img_x-val :lambda-list '(m))
(cl:defmethod img_x-val ((m <SingleFireRGB>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader forest_fire_detection_system-msg:img_x-val is deprecated.  Use forest_fire_detection_system-msg:img_x instead.")
  (img_x m))

(cl:ensure-generic-function 'img_y-val :lambda-list '(m))
(cl:defmethod img_y-val ((m <SingleFireRGB>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader forest_fire_detection_system-msg:img_y-val is deprecated.  Use forest_fire_detection_system-msg:img_y instead.")
  (img_y m))
(cl:defmethod roslisp-msg-protocol:symbol-codes ((msg-type (cl:eql '<SingleFireRGB>)))
    "Constants for message type '<SingleFireRGB>"
  '((:IS_BACKGROUND . 0)
    (:IS_FIRE . 1)
    (:IS_SMOKE . 2)
    (:IS_UNKNOWN . 255))
)
(cl:defmethod roslisp-msg-protocol:symbol-codes ((msg-type (cl:eql 'SingleFireRGB)))
    "Constants for message type 'SingleFireRGB"
  '((:IS_BACKGROUND . 0)
    (:IS_FIRE . 1)
    (:IS_SMOKE . 2)
    (:IS_UNKNOWN . 255))
)
(cl:defmethod roslisp-msg-protocol:serialize ((msg <SingleFireRGB>) ostream)
  "Serializes a message object of type '<SingleFireRGB>"
  (roslisp-msg-protocol:serialize (cl:slot-value msg 'header) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'img_width)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 8) (cl:slot-value msg 'img_width)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'img_height)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 8) (cl:slot-value msg 'img_height)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'resize_img_width)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 8) (cl:slot-value msg 'resize_img_width)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'resize_img_height)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 8) (cl:slot-value msg 'resize_img_height)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'target_type)) ostream)
  (cl:let ((bits (roslisp-utils:encode-single-float-bits (cl:slot-value msg 'img_x))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream))
  (cl:let ((bits (roslisp-utils:encode-single-float-bits (cl:slot-value msg 'img_y))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream))
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <SingleFireRGB>) istream)
  "Deserializes a message object of type '<SingleFireRGB>"
  (roslisp-msg-protocol:deserialize (cl:slot-value msg 'header) istream)
    (cl:setf (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'img_width)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 8) (cl:slot-value msg 'img_width)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'img_height)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 8) (cl:slot-value msg 'img_height)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'resize_img_width)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 8) (cl:slot-value msg 'resize_img_width)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'resize_img_height)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 8) (cl:slot-value msg 'resize_img_height)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'target_type)) (cl:read-byte istream))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'img_x) (roslisp-utils:decode-single-float-bits bits)))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'img_y) (roslisp-utils:decode-single-float-bits bits)))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<SingleFireRGB>)))
  "Returns string type for a message object of type '<SingleFireRGB>"
  "forest_fire_detection_system/SingleFireRGB")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'SingleFireRGB)))
  "Returns string type for a message object of type 'SingleFireRGB"
  "forest_fire_detection_system/SingleFireRGB")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<SingleFireRGB>)))
  "Returns md5sum for a message object of type '<SingleFireRGB>"
  "07b3335d23070b1b1f83844b96f60949")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'SingleFireRGB)))
  "Returns md5sum for a message object of type 'SingleFireRGB"
  "07b3335d23070b1b1f83844b96f60949")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<SingleFireRGB>)))
  "Returns full string definition for message of type '<SingleFireRGB>"
  (cl:format cl:nil "Header header~%~%# image shape~%uint16 img_width~%uint16 img_height~%~%# reszie shape~%uint16 resize_img_width~%uint16 resize_img_height~%~%# target type~%uint8 IS_BACKGROUND = 0~%uint8 IS_FIRE = 1~%uint8 IS_SMOKE = 2~%uint8 IS_UNKNOWN = 255~%~%uint8 target_type~%~%# the x and y pos (sub-pixel) of the single fire, opencv style coordinates~%float32 img_x~%float32 img_y~%~%~%================================================================================~%MSG: std_msgs/Header~%# Standard metadata for higher-level stamped data types.~%# This is generally used to communicate timestamped data ~%# in a particular coordinate frame.~%# ~%# sequence ID: consecutively increasing ID ~%uint32 seq~%#Two-integer timestamp that is expressed as:~%# * stamp.sec: seconds (stamp_secs) since epoch (in Python the variable is called 'secs')~%# * stamp.nsec: nanoseconds since stamp_secs (in Python the variable is called 'nsecs')~%# time-handling sugar is provided by the client library~%time stamp~%#Frame this data is associated with~%string frame_id~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'SingleFireRGB)))
  "Returns full string definition for message of type 'SingleFireRGB"
  (cl:format cl:nil "Header header~%~%# image shape~%uint16 img_width~%uint16 img_height~%~%# reszie shape~%uint16 resize_img_width~%uint16 resize_img_height~%~%# target type~%uint8 IS_BACKGROUND = 0~%uint8 IS_FIRE = 1~%uint8 IS_SMOKE = 2~%uint8 IS_UNKNOWN = 255~%~%uint8 target_type~%~%# the x and y pos (sub-pixel) of the single fire, opencv style coordinates~%float32 img_x~%float32 img_y~%~%~%================================================================================~%MSG: std_msgs/Header~%# Standard metadata for higher-level stamped data types.~%# This is generally used to communicate timestamped data ~%# in a particular coordinate frame.~%# ~%# sequence ID: consecutively increasing ID ~%uint32 seq~%#Two-integer timestamp that is expressed as:~%# * stamp.sec: seconds (stamp_secs) since epoch (in Python the variable is called 'secs')~%# * stamp.nsec: nanoseconds since stamp_secs (in Python the variable is called 'nsecs')~%# time-handling sugar is provided by the client library~%time stamp~%#Frame this data is associated with~%string frame_id~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <SingleFireRGB>))
  (cl:+ 0
     (roslisp-msg-protocol:serialization-length (cl:slot-value msg 'header))
     2
     2
     2
     2
     1
     4
     4
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <SingleFireRGB>))
  "Converts a ROS message object to a list"
  (cl:list 'SingleFireRGB
    (cl:cons ':header (header msg))
    (cl:cons ':img_width (img_width msg))
    (cl:cons ':img_height (img_height msg))
    (cl:cons ':resize_img_width (resize_img_width msg))
    (cl:cons ':resize_img_height (resize_img_height msg))
    (cl:cons ':target_type (target_type msg))
    (cl:cons ':img_x (img_x msg))
    (cl:cons ':img_y (img_y msg))
))
