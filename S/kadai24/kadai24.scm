(define (sq x) (* x x))

(define (create-triples i j)
  (let ((triples;=
          (list 
            (- (sq j) (sq i)) 
            (* (* i j) 2) 
            (+ (sq j) (sq i))
          )))
    (cons-stream
      triples
      (if (< (+ i 1) j)
          (create-triples (+ i 1) j)
          (create-triples 1 (+ 1 j))
      ))
  )
)

(define pythagorean-triples (create-triples 1 2))

(stream-ref pythagorean-triples 0)
(stream-ref pythagorean-triples 1)
(stream-ref pythagorean-triples 2)
(stream-ref pythagorean-triples 3)
(stream-ref pythagorean-triples 4)
(stream-ref pythagorean-triples 5)
(stream-ref pythagorean-triples 6)
