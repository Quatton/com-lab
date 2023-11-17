(import (rnrs) (srfi :41))

(define triple-index
  (stream-cons (list 0 0 0)
    (stream-map
      (lambda (x)
        (let ((i (car x)) (j (cadr x)) (k (caddr x)))
          ;k++ したいが、jがついて来られない場合は j++ する
          (if (= k j)
            (list i 0 (+ k 1))
            ;j++ したいが、iがついて来られない場合は i++ する
            (if (= j i)
              (list 0 (+ j 1) k)
              (list (+ i 1) j k)
            )
          )

        )
      )
      triple-index
    )
  )
)

(define (triples s t u)
    (stream-map
      (lambda (x)
        (let ((i (car x)) (j (cadr x)) (k (caddr x)))
          (list (stream-ref s i) (stream-ref t j) (stream-ref u k))
        )
      )
      triple-index
    )
)

(define (int n) (stream-cons n (int (+ n 1))))

(define pythagorean-triples
  (stream-filter
    (lambda (x)
      (let ((a (car x)) (b (cadr x)) (c (caddr x)))
        (= (+ (* a a) (* b b)) (* c c))
      )
    )
    (triples (int 1) (int 1) (int 1))
  )
)



(stream-ref pythagorean-triples 0)
(stream-ref pythagorean-triples 1)
(stream-ref pythagorean-triples 2)
(stream-ref pythagorean-triples 3)
(stream-ref pythagorean-triples 4)