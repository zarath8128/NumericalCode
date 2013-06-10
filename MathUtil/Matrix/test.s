	.file	"test.cpp"
	.section	.rodata
	.type	_ZStL19piecewise_construct, @object
	.size	_ZStL19piecewise_construct, 1
_ZStL19piecewise_construct:
	.zero	1
	.section	.text._ZStanSt13_Ios_FmtflagsS_,"axG",@progbits,_ZStanSt13_Ios_FmtflagsS_,comdat
	.weak	_ZStanSt13_Ios_FmtflagsS_
	.type	_ZStanSt13_Ios_FmtflagsS_, @function
_ZStanSt13_Ios_FmtflagsS_:
.LFB810:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movl	%edi, -4(%rbp)
	movl	%esi, -8(%rbp)
	movl	-4(%rbp), %edx
	movl	-8(%rbp), %eax
	andl	%edx, %eax
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE810:
	.size	_ZStanSt13_Ios_FmtflagsS_, .-_ZStanSt13_Ios_FmtflagsS_
	.section	.text._ZStorSt13_Ios_FmtflagsS_,"axG",@progbits,_ZStorSt13_Ios_FmtflagsS_,comdat
	.weak	_ZStorSt13_Ios_FmtflagsS_
	.type	_ZStorSt13_Ios_FmtflagsS_, @function
_ZStorSt13_Ios_FmtflagsS_:
.LFB811:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movl	%edi, -4(%rbp)
	movl	%esi, -8(%rbp)
	movl	-4(%rbp), %edx
	movl	-8(%rbp), %eax
	orl	%edx, %eax
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE811:
	.size	_ZStorSt13_Ios_FmtflagsS_, .-_ZStorSt13_Ios_FmtflagsS_
	.section	.text._ZStcoSt13_Ios_Fmtflags,"axG",@progbits,_ZStcoSt13_Ios_Fmtflags,comdat
	.weak	_ZStcoSt13_Ios_Fmtflags
	.type	_ZStcoSt13_Ios_Fmtflags, @function
_ZStcoSt13_Ios_Fmtflags:
.LFB813:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movl	%edi, -4(%rbp)
	movl	-4(%rbp), %eax
	notl	%eax
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE813:
	.size	_ZStcoSt13_Ios_Fmtflags, .-_ZStcoSt13_Ios_Fmtflags
	.section	.text._ZStoRRSt13_Ios_FmtflagsS_,"axG",@progbits,_ZStoRRSt13_Ios_FmtflagsS_,comdat
	.weak	_ZStoRRSt13_Ios_FmtflagsS_
	.type	_ZStoRRSt13_Ios_FmtflagsS_, @function
_ZStoRRSt13_Ios_FmtflagsS_:
.LFB814:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$16, %rsp
	movq	%rdi, -8(%rbp)
	movl	%esi, -12(%rbp)
	movq	-8(%rbp), %rax
	movl	(%rax), %eax
	movl	-12(%rbp), %edx
	movl	%edx, %esi
	movl	%eax, %edi
	call	_ZStorSt13_Ios_FmtflagsS_
	movq	-8(%rbp), %rdx
	movl	%eax, (%rdx)
	movq	-8(%rbp), %rax
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE814:
	.size	_ZStoRRSt13_Ios_FmtflagsS_, .-_ZStoRRSt13_Ios_FmtflagsS_
	.section	.text._ZStaNRSt13_Ios_FmtflagsS_,"axG",@progbits,_ZStaNRSt13_Ios_FmtflagsS_,comdat
	.weak	_ZStaNRSt13_Ios_FmtflagsS_
	.type	_ZStaNRSt13_Ios_FmtflagsS_, @function
