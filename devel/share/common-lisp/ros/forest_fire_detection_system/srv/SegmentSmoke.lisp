; Auto-generated. Do not edit!


(cl:in-package forest_fire_detection_system-srv)


;//! \htmlinclude SegmentSmoke-request.msg.html

(cl:defclass <SegmentSmoke-request> (roslisp-msg-protocol:ros-message)
  ((timeOut
    :reader timeOut
    :initarg :timeOut
    :type cl:float
    :initform 0.0))
)

(cl:defclass SegmentSmoke-request (<SegmentSmoke-request>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <SegmentSmoke-request>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'SegmentSmoke-request)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name forest_fire_detection_system-srv:<SegmentSmoke-request> is deprecated: use forest_fire_detection_system-srv:SegmentSmoke-request instead.")))

(cl:ensure-generic-function 'timeOut-val :lambda-list '(m))
(cl:defmethod timeOut-val ((m <SegmentSmoke-request>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader forest_fire_detection_system-srv:timeOut-val is deprecated.  Use forest_fire_detection_system-srv:timeOut instead.")
  (timeOut m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <SegmentSmoke-request>) ostream)
  "Serializes a message object of type '<SegmentSmoke-request>"
  (cl:let ((bits (roslisp-utils:encode-single-float-bits (cl:slot-value msg 'timeOut))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream))
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <SegmentSmoke-request>) istream)
  "Deserializes a message object of type '<SegmentSmoke-request>"
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'timeOut) (roslisp-utils:decode-single-float-bits bits)))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<SegmentSmoke-request>)))
  "Returns string type for a service object of type '<SegmentSmoke-request>"
  "forest_fire_detection_system/SegmentSmokeRequest")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'SegmentSmoke-request)))
  "Returns string type for a service object of type 'SegmentSmoke-request"
  "forest_fire_detection_system/SegmentSmokeRequest")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<SegmentSmoke-request>)))
  "Returns md5sum for a message object of type '<SegmentSmoke-request>"
  "11478f9622703c748b49ba15c30aea4e")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'SegmentSmoke-request)))
  "Returns md5sum for a message object of type 'SegmentSmoke-request"
  "11478f9622703c748b49ba15c30aea4e")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<SegmentSmoke-request>)))
  "Returns full string definition for message of type '<SegmentSmoke-request>"
  (cl:format cl:nil "# time to call the smoke segmentation, in seconds~%float32 timeOut~%~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'SegmentSmoke-request)))
  "Returns full string definition for message of type 'SegmentSmoke-request"
  (cl:format cl:nil "# time to call the smoke segmentation, in seconds~%float32 timeOut~%~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <SegmentSmoke-request>))
  (cl:+ 0
     4
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <SegmentSmoke-request>))
  "Converts a ROS message object to a list"
  (cl:list 'SegmentSmoke-request
    (cl:cons ':timeOut (timeOut msg))
))
;//! \htmlinclude SegmentSmoke-response.msg.html

(cl:defclass <SegmentSmoke-response> (roslisp-msg-protocol:ros-message)
  ((result
    :reader result
    :initarg :result
    :type cl:boolean
    :initform cl:nil))
)

(cl:defclass SegmentSmoke-response (<SegmentSmoke-response>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <SegmentSmoke-response>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'SegmentSmoke-response)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name forest_fire_detection_system-srv:<SegmentSmoke-response> is deprecated: use forest_fire_detection_system-srv:SegmentSmoke-response instead.")))

(cl:ensure-generic-function 'result-val :lambda-list '(m))
(cl:defmethod result-val ((m <SegmentSmoke-response>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader forest_fire_detection_system-srv:result-val is deprecated.  Use forest_fire_detection_system-srv:result instead.")
  (result m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <SegmentSmoke-response>) ostream)
  "Serializes a message object of type '<SegmentSmoke-response>"
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:if (cl:slot-value msg 'result) 1 0)) ostream)
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <SegmentSmoke-response>) istream)
  "Deserializes a message object of type '<SegmentSmoke-response>"
    (cl:setf (cl:slot-value msg 'result) (cl:not (cl:zerop (cl:read-byte istream))))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<SegmentSmoke-response>)))
  "Returns string type for a service object of type '<SegmentSmoke-response>"
  "forest_fire_detection_system/SegmentSmokeResponse")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'SegmentSmoke-response)))
  "Returns string type for a service object of type 'SegmentSmoke-response"
  "forest_fire_detection_system/SegmentSmokeResponse")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<SegmentSmoke-response>)))
  "Returns md5sum for a message object of type '<SegmentSmoke-response>"
  "11478f9622703c748b49ba15c30aea4e")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'SegmentSmoke-response)))
  "Returns md5sum for a message object of type 'SegmentSmoke-response"
  "11478f9622703c748b49ba15c30aea4e")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<SegmentSmoke-response>)))
  "Returns full string definition for message of type '<SegmentSmoke-response>"
  (cl:format cl:nil "bool result~%~%~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'SegmentSmoke-response)))
  "Returns full string definition for message of type 'SegmentSmoke-response"
  (cl:format cl:nil "bool result~%~%~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <SegmentSmoke-response>))
  (cl:+ 0
     1
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <SegmentSmoke-response>))
  "Converts a ROS message object to a list"
  (cl:list 'SegmentSmoke-response
    (cl:cons ':result (result msg))
))
(cl:defmethod roslisp-msg-protocol:service-request-type ((msg (cl:eql 'SegmentSmoke)))
  'SegmentSmoke-request)
(cl:defmethod roslisp-msg-protocol:service-response-type ((msg (cl:eql 'SegmentSmoke)))
  'SegmentSmoke-response)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'SegmentSmoke)))
  "Returns string type for a service object of type '<SegmentSmoke>"
  "forest_fire_detection_system/SegmentSmoke")