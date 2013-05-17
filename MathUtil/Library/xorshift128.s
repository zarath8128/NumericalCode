.text
.globl xorshift128
#	uint32_t xorshift128(uint32_t state[4])
xorshift128:
#	load state
	MOVDQA		(%RDI)		,	%XMM0
	MOVD		%XMM0		,	%EAX
	MOV		%EAX		,	%ECX
	SHL		$0x0B		,	%ECX
	XOR		%ECX		,	%EAX
	SHUFPS		$0b11100111	,	%XMM0		,	%XMM0
	MOVD		%XMM0		,	%ECX
	MOV		%ECX		,	%EDX
	SHR		$0x13		,	%EDX
	XOR		%EDX		,	%ECX
	MOV		%EAX		,	%EDX
	SHR		$0x08		,	%EDX
	XOR		%EDX		,	%EAX
	XOR		%ECX		,	%EAX
	MOVD		%EAX		,	%XMM0
	SHUFPS		$0b00111001	,	%XMM0		,	%XMM0
	MOVDQA		%XMM0		,	(%RDI)
	ret