_ZStaNRSt13_Ios_FmtflagsS_:
.LFB815:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$16, %rsp
	movq	%rdi, -8(%rbp)
	movl	%esi, -12(%rbp)
	movq	-8(%rbp), %rax
	movl	(%rax), %eax
	movl	-12(%rbp), %edx
	movl	%edx, %esi
	movl	%eax, %edi
	call	_ZStanSt13_Ios_FmtflagsS_
	movq	-8(%rbp), %rdx
	movl	%eax, (%rdx)
	movq	-8(%rbp), %rax
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE815:
	.size	_ZStaNRSt13_Ios_FmtflagsS_, .-_ZStaNRSt13_Ios_FmtflagsS_
	.section	.text._ZNSt8ios_base4setfESt13_Ios_FmtflagsS0_,"axG",@progbits,_ZNSt8ios_base4setfESt13_Ios_FmtflagsS0_,comdat
	.align 2
	.weak	_ZNSt8ios_base4setfESt13_Ios_FmtflagsS0_
	.type	_ZNSt8ios_base4setfESt13_Ios_FmtflagsS0_, @function
_ZNSt8ios_base4setfESt13_Ios_FmtflagsS0_:
.LFB842:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$32, %rsp
	movq	%rdi, -24(%rbp)
	movl	%esi, -28(%rbp)
	movl	%edx, -32(%rbp)
	movq	-24(%rbp), %rax
	movl	24(%rax), %eax
	movl	%eax, -4(%rbp)
	movl	-32(%rbp), %eax
	movl	%eax, %edi
	call	_ZStcoSt13_Ios_Fmtflags
	movq	-24(%rbp), %rdx
	addq	$24, %rdx
	movl	%eax, %esi
	movq	%rdx, %rdi
	call	_ZStaNRSt13_Ios_FmtflagsS_
	movl	-32(%rbp), %edx
	movl	-28(%rbp), %eax
	movl	%edx, %esi
	movl	%eax, %edi
	call	_ZStanSt13_Ios_FmtflagsS_
	movq	-24(%rbp), %rdx
	addq	$24, %rdx
	movl	%eax, %esi
	movq	%rdx, %rdi
	call	_ZStoRRSt13_Ios_FmtflagsS_
	movl	-4(%rbp), %eax
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE842:
	.size	_ZNSt8ios_base4setfESt13_Ios_FmtflagsS0_, .-_ZNSt8ios_base4setfESt13_Ios_FmtflagsS0_
	.section	.text._ZSt5rightRSt8ios_base,"axG",@progbits,_ZSt5rightRSt8ios_base,comdat
	.weak	_ZSt5rightRSt8ios_base
	.type	_ZSt5rightRSt8ios_base, @function
_ZSt5rightRSt8ios_base:
.LFB868:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$16, %rsp
	movq	%rdi, -8(%rbp)
	movq	-8(%rbp), %rax
	movl	$176, %edx
	movl	$128, %esi
	movq	%rax, %rdi
	call	_ZNSt8ios_base4setfESt13_Ios_FmtflagsS0_
	movq	-8(%rbp), %rax
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE868:
	.size	_ZSt5rightRSt8ios_base, .-_ZSt5rightRSt8ios_base
	.section	.text._ZSt10scientificRSt8ios_base,"axG",@progbits,_ZSt10scientificRSt8ios_base,comdat
	.weak	_ZSt10scientificRSt8ios_base
	.type	_ZSt10scientificRSt8ios_base, @function
_ZSt10scientificRSt8ios_base:
.LFB873:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$16, %rsp
	movq	%rdi, -8(%rbp)
	movq	-8(%rbp), %rax
	movl	$260, %edx
	movl	$256, %esi
	movq	%rax, %rdi
	call	_ZNSt8ios_base4setfESt13_Ios_FmtflagsS0_
	movq	-8(%rbp), %rax
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE873:
	.size	_ZSt10scientificRSt8ios_base, .-_ZSt10scientificRSt8ios_base
	.local	_ZStL8__ioinit
	.comm	_ZStL8__ioinit,1,1
	.section	.text._ZSt12setprecisioni,"axG",@progbits,_ZSt12setprecisioni,comdat
	.weak	_ZSt12setprecisioni
	.type	_ZSt12setprecisioni, @function
_ZSt12setprecisioni:
.LFB1317:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movl	%edi, -4(%rbp)
	movl	-4(%rbp), %eax
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE1317:
	.size	_ZSt12setprecisioni, .-_ZSt12setprecisioni
	.section	.text._ZSt4setwi,"axG",@progbits,_ZSt4setwi,comdat
	.weak	_ZSt4setwi
	.type	_ZSt4setwi, @function
