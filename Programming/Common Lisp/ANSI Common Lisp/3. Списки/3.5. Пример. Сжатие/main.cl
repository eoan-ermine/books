(defun compress (x)
    (if (consp x)
        (compr (car x) 1 (cdr x))
        x
    )
)

(defun compr (elt n lst)
    (if (null lst)
        (list (n-elts elt n))
        (let ((next (car lst)))
            (if (eql next elt)
                (compr elt (+ n 1) (cdr lst))
                (cons (n-elts elt n) (compr next 1 (cdr lst)))
            )
        )
    )
)

; (compress ’(1 1 1 0 1 0 0 0 0 1))

; (compr 1 1 '(1 1 0 1 0 0 0 0 1)) (next = 1)
; (eql 1 1) = True
; (compr 1 2 '(1 0 1 0 0 0 0 1)) (next = 1)
; (eql 1 1) = True
; (compr 1 3 '(0 1 0 0 0 0 1)) (next = 0)
; (eql 1 0) = False
; (cons (n-elts 1 3) (compr 0 1 '(1 0 0 0 0 1)))
; ...

(defun n-elts (elt n)
    (if (> n 1)
        (list n elt)
        elt
    )
)

(defun uncompress (lst)
    (if (null lst)
        nil
        (let ((elt (car lst)) (rest (uncompress (cdr lst))))
            (if (consp elt)
                (append (apply #'list-of elt) rest)
                (cons elt rest)
            )
        )
    )
)

; (uncompress ((3 1) 0 1 (4 0) 1))
; elt = (3 1), rest = (uncompress (0 1 (4 0) 1))
; Okay, I've got it

(defun list-of (n elt)
    (if (zerop n)
        nil
        (cons elt (list-of (- n 1) elt))
    )
)