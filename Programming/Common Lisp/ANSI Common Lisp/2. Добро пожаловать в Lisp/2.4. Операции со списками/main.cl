(cons 'a '(b c d))
; (A B C D)

(cons 'a (cons 'b nil))
; (A B)

(list 'a 'b)
; (A B)

(car '(a b c))
; A - head of the list

(cdr '(a b c))
; (B C) - Tail of the list

(car (cdr(cdr '(a b c d))))
; C

(third '(a b c d))
; C