_ZSt4setwi:
.LFB1320:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movl	%edi, -4(%rbp)
	movl	-4(%rbp), %eax
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE1320:
	.size	_ZSt4setwi, .-_ZSt4setwi
	.section	.text._ZN6zarath10MatrixBaseIdEC2Ev,"axG",@progbits,_ZN6zarath10MatrixBaseIdEC5Ev,comdat
	.align 2
	.weak	_ZN6zarath10MatrixBaseIdEC2Ev
	.type	_ZN6zarath10MatrixBaseIdEC2Ev, @function
_ZN6zarath10MatrixBaseIdEC2Ev:
.LFB1335:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movq	%rdi, -8(%rbp)
	movq	-8(%rbp), %rax
	movq	$_ZTVN6zarath10MatrixBaseIdEE+16, (%rax)
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE1335:
	.size	_ZN6zarath10MatrixBaseIdEC2Ev, .-_ZN6zarath10MatrixBaseIdEC2Ev
	.weak	_ZN6zarath10MatrixBaseIdEC1Ev
	.set	_ZN6zarath10MatrixBaseIdEC1Ev,_ZN6zarath10MatrixBaseIdEC2Ev
	.section	.text._ZN6zarath8LUMatrixC2Ej,"axG",@progbits,_ZN6zarath8LUMatrixC5Ej,comdat
	.align 2
	.weak	_ZN6zarath8LUMatrixC2Ej
	.type	_ZN6zarath8LUMatrixC2Ej, @function
_ZN6zarath8LUMatrixC2Ej:
.LFB1337:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$32, %rsp
	movq	%rdi, -24(%rbp)
	movl	%esi, -28(%rbp)
	movq	-24(%rbp), %rax
	movq	%rax, %rdi
	call	_ZN6zarath10MatrixBaseIdEC2Ev
	movq	-24(%rbp), %rax
	movq	$_ZTVN6zarath8LUMatrixE+16, (%rax)
	movq	-24(%rbp), %rax
	movl	-28(%rbp), %edx
	movl	%edx, 8(%rax)
	movl	-28(%rbp), %eax
	imull	-28(%rbp), %eax
	movl	%eax, %eax
	salq	$3, %rax
	movq	%rax, %rdi
	call	_Znam
	movq	%rax, %rdx
	movq	-24(%rbp), %rax
	movq	%rdx, 16(%rax)
	movl	-28(%rbp), %eax
	subl	$1, %eax
	movl	%eax, %eax
	salq	$3, %rax
	movq	%rax, %rdi
	call	_Znam
	movq	%rax, %rdx
	movq	-24(%rbp), %rax
	movq	%rdx, 24(%rax)
	movl	-28(%rbp), %eax
	salq	$3, %rax
	movq	%rax, %rdi
	call	_Znam
	movq	%rax, %rdx
	movq	-24(%rbp), %rax
	movq	%rdx, 32(%rax)
	movl	$2, %esi
	movl	$_ZSt4cout, %edi
	call	_ZNSolsEi
	movq	-24(%rbp), %rax
	movq	16(%rax), %rax
	movq	%rax, -8(%rbp)
	movl	$0, -12(%rbp)
	jmp	.L23
.L24:
	movq	-24(%rbp), %rax
	movq	32(%rax), %rax
	movl	-12(%rbp), %edx
	salq	$3, %rdx
	addq	%rax, %rdx
	movl	-12(%rbp), %eax
	salq	$3, %rax
	addq	%rax, -8(%rbp)
	movq	-8(%rbp), %rax
	movq	%rax, (%rdx)
	addl	$1, -12(%rbp)
.L23:
	movl	-12(%rbp), %eax
	cmpl	-28(%rbp), %eax
	setb	%al
	testb	%al, %al
	jne	.L24
	movl	-28(%rbp), %eax
	salq	$3, %rax
	addq	%rax, -8(%rbp)
	movl	$0, -16(%rbp)
	jmp	.L25
