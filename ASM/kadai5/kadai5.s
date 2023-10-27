	.globl swap_gt

swap_gt: # void swap_gt(int *x, int *y)
  lw a3, 0(a0) # a3 = *x
  lw a4, 0(a1) # a4 = *y
  
  # if (a3 > a4) swap()
  blt a3, a4, .no_swap
  sw a4, 0(a0) # *x = a4
  sw a3, 0(a1) # *y = a3

.no_swap:
  jr ra
