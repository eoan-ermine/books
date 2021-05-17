; a)

; (car (x (cdr '(a (b c) d))))
; B

(car (car (cdr (cons 'a (cdr '(a (b c) d))))))

; b)

; (x 13 (/ 1 0))
; 13
3
(or 13 (/ 1 0))

; c)

; (x #'list 1 nil)
; (1)

(apply #'list 1 nil)