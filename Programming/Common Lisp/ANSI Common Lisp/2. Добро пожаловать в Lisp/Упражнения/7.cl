; a)

(defun show-dots (count)
    (do ((i 0 (+ i 1)))
        ((= i count) 'done)
        (format t "~A" ".")
    )
    (FINISH-OUTPUT)
)

(defun show-dots-recursive (i count)
    (if (= i count)
        'done
        (progn
            (format t "~A" ".")
            (show-dots-recursive (+ i 1) count)
        )
    )
    (FINISH-OUTPUT)
)

; b)

(defun our-count (symb lst)
    (let ((count 0))
        (dolist (obj lst)
            (if (eql obj symb)
                (setf count (+ count 1))
            )
        )
        count
    )
)

(defun our-count-rec (symb lst)
    (if (null lst)
        0
        (if (eql symb (car lst))
            (+ (our-count-rec symb (cdr lst)) 1)
            (our-count-rec symb (cdr lst))
        )
    )
)