(assert
    (equal
        (mapcar #'(lambda (x) (+ x 10)) '(1 2 3))
        '(11 12 13)
    )
)

(assert
    (equal
        (mapcar #'list '(a b c) '(1 2 3 4))
        '((A 1) (B 2) (C 3))
    )
)

(assert
    (equal
        (maplist #'(lambda (x) x) '(a b c))
        '((A B C) (B C) (C))
    )
)