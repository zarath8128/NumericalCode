.text
.globl BenchMark
#	uint64_t BenchMark(void (*test)(void), uint64_t);
BenchMark:
	XOR	%RDX	,	%RDX
	DEC	%RDX
	TEST	%ESI	,	%ESI
	CMOVZ	%RDX	,	%RAX
	JZ	err

	PUSH	%R12
	PUSH	%R13
	PUSH	%R14
	PUSH	%R15

	MOV	%RSI	,	%R12
	MOV	%RDI	,	%R13

	RDTSC	
	MOV	%RAX	,	%R14
	MOV	%RDX	,	%R15

loop:
	CALL	*%R13
	DEC	%R12
	JNZ	loop

	RDTSC
	SUB	%R14	,	%RAX
	SBB	%R15	,	%RDX
	SHL	$0x20	,	%RDX
	ADD	%RDX	,	%RAX

	POP	%R15
	POP	%R14
	POP	%R13
	POP	%R12
err:
	RET

.globl BenchMarkClock
#	uint64_t BenchMarkClock(void (test*)(void), uint64_t count);
BenchMarkClock:

	XOR	%RDX	,	%RDX
	DEC	%RDX
	TEST	%RSI	,	%RSI
	CMOVZ	%RDX	,	%RAX
	JZ	err

	PUSH	%R12
	PUSH	%R13
	PUSH	%R14

	MOV	%RSI	,	%R12
	MOV	%RDI	,	%R13

	CALL	clock
	MOV	%RAX	,	%R14

loop_c:
	CALL	*%R13
	DEC	%R12
	JNZ	loop_c

	CALL	clock
	SUB	%R14	,	%RAX

	POP	%R14
	POP	%R13
	POP	%R12

	RET
