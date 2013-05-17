.text
.globl distance2
#	double distance2(double *x, double *y);
distance2:
#	load x
	MOVAPD		(%RDI)		,	%XMM0
#	load y
	MOVAPD		(%RSI)		,	%XMM1
#	x <- x - y
	SUBPD		%XMM1		,	%XMM0
#	x <- x * x
	MULPD		%XMM0		,	%XMM0
#	x[0] <- x[0] + x[1]
	HADDPD		%XMM0		,	%XMM0
#	x[0] <- sqrt(x[0])
	SQRTPD		%XMM0		,	%XMM0
	ret
