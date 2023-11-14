(define triple-index
  (stream-cons (list 1 1 1)
    (stream-map
      (lambda (x)
        (let ((i (car x)) (j (cadr x)) (k (caddr x)))
          ;i++ したい jで抑えられている
          (if (< i j)
            ;then ok
            (list (+ i 1) j k)
            ;j++ first, but kで抑えられている
            (if (< j k)
              ;then ok
              (list i (+ j 1) k)
              ;then k++ first
              (list i k (+ k 1 ))
            )

          )
        )
      )
      triple-index
    )
  )
)

(stream-ref triple-index 1)
