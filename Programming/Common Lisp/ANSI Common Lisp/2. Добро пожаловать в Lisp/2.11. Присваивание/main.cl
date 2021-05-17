(defparameter *glob* 0)
(setf *glob* 98) ; *glob* is 98 now
; 98

(let ((n 10))
    (setf n 2)
    n
)
; 2

(defparameter x nil)
(setf x (list 'a 'b 'c)) ; x is (A B C)
; (A B C)

(setf (car x) 'N) ; Value inserts in place first argument references
; N
; x is (N B C)

(defparameter a nil)
(defparameter c nil)
(defparameter e nil)

(setf a 'b c 'd e 'f) ; Is equal to
(setf a 'b)
(setf c 'd)
(setf e 'f)