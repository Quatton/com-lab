	.globl maxof2
	.align 2

maxof2:
	blt a0, a1, .A1
	ret

.A1:
	mv a0, a1
	ret
