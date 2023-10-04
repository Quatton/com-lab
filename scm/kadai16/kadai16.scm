(define (if-fun exp1 exp2 exp3)
  (if exp1 exp2 exp3))



(define (fact3 n)
  (if-fun (< n 1)
    1
    (* n (fact3 (- n 1)))))

(fact3 0)

(define (fact4 n)
  (if (< n 1)
    1
    (* n (fact4 (- n 1)))))

(fact4 10)
; 3628800