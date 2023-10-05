(define (set-prev prev styes stno)
  (if (eq? (stream-car styes) prev)
    (stream-merge-helper 
      prev 
      (stream-cdr styes) 
      stno
    )
    (cons-stream 
      (stream-car styes) 
      (stream-merge-helper 
        (stream-car styes) 
        (stream-cdr styes) 
        stno)
    )
  )
)

(define (stream-merge-helper prev sta stb)
  (if (stream-null? sta)
    (if (stream-null? stb)
      (stream)
      (set-prev prev stb sta)
    )
    (if (stream-null? stb)
      (set-prev prev sta stb)
      (let ((cara (stream-car sta))
            (carb (stream-car stb)))
        (if (< cara carb)
          (set-prev prev sta stb)
          (set-prev prev stb sta)
        )
      )
    )
  )
)

(define (stream-merge sta stb)
  (stream-merge-helper () sta stb)
)

(define merge_s (stream-merge (list->stream (list 1 2 3 4 5)) (list->stream (list 1 3 5 7 9))))

(stream-ref merge_s 0)
(stream-ref merge_s 1)
(stream-ref merge_s 2)
(stream-ref merge_s 3)
(stream-ref merge_s 4)
(stream-ref merge_s 5)
(stream-ref merge_s 6)