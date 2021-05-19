(defun proper-list? (x)
    (or (null x)
        (and    (consp x)
                (proper-list? (cdr x))
        )
    )
)

(defparameter pair nil)
(setf pair (cons 'a 'b))
; (A . B) - Not proper list. Точечная пара

(car pair)
; A
(cdr pair)
; B

'(a . (b . (c . nil)))
; (A B C)

(cons 'a (cons 'b (cons 'c 'd)))
; (A B C . D)

'(a . (b . nil))
'(a . (b))
'(a b . nil)
'(a b)
; (A B)