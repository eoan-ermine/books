(function +)
; #<Compiled-Function + 17BA4E>

; (#'+)
; #<Compiled-Function + 17BA4E>

(apply #'+ '(1 2 3)) ; Takes fn and args
; 6
(+ 1 2 3)
; 6

; Apply requires last argument to be a list:
(apply #'+ 1 2 '(3 4 5))
; 15

; funcall is quite similiar to apply but don't requires it
(funcall #'+ 1 2 3)
; 6

(lambda (x y)
    (+ x y)
)

((lambda (x) (+ x 100)) 1)
; 101

(funcall #'(lambda (x) (+ x 100)) 1)
; 101