(define (variable? x) (symbol? x))
; in Scheme, symbols are used to represent variables

(define (same-variable? v1 v2)
  (and (variable? v1) (variable? v2) (eq? v1 v2)))
; Checks if two variables are the same symbol

(define (make-sum a1 a2) (list '+ a1 a2))
; Creates a sum expression

(define (make-op op a1 a2) (list op a1 a2))

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
      (cond ((or (variable? (addend s)) (variable? (augend s))) (make-op op (addend s) (augend s)))
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
                  ((and (op? a) (op? b)) (op (eval a) (eval b)))
            ))
        )
  )
)

(define (deriv-helper exp var)
  (cond ((number? exp) 0); d/dx C = 0
        ((variable? exp) (if (same-variable? exp var) 1 exp)); d/dx x = 1

        ; this is like a match statement
        ; if exp is a sum, then we return the sum of the derivatives of the addend and augend
        ((op? exp) 
        (make-op (car exp) (deriv (addend exp) var)
            (deriv (augend exp) var)))        
        ))

(define (deriv exp var)
  (let ((res (deriv-helper exp var)))
    (cond ((number? res) res)
          ((variable? res) res)
          ((op? res) (eval res))
    )
  )
)