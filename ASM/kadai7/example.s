	.file	"example.c"
	.option nopic
	.attribute arch, "rv64i2p0_m2p0_a2p0_f2p0_d2p0_c2p0"
	.attribute unaligned_access, 0
	.attribute stack_align, 16
	.text
	.align	1
	.globl	mystrcmp
	.type	mystrcmp, @function
mystrcmp:
	addi	sp,sp,-48
	sd	s0,40(sp)
	addi	s0,sp,48
	sd	a0,-40(s0)
	sd	a1,-48(s0)
	ld	a5,-40(s0)
	sd	a5,-24(s0)
	ld	a5,-48(s0)
	sd	a5,-32(s0)
	j	.L2
.L6:
	ld	a5,-24(s0)
	lbu	a4,0(a5)
	ld	a5,-32(s0)
	lbu	a5,0(a5)
	beq	a4,a5,.L3
	ld	a5,-24(s0)
	lbu	a5,0(a5)
	sext.w	a4,a5
	ld	a5,-32(s0)
	lbu	a5,0(a5)
	sext.w	a5,a5
	subw	a5,a4,a5
	sext.w	a5,a5
	j	.L1
.L3:
	ld	a5,-24(s0)
	addi	a5,a5,1
	sd	a5,-24(s0)
	ld	a5,-32(s0)
	addi	a5,a5,1
	sd	a5,-32(s0)
.L2:
	ld	a5,-24(s0)
	lbu	a5,0(a5)
	beq	a5,zero,.L5
	ld	a5,-32(s0)
	lbu	a5,0(a5)
	bne	a5,zero,.L6
.L5:
.L1:
	mv	a0,a5
	ld	s0,40(sp)
	addi	sp,sp,48
	jr	ra
	.size	mystrcmp, .-mystrcmp
	.ident	"GCC: (g2ee5e430018-dirty) 12.2.0"
