(defun our-copy-tree (tr)
    (if (atom tr)
        tr
        (cons   (our-copy-tree (car tr))
                (our-copy-tree (cdr tr))
        )
    )
)

(substitute 'y 'x '(and (integerp x) (zerop (mod x 2))))
; (AND (INTEGERP X) (ZEROP (MOD X 2)))
; Не сработало, так как список имеет 3 элемента, и ни один из них не x

(subst 'y 'x '(and (integerp x) (zerop (mod x 2))))
; (AND (INTEGERP Y) (ZEROP (MOD Y 2)))
; Сработало, так как функция работает с деревьями

(defun our-subst (new old tree)
    (if (eql tree old)
        new
        (if (atom tree)
            tree
            (cons   (our-subst new old (car tree))
                    (our-subst new old (cdr tree))
            )
    )
)