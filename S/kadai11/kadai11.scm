(define (reducer acc lst)
  (if (null? lst); (reducer (5 4 3 2 1) ())
    acc; (5 4 3 2 1)
    ;(3 2 1) (4 5)
    (reducer (cons (car lst) acc) (cdr lst))
  )
)

(define (my-reverse lst)
  (reducer () lst)
)

(my-reverse '(1 2 3 4 5))