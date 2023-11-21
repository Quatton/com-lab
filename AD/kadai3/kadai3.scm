(define (stack-push st val)

  ;; スタック`st'の先頭に`val'を追加して、
  (set! st (cons val st))
  st
  ) 

(define (stack-read st)

  ;; スタック`st'の先頭の要素を返す。
  (car st)
  )

(define (stack-pop st)

  ;; スタック`st'から先頭の要素を取り除いたスタックを返す。
  (set! st (cdr st))
  st
  )