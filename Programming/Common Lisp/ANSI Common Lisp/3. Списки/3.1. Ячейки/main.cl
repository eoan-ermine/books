(defparameter x nil)
(setf x (cons 'a nil))
; (A)

(car x)
; A

(cdr x)
; NIL

(defparameter y nil)
(setf y (list 'a 'b 'c))
; (A B C)

(cdr y)
; (B C)

(defparameter z nil)
(setf z (list 'a (list 'b 'c) 'd))
; (A (B C) D)

(car (cdr z))
; (B C)

(defun our-listp (x)
    (or (null x) (consp x))
)

(defun our-atom (x) (not (consp x)))