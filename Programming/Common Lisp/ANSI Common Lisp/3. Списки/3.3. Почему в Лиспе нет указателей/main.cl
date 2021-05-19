(defparameter x nil)
(defparameter y nil)

(setf x '(a b c))
; (A B C)
(setf y x)
; (A B C)

(eql x y) ; Переменные ссылаются на один и тот же список
; T

; Любое значение в Лиспе является указателем
; Когда присваиваем значение переменной или сохраняем в какую-либо структуру данных
; Туда, на самом деле, записывается указатель