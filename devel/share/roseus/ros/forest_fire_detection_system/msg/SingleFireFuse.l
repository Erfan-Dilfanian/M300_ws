;; Auto-generated. Do not edit!


(when (boundp 'forest_fire_detection_system::SingleFireFuse)
  (if (not (find-package "FOREST_FIRE_DETECTION_SYSTEM"))
    (make-package "FOREST_FIRE_DETECTION_SYSTEM"))
  (shadow 'SingleFireFuse (find-package "FOREST_FIRE_DETECTION_SYSTEM")))
(unless (find-package "FOREST_FIRE_DETECTION_SYSTEM::SINGLEFIREFUSE")
  (make-package "FOREST_FIRE_DETECTION_SYSTEM::SINGLEFIREFUSE"))

(in-package "ROS")
;;//! \htmlinclude SingleFireFuse.msg.html
(if (not (find-package "STD_MSGS"))
  (ros::roseus-add-msgs "std_msgs"))


(intern "*IS_BACKGROUND*" (find-package "FOREST_FIRE_DETECTION_SYSTEM::SINGLEFIREFUSE"))
(shadow '*IS_BACKGROUND* (find-package "FOREST_FIRE_DETECTION_SYSTEM::SINGLEFIREFUSE"))
(defconstant forest_fire_detection_system::SingleFireFuse::*IS_BACKGROUND* 0)
(intern "*IS_TARGET*" (find-package "FOREST_FIRE_DETECTION_SYSTEM::SINGLEFIREFUSE"))
(shadow '*IS_TARGET* (find-package "FOREST_FIRE_DETECTION_SYSTEM::SINGLEFIREFUSE"))
(defconstant forest_fire_detection_system::SingleFireFuse::*IS_TARGET* 1)
(intern "*IS_UNKNOWN*" (find-package "FOREST_FIRE_DETECTION_SYSTEM::SINGLEFIREFUSE"))
(shadow '*IS_UNKNOWN* (find-package "FOREST_FIRE_DETECTION_SYSTEM::SINGLEFIREFUSE"))
(defconstant forest_fire_detection_system::SingleFireFuse::*IS_UNKNOWN* 255)
(intern "*USE_NONE*" (find-package "FOREST_FIRE_DETECTION_SYSTEM::SINGLEFIREFUSE"))
(shadow '*USE_NONE* (find-package "FOREST_FIRE_DETECTION_SYSTEM::SINGLEFIREFUSE"))
(defconstant forest_fire_detection_system::SingleFireFuse::*USE_NONE* 0)
(intern "*USE_IR*" (find-package "FOREST_FIRE_DETECTION_SYSTEM::SINGLEFIREFUSE"))
(shadow '*USE_IR* (find-package "FOREST_FIRE_DETECTION_SYSTEM::SINGLEFIREFUSE"))
(defconstant forest_fire_detection_system::SingleFireFuse::*USE_IR* 1)
(intern "*USE_RGB*" (find-package "FOREST_FIRE_DETECTION_SYSTEM::SINGLEFIREFUSE"))
(shadow '*USE_RGB* (find-package "FOREST_FIRE_DETECTION_SYSTEM::SINGLEFIREFUSE"))
(defconstant forest_fire_detection_system::SingleFireFuse::*USE_RGB* 2)

(defun forest_fire_detection_system::SingleFireFuse-to-symbol (const)
  (cond
        ((= const 0) 'forest_fire_detection_system::SingleFireFuse::*IS_BACKGROUND*)
        ((= const 1) 'forest_fire_detection_system::SingleFireFuse::*IS_TARGET*)
        ((= const 255) 'forest_fire_detection_system::SingleFireFuse::*IS_UNKNOWN*)
        ((= const 0) 'forest_fire_detection_system::SingleFireFuse::*USE_NONE*)
        ((= const 1) 'forest_fire_detection_system::SingleFireFuse::*USE_IR*)
        ((= const 2) 'forest_fire_detection_system::SingleFireFuse::*USE_RGB*)
        (t nil)))

(defclass forest_fire_detection_system::SingleFireFuse
  :super ros::object
  :slots (_header _ir_img_width _ir_img_height _rgb_img_width _rgb_img_height _target_type _focuse_mode _ir_img_x _ir_img_y _rgb_img_x _rgb_img_y _scale _offset_x _offset_y ))

(defmethod forest_fire_detection_system::SingleFireFuse
  (:init
   (&key
    ((:header __header) (instance std_msgs::Header :init))
    ((:ir_img_width __ir_img_width) 0)
    ((:ir_img_height __ir_img_height) 0)
    ((:rgb_img_width __rgb_img_width) 0)
    ((:rgb_img_height __rgb_img_height) 0)
    ((:target_type __target_type) 0)
    ((:focuse_mode __focuse_mode) 0)
    ((:ir_img_x __ir_img_x) 0.0)
    ((:ir_img_y __ir_img_y) 0.0)
    ((:rgb_img_x __rgb_img_x) 0.0)
    ((:rgb_img_y __rgb_img_y) 0.0)
    ((:scale __scale) 0.0)
    ((:offset_x __offset_x) 0.0)
    ((:offset_y __offset_y) 0.0)
    )
   (send-super :init)
   (setq _header __header)
   (setq _ir_img_width (round __ir_img_width))
   (setq _ir_img_height (round __ir_img_height))
   (setq _rgb_img_width (round __rgb_img_width))
   (setq _rgb_img_height (round __rgb_img_height))
   (setq _target_type (round __target_type))
   (setq _focuse_mode (round __focuse_mode))
   (setq _ir_img_x (float __ir_img_x))
   (setq _ir_img_y (float __ir_img_y))
   (setq _rgb_img_x (float __rgb_img_x))
   (setq _rgb_img_y (float __rgb_img_y))
   (setq _scale (float __scale))
   (setq _offset_x (float __offset_x))
   (setq _offset_y (float __offset_y))
   self)
  (:header
   (&rest __header)
   (if (keywordp (car __header))
       (send* _header __header)
     (progn
       (if __header (setq _header (car __header)))
       _header)))
  (:ir_img_width
   (&optional __ir_img_width)
   (if __ir_img_width (setq _ir_img_width __ir_img_width)) _ir_img_width)
  (:ir_img_height
   (&optional __ir_img_height)
   (if __ir_img_height (setq _ir_img_height __ir_img_height)) _ir_img_height)
  (:rgb_img_width
   (&optional __rgb_img_width)
   (if __rgb_img_width (setq _rgb_img_width __rgb_img_width)) _rgb_img_width)
  (:rgb_img_height
   (&optional __rgb_img_height)
   (if __rgb_img_height (setq _rgb_img_height __rgb_img_height)) _rgb_img_height)
  (:target_type
   (&optional __target_type)
   (if __target_type (setq _target_type __target_type)) _target_type)
  (:focuse_mode
   (&optional __focuse_mode)
   (if __focuse_mode (setq _focuse_mode __focuse_mode)) _focuse_mode)
  (:ir_img_x
   (&optional __ir_img_x)
   (if __ir_img_x (setq _ir_img_x __ir_img_x)) _ir_img_x)
  (:ir_img_y
   (&optional __ir_img_y)
   (if __ir_img_y (setq _ir_img_y __ir_img_y)) _ir_img_y)
  (:rgb_img_x
   (&optional __rgb_img_x)
   (if __rgb_img_x (setq _rgb_img_x __rgb_img_x)) _rgb_img_x)
  (:rgb_img_y
   (&optional __rgb_img_y)
   (if __rgb_img_y (setq _rgb_img_y __rgb_img_y)) _rgb_img_y)
  (:scale
   (&optional __scale)
   (if __scale (setq _scale __scale)) _scale)
  (:offset_x
   (&optional __offset_x)
   (if __offset_x (setq _offset_x __offset_x)) _offset_x)
  (:offset_y
   (&optional __offset_y)
   (if __offset_y (setq _offset_y __offset_y)) _offset_y)
  (:serialization-length
   ()
   (+
    ;; std_msgs/Header _header
    (send _header :serialization-length)
    ;; uint16 _ir_img_width
    2
    ;; uint16 _ir_img_height
    2
    ;; uint16 _rgb_img_width
    2
    ;; uint16 _rgb_img_height
    2
    ;; uint8 _target_type
    1
    ;; uint8 _focuse_mode
    1
    ;; float32 _ir_img_x
    4
    ;; float32 _ir_img_y
    4
    ;; float32 _rgb_img_x
    4
    ;; float32 _rgb_img_y
    4
    ;; float32 _scale
    4
    ;; float32 _offset_x
    4
    ;; float32 _offset_y
    4
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; std_msgs/Header _header
       (send _header :serialize s)
     ;; uint16 _ir_img_width
       (write-word _ir_img_width s)
     ;; uint16 _ir_img_height
       (write-word _ir_img_height s)
     ;; uint16 _rgb_img_width
       (write-word _rgb_img_width s)
     ;; uint16 _rgb_img_height
       (write-word _rgb_img_height s)
     ;; uint8 _target_type
       (write-byte _target_type s)
     ;; uint8 _focuse_mode
       (write-byte _focuse_mode s)
     ;; float32 _ir_img_x
       (sys::poke _ir_img_x (send s :buffer) (send s :count) :float) (incf (stream-count s) 4)
     ;; float32 _ir_img_y
       (sys::poke _ir_img_y (send s :buffer) (send s :count) :float) (incf (stream-count s) 4)
     ;; float32 _rgb_img_x
       (sys::poke _rgb_img_x (send s :buffer) (send s :count) :float) (incf (stream-count s) 4)
     ;; float32 _rgb_img_y
       (sys::poke _rgb_img_y (send s :buffer) (send s :count) :float) (incf (stream-count s) 4)
     ;; float32 _scale
       (sys::poke _scale (send s :buffer) (send s :count) :float) (incf (stream-count s) 4)
     ;; float32 _offset_x
       (sys::poke _offset_x (send s :buffer) (send s :count) :float) (incf (stream-count s) 4)
     ;; float32 _offset_y
       (sys::poke _offset_y (send s :buffer) (send s :count) :float) (incf (stream-count s) 4)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; std_msgs/Header _header
     (send _header :deserialize buf ptr-) (incf ptr- (send _header :serialization-length))
   ;; uint16 _ir_img_width
     (setq _ir_img_width (sys::peek buf ptr- :short)) (incf ptr- 2)
   ;; uint16 _ir_img_height
     (setq _ir_img_height (sys::peek buf ptr- :short)) (incf ptr- 2)
   ;; uint16 _rgb_img_width
     (setq _rgb_img_width (sys::peek buf ptr- :short)) (incf ptr- 2)
   ;; uint16 _rgb_img_height
     (setq _rgb_img_height (sys::peek buf ptr- :short)) (incf ptr- 2)
   ;; uint8 _target_type
     (setq _target_type (sys::peek buf ptr- :char)) (incf ptr- 1)
   ;; uint8 _focuse_mode
     (setq _focuse_mode (sys::peek buf ptr- :char)) (incf ptr- 1)
   ;; float32 _ir_img_x
     (setq _ir_img_x (sys::peek buf ptr- :float)) (incf ptr- 4)
   ;; float32 _ir_img_y
     (setq _ir_img_y (sys::peek buf ptr- :float)) (incf ptr- 4)
   ;; float32 _rgb_img_x
     (setq _rgb_img_x (sys::peek buf ptr- :float)) (incf ptr- 4)
   ;; float32 _rgb_img_y
     (setq _rgb_img_y (sys::peek buf ptr- :float)) (incf ptr- 4)
   ;; float32 _scale
     (setq _scale (sys::peek buf ptr- :float)) (incf ptr- 4)
   ;; float32 _offset_x
     (setq _offset_x (sys::peek buf ptr- :float)) (incf ptr- 4)
   ;; float32 _offset_y
     (setq _offset_y (sys::peek buf ptr- :float)) (incf ptr- 4)
   ;;
   self)
  )

(setf (get forest_fire_detection_system::SingleFireFuse :md5sum-) "5acee9e57a872fd936b9b0d95ff37894")
(setf (get forest_fire_detection_system::SingleFireFuse :datatype-) "forest_fire_detection_system/SingleFireFuse")
(setf (get forest_fire_detection_system::SingleFireFuse :definition-)
      "Header header

# image detecting on info
uint16 ir_img_width
uint16 ir_img_height
uint16 rgb_img_width
uint16 rgb_img_height

# target type
uint8 IS_BACKGROUND = 0
uint8 IS_TARGET = 1
uint8 IS_UNKNOWN = 255

uint8 target_type

# focuse mode
uint8 USE_NONE = 0
uint8 USE_IR  = 1
uint8 USE_RGB  = 2

uint8 focuse_mode

# the x and y pos (sub-pixel) of the single fire, opencv style coordinates
float32 ir_img_x
float32 ir_img_y
float32 rgb_img_x
float32 rgb_img_y

# translation(ir->rgb)
float32 scale
float32 offset_x
float32 offset_y

================================================================================
MSG: std_msgs/Header
# Standard metadata for higher-level stamped data types.
# This is generally used to communicate timestamped data 
# in a particular coordinate frame.
# 
# sequence ID: consecutively increasing ID 
uint32 seq
#Two-integer timestamp that is expressed as:
# * stamp.sec: seconds (stamp_secs) since epoch (in Python the variable is called 'secs')
# * stamp.nsec: nanoseconds since stamp_secs (in Python the variable is called 'nsecs')
# time-handling sugar is provided by the client library
time stamp
#Frame this data is associated with
string frame_id

")



(provide :forest_fire_detection_system/SingleFireFuse "5acee9e57a872fd936b9b0d95ff37894")


