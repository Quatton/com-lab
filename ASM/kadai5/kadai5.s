	.globl swap_gt

swap_gt:
  lw a3, 0(a0) # load x to a3
  lw a4, 0(a1) # load y to a4
  bgt a3, a4, .swap # *x > *y

.swap:
  sw a4, 0(a0) # *x -> 
  sw a3, 0(a1) # *y -> 
  ret
