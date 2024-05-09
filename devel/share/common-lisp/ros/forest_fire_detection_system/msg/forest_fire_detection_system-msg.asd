
(cl:in-package :asdf)

(defsystem "forest_fire_detection_system-msg"
  :depends-on (:roslisp-msg-protocol :roslisp-utils :std_msgs-msg
)
  :components ((:file "_package")
    (:file "SingleFireFuse" :depends-on ("_package_SingleFireFuse"))
    (:file "_package_SingleFireFuse" :depends-on ("_package"))
    (:file "SingleFireIR" :depends-on ("_package_SingleFireIR"))
    (:file "_package_SingleFireIR" :depends-on ("_package"))
    (:file "SingleFireRGB" :depends-on ("_package_SingleFireRGB"))
    (:file "_package_SingleFireRGB" :depends-on ("_package"))
  ))