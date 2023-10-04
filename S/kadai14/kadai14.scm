(define (complex a b)
  (cons a b)
) ; aを実数部、bを虚数部とする複素数を返す。

(define (complex= c1 c2)
  (and (= (car c1) (car c2)) (= (cdr c1) (cdr c2)))
) ; 複素数`c1'と`c2'が等しいかどうかをブール値で返す。

(define (complex+ c1 c2)
  (complex (+ (car c1) (car c2)) (+ (cdr c1) (cdr c2)))
) ; 複素数`c1'と`c2'の和を返す。

(define (complex* c1 c2)
  (complex 
    (-  (* (car c1) (car c2)) 
        (* (cdr c1) (cdr c2))
    ) 
    
    (+  (* (car c1) (cdr c2)) 
        (* (cdr c1) (car c2))
    )
  )
) ; 複素数`c1'と`c2'の積を返す。

; test
(complex= (complex 1 2) (complex 1 2))
(complex= (complex 1 2) (complex 2 1))
(complex= (complex+ (complex 1 2) (complex 3 4)) (complex 4 6))
(complex= (complex* (complex 1 2) (complex 3 4)) (complex 5 10))