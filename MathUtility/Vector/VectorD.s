.text
.globl VectorD_add
#	void VectorD_add(doublea *src1, doublea *src2, uint32_t dimension, doublea *dest);
.align	0x10
VectorD_add:
	SUB	$0x10	,	%RDX
	JS	rounding_add	
	MOVAPD	(%RDI)	,	%XMM0
	MOVAPD	16(%RDI),	%XMM1
	MOVAPD	32(%RDI),	%XMM2
	MOVAPD	48(%RDI),	%XMM3
	MOVAPD	64(%RDI),	%XMM4
	MOVAPD	80(%RDI),	%XMM5
	MOVAPD	96(%RDI),	%XMM6
	MOVAPD	112(%RDI),	%XMM7
	MOVAPD	(%RSI)	,	%XMM8
	MOVAPD	16(%RSI),	%XMM9
	MOVAPD	32(%RSI),	%XMM10
	MOVAPD	48(%RSI),	%XMM11
	MOVAPD	64(%RSI),	%XMM12
	MOVAPD	80(%RSI),	%XMM13
	MOVAPD	96(%RSI),	%XMM14
	MOVAPD	112(%RSI),	%XMM15
	ADDPD	%XMM8	,	%XMM0
	ADDPD	%XMM9	,	%XMM1
	ADDPD	%XMM10	,	%XMM2
	ADDPD	%XMM11	,	%XMM3
	ADDPD	%XMM12	,	%XMM4
	ADDPD	%XMM13	,	%XMM5
	ADDPD	%XMM14	,	%XMM6
	ADDPD	%XMM15	,	%XMM7
	MOVAPD	%XMM0	,	(%RCX)
	MOVAPD	%XMM1	,	16(%RCX)
	MOVAPD	%XMM2	,	32(%RCX)
	MOVAPD	%XMM3	,	48(%RCX)
	MOVAPD	%XMM4	,	64(%RCX)
	MOVAPD	%XMM5	,	80(%RCX)
	MOVAPD	%XMM6	,	96(%RCX)
	MOVAPD	%XMM7	,	112(%RCX)
	ADD	$0x80	,	%RDI
	ADD	$0x80	,	%RSI
	ADD	$0x80	,	%RCX
	JMP	VectorD_add
.align	0x10
rounding_add:
	ADD	$0x10	,	%RDX
	JZ	end_add
	MOV	jump_table_add(, %RDX, 8),%RAX
	JMP	*%RAX
jump_table_add:
.quad	.t1_add
.quad	.t2_add
.quad	.t3_add
.quad	.t4_add
.quad	.t5_add
.quad	.t6_add
.quad	.t7_add
.quad	.t8_add
.quad	.t9_add
.quad	.t10_add
.quad	.t11_add
.quad	.t12_add
.quad	.t13_add
.quad	.t14_add
.quad	.t15_add
.align	0x10
.t1_add:
	MOVLPD	(%RDI)	,	%XMM1
	MULPD	%XMM0	,	%XMM1
	MOVLPD	%XMM1	,	(%RSI)
	JMP	end_add:
.t3_add:
.t5_add:
.t7_add:
.t9_add:
.t11_add:
.t13_add:
.t15_add:
.t2_add:
.t4_add:
.t6_add:
.t8_add:
.t10_add:
.t12_add:
.t14_add:
	


.align	0x10
end_add:
	ret



.globl VectorD_ADD
#	void VectorD_ADD(doublea *src1, doublea *src2, uint32_t dimension, doublea *dest);
VectorD_ADD:
	TEST	$0x01	,	%RDX
	JNZ	odd
.align	0x10
even:
	MOVAPD	(%RDI)	,	%XMM0
	ADD	$0x10	,	%RDI
	MOVAPD	(%RSI)	,	%XMM1
	ADD	$0x10	,	%RSI
	ADDPD	%XMM1	,	%XMM0
	MOVAPD	%XMM0	,	(%RCX)
	ADD	$0x10	,	%RCX
	SUB	$0x02	,	%RDX
	JNZ	even
	JMP	end
