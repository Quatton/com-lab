(define my-gcd 
  (lambda (x y)
    (
      if (< x y)
        (gcd y x)
        (
          if (= 0 (modulo x y))
            y
            (gcd y (modulo x y))
        )
    )
  )
)

(my-gcd 9801 1287)