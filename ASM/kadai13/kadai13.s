  .globl itoa10

itoa10:
  addi sp, sp, -32
  sd ra, 0(sp)
  sd a1, 8(sp)  # original
  sd a1, 16(sp) # for reverse only
  sd a2, 24(sp) # for reverse only

  bgez a0, .itoa10_loop
  li t2, 45
  sb t2, 0(a1)
  addi a1, a1, 1
  neg a0, a0
  sd a1, 16(sp)

.itoa10_loop:
  li t0, 10
  divu t1, a0, t0
  remu t2, a0, t0
  addi t2, t2, 48

  sb t2, 0(a1)

  addi a1, a1, 1
  sd a1, 24(sp)
  mv a0, t1
  beqz a0, .itoa10_end

  j .itoa10_loop

.itoa10_end:
  ld ra, 0(sp)
  ld a0, 8(sp)
  ld a1, 16(sp)
  ld a2, 24(sp)
  li t0, 0
  sb t0, 0(a2)
  addi a2, a2, -1

.itoa10_reverse:
  # two pointers
  bge a1, a2, .itoa10_reverse_end

  lb t0, 0(a1)
  lb t1, 0(a2)

  sb t0, 0(a2)
  sb t1, 0(a1)

  addi a2, a2, -1
  addi a1, a1, 1

  j .itoa10_reverse

.itoa10_reverse_end:
  addi sp, sp, 32
  ret

  
