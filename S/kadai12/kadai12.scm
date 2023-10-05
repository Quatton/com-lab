(define (my-assoc idx lst)
  (if (null? lst)
    #f
    ;take the first element
    ;(1 . "One")
    ;take the first element and if right return second
    (if (equal? idx (caar lst))
      (cdar lst)
      ;if not right, we will my-assoc the rest of the list
      (my-assoc idx (cdr lst))
    )  
  )
)

(define alist '(("a" . "One") (4 . "Two") (3 . "Three")))

(my-assoc "a" alist)
(my-assoc 2 alist)
(my-assoc 3 alist)
(my-assoc 4 alist)
