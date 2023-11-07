  .globl fact

fact:
  beqz a0, .zero
  addi sp, sp, -8
  sw ra, 4(sp) # return address
  sw a0, 0(sp) # n
  addi a0, a0, -1
  call fact
  lw a1, 0(sp) # load n to a1
  mul a0, a1, a0 # a0 = n * fact(n-1)
  lw ra, 4(sp) # load return address
  addi sp, sp, 8
  ret

.zero:
  li a0, 1
  ret
