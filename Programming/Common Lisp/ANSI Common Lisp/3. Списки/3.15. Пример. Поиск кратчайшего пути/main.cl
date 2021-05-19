(defparameter min nil)
(setf min '((a b c) (b c) (c d)))

(cdr (assoc 'a min))
; (B C) - узлы, в которые можно попасть из узла a

(defun shortest-path (start end net)
    (bfs end (list (list start)) net)
)

(defun bfs (end queue net)
    (if (null queue)
        nil
        (let ((path (car queue)))
            (let ((node (car path)))
                (if (eql node end)
                    (reverse path)
                    (bfs end
                        (append
                            (cdr queue)
                            (new-paths path mode net)
                        )
                    )
                )
            )
        )
    )
)

(defun new-paths (path node net)
    (mapcar #'(lambda (n) (cons n path))
        (cdr (assoc node net))
    )
)