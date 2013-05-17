.text
.globl Align
#	void*	Align(void* p, uint32_t Alignment);
Align:
	MOV	%RDI	,	%RAX
	XOR	%RDX	,	%RDX
	DIV	%RSI
	TEST	%RDX	,	%RDX
	CMOVZ	%RSI	,	%RDX
	ADD	%RSI	,	%RDI
	SUB	%RDX	,	%RDI
	MOV	%RDI	,	%RAX
	ret
