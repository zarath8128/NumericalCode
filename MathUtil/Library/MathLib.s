.text
.globl sqrt_asm
#	double sqrt_asm(double);
sqrt_asm:
	SQRTPD	%XMM0	,	%XMM0
	ret

.globl norm_asm
#	double norm_asm(double2 dist);
norm_asm:
	MOVAPD	(%RDI)	,	%XMM0
	MULPD	%XMM0	,	%XMM0
	HADDPD	%XMM0	,	%XMM0
	ret
	
