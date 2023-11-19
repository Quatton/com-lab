(define (reduce fn lst acc)
  (if (null? lst)
      acc
      (reduce fn (cdr lst) (fn acc (car lst)))))

(define (partition lst pivot)
  ; we will use the reducer that we just wrote
  (reduce (lambda (acc x)
            (if (string<? x pivot)
                (cons (cons x (car acc)) (cdr acc))
                (cons (car acc) (cons x (cdr acc)))))
          lst
          (cons '() '())
  )
)

;test
;(write (partition '("a" "b" "c" "d" "e" "f" "g" "h" "i" "j") "f"))
;(newline)
;ok

(define (quicksort lst)
  (if (null? lst)
      '()
    ;we learnt in the DSA course
    ;that we should choose the larger element
    ;from the first two elements as the pivot
    ;but kinda lazy so let's just choose the first element
    (let* ((pivot (car lst))
           (partitioned (partition (cdr lst) pivot))
           (left (car partitioned))
           (right (cdr partitioned)))
      
      ;so now let's append left and right
      (append (quicksort left) (cons pivot (quicksort right)))
    )
  )
)

;test
; (write (quicksort '("a" "c" "j" "b" "d" "g" "e" "f" "h" "i")))
; (newline)
      