.L26:
	movq	-24(%rbp), %rax
	movq	24(%rax), %rax
	movl	-16(%rbp), %edx
	salq	$3, %rdx
	addq	%rax, %rdx
	movl	-16(%rbp), %eax
	salq	$3, %rax
	addq	%rax, -8(%rbp)
	movq	-8(%rbp), %rax
	movq	%rax, (%rdx)
	addl	$1, -16(%rbp)
.L25:
	movl	-28(%rbp), %eax
	subl	$1, %eax
	cmpl	-16(%rbp), %eax
	seta	%al
	testb	%al, %al
	jne	.L26
	movl	$3, %esi
	movl	$_ZSt4cout, %edi
	call	_ZNSolsEi
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE1337:
	.size	_ZN6zarath8LUMatrixC2Ej, .-_ZN6zarath8LUMatrixC2Ej
	.weak	_ZN6zarath8LUMatrixC1Ej
	.set	_ZN6zarath8LUMatrixC1Ej,_ZN6zarath8LUMatrixC2Ej
	.section	.text._ZN6zarath8LUMatrixD2Ev,"axG",@progbits,_ZN6zarath8LUMatrixD5Ev,comdat
	.align 2
	.weak	_ZN6zarath8LUMatrixD2Ev
	.type	_ZN6zarath8LUMatrixD2Ev, @function
_ZN6zarath8LUMatrixD2Ev:
.LFB1340:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$16, %rsp
	movq	%rdi, -8(%rbp)
	movq	-8(%rbp), %rax
	movq	$_ZTVN6zarath8LUMatrixE+16, (%rax)
	movq	-8(%rbp), %rax
	movq	16(%rax), %rax
	testq	%rax, %rax
	je	.L28
	movq	-8(%rbp), %rax
	movq	16(%rax), %rax
	movq	%rax, %rdi
	call	_ZdaPv
.L28:
	movq	-8(%rbp), %rax
	movq	24(%rax), %rax
	testq	%rax, %rax
	je	.L29
	movq	-8(%rbp), %rax
	movq	24(%rax), %rax
	movq	%rax, %rdi
	call	_ZdaPv
.L29:
	movq	-8(%rbp), %rax
	movq	32(%rax), %rax
	testq	%rax, %rax
	je	.L27
	movq	-8(%rbp), %rax
	movq	32(%rax), %rax
	movq	%rax, %rdi
	call	_ZdaPv
.L27:
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE1340:
	.size	_ZN6zarath8LUMatrixD2Ev, .-_ZN6zarath8LUMatrixD2Ev
	.weak	_ZN6zarath8LUMatrixD1Ev
	.set	_ZN6zarath8LUMatrixD1Ev,_ZN6zarath8LUMatrixD2Ev
	.section	.text._ZN6zarath8LUMatrixclEjj,"axG",@progbits,_ZN6zarath8LUMatrixclEjj,comdat
	.align 2
	.weak	_ZN6zarath8LUMatrixclEjj
	.type	_ZN6zarath8LUMatrixclEjj, @function
_ZN6zarath8LUMatrixclEjj:
.LFB1342:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movq	%rdi, -8(%rbp)
	movl	%esi, -12(%rbp)
	movl	%edx, -16(%rbp)
	movl	-12(%rbp), %eax
	cmpl	-16(%rbp), %eax
	jbe	.L32
	movq	-8(%rbp), %rax
	movq	24(%rax), %rax
	movl	-12(%rbp), %edx
	salq	$3, %rdx
	addq	%rdx, %rax
	movq	(%rax), %rax
	movl	-16(%rbp), %edx
	salq	$3, %rdx
	addq	%rdx, %rax
	jmp	.L33
.L32:
	movq	-8(%rbp), %rax
	movq	32(%rax), %rax
	movl	-16(%rbp), %edx
	salq	$3, %rdx
	addq	%rdx, %rax
	movq	(%rax), %rax
	movl	-12(%rbp), %edx
	salq	$3, %rdx
	addq	%rdx, %rax
