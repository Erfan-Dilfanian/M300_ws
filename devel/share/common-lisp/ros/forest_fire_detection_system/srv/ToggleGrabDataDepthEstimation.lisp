; Auto-generated. Do not edit!


(cl:in-package forest_fire_detection_system-srv)


;//! \htmlinclude ToggleGrabDataDepthEstimation-request.msg.html

(cl:defclass <ToggleGrabDataDepthEstimation-request> (roslisp-msg-protocol:ros-message)
  ((start
    :reader start
    :initarg :start
    :type cl:boolean
    :initform cl:nil))
)

(cl:defclass ToggleGrabDataDepthEstimation-request (<ToggleGrabDataDepthEstimation-request>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <ToggleGrabDataDepthEstimation-request>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'ToggleGrabDataDepthEstimation-request)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name forest_fire_detection_system-srv:<ToggleGrabDataDepthEstimation-request> is deprecated: use forest_fire_detection_system-srv:ToggleGrabDataDepthEstimation-request instead.")))

(cl:ensure-generic-function 'start-val :lambda-list '(m))
(cl:defmethod start-val ((m <ToggleGrabDataDepthEstimation-request>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader forest_fire_detection_system-srv:start-val is deprecated.  Use forest_fire_detection_system-srv:start instead.")
  (start m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <ToggleGrabDataDepthEstimation-request>) ostream)
  "Serializes a message object of type '<ToggleGrabDataDepthEstimation-request>"
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:if (cl:slot-value msg 'start) 1 0)) ostream)
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <ToggleGrabDataDepthEstimation-request>) istream)
  "Deserializes a message object of type '<ToggleGrabDataDepthEstimation-request>"
    (cl:setf (cl:slot-value msg 'start) (cl:not (cl:zerop (cl:read-byte istream))))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<ToggleGrabDataDepthEstimation-request>)))
  "Returns string type for a service object of type '<ToggleGrabDataDepthEstimation-request>"
  "forest_fire_detection_system/ToggleGrabDataDepthEstimationRequest")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'ToggleGrabDataDepthEstimation-request)))
  "Returns string type for a service object of type 'ToggleGrabDataDepthEstimation-request"
  "forest_fire_detection_system/ToggleGrabDataDepthEstimationRequest")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<ToggleGrabDataDepthEstimation-request>)))
  "Returns md5sum for a message object of type '<ToggleGrabDataDepthEstimation-request>"
  "0304abb62c1d15138b7d0bfcf0865362")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'ToggleGrabDataDepthEstimation-request)))
  "Returns md5sum for a message object of type 'ToggleGrabDataDepthEstimation-request"
  "0304abb62c1d15138b7d0bfcf0865362")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<ToggleGrabDataDepthEstimation-request>)))
  "Returns full string definition for message of type '<ToggleGrabDataDepthEstimation-request>"
  (cl:format cl:nil "# toggle the GrabData~%bool start~%~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'ToggleGrabDataDepthEstimation-request)))
  "Returns full string definition for message of type 'ToggleGrabDataDepthEstimation-request"
  (cl:format cl:nil "# toggle the GrabData~%bool start~%~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <ToggleGrabDataDepthEstimation-request>))
  (cl:+ 0
     1
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <ToggleGrabDataDepthEstimation-request>))
  "Converts a ROS message object to a list"
  (cl:list 'ToggleGrabDataDepthEstimation-request
    (cl:cons ':start (start msg))
))
;//! \htmlinclude ToggleGrabDataDepthEstimation-response.msg.html

(cl:defclass <ToggleGrabDataDepthEstimation-response> (roslisp-msg-protocol:ros-message)
  ((result
    :reader result
    :initarg :result
    :type cl:boolean
    :initform cl:nil))
)

(cl:defclass ToggleGrabDataDepthEstimation-response (<ToggleGrabDataDepthEstimation-response>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <ToggleGrabDataDepthEstimation-response>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'ToggleGrabDataDepthEstimation-response)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name forest_fire_detection_system-srv:<ToggleGrabDataDepthEstimation-response> is deprecated: use forest_fire_detection_system-srv:ToggleGrabDataDepthEstimation-response instead.")))

(cl:ensure-generic-function 'result-val :lambda-list '(m))
(cl:defmethod result-val ((m <ToggleGrabDataDepthEstimation-response>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader forest_fire_detection_system-srv:result-val is deprecated.  Use forest_fire_detection_system-srv:result instead.")
  (result m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <ToggleGrabDataDepthEstimation-response>) ostream)
  "Serializes a message object of type '<ToggleGrabDataDepthEstimation-response>"
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:if (cl:slot-value msg 'result) 1 0)) ostream)
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <ToggleGrabDataDepthEstimation-response>) istream)
  "Deserializes a message object of type '<ToggleGrabDataDepthEstimation-response>"
    (cl:setf (cl:slot-value msg 'result) (cl:not (cl:zerop (cl:read-byte istream))))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<ToggleGrabDataDepthEstimation-response>)))
  "Returns string type for a service object of type '<ToggleGrabDataDepthEstimation-response>"
  "forest_fire_detection_system/ToggleGrabDataDepthEstimationResponse")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'ToggleGrabDataDepthEstimation-response)))
  "Returns string type for a service object of type 'ToggleGrabDataDepthEstimation-response"
  "forest_fire_detection_system/ToggleGrabDataDepthEstimationResponse")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<ToggleGrabDataDepthEstimation-response>)))
  "Returns md5sum for a message object of type '<ToggleGrabDataDepthEstimation-response>"
  "0304abb62c1d15138b7d0bfcf0865362")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'ToggleGrabDataDepthEstimation-response)))
  "Returns md5sum for a message object of type 'ToggleGrabDataDepthEstimation-response"
  "0304abb62c1d15138b7d0bfcf0865362")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<ToggleGrabDataDepthEstimation-response>)))
  "Returns full string definition for message of type '<ToggleGrabDataDepthEstimation-response>"
  (cl:format cl:nil "bool result~%~%~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'ToggleGrabDataDepthEstimation-response)))
  "Returns full string definition for message of type 'ToggleGrabDataDepthEstimation-response"
  (cl:format cl:nil "bool result~%~%~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <ToggleGrabDataDepthEstimation-response>))
  (cl:+ 0
     1
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <ToggleGrabDataDepthEstimation-response>))
  "Converts a ROS message object to a list"
  (cl:list 'ToggleGrabDataDepthEstimation-response
    (cl:cons ':result (result msg))
))
(cl:defmethod roslisp-msg-protocol:service-request-type ((msg (cl:eql 'ToggleGrabDataDepthEstimation)))
  'ToggleGrabDataDepthEstimation-request)
(cl:defmethod roslisp-msg-protocol:service-response-type ((msg (cl:eql 'ToggleGrabDataDepthEstimation)))
  'ToggleGrabDataDepthEstimation-response)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'ToggleGrabDataDepthEstimation)))
  "Returns string type for a service object of type '<ToggleGrabDataDepthEstimation>"
  "forest_fire_detection_system/ToggleGrabDataDepthEstimation")