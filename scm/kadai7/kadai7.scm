;f'(x) = (f(x+dx) - f (x))/dx
(define deriv
  (lambda (f dx)
    
    (lambda (x) 
      (/ (- (f (+ x dx)) (f x)) dx)
    )

  )
)

;newton's method
;find the root of f(x) = x^2 - 2
;f'(x) = 2x
;we iterate x_n+1 = x_n - f(x_n)/f'(x_n)
(define (newton-iter g d guess)
(if (good-enough? g guess)
guess
(newton-iter g d (improve g d guess))))
(define (good-enough? g guess)
(< (abs (g guess)) 0.0000001))
(define (improve g d guess)
(- guess (/ (g guess) (d guess))))

(define (newton-iter2 g guess)
  (newton-iter g (deriv g 0.0001) guess)
)

(newton-iter2 (lambda (x) (- (* x x) 2)) 1.0)
;1.4142135624530596