.L33:
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE1342:
	.size	_ZN6zarath8LUMatrixclEjj, .-_ZN6zarath8LUMatrixclEjj
	.section	.text._ZNK6zarath8LUMatrix3RowEv,"axG",@progbits,_ZNK6zarath8LUMatrix3RowEv,comdat
	.align 2
	.weak	_ZNK6zarath8LUMatrix3RowEv
	.type	_ZNK6zarath8LUMatrix3RowEv, @function
_ZNK6zarath8LUMatrix3RowEv:
.LFB1343:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movq	%rdi, -8(%rbp)
	movq	-8(%rbp), %rax
	movl	8(%rax), %eax
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE1343:
	.size	_ZNK6zarath8LUMatrix3RowEv, .-_ZNK6zarath8LUMatrix3RowEv
	.section	.text._ZNK6zarath8LUMatrix6ColumnEv,"axG",@progbits,_ZNK6zarath8LUMatrix6ColumnEv,comdat
	.align 2
	.weak	_ZNK6zarath8LUMatrix6ColumnEv
	.type	_ZNK6zarath8LUMatrix6ColumnEv, @function
_ZNK6zarath8LUMatrix6ColumnEv:
.LFB1344:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movq	%rdi, -8(%rbp)
	movq	-8(%rbp), %rax
	movl	8(%rax), %eax
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE1344:
	.size	_ZNK6zarath8LUMatrix6ColumnEv, .-_ZNK6zarath8LUMatrix6ColumnEv
	.text
	.globl	main
	.type	main, @function
main:
.LFB1345:
	.cfi_startproc
	.cfi_personality 0x3,__gxx_personality_v0
	.cfi_lsda 0x3,.LLSDA1345
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	pushq	%rbx
	subq	$56, %rsp
	.cfi_offset 3, -24
	movl	$5, %esi
	movl	$_ZSt4cout, %edi
.LEHB0:
	call	_ZNSolsEi
	leaq	-64(%rbp), %rax
	movl	$8, %esi
	movq	%rax, %rdi
	call	_ZN6zarath8LUMatrixC1Ej
.LEHE0:
	movl	$1, %esi
	movl	$_ZSt4cout, %edi
.LEHB1:
	call	_ZNSolsEi
	movl	$0, -20(%rbp)
	jmp	.L40
.L43:
	movl	$0, -24(%rbp)
	jmp	.L41
.L42:
	movq	_ZTVN6zarath8LUMatrixE+32(%rip), %rax
	movl	-24(%rbp), %edx
	movl	-20(%rbp), %esi
	leaq	-64(%rbp), %rcx
	movq	%rcx, %rdi
	call	*%rax
	movl	-20(%rbp), %edx
	leal	1(%rdx), %ecx
	movl	-24(%rbp), %edx
	addl	%ecx, %edx
	cvtsi2sd	%edx, %xmm0
	movsd	.LC0(%rip), %xmm1
	movapd	%xmm1, %xmm2
	divsd	%xmm0, %xmm2
	movapd	%xmm2, %xmm0
	movsd	%xmm0, (%rax)
	addl	$1, -24(%rbp)
.L41:
	movl	-24(%rbp), %ebx
	leaq	-64(%rbp), %rax
	movq	%rax, %rdi
	call	_ZNK6zarath8LUMatrix6ColumnEv
	cmpl	%eax, %ebx
	setb	%al
	testb	%al, %al
	jne	.L42
	addl	$1, -20(%rbp)
.L40:
	movl	-20(%rbp), %ebx
	leaq	-64(%rbp), %rax
	movq	%rax, %rdi
	call	_ZNK6zarath8LUMatrix3RowEv
	cmpl	%eax, %ebx
	setb	%al
	testb	%al, %al
	jne	.L43
	leaq	-64(%rbp), %rax
	movq	%rax, %rsi
	movl	$_ZSt4cout, %edi
	call	_ZN6zarathlsIdEERSoS1_RNS_10MatrixBaseIT_EE
	movl	$_ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_, %esi
	movq	%rax, %rdi
	call	_ZNSolsEPFRSoS_E
.LEHE1:
	movl	$0, %ebx
	leaq	-64(%rbp), %rax
	movq	%rax, %rdi
	call	_ZN6zarath8LUMatrixD1Ev
	movl	%ebx, %eax
	jmp	.L49
