.text
.globl VectorD_ADD
#	void VectorD_ADD(doublea *src1, doublea *src2, uint32_t dimension, doublea *dest);
VectorD_ADD:
	TEST	$0x01	,	%RDX
	JNZ	odd
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
	JP	end
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
	JP	end
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
	JP	end_sub
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
	JP	end_sub
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
	JP	end_neg
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
	JP	end_neg
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
	JP	end_sca
odd_sca:
	MOVAPD	(%RDI)	,	%XMM1
	ADD	$0x10	,	%RDI
	MULPD	%XMM0	,	%XMM1
	MOVAPD	%XMM1	,	(%RSI)
	ADD	$0x10	,	%RSI
	SUB	$0x02	,	%RDX
	JS	odd_last_sca
	JNZ	odd_sca
	JP	end_sca
odd_last_sca:
	MOVLPD	(%RDI)	,	%XMM1
	MULPD	%XMM0	,	%XMM1
	MOVLPD	%XMM1	,	(%RSI)
end_sca:
	RET

