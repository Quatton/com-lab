  .globl mystrlen
  .globl mystrcat
  .globl mystrcpy

mystrlen:
  addi sp, sp, -16
  sw ra, 0(sp)
  li a4, 0

.loop:
  lbu t0, 0(a0)
  beq t0, zero, .end
  addi a0, a0, 1
  addi a4, a4, 1
  j .loop

.end:
  mv a0, a4

  lw ra, 0(sp)
  addi sp, sp, 16
  ret

mystrcpy:
  # a0 = dest
  # a1 = src

  addi sp, sp, -16
  sw ra, 0(sp)
  # call .mystrcpy_loop
  
.mystrcpy_loop:
  lbu t0, 0(a1)
  sb t0, 0(a0)
  beqz t0, .mystrcpy_end

  addi a0, a0, 1
  addi a1, a1, 1
  j .mystrcpy_loop

.mystrcpy_end:
  lw ra, 0(sp)
  addi sp, sp, 16
  jr ra

mystrcat:
  # a0 = dest
  # a1 = src

  addi sp, sp, -16
  sd a0, 0(sp)
  sw ra, 8(sp)

  mv a2, a0
  call mystrlen
  add a0, a0, a2

  call mystrcpy

  ld a0, 0(sp)
  lw ra, 8(sp)
  addi sp, sp, 16
  jr ra
