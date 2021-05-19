(eql (cons 'a nil) (cons 'a nil))
; NIL

(defparameter x nil)
(setf x (cons 'a nil))
; (A)
(eql x x)
; T

(equal x (cons 'a nil))
; T

(defun our-equal (x y)
    (or (eql x y)
        (and (consp x)
            (consp y)
            (our-equal (car x) (car y))
            (our-equal (cdr x) (cdr y))
        )
    )
)