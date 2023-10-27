(import (rnrs) (srfi :41))

(define (stream-reducer acc curr f)
  (cond ((stream-null? curr) acc)
        (else (stream-reducer (f acc (stream-car curr)) (stream-cdr curr) f))
  )
)

(define (my-stream-map f st)
  (if (stream-null? st)
      stream-null; empty stream
      (stream-cons (f (stream-car st)) ;would do the same with list
                  (my-stream-map f (stream-cdr st)))))


; partial sum
; 1 2 3 4 5 
; 1 1+2 1+2+3

(define (plus x) 
  (lambda (y) (+ x y))
)

(define (partial-sums-helper s acc)
  (if (stream-null? s) 
    stream-null
    (stream-cons (+ acc (stream-car s))
                (partial-sums-helper (stream-cdr s) (+ acc (stream-car s)))
    )
  )
)

(define (partial-sums s) (partial-sums-helper s 0))

(stream-car (partial-sums (stream 1 2 3 4 5)))
(stream-ref (partial-sums (stream 1 2 3 4 5)) 3)