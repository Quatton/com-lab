	.file	"example.c"
	.option nopic
	.attribute arch, "rv64i2p0_m2p0_a2p0_f2p0_d2p0_c2p0"
	.attribute unaligned_access, 0
	.attribute stack_align, 16
	.text
	.align	1
	.globl	swap_gt
	.type	swap_gt, @function
swap_gt:
	addi	sp,sp,-48
	sd	s0,40(sp)
	addi	s0,sp,48
	sd	a0,-40(s0) 
	sd	a1,-48(s0) 
	# y _ _ _ _ _ _ _
	# x _ _ _ _ _ _ _
	# _ _ _ _ _ _ _ _ _
	# _ _ _ _ _ _ _ _ _
	# _ _ _ _ _ _ _ _ _ 
	# _ _ _ _ _ _ _ _ _
	# ^s0


	ld	a5,-40(s0) # load a0 to a5
	lw	a4,0(a5) # load 
	ld	a5,-48(s0) # load 
	lw	a5,0(a5)
	ble	a4,a5,.L3
	ld	a5,-40(s0)
	lw	a5,0(a5)
	sw	a5,-20(s0)
	ld	a5,-48(s0)
	lw	a4,0(a5)
	ld	a5,-40(s0)
	sw	a4,0(a5)
	ld	a5,-48(s0)
	lw	a4,-20(s0)
	sw	a4,0(a5)
.L3:
	nop
	ld	s0,40(sp)
	addi	sp,sp,48
	jr	ra
	.size	swap_gt, .-swap_gt
	.ident	"GCC: (g2ee5e430018-dirty) 12.2.0"
