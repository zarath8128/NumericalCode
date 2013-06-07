.text
.globl ADD_V
#	void ADD_V(doublena src1, doublena src2, doublena dist, uint32_t n);
ADD_V:
	MOV	(%RDI)	,	%RAX
	MOV	%RAX	,	%RCX
	BT	$00	,	%RAX
	CMOVC	$01	,	%RDX
	DEC	%RDX
	AND		

	CMOVC	
	SHR	$0x01	,	%RAX
	
EXIT:
	ret
