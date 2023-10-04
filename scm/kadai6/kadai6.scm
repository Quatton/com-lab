(define fib2; using tail recursion
  (lambda (n)
    (helper 0 1 n)
  )
)

(define helper; this helper will recurse itself until the count reaches 0
  (lambda (acc1 acc2 count)
    (if (= count 0)
      acc1
      (helper acc2 (+ acc1 acc2) (- count 1))
    )
  )
)

(fib2 11)
;(helper 0 1 11)
;(helper 1 1 10)
;(helper 1 2 9)
;(helper 2 3 8)
;(helper 3 5 7)
;... much more 'efficient' than fib
;(fib 11)
;(+ (fib 10) (fib 9))
;(+ (+ (fib 9) (fib 8)) (+ (fib 8) (fib 7)))
;(+ (+ (+ (fib 8) (fib 7)) (+ (fib 7) (fib 6))) (+ (+ (fib 7) (fib 6)) (+ (fib 6) (fib 5))))
;... not so efficient
