; (push obj lst) equal to
; (setf lst (cons obj lst))

; (pop lst) equal to
; (let ((x (car lst))
;     (setf lst (cdr lst)) x))

(defparameter x nil)
(defparameter y nil)

(setf x '(b))
; (B)
(push 'a x)
; (A B)
(setf y x)
; (A B)
(pop x)
; A
x
; (B)
y
; (A B)

(defun our-reverse (lst)
    (let ((acc nil))
        (dolist (elt lst)
            (push elt acc)
        )
        acc
    )
)

(let ((x '(a b)))
    (pushnew 'c x)
    (pushnew 'a x)
    x
)
; (C A B)