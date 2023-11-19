(define (btree-empty)
  ;a binary tree is empty when it is null
  '(() () ())
)

(define (btree-null? t)
  (eq? t (btree-empty))
)

(define (btree-insert key val t)
  (cond
    ; if the tree is empty, return a new tree with the key and value 
    ((btree-null? t) (list (cons key val) (btree-empty) (btree-empty)))

    ; if the key is less than the key of the root, insert the key and value into the left subtree
    ((string<? key (caar t)) (list (car t) (btree-insert key val (cadr t)) (caddr t)))

    ; else insert the key and value into the right subtree
    ((string>? key (caar t)) (list (car t) (cadr t) (btree-insert key val (caddr t))))

    ; and if the key is equal to the key of the root, update the value of the root
    (else (list (cons key val) (cadr t) (caddr t)))
  )
)

;; we have to define btree-min for the delete function
(define (btree-min t)

  (cond
    ; if the tree is empty, return an empty tree
    ((btree-null? t) (btree-empty))

    ; if the left subtree is empty, return the root
    ((btree-null? (cadr t)) (car t))

    ; else traverse the left subtree
    (else (btree-min (cadr t)))
  )
)

(define (btree-delete key t)

  ;; 文字列`key'をキーとする項目を、二分探索木`t'から削除し、その木を返す。

  ;; this is kinda annoying becuase we have to move the nodes around

  (cond
    
    ;; if the tree is empty, return an empty tree
    ((btree-null? t) (btree-empty))

    ;; if we want to delete the root, we traverse the right subtree and find the leftmost node
    ((string=? key (caar t)) (

      ;; oh my god this is the annoying part
      ;; there must be a better way to classify these cases
      ;; but it works so idc
      let ((r (caddr t)))
        (if
          ;; but if the right subtree is empty, we return the left subtree
          (btree-null? r) 
          (cadr t)

          ;; else we find the leftmost node in the right subtree
          (let ((m (btree-min r)))
            (list m (cadr t) (btree-delete (car m) r))
          )
        )
      )
    )

    ;; if we want to delete a node in the left subtree, we traverse the left subtree
    ((string<? key (caar t)) (list (car t) (btree-delete key (cadr t)) (caddr t)))

    ;; if we want to delete a node in the right subtree, we traverse the right subtree
    ((string>? key (caar t)) (list (car t) (cadr t) (btree-delete key (caddr t))))
  )
)

(define (btree-search key t)

  ;; 文字列`key'をキーとして二分探索木`t'を検索し、キーとデータのペアを返す。

  ;; 見つからない場合は、#fを返す。

  (cond

    ;; if the tree is empty, return #f
    ((btree-null? t) #f)

    ;; if the key is less than the key of the root, search the left subtree
    ((string<? key (caar t)) (btree-search key (cadr t)))

    ;; if the key is greater than the key of the root, search the right subtree
    ((string>? key (caar t)) (btree-search key (caddr t)))

    ;; if the key is equal to the key of the root, return the root
    ((string=? key (caar t)) (car t))
  )
)
