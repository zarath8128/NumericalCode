.text
.globl URVectorD_ADD
#	void URVectorD_ADD(doublea *src1, doublea *src2, uint32_t dimension, doublea *dist);
.align	0x10
URVectorD_ADD:
	XOR	%RAX	,	%RAX
add_loop:
	SUB	$0x10	,	%EDX
	JS	add_end
	MOVAPD	(%RDI, %RAX, 8),%XMM0
	MOVAPD	16(%RDI, %RAX, 8),%XMM1
	MOVAPD	32(%RDI, %RAX, 8),%XMM2
	MOVAPD	48(%RDI, %RAX, 8),%XMM3
	MOVAPD	64(%RDI, %RAX, 8),%XMM4
	MOVAPD	80(%RDI, %RAX, 8),%XMM5
	MOVAPD	96(%RDI, %RAX, 8),%XMM6
	MOVAPD	112(%RDI, %RAX, 8),%XMM7
	MOVAPD	(%RSI, %RAX, 8),%XMM8
	MOVAPD	16(%RSI, %RAX, 8),%XMM9
	MOVAPD	32(%RSI, %RAX, 8),%XMM10
	MOVAPD	48(%RSI, %RAX, 8),%XMM11
	MOVAPD	64(%RSI, %RAX, 8),%XMM12
	MOVAPD	80(%RSI, %RAX, 8),%XMM13
	MOVAPD	96(%RSI, %RAX, 8),%XMM14
	MOVAPD	112(%RSI, %RAX, 8),%XMM15
	ADDPD	%XMM0	,	%XMM8
	ADDPD	%XMM1	,	%XMM9
	ADDPD	%XMM2	,	%XMM10
	ADDPD	%XMM3	,	%XMM11
	ADDPD	%XMM4	,	%XMM12
	ADDPD	%XMM5	,	%XMM13
	ADDPD	%XMM6	,	%XMM14
	ADDPD	%XMM7	,	%XMM15
	MOVAPD	%XMM8	,	(%RCX, %RAX, 8)
	MOVAPD	%XMM9	,	16(%RCX, %RAX, 8)
	MOVAPD	%XMM10	,	32(%RCX, %RAX, 8)
	MOVAPD	%XMM11	,	48(%RCX, %RAX, 8)
	MOVAPD	%XMM12	,	64(%RCX, %RAX, 8)
	MOVAPD	%XMM13	,	80(%RCX, %RAX, 8)
	MOVAPD	%XMM14	,	96(%RCX, %RAX, 8)
	MOVAPD	%XMM15	,	112(%RCX, %RAX, 8)
	ADD	$0x10	,	%RAX
	JMP	add_loop
add_end:
	ret