;; Auto-generated. Do not edit!


(when (boundp 'forest_fire_detection_system::ToggleGrabDataDepthEstimation)
  (if (not (find-package "FOREST_FIRE_DETECTION_SYSTEM"))
    (make-package "FOREST_FIRE_DETECTION_SYSTEM"))
  (shadow 'ToggleGrabDataDepthEstimation (find-package "FOREST_FIRE_DETECTION_SYSTEM")))
(unless (find-package "FOREST_FIRE_DETECTION_SYSTEM::TOGGLEGRABDATADEPTHESTIMATION")
  (make-package "FOREST_FIRE_DETECTION_SYSTEM::TOGGLEGRABDATADEPTHESTIMATION"))
(unless (find-package "FOREST_FIRE_DETECTION_SYSTEM::TOGGLEGRABDATADEPTHESTIMATIONREQUEST")
  (make-package "FOREST_FIRE_DETECTION_SYSTEM::TOGGLEGRABDATADEPTHESTIMATIONREQUEST"))
(unless (find-package "FOREST_FIRE_DETECTION_SYSTEM::TOGGLEGRABDATADEPTHESTIMATIONRESPONSE")
  (make-package "FOREST_FIRE_DETECTION_SYSTEM::TOGGLEGRABDATADEPTHESTIMATIONRESPONSE"))

(in-package "ROS")





(defclass forest_fire_detection_system::ToggleGrabDataDepthEstimationRequest
  :super ros::object
  :slots (_start ))

(defmethod forest_fire_detection_system::ToggleGrabDataDepthEstimationRequest
  (:init
   (&key
    ((:start __start) nil)
    )
   (send-super :init)
   (setq _start __start)
   self)
  (:start
   (&optional (__start :null))
   (if (not (eq __start :null)) (setq _start __start)) _start)
  (:serialization-length
   ()
   (+
    ;; bool _start
    1
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; bool _start
       (if _start (write-byte -1 s) (write-byte 0 s))
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; bool _start
     (setq _start (not (= 0 (sys::peek buf ptr- :char)))) (incf ptr- 1)
   ;;
   self)
  )

(defclass forest_fire_detection_system::ToggleGrabDataDepthEstimationResponse
  :super ros::object
  :slots (_result ))

(defmethod forest_fire_detection_system::ToggleGrabDataDepthEstimationResponse
  (:init
   (&key
    ((:result __result) nil)
    )
   (send-super :init)
   (setq _result __result)
   self)
  (:result
   (&optional (__result :null))
   (if (not (eq __result :null)) (setq _result __result)) _result)
  (:serialization-length
   ()
   (+
    ;; bool _result
    1
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; bool _result
       (if _result (write-byte -1 s) (write-byte 0 s))
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; bool _result
     (setq _result (not (= 0 (sys::peek buf ptr- :char)))) (incf ptr- 1)
   ;;
   self)
  )

(defclass forest_fire_detection_system::ToggleGrabDataDepthEstimation
  :super ros::object
  :slots ())

(setf (get forest_fire_detection_system::ToggleGrabDataDepthEstimation :md5sum-) "0304abb62c1d15138b7d0bfcf0865362")
(setf (get forest_fire_detection_system::ToggleGrabDataDepthEstimation :datatype-) "forest_fire_detection_system/ToggleGrabDataDepthEstimation")
(setf (get forest_fire_detection_system::ToggleGrabDataDepthEstimation :request) forest_fire_detection_system::ToggleGrabDataDepthEstimationRequest)
(setf (get forest_fire_detection_system::ToggleGrabDataDepthEstimation :response) forest_fire_detection_system::ToggleGrabDataDepthEstimationResponse)

(defmethod forest_fire_detection_system::ToggleGrabDataDepthEstimationRequest
  (:response () (instance forest_fire_detection_system::ToggleGrabDataDepthEstimationResponse :init)))

(setf (get forest_fire_detection_system::ToggleGrabDataDepthEstimationRequest :md5sum-) "0304abb62c1d15138b7d0bfcf0865362")
(setf (get forest_fire_detection_system::ToggleGrabDataDepthEstimationRequest :datatype-) "forest_fire_detection_system/ToggleGrabDataDepthEstimationRequest")
(setf (get forest_fire_detection_system::ToggleGrabDataDepthEstimationRequest :definition-)
      "# toggle the GrabData
bool start

---
bool result


")

(setf (get forest_fire_detection_system::ToggleGrabDataDepthEstimationResponse :md5sum-) "0304abb62c1d15138b7d0bfcf0865362")
(setf (get forest_fire_detection_system::ToggleGrabDataDepthEstimationResponse :datatype-) "forest_fire_detection_system/ToggleGrabDataDepthEstimationResponse")
(setf (get forest_fire_detection_system::ToggleGrabDataDepthEstimationResponse :definition-)
      "# toggle the GrabData
bool start

---
bool result


")



(provide :forest_fire_detection_system/ToggleGrabDataDepthEstimation "0304abb62c1d15138b7d0bfcf0865362")


