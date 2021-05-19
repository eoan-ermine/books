; Помимо car и cdr есть вся эта хрень:

(nth 0 '(a b c))
; A

(nthcdr 0 '(a b c))
; (A B C)
(nthcdr 2 '(a b c))
; (C)

(defun our-nthcdr (n lst)
    (if (zerop n)
        (lst)
        (our-ntchdr (- n 1) (cdr lst))
    )
)

(zerop 0)
; T
(zerop 2)
; NIL

(last '(a b c))
; (C) - последняя ячейка. Не последний элемент.

(first '(a b c))
(second '(a b c))
(third '(a b c))
; ...
(tenth '(a b c))

(cadr '(a b c))
; B - car от cdr
(caddr '(a b c)) 
; C - car от cdr от cdr

; Еще есть cadddr и caddddr

