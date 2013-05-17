.text
.globl distance4
#	double distance4(double *x, double *y) ;
distance4:
#	load x
	MOVAPD		(%RDI)		,	%XMM0
	MOVAPD		16(%RDI)	,	%XMM1
#	load y
	MOVAPD		(%RSI)		,	%XMM2
	MOVAPD		16(%RSI)	,	%XMM3
#	x <- x - y
	SUBPD		%XMM2		,	%XMM0
	SUBPD		%XMM3		,	%XMM1
#	x <- x * x
	MULPD		%XMM0		,	%XMM0
	MULPD		%XMM1		,	%XMM1
#	x[0] <- sum(x)
	HADDPD		%XMM1		,	%XMM0
	HADDPD		%XMM0		,	%XMM0
#	x[0] <- sqrt(x[0])
	SQRTPD		%XMM0		,	%XMM0
	ret

