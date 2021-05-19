(defparameter trans '((+ . "add") (- . "subtract")))
; ((+ . "add") (- . "subtract"))

(assoc '+ trans)
; (+ . "add")

(assoc '* trans)
; NIL

(defun our-assoc (key alist)
    (and (consp alist)
        (let ((pair (car alist)))
            (if (eql key (car pair))
                pair
                (our-assoc key (cdr alist))
            )
        )
    )
)

; Настоящая функцая assoc принимает несколько аргументов, включая :test и :key
; Также существует assoc-if