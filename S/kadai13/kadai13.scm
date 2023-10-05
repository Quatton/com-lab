(define (my-fold op init l)
  (if (null? l)
      init
      (my-fold op (op (car l) init) (cdr l))))

(define (my-reverse2 l)
  (my-fold cons '() l)
)

(define lst '(1 2 3 4 5 6 7 8 9 10))

(my-reverse2 lst)