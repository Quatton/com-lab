  .globl maxof2
  .globl maxof3

maxof2:
  add sp, sp, -4
  sw ra, 0(sp)

  bgt a0, a1, maxof2_else
  mv a0, a1

  lw ra, 0(sp)
  add sp, sp, 4
  jr ra

maxof2_else:
  lw ra, 0(sp)
  add sp, sp, 4

  jr ra

maxof3:
  add sp, sp, -4
  sw ra, 0(sp)

  jal maxof2
  mv a1, a2

  jal maxof2
  
  lw ra, 0(sp)
  add sp, sp, 4

  jr ra