.L48:
	movq	%rax, %rbx
	leaq	-64(%rbp), %rax
	movq	%rax, %rdi
	call	_ZN6zarath8LUMatrixD1Ev
	movq	%rbx, %rax
	jmp	.L46
.L47:
.L46:
	movq	%rax, %rdi
.LEHB2:
	call	_Unwind_Resume
.LEHE2:
.L49:
	addq	$56, %rsp
	popq	%rbx
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE1345:
	.globl	__gxx_personality_v0
	.section	.gcc_except_table,"a",@progbits
.LLSDA1345:
	.byte	0xff
	.byte	0xff
	.byte	0x1
	.uleb128 .LLSDACSE1345-.LLSDACSB1345
.LLSDACSB1345:
	.uleb128 .LEHB0-.LFB1345
	.uleb128 .LEHE0-.LEHB0
	.uleb128 .L47-.LFB1345
	.uleb128 0
	.uleb128 .LEHB1-.LFB1345
	.uleb128 .LEHE1-.LEHB1
	.uleb128 .L48-.LFB1345
	.uleb128 0
	.uleb128 .LEHB2-.LFB1345
	.uleb128 .LEHE2-.LEHB2
	.uleb128 0
	.uleb128 0
.LLSDACSE1345:
	.text
	.size	main, .-main
	.section	.rodata
.LC1:
	.string	" "
.LC2:
	.string	"\n"
.LC3:
	.string	": "
	.section	.text._ZN6zarathlsIdEERSoS1_RNS_10MatrixBaseIT_EE,"axG",@progbits,_ZN6zarathlsIdEERSoS1_RNS_10MatrixBaseIT_EE,comdat
	.weak	_ZN6zarathlsIdEERSoS1_RNS_10MatrixBaseIT_EE
	.type	_ZN6zarathlsIdEERSoS1_RNS_10MatrixBaseIT_EE, @function
_ZN6zarathlsIdEERSoS1_RNS_10MatrixBaseIT_EE:
.LFB1401:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	pushq	%r12
	pushq	%rbx
	subq	$48, %rsp
	.cfi_offset 12, -24
	.cfi_offset 3, -32
	movq	%rdi, -40(%rbp)
	movq	%rsi, -48(%rbp)
	movl	$12, %edi
	call	_ZSt4setwi
	movl	%eax, %edx
	movq	-40(%rbp), %rax
	movl	%edx, %esi
	movq	%rax, %rdi
	call	_ZStlsIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_St5_Setw
	movl	$.LC1, %esi
	movq	%rax, %rdi
	call	_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc
	movl	$0, -20(%rbp)
	jmp	.L51
.L52:
	movl	$14, %edi
	call	_ZSt4setwi
	movl	%eax, %edx
	movq	-40(%rbp), %rax
	movl	%edx, %esi
	movq	%rax, %rdi
	call	_ZStlsIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_St5_Setw
	movl	$_ZSt5rightRSt8ios_base, %esi
	movq	%rax, %rdi
	call	_ZNSolsEPFRSt8ios_baseS0_E
	movl	-20(%rbp), %edx
	movl	%edx, %esi
	movq	%rax, %rdi
	call	_ZNSolsEj
	addl	$1, -20(%rbp)
.L51:
	movq	-48(%rbp), %rax
	movq	(%rax), %rax
	addq	$8, %rax
	movq	(%rax), %rax
	movq	-48(%rbp), %rdx
	movq	%rdx, %rdi
	call	*%rax
	cmpl	-20(%rbp), %eax
	seta	%al
	testb	%al, %al
	jne	.L52
	movq	-40(%rbp), %rax
	movl	$.LC2, %esi
	movq	%rax, %rdi
	call	_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc
	movl	$0, -24(%rbp)
	jmp	.L53
