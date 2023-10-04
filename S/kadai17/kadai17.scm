(define (variable? x) (symbol? x))
; in Scheme, symbols are used to represent variables

(define (same-variable? v1 v2)
  (and (variable? v1) (variable? v2) (eq? v1 v2)))
; Checks if two variables are the same symbol

(define (make-op op a1 a2) (list op a1 a2))


(define (make-sum a1 a2) (list '+ a1 a2))
; Creates a sum expression

(define (make-product m1 m2) (list '* m1 m2))

(define (make-diff s1 s2) (list '- s1 s2))

(define (make-quotient s1 s2) (list '/ s1 s2))


(define (sum? x) (and (pair? x) (eq? (car x) '+)))
; Checks if an expression is a sum
; by checking if it's a pair and if the first element is '+

(define (op? x) (and (pair? x) (
  cond  ((eq? (car x) '+) #t)
        ((eq? (car x) '-) #t)
        ((eq? (car x) '*) #t)
        ((eq? (car x) '/) #t)
        (else #f)
  )
))

(define (addend s) (cadr s))
; imagine s is '(+ 3 x)
; cadr returns the second element of the list
(define (augend s) (caddr s))
; imagine s is '(+ 3 x)
; caddr returns the third element of the list

(define (eval-number s)
    (let ((op (car s)))
      (cond 
            ; 0 + x, x + 0
            ((and (eq? op '+) (eq? (addend s) 0)) (augend s))
            ((and (eq? op '+) (eq? (augend s) 0)) (addend s))
            ; 0 * x = 0, x * 0 = 0
            ((and (eq? op '*) (or (eq? (addend s) 0) (eq? (augend s) 0))) 0)
            ; 1 * x = x, x * 1 = x
            ((and (eq? op '*) (eq? (addend s) 1)) (augend s))
            ((and (eq? op '*) (eq? (augend s) 1)) (addend s))
            ((or (not (number? (addend s))) (not (number? (augend s)))) (make-op op (addend s) (augend s)))
            ((eq? op '+) (+ (addend s) (augend s)))
            ((eq? op '-) (- (addend s) (augend s)))
            ((eq? op '*) (* (addend s) (augend s)))
            ((eq? op '/) (/ (addend s) (augend s)))
      )
    )
)

(define (eval s)
  (cond ((number? s) s)
        ((variable? s) s)
        ((op? s) 
          (let ((op (car s))
                (a (addend s))
                (b (augend s)))

            (cond ((and (not (op? a)) (not (op? b))) (eval-number s))
                  ((and (not (op? a)) (op? b)) (eval-number (make-op op a (eval b))))
                  ((and (op? a) (not (op? b))) (eval-number (make-op op (eval a) b)))
                  ((and (op? a) (op? b)) (eval-number (make-op op (eval a) (eval b))))
            ))
        )
  )
)

(define (deriv-helper exp var)
  (cond ((number? exp) 0); d/dx C = 0
        ((variable? exp) (if (same-variable? exp var) 1 0)); d/dx x = 1

        ; this is like a match statement
        ; if exp is a sum, then we return the sum of the derivatives of the addend and augend
        ((op? exp) 
          (cond ((eq? (car exp) '+) 
                  ; (a + b)' = a' + b' 
                  (make-sum (deriv (cadr exp) var) (deriv (caddr exp) var)))
                ((eq? (car exp) '-) 
                  ; (a - b)' = a' - b'
                  (make-diff (deriv (cadr exp) var) (deriv (caddr exp) var)))
                ((eq? (car exp) '*) 
                  ; (a * b)' = a' * b + a * b'
                  (make-sum 
                                    ;a                    b'
                    (make-product (cadr exp) (deriv (caddr exp) var))
                                    ;a'                   b 
                    (make-product (deriv (cadr exp) var) (caddr exp))
                  )
                )
                ((eq? (car exp) '/) 
                  ; (a / b)' = (a' * b - a * b') / b^2
                  (make-quotient 
                    (make-diff                ;a'                  b
                      (make-product (deriv (cadr exp) var) (caddr exp)) 
                                      ;a                   b'
                      (make-product (cadr exp) (deriv (caddr exp) var))
                    ) 
                                      ;b^2
                    (make-product (caddr exp) (caddr exp))
                  )
                )
          )
        )        
  )
)

(define (deriv exp var)
  (let ((res (deriv-helper exp var)))
    (cond ((number? res) res)
          ((variable? res) res)
          ((op? res) (eval res))
    )
  )
)

; Test with more complex expressions
; '(+ (+ (* x y) (* 3 x)) (* 2 y))
(deriv '(+ (+ (* x y) (* 3 x)) (* x y)) 'x)