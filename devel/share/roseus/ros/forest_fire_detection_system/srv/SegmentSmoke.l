;; Auto-generated. Do not edit!


(when (boundp 'forest_fire_detection_system::SegmentSmoke)
  (if (not (find-package "FOREST_FIRE_DETECTION_SYSTEM"))
    (make-package "FOREST_FIRE_DETECTION_SYSTEM"))
  (shadow 'SegmentSmoke (find-package "FOREST_FIRE_DETECTION_SYSTEM")))
(unless (find-package "FOREST_FIRE_DETECTION_SYSTEM::SEGMENTSMOKE")
  (make-package "FOREST_FIRE_DETECTION_SYSTEM::SEGMENTSMOKE"))
(unless (find-package "FOREST_FIRE_DETECTION_SYSTEM::SEGMENTSMOKEREQUEST")
  (make-package "FOREST_FIRE_DETECTION_SYSTEM::SEGMENTSMOKEREQUEST"))
(unless (find-package "FOREST_FIRE_DETECTION_SYSTEM::SEGMENTSMOKERESPONSE")
  (make-package "FOREST_FIRE_DETECTION_SYSTEM::SEGMENTSMOKERESPONSE"))

(in-package "ROS")





(defclass forest_fire_detection_system::SegmentSmokeRequest
  :super ros::object
  :slots (_timeOut ))

(defmethod forest_fire_detection_system::SegmentSmokeRequest
  (:init
   (&key
    ((:timeOut __timeOut) 0.0)
    )
   (send-super :init)
   (setq _timeOut (float __timeOut))
   self)
  (:timeOut
   (&optional __timeOut)
   (if __timeOut (setq _timeOut __timeOut)) _timeOut)
  (:serialization-length
   ()
   (+
    ;; float32 _timeOut
    4
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; float32 _timeOut
       (sys::poke _timeOut (send s :buffer) (send s :count) :float) (incf (stream-count s) 4)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; float32 _timeOut
     (setq _timeOut (sys::peek buf ptr- :float)) (incf ptr- 4)
   ;;
   self)
  )

(defclass forest_fire_detection_system::SegmentSmokeResponse
  :super ros::object
  :slots (_result ))

(defmethod forest_fire_detection_system::SegmentSmokeResponse
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

(defclass forest_fire_detection_system::SegmentSmoke
  :super ros::object
  :slots ())

(setf (get forest_fire_detection_system::SegmentSmoke :md5sum-) "11478f9622703c748b49ba15c30aea4e")
(setf (get forest_fire_detection_system::SegmentSmoke :datatype-) "forest_fire_detection_system/SegmentSmoke")
(setf (get forest_fire_detection_system::SegmentSmoke :request) forest_fire_detection_system::SegmentSmokeRequest)
(setf (get forest_fire_detection_system::SegmentSmoke :response) forest_fire_detection_system::SegmentSmokeResponse)

(defmethod forest_fire_detection_system::SegmentSmokeRequest
  (:response () (instance forest_fire_detection_system::SegmentSmokeResponse :init)))

(setf (get forest_fire_detection_system::SegmentSmokeRequest :md5sum-) "11478f9622703c748b49ba15c30aea4e")
(setf (get forest_fire_detection_system::SegmentSmokeRequest :datatype-) "forest_fire_detection_system/SegmentSmokeRequest")
(setf (get forest_fire_detection_system::SegmentSmokeRequest :definition-)
      "# time to call the smoke segmentation, in seconds
float32 timeOut

---
bool result


")

(setf (get forest_fire_detection_system::SegmentSmokeResponse :md5sum-) "11478f9622703c748b49ba15c30aea4e")
(setf (get forest_fire_detection_system::SegmentSmokeResponse :datatype-) "forest_fire_detection_system/SegmentSmokeResponse")
(setf (get forest_fire_detection_system::SegmentSmokeResponse :definition-)
      "# time to call the smoke segmentation, in seconds
float32 timeOut

---
bool result


")



(provide :forest_fire_detection_system/SegmentSmoke "11478f9622703c748b49ba15c30aea4e")


