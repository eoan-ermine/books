(defun show-squares (start end)
    (do ((i start (+ i 1)))
        ((> i end) 'done)
        (format t "~A ~A~%" i (* i i))
        (FINISH-OUTPUT)
    )
)

; First argument: list[(variable initial update)]
; Second argument: list[(list of end preds) ... (that will be evaluated and returned)]
; Other args - body

(show-squares 2 5)

; Recursive version:

(defun show-squares (i end)
    (if (> i end)
        'done
        (progn
            (format t "~A ~A~%" i (* i i))
            (show-square (+ i 1) end)
        )
    )
)

(defun our-length (lst)
    (let ((len 0))
        (dolist (obj lst)
            (setf len (+ len 1))
        )
        len
    )
)

(defun our-length (lst)
    (if (null lst)
        0
        (+ (our-length (cdr lst)) 1)
    )
)