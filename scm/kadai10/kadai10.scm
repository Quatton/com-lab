(define (sum-total list)
  (if (null? list)
      0
      (+ (car list) (sum-total (cdr list)))
  )
)


(sum-total '(1 2 3 4 5 6 7 8 9 10))
