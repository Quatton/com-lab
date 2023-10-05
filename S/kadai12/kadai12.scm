(define (my-assoc idx lst)
  (if (null? lst)
    #f
    ;take the first element
    ;(1 . "One")
    ;take the first element and if right return second
    ;(11/6 追記: 連想リストのキーは数値だけとは限りません。
    ;文字列やリストなどがキーになっている場合でも組み込み関数の
    ;assocと同じ挙動を示すようにしてください。)
    (if (equal? idx (caar lst))
      (car lst)
      ;if not right, we will my-assoc the rest of the list
      (my-assoc idx (cdr lst))
    )  
  )
)

(define alist '(((1 2). "One") (2 . "Three") (3 . "Five")))

(my-assoc '(1 2) alist)
(my-assoc 2 alist)
(my-assoc 3 alist)
(my-assoc 4 alist)

(assoc '(1 2) alist)