.L56:
	movl	$10, %edi
	call	_ZSt4setwi
	movl	%eax, %edx
	movq	-40(%rbp), %rax
	movl	%edx, %esi
	movq	%rax, %rdi
	call	_ZStlsIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_St5_Setw
	movl	$_ZSt5rightRSt8ios_base, %esi
	movq	%rax, %rdi
	call	_ZNSolsEPFRSt8ios_baseS0_E
	movl	-24(%rbp), %edx
	movl	%edx, %esi
	movq	%rax, %rdi
	call	_ZNSolsEj
	movl	$.LC3, %esi
	movq	%rax, %rdi
	call	_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc
	movl	$0, -28(%rbp)
	jmp	.L54
.L55:
	movq	-48(%rbp), %rax
	movq	(%rax), %rax
	addq	$16, %rax
	movq	(%rax), %rax
	movl	-28(%rbp), %edx
	movl	-24(%rbp), %esi
	movq	-48(%rbp), %rcx
	movq	%rcx, %rdi
	call	*%rax
	movq	(%rax), %rbx
	movl	$6, %edi
	call	_ZSt12setprecisioni
	movl	%eax, %r12d
	movl	$14, %edi
	call	_ZSt4setwi
	movl	%eax, %edx
	movq	-40(%rbp), %rax
	movl	%edx, %esi
	movq	%rax, %rdi
	call	_ZStlsIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_St5_Setw
	movl	$_ZSt10scientificRSt8ios_base, %esi
	movq	%rax, %rdi
	call	_ZNSolsEPFRSt8ios_baseS0_E
	movl	%r12d, %esi
	movq	%rax, %rdi
	call	_ZStlsIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_St13_Setprecision
	movl	$_ZSt5rightRSt8ios_base, %esi
	movq	%rax, %rdi
	call	_ZNSolsEPFRSt8ios_baseS0_E
	movq	%rbx, -56(%rbp)
	movsd	-56(%rbp), %xmm0
	movq	%rax, %rdi
	call	_ZNSolsEd
	addl	$1, -28(%rbp)
.L54:
	movq	-48(%rbp), %rax
	movq	(%rax), %rax
	addq	$8, %rax
	movq	(%rax), %rax
	movq	-48(%rbp), %rdx
	movq	%rdx, %rdi
	call	*%rax
	cmpl	-28(%rbp), %eax
	seta	%al
	testb	%al, %al
	jne	.L55
	movq	-40(%rbp), %rax
	movl	$.LC2, %esi
	movq	%rax, %rdi
	call	_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc
	addl	$1, -24(%rbp)
.L53:
	movq	-48(%rbp), %rax
	movq	(%rax), %rax
	movq	(%rax), %rax
	movq	-48(%rbp), %rdx
	movq	%rdx, %rdi
	call	*%rax
	cmpl	-24(%rbp), %eax
	seta	%al
	testb	%al, %al
	jne	.L56
	movq	-40(%rbp), %rax
	movl	$.LC2, %esi
	movq	%rax, %rdi
	call	_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc
	addq	$48, %rsp
	popq	%rbx
	popq	%r12
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE1401:
	.size	_ZN6zarathlsIdEERSoS1_RNS_10MatrixBaseIT_EE, .-_ZN6zarathlsIdEERSoS1_RNS_10MatrixBaseIT_EE
	.weak	_ZTVN6zarath8LUMatrixE
	.section	.rodata._ZTVN6zarath8LUMatrixE,"aG",@progbits,_ZTVN6zarath8LUMatrixE,comdat
	.align 32
	.type	_ZTVN6zarath8LUMatrixE, @object
	.size	_ZTVN6zarath8LUMatrixE, 40
_ZTVN6zarath8LUMatrixE:
	.quad	0
	.quad	_ZTIN6zarath8LUMatrixE
	.quad	_ZNK6zarath8LUMatrix3RowEv
	.quad	_ZNK6zarath8LUMatrix6ColumnEv
	.quad	_ZN6zarath8LUMatrixclEjj
	.weak	_ZTVN6zarath10MatrixBaseIdEE
	.section	.rodata._ZTVN6zarath10MatrixBaseIdEE,"aG",@progbits,_ZTVN6zarath10MatrixBaseIdEE,comdat
	.align 32
	.type	_ZTVN6zarath10MatrixBaseIdEE, @object
	.size	_ZTVN6zarath10MatrixBaseIdEE, 40
