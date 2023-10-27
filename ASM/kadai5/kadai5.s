	.globl swap_gt

swap_gt:
  
  bgt a0, a1, .swap

.swap:
  mv a2, a1
  mv a1, a0
  mv a0, a2
  ret
