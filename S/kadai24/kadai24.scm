(import (rnrs) (srfi :41))

(define (range low high)
  (if (> low high)
      stream-null
      (stream-cons low (range (+ low 1) high))))

; (define (triples s t u)
;   (stream-cons
;     (list (stream-car s) (stream-car t) (stream-car u))
;     (stream-append
;       (
;       (triples (stream-cdr s) (stream-cdr t) (stream-cdr u))
;     )
;   )
; )

(define (interleave s1 s2)
  (if (stream-null? s1)
      s2
      (stream-cons (stream-car s1)
      (interleave s2 (stream-cdr s1)))))

(define (pairs s t)
  (stream-cons 
    (list (stream-car s) (stream-car t)) 
    (interleave ;;ここだけ先ほどのプログラムから変更する。
      (stream-map (lambda (x) (list (stream-car s) x))
                  (stream-cdr t))
      (pairs (stream-cdr s) (stream-cdr t)))))

(define (triples s t u)
  (stream-cons
    (list (stream-car s) (stream-car t) (stream-car u))
    (interleave
      (stream-map (lambda (ptu) (list (stream-car s) (car ptu) (cadr ptu)))
                  (pairs t (stream-cdr u)))
      (triples (stream-cdr s) (stream-cdr t) (stream-cdr u)))))

(define integers (range 1 +inf.0))

(define intriples
  (triples integers integers integers))

(define pythagorean-triples
  (stream-filter
    (lambda (x) (
      let (
          (a (car x))
          (b (cadr x))
          (c (caddr x))
          )
        (and (= (+ (* a a) (* b b)) (* c c)))
      )
    )
    intriples
  )
)

(stream-ref pythagorean-triples 0)
(stream-ref pythagorean-triples 2)
  