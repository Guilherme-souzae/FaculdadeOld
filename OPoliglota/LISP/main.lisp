(defun funcao (x)
  (if (< x 4)
      (/ x 2.0)
      (* x 2)
   )
)

(defparameter lista1 (list 1 2 3))
(defparameter lista2 (list 4 5 6))

(print (append (mapcar #'funcao lista1) (mapcar #'funcao lista2)))