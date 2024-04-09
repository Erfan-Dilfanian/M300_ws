
(cl:in-package :asdf)

(defsystem "forest_fire_detection_system-srv"
  :depends-on (:roslisp-msg-protocol :roslisp-utils )
  :components ((:file "_package")
    (:file "SegmentSmoke" :depends-on ("_package_SegmentSmoke"))
    (:file "_package_SegmentSmoke" :depends-on ("_package"))
    (:file "ToggleGrabDataDepthEstimation" :depends-on ("_package_ToggleGrabDataDepthEstimation"))
    (:file "_package_ToggleGrabDataDepthEstimation" :depends-on ("_package"))
  ))