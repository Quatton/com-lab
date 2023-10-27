(define (my-stream-map f st)
  (if (stream-null? st)
      (stream); empty stream
      (cons-stream (f (stream-car st)) ;would do the same with list
          (my-stream-map f (stream-cdr st)))))

(define squared_s (my-stream-map square (list->stream (list 1 2 3 4))))
(stream-car squared_s)
(stream-ref squared_s 2)

