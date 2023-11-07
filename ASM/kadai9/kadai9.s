  .globl mystrlen
  .globl mystrcat
  .globl mystrcpy

mystrlen:
  addi sp, sp, -4
  sw ra, 0(sp)
  li a4, 0
  call loop

loop:
  lbu t0, (a0)
  beq t0, zero, end
  addi a0, a0, 1
  addi a4, a4, 1
  j loop

end:
  lw ra, 0(sp)
  addi sp, sp, 4
  mv a0, a4
  jr ra

mystrcpy:
  # a0 = dest
  # a1 = src

  addi sp, sp, -4
  sw ra, 0(sp)
  call mystrcpy_loop
  
mystrcpy_loop:
  lbu t0, (a1)
  sb t0, (a0)
  beqz t0, mystrcpy_end

  addi a0, a0, 1
  addi a1, a1, 1
  j mystrcpy_loop

mystrcpy_end:
  lw ra, 0(sp)
  addi sp, sp, 4
  jr ra

mystrcat:
  # a0 = dest
  # a1 = src

  addi sp, sp, -4
  sw ra, 0(sp)

  mv a2, a0
  call mystrlen
  add a0, a0, a2

  call mystrcpy
  
  lw ra, 0(sp)
  addi sp, sp, 4
  jr ra