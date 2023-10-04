(define c ;= counter
  (lambda (acc cur)
    (if (even? cur)
        (- acc 1)
        (+ acc 1)
    )
  )
)

(c 0 1)

(define a ;= accumulator
  (lambda (k b f d e) ; i used a and c already
    (c 
      (c 
        (c 
          (c
            (c 0 d)
            k
          )
          b
        )
        f
      )
      e
    )
  )
)

(define even<odd?
  (lambda (k b f d e) ; i used a and c already
    (if (> (a k b f d e) 0)
      #t
      #f
    )
  )
)

(even<odd? 7 1 2 4 9)

