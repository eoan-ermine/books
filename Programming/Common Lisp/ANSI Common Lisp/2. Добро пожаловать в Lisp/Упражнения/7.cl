(defun my-contains (obj lst)
    (if (null lst)
        nil
        (or (eql obj (car lst)) (my-contains obj (cdr lst)))
    )
)
