(defun our-member (obj lst)
    (if (null lst)
        nil
        (if (eql (car lst) obj)
            lst
            (our-member obj (cdr lst))
        )
    )
)

(our-member 'b '(a b c))
; (B C)

(our-member 'z '(a b c))
; NIL