_ZTVN6zarath10MatrixBaseIdEE:
	.quad	0
	.quad	_ZTIN6zarath10MatrixBaseIdEE
	.quad	__cxa_pure_virtual
	.quad	__cxa_pure_virtual
	.quad	__cxa_pure_virtual
	.weak	_ZTSN6zarath8LUMatrixE
	.section	.rodata._ZTSN6zarath8LUMatrixE,"aG",@progbits,_ZTSN6zarath8LUMatrixE,comdat
	.align 16
	.type	_ZTSN6zarath8LUMatrixE, @object
	.size	_ZTSN6zarath8LUMatrixE, 19
_ZTSN6zarath8LUMatrixE:
	.string	"N6zarath8LUMatrixE"
	.weak	_ZTIN6zarath8LUMatrixE
	.section	.rodata._ZTIN6zarath8LUMatrixE,"aG",@progbits,_ZTIN6zarath8LUMatrixE,comdat
	.align 16
	.type	_ZTIN6zarath8LUMatrixE, @object
	.size	_ZTIN6zarath8LUMatrixE, 24
_ZTIN6zarath8LUMatrixE:
	.quad	_ZTVN10__cxxabiv120__si_class_type_infoE+16
	.quad	_ZTSN6zarath8LUMatrixE
	.quad	_ZTIN6zarath10MatrixBaseIdEE
	.weak	_ZTSN6zarath10MatrixBaseIdEE
	.section	.rodata._ZTSN6zarath10MatrixBaseIdEE,"aG",@progbits,_ZTSN6zarath10MatrixBaseIdEE,comdat
	.align 16
	.type	_ZTSN6zarath10MatrixBaseIdEE, @object
	.size	_ZTSN6zarath10MatrixBaseIdEE, 25
_ZTSN6zarath10MatrixBaseIdEE:
	.string	"N6zarath10MatrixBaseIdEE"
	.weak	_ZTIN6zarath10MatrixBaseIdEE
	.section	.rodata._ZTIN6zarath10MatrixBaseIdEE,"aG",@progbits,_ZTIN6zarath10MatrixBaseIdEE,comdat
	.align 16
	.type	_ZTIN6zarath10MatrixBaseIdEE, @object
	.size	_ZTIN6zarath10MatrixBaseIdEE, 16
_ZTIN6zarath10MatrixBaseIdEE:
	.quad	_ZTVN10__cxxabiv117__class_type_infoE+16
	.quad	_ZTSN6zarath10MatrixBaseIdEE
	.text
	.type	_Z41__static_initialization_and_destruction_0ii, @function
_Z41__static_initialization_and_destruction_0ii:
.LFB1507:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$16, %rsp
	movl	%edi, -4(%rbp)
	movl	%esi, -8(%rbp)
	cmpl	$1, -4(%rbp)
	jne	.L58
	cmpl	$65535, -8(%rbp)
	jne	.L58
	movl	$_ZStL8__ioinit, %edi
	call	_ZNSt8ios_base4InitC1Ev
	movl	$__dso_handle, %edx
	movl	$_ZStL8__ioinit, %esi
	movl	$_ZNSt8ios_base4InitD1Ev, %edi
	call	__cxa_atexit
.L58:
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE1507:
	.size	_Z41__static_initialization_and_destruction_0ii, .-_Z41__static_initialization_and_destruction_0ii
	.type	_GLOBAL__sub_I_main, @function
_GLOBAL__sub_I_main:
.LFB1508:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movl	$65535, %esi
	movl	$1, %edi
	call	_Z41__static_initialization_and_destruction_0ii
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE1508:
	.size	_GLOBAL__sub_I_main, .-_GLOBAL__sub_I_main
	.section	.init_array,"aw"
	.align 8
	.quad	_GLOBAL__sub_I_main
	.section	.rodata
	.align 8
.LC0:
	.long	0
	.long	1072693248
	.hidden	__dso_handle
	.ident	"GCC: (GNU) 4.7.3"
	.section	.note.GNU-stack,"",@progbits
