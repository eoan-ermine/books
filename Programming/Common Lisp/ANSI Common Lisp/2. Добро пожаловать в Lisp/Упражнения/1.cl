; a)
(+ (- 5 1) (+ 3 7)) ; =>
(+ 4 10) ; =>
14

; b)
(list 1 (+ 2 3)) ; =>
(list 1 5) ; =>
; (1 5)

; c)
(if (listp 1) (+ 1 2) (+ 3 4)) ; =>
(if nil 3 7) ; =>
7

; d)
(list (and (listp 3) t) (+ 1 2)) ; =>
(list nil 3) ; =>
(cons nil (cons 3 nil)) ; =>
; (nil 3)