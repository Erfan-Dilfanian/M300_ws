;; Auto-generated. Do not edit!


(when (boundp 'forest_fire_detection_system::SingleFireIR)
  (if (not (find-package "FOREST_FIRE_DETECTION_SYSTEM"))
    (make-package "FOREST_FIRE_DETECTION_SYSTEM"))
  (shadow 'SingleFireIR (find-package "FOREST_FIRE_DETECTION_SYSTEM")))
(unless (find-package "FOREST_FIRE_DETECTION_SYSTEM::SINGLEFIREIR")
  (make-package "FOREST_FIRE_DETECTION_SYSTEM::SINGLEFIREIR"))

(in-package "ROS")
;;//! \htmlinclude SingleFireIR.msg.html
(if (not (find-package "STD_MSGS"))
  (ros::roseus-add-msgs "std_msgs"))


(intern "*IS_BACKGROUND*" (find-package "FOREST_FIRE_DETECTION_SYSTEM::SINGLEFIREIR"))
(shadow '*IS_BACKGROUND* (find-package "FOREST_FIRE_DETECTION_SYSTEM::SINGLEFIREIR"))
(defconstant forest_fire_detection_system::SingleFireIR::*IS_BACKGROUND* 0)
(intern "*IS_HEAT*" (find-package "FOREST_FIRE_DETECTION_SYSTEM::SINGLEFIREIR"))
(shadow '*IS_HEAT* (find-package "FOREST_FIRE_DETECTION_SYSTEM::SINGLEFIREIR"))
(defconstant forest_fire_detection_system::SingleFireIR::*IS_HEAT* 1)
(intern "*IS_UNKNOWN*" (find-package "FOREST_FIRE_DETECTION_SYSTEM::SINGLEFIREIR"))
(shadow '*IS_UNKNOWN* (find-package "FOREST_FIRE_DETECTION_SYSTEM::SINGLEFIREIR"))
(defconstant forest_fire_detection_system::SingleFireIR::*IS_UNKNOWN* 255)

(defun forest_fire_detection_system::SingleFireIR-to-symbol (const)
  (cond
        ((= const 0) 'forest_fire_detection_system::SingleFireIR::*IS_BACKGROUND*)
        ((= const 1) 'forest_fire_detection_system::SingleFireIR::*IS_HEAT*)
        ((= const 255) 'forest_fire_detection_system::SingleFireIR::*IS_UNKNOWN*)
        (t nil)))

(defclass forest_fire_detection_system::SingleFireIR
  :super ros::object
  :slots (_header _img_width _img_height _resize_img_width _resize_img_height _target_type _img_x _img_y ))

(defmethod forest_fire_detection_system::SingleFireIR
  (:init
   (&key
    ((:header __header) (instance std_msgs::Header :init))
    ((:img_width __img_width) 0)
    ((:img_height __img_height) 0)
    ((:resize_img_width __resize_img_width) 0)
    ((:resize_img_height __resize_img_height) 0)
    ((:target_type __target_type) 0)
    ((:img_x __img_x) 0.0)
    ((:img_y __img_y) 0.0)
    )
   (send-super :init)
   (setq _header __header)
   (setq _img_width (round __img_width))
   (setq _img_height (round __img_height))
   (setq _resize_img_width (round __resize_img_width))
   (setq _resize_img_height (round __resize_img_height))
   (setq _target_type (round __target_type))
   (setq _img_x (float __img_x))
   (setq _img_y (float __img_y))
   self)
  (:header
   (&rest __header)
   (if (keywordp (car __header))
       (send* _header __header)
     (progn
       (if __header (setq _header (car __header)))
       _header)))
  (:img_width
   (&optional __img_width)
   (if __img_width (setq _img_width __img_width)) _img_width)
  (:img_height
   (&optional __img_height)
   (if __img_height (setq _img_height __img_height)) _img_height)
  (:resize_img_width
   (&optional __resize_img_width)
   (if __resize_img_width (setq _resize_img_width __resize_img_width)) _resize_img_width)
  (:resize_img_height
   (&optional __resize_img_height)
   (if __resize_img_height (setq _resize_img_height __resize_img_height)) _resize_img_height)
  (:target_type
   (&optional __target_type)
   (if __target_type (setq _target_type __target_type)) _target_type)
  (:img_x
   (&optional __img_x)
   (if __img_x (setq _img_x __img_x)) _img_x)
  (:img_y
   (&optional __img_y)
   (if __img_y (setq _img_y __img_y)) _img_y)
  (:serialization-length
   ()
   (+
    ;; std_msgs/Header _header
    (send _header :serialization-length)
    ;; uint16 _img_width
    2
    ;; uint16 _img_height
    2
    ;; uint16 _resize_img_width
    2
    ;; uint16 _resize_img_height
    2
    ;; uint8 _target_type
    1
    ;; float32 _img_x
    4
    ;; float32 _img_y
    4
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; std_msgs/Header _header
       (send _header :serialize s)
     ;; uint16 _img_width
       (write-word _img_width s)
     ;; uint16 _img_height
       (write-word _img_height s)
     ;; uint16 _resize_img_width
       (write-word _resize_img_width s)
     ;; uint16 _resize_img_height
       (write-word _resize_img_height s)
     ;; uint8 _target_type
       (write-byte _target_type s)
     ;; float32 _img_x
       (sys::poke _img_x (send s :buffer) (send s :count) :float) (incf (stream-count s) 4)
     ;; float32 _img_y
       (sys::poke _img_y (send s :buffer) (send s :count) :float) (incf (stream-count s) 4)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; std_msgs/Header _header
     (send _header :deserialize buf ptr-) (incf ptr- (send _header :serialization-length))
   ;; uint16 _img_width
     (setq _img_width (sys::peek buf ptr- :short)) (incf ptr- 2)
   ;; uint16 _img_height
     (setq _img_height (sys::peek buf ptr- :short)) (incf ptr- 2)
   ;; uint16 _resize_img_width
     (setq _resize_img_width (sys::peek buf ptr- :short)) (incf ptr- 2)
   ;; uint16 _resize_img_height
     (setq _resize_img_height (sys::peek buf ptr- :short)) (incf ptr- 2)
   ;; uint8 _target_type
     (setq _target_type (sys::peek buf ptr- :char)) (incf ptr- 1)
   ;; float32 _img_x
     (setq _img_x (sys::peek buf ptr- :float)) (incf ptr- 4)
   ;; float32 _img_y
     (setq _img_y (sys::peek buf ptr- :float)) (incf ptr- 4)
   ;;
   self)
  )

(setf (get forest_fire_detection_system::SingleFireIR :md5sum-) "9ea94f8510b24f699c5a36dcda64a4f8")
(setf (get forest_fire_detection_system::SingleFireIR :datatype-) "forest_fire_detection_system/SingleFireIR")
(setf (get forest_fire_detection_system::SingleFireIR :definition-)
      "Header header

# image shape
uint16 img_width
uint16 img_height

# reszie shape
uint16 resize_img_width
uint16 resize_img_height

# target type
uint8 IS_BACKGROUND = 0
uint8 IS_HEAT = 1
uint8 IS_UNKNOWN = 255

uint8 target_type

# the x and y pos (sub-pixel) of the single fire, opencv style coordinates
float32 img_x
float32 img_y


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



(provide :forest_fire_detection_system/SingleFireIR "9ea94f8510b24f699c5a36dcda64a4f8")


