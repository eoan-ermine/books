(defparameter x nil)
(defparameter y nil)

(setf   x '(a b c)
        y (copy-list x)
)
; (A B C)

(defun our-copy-list (lst)
    (if (atom lst)
        lst
        (cons (car lst) (our-copy-list (cdr lst)))
    )
)

(append '(a b) '(c d) '(e))
; (A B C D E)

(setf y (append x))
(eql x y)
; T