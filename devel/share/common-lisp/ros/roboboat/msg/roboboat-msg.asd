
(cl:in-package :asdf)

(defsystem "roboboat-msg"
  :depends-on (:roslisp-msg-protocol :roslisp-utils )
  :components ((:file "_package")
    (:file "image_process" :depends-on ("_package_image_process"))
    (:file "_package_image_process" :depends-on ("_package"))
    (:file "node_status" :depends-on ("_package_node_status"))
    (:file "_package_node_status" :depends-on ("_package"))
    (:file "override_motor" :depends-on ("_package_override_motor"))
    (:file "_package_override_motor" :depends-on ("_package"))
  ))