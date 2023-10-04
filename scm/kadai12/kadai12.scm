(define (my-assoc idx lst)
  (if (null? lst)
    #f
    ;take the first element
    ;(1 . "One")
    ;take the first element and if right return second
    (if (= idx (caar lst))
      (cdar lst)
      ;if not right, we will my-assoc the rest of the list
      (my-assoc idx (cdr lst))
    )  
  )
)

(my-assoc 1 '((1 . "One") (2 . "Two") (3 . "Three")))
(my-assoc 2 '((1 . "One") (2 . "Two") (3 . "Three")))
(my-assoc 3 '((1 . "One") (2 . "Two") (3 . "Three")))
(my-assoc 4 '((1 . "One") (2 . "Two") (3 . "Three")))