.align	0x10
odd:
	MOVAPD	(%RDI)	,	%XMM0
	ADD	$0x10	,	%RDI
	MOVAPD	(%RSI)	,	%XMM1
	ADD	$0x10	,	%RSI
	ADDPD	%XMM1	,	%XMM0
	MOVAPD	%XMM0	,	(%RCX)
	ADD	$0x10	,	%RCX
	SUB	$0x02	,	%RDX
	JS	odd_last
	JNZ	odd
	JMP	end
odd_last:
	FLD	(%RDI)
	FLD	(%RSI)
	FADDP
	FST	(%RCX)
end:
	RET

.globl VectorD_SUB
#	void VectorD_SUB(doublea *src1, doublea *src2, uint32_t dimension, doublea *dest);
VectorD_SUB:
	TEST	$0x01	,	%RDX
	JNZ	odd_sub
even_sub:
	MOVAPD	(%RDI)	,	%XMM0
	ADD	$0x10	,	%RDI
	MOVAPD	(%RSI)	,	%XMM1
	ADD	$0x10	,	%RSI
	SUBPD	%XMM1	,	%XMM0
	MOVAPD	%XMM0	,	(%RCX)
	ADD	$0x10	,	%RCX
	SUB	$0x02	,	%RDX
	JNZ	even_sub
	JMP	end_sub
odd_sub:
	MOVAPD	(%RDI)	,	%XMM0
	ADD	$0x10	,	%RDI
	MOVAPD	(%RSI)	,	%XMM1
	ADD	$0x10	,	%RSI
	SUBPD	%XMM1	,	%XMM0
	MOVAPD	%XMM0	,	(%RCX)
	ADD	$0x10	,	%RCX
	SUB	$0x02	,	%RDX
	JS	odd_last_sub
	JNZ	odd_sub
	JMP	end_sub
odd_last_sub:
	FLD	(%RDI)
	FLD	(%RSI)
	FSUBP
	FST	(%RCX)
end_sub:
	RET


.globl VectorD_NEG
#	void VectorD_NEG(doublea *src, doublea *dest, uint32_t dimension);//dest <- -src
VectorD_NEG:
	TEST	$0x01	,	%RDX
	JNZ	odd_neg
even_neg:
	MOVAPD	(%RDI)	,	%XMM1
	ADD	$0x10	,	%RDI
	XORPD	%XMM0	,	%XMM0
	SUBPD	%XMM1	,	%XMM0
	MOVAPD	%XMM0	,	(%RSI)
	ADD	$0x10	,	%RSI
	SUB	$0x02	,	%RDX
	JNZ	even_neg
	JMP	end_neg
odd_neg:
	MOVAPD	(%RDI)	,	%XMM1
	ADD	$0x10	,	%RDI
	XORPD	%XMM0	,	%XMM0
	SUBPD	%XMM1	,	%XMM0
	MOVAPD	%XMM0	,	(%RSI)
	ADD	$0x10	,	%RSI
	SUB	$0x02	,	%RDX
	JS	odd_last_neg
	JNZ	odd_neg
	JMP	end_neg
odd_last_neg:
	FLD	(%RDI)
	FCHS
	FST	(%RSI)
end_neg:
	RET

.globl VectorD_SCA
#	void VectorD_SCA(doublea *src, doublea *dest, uint32_t dimnesion, double scalar)
VectorD_SCA:
	MOVDDUP	%XMM0	,	%XMM0
	TEST	$0x01	,	%RDX
	JNZ	odd_sca
even_sca:
	MOVAPD	(%RDI)	,	%XMM1
	ADD	$0x10	,	%RDI
	MULPD	%XMM0	,	%XMM1
	MOVAPD	%XMM1	,	(%RSI)
	ADD	$0x10	,	%RSI
	SUB	$0x02	,	%RDX
	JNZ	even_sca
	JMP	end_sca
odd_sca:
	MOVAPD	(%RDI)	,	%XMM1
	ADD	$0x10	,	%RDI
	MULPD	%XMM0	,	%XMM1
	MOVAPD	%XMM1	,	(%RSI)
	ADD	$0x10	,	%RSI
	SUB	$0x02	,	%RDX
	JS	odd_last_sca
	JNZ	odd_sca
	JMP	end_sca
odd_last_sca:
	MOVLPD	(%RDI)	,	%XMM1
	MULPD	%XMM0	,	%XMM1
	MOVLPD	%XMM1	,	(%RSI)
end_sca:
	RET

