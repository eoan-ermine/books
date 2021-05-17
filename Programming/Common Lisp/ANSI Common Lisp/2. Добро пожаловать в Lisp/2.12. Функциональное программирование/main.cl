(defparameter lst '(c a r a t))
; ( C A R A T )
(remove 'a lst) ; lst itself stays unchangeed
; ( C R T )

(setf x (remove 'a x)) ; If we wanna change the variable
