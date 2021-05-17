(format t "~A plus ~A equals ~A.~%" 2 3 (+ 2 3))
; Result of expr eval: NIL

(defun askem (string)
    (format t "~A" string)
    (FINISH-OUTPUT)
    (read)
)

(askem "How old are you? ")
; 29