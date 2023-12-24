(define (make-monitored f)
  (let ((i 0))
    (lambda (param)
      (cond ((eq? 'how-many-calls? param) i)
            ((eq? 'reset-count param) (set! i 0))
            (else 
              (set! i (+ 1 i))
              (f param)
            )
       )
    )
  )
)

(define s (make-monitored sqrt)) 
(s 100)
(s 100)
(s 100)
(s 'how-many-calls?)
(s 'reset-count)
(s 900)
(s 'how-many-calls?)