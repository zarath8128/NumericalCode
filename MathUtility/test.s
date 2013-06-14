	.file	"test.c"
	.text
	.globl	main
	.type	main, @function
main:
.LFB0:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movl	$1, -4(%rbp)
	cmpl	$4, -4(%rbp)
	ja	.L2
	movl	-4(%rbp), %eax
	movq	.L8(,%rax,8), %rax
	jmp	*%rax
	.section	.rodata
	.align 8
	.align 4
.L8:
	.quad	.L3
	.quad	.L4
	.quad	.L5
	.quad	.L6
	.quad	.L7
	.text
.L3:
	movl	$1, -4(%rbp)
	jmp	.L2
.L4:
	movl	$2, -4(%rbp)
	jmp	.L2
.L5:
	movl	$3, -4(%rbp)
	jmp	.L2
.L6:
	movl	$4, -4(%rbp)
	jmp	.L2
.L7:
	movl	$5, -4(%rbp)
	nop
.L2:
	movl	$0, %eax
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE0:
	.size	main, .-main
	.ident	"GCC: (Debian 4.7.2-5) 4.7.2"
	.section	.note.GNU-stack,"",@progbits
