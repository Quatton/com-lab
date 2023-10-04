(define (f1 l)
  (car (cadr (cdr l)))
)

(define (f2 l)
  (car (car l))
)

(define (f3 l)
  (cadadr (cadadr (cadadr l)))
)

(f1 '(1 2 (3 4) 5))
(f2 '((3)))
(f3 '(1 (2 (4 (5 (6 (7 3)))))))