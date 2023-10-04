(define min-of-two (lambda (a b) (if (< a b) a b)))

(min-of-two 3 4)

(define min-of-four (lambda (a b c d) 
  (min-of-two
    a
    (min-of-two
      b
      (min-of-two
        c d
      )
    )
  )
))

(min-of-four 3 5 4 6)