(defun our-third (x)
    (car (cdr (cdr x)))
)
; OUR-THIRD

(our-third '(a b c d))
; C

(defun sum-greater (x y z)
    (> (+ x y) z)
)
; SUM-GREATER

(sum-greater 1 4 3)
; T