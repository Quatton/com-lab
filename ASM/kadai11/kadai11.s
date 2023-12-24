  .globl add128

add128:
  # a0: 2-item array of ull 
  # a1: 2-item array of ull
  # a2: 2-item array of ull

  ld a3, 0(a0)
  ld a4, 0(a1)
  add a5, a3, a4

  sltu t0, a5, a3

  ld a6, 8(a0)
  ld a7, 8(a1)
  add a6, a6, a7
  add a6, a6, t0
  
  sd a5, 0(a2)
  sd a6, 8(a2)

  ret

  

