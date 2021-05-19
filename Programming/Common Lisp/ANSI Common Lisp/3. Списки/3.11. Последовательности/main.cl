(length '(a b c))
; 3

(subseq '(a b c d) 1 2)
; second arg - первый аргумент, не подлежащий копированию
; (B)

(subseq '(a b c d) 1)
; (B C D)

(reverse '(a b c))
; (C B A)

(defun mirror? (s)
    (let ((len (length s)))
        (and (evenp len)
            (let ((mid (/ len 2)))
                (equal  (subseq s 0 mid)
                        (reverse (subseq s mid))
                )
            )
        )
    )
)

(defun mirror?? (x)
    (equal x (reverse x))
)

(mirror? '(a b b a))
; T

(sort '(0 2 1 3 8) #'>)
; (8 3 2 1 0)
; Деструктивна. Модифицирует исходный список

(defun nthmost (n lst)
    (nth    (- n 1)
            (sort (copy-list lst) #'>)
    )
)

(nthmost 2 '(0 2 1 3 8))
; 3

(every #'oddp '(1 3 5))
; T
(some #'evenp '(1 2 3))
; T

(every #'> '(1 3 5) '(0 2 4))
; T