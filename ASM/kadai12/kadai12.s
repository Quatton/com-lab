  .globl dot

dot:
  # a0 = dim of vector
  # a1 = address of vector 1
  # a2 = address of vector 2

  # set dot product to 0
  add sp, sp, -8

.loop:

  # if (a0 == 0) goto done
  beqz a0, .done

  # dot += a1[0] * a2[0]
  fld fa0, 0(sp)
  fld fa1, 0(a1)
  fld fa2, 0(a2)
  fmul.d fa1, fa1, fa2
  fadd.d fa0, fa0, fa1
  fsd fa0, 0(sp)

  # decrement a0
  addi a0, a0, -1

  # bump a1 and a2
  addi a1, a1, 8
  addi a2, a2, 8
  j .loop

.done:
  fld fa0, 0(sp)
  add sp, sp, 8
  ret
