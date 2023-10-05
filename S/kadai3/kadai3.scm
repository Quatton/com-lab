(define my-gcd 
  (lambda (x y)
    (
      if (< x y)
        (my-gcd y x)
        (
          if (= 0 (modulo x y))
            y
            (my-gcd y (modulo x y))
        )
    )
  )
)

(my-gcd 9801 1287)