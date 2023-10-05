(define egg (list->stream (list 1 2 3 4)))

(define (my-stream-map f st)
  (if (stream-null? st)
      stream; empty stream
      (cons-stream (f (stream-car st)) ;would do the same with list
                  (my-stream-map f (stream-cdr st)))))

(define egg-map (my-stream-map (lambda (x) (* x x)) egg))

(stream-car egg-map)
(stream-ref egg-map 2)