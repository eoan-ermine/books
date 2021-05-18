; a)

; (defun summit (lst)
;    (remove nil lst)
;    (apply #'+ lst)
; ) - некорректно, ибо lst не присваивается список, в котором удалено nil

; correct version:

(defun summit (lst)
    (setf lst (remove nil lst))
    (apply #'+ lst)
)

; b)

; (defun summit (lst)
;     (let ((x (car lst)))
;         (if (null x)
;             (summit (cdr lst))
;             (+ x (summit (cdr lst))))))

; Некорректно, ибо нет условия выхода из рекурсии

(defun summit (lst)
    (if (null lst)
        0
        (let ((x (car lst)))
            (if (null x)
                (summit (cdr lst))
                (+ x (summit (cdr lst)))
            )
        )
    )
)