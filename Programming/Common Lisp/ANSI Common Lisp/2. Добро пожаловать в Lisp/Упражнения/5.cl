(defun enigma (x)
    (and (not (null x))
        (or (null (car x))
            (enigma (cdr x)))))
; Данная функция возвращает T если один из элементов списка равен nil

(defun mystery (x y)
    (if (null y)
        nil
        (if (eql (car y) x)
            0
            (let ((z (mystery x (cdr y))))
                (and z (+ z 1))
            )
        )
    )
)
; Рекурсивное говно.