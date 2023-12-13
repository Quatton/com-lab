  .globl mystrcmp

mystrcmp:
  addi sp, sp, -16
  sd ra, 0(sp)
  call loop

loop:
  lbu a3, (a0)
  lbu a4, (a1)
  beq a3, zero, end
  beq a4, zero, end
  bne a3, a4, end
  addi a0, a0, 1
  addi a1, a1, 1
  j loop

end:
  ld ra, 0(sp)
  addi sp, sp, 16
  sub a0, a3, a4
  ret
