(member 'b '(a b c))
; (B C)

; По стандарту сравнивает по ключу.
; Но можно задать и свою функцию

(member '(a) '((a) (z)) :test #'equal)
; ((A) (Z))

; Это называется аргументом по ключу
; Вот еще есть какой: key, это функция
; применяющаяся к каждому элементу перед сравнением

(member 'a '((a b) (c d)) :key #'car)
; ((A B) (C D))

(member 2 '((1) (2)) :key #'car :test #'equal)
; ((2))
(member 2 '((1) (2)) :test #'equal :key #'car)
; ((2))

(member-if #'oddp '(2 3 4))
; (3 4)

(defun our-member-if (fn lst)
    (and (consp lst)
        (if (funcall fn (car lst))
            lst
            (our-member-if fn (cdr lst))
        )
    )
)

(adjoin 'b '(a b c))
; (A B C)
(adjoin 'z '(a b c))
; (Z A B C)

(union '(a b c) '(c b s))
; (A C B S)
(intersection '(a b c) '(b b c))
; (B C)
(set-difference '(a b c d e) '(b e))
; (A C D)