(let ((x1 1) (y 2))
    (+ x1 y)
) ; Variable exists only in let body
; 3

(defun ask-number ()
    (format t "Please enter a number. ")
    (FINISH-OUTPUT)
    (let ((val (read)))
        (if (numberp val)
            val
            (ask-number)
        )
    )
)

(ask-number)
; 52 if input is 52

(defparameter *glob* 99) ; Global variable. Asterisk is convention to distinguish with local var with some name
; *GLOB*

(defconstant limit (+ *glob* 1)) ; Vars with same name cannot be defined. Convention: +limit+
(boundp '*glob*) ; Check if name is bounded to var/const
; T

