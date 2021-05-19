(defparameter lst nil)
(setf lst (list 'a 'b 'c))
; (A B C)
(setf lst nil)
; NIL

; Lisp выделил на куче место для списка
; А потом, как мы присвоили lst nil,
; освободил его
; Ибо теперь ни одна из трех ячеек не
; не может быть использована