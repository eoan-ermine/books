(listp '(a b c)) ; True if arg is a list
; T - True

(listp 27)
; NIL - False

(null nil) ; True if arg is empty list
; T

(not nil) ; True if arg is false
; T

(if (listp '(a b c))
    (+ 1 2)
    (+ 5 6)
)

(if (listp 27) (+ 2 3))
; NIL - If else isn't specified then it's NIL

(if 27 1 2)
; 1 - Any expression other than NIL is True

(and t (+ 1 2)) ; If all args true returns last expression, evaluates till argument is true. Take any num of args - macro
; 3