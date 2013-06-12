.text
.global ADD_C
#	void ADD_C(double2a v, double2a w, double2a buf)
ADD_C:
	MOVAPD	(%RDI)	,	%XMM0
	MOVAPD	(%RSI)	,	%XMM1
	ADDPD	%XMM1	,	%XMM0
	MOVAPD	%XMM0	,	(%RDX)
	ret

.global SUB_C
#       void SUB_C(double2a v, double2a w, double2a buf)
SUB_C:
        MOVAPD  (%RSI)  ,       %XMM0
        MOVAPD  (%RDI)  ,       %XMM1
        SUBPD   %XMM1   ,       %XMM0
        MOVAPD  %XMM0   ,       (%RDX)
        ret

.global MUL_C
#       void MUL_C(double2a v, double2a w, double2a buf)
MUL_C:
        MOVAPD  (%RDI)  ,       %XMM0
        MOVAPD  (%RSI)  ,       %XMM1
	MOVAPD	%XMM1	,	%XMM2
	SHUFPD	$0b01	,	%XMM2	,	%XMM2
	MULPD	%XMM0	,	%XMM2
        MULPD   %XMM1   ,       %XMM0
	HSUBPD	%XMM0	,	%XMM0
	HADDPD	%XMM2	,	%XMM2
	SHUFPD	$0b10	,	%XMM2	,	%XMM0	
        MOVAPD  %XMM0   ,       (%RDX)
        ret

.global DIV_C
#       void MUL_C(double2a v, double2a w, double2a buf)
DIV_C:
        MOVAPD  (%RSI)  ,       %XMM0
        MOVAPD  (%RDI)  ,       %XMM1
        MOVAPD  %XMM1   ,       %XMM2
        SHUFPD  $0b01   ,       %XMM2   ,       %XMM2
        MULPD   %XMM0   ,       %XMM2
        MULPD   %XMM1   ,       %XMM0
        HADDPD  %XMM0   ,       %XMM0
        HSUBPD  %XMM2   ,       %XMM2
        SHUFPD  $0b10   ,       %XMM2   ,       %XMM0
	MULPD	%XMM1	,	%XMM1
	HADDPD	%XMM1	,	%XMM1
	DIVPD	%XMM1	,	%XMM0
        MOVAPD  %XMM0   ,       (%RDX)
        ret

.global ADD_E_C
#       void ADD_E_C(double2a v, double2a w)
ADD_E_C:
        MOVAPD  (%RDI)  ,       %XMM0
        MOVAPD  (%RSI)  ,       %XMM1
        ADDPD   %XMM1   ,       %XMM0
        MOVAPD  %XMM0   ,       (%RSI)
        ret

.global SUB_E_C
#       void SUB_E_C(double2a v, double2a w)
SUB_E_C:
        MOVAPD  (%RSI)  ,       %XMM0
        MOVAPD  (%RDI)  ,       %XMM1
        SUBPD   %XMM1   ,       %XMM0
        MOVAPD  %XMM0   ,       (%RSI)
        ret

.global MUL_E_C
#       void MUL_E_C(double2a v, double2a w)
MUL_E_C:
        MOVAPD  (%RDI)  ,       %XMM0
        MOVAPD  (%RSI)  ,       %XMM1
        MOVAPD  %XMM1   ,       %XMM2
        SHUFPD  $0b01   ,       %XMM2   ,       %XMM2
        MULPD   %XMM0   ,       %XMM2
        MULPD   %XMM1   ,       %XMM0
        HSUBPD  %XMM0   ,       %XMM0
        HADDPD  %XMM2   ,       %XMM2
        SHUFPD  $0b10   ,       %XMM2   ,       %XMM0
        MOVAPD  %XMM0   ,       (%RSI)
        ret

.global DIV_E_C
#       void DEV_E_C(double2a v, double2a w)
DIV_E_C:
        MOVAPD  (%RSI)  ,       %XMM0
        MOVAPD  (%RDI)  ,       %XMM1
        MOVAPD  %XMM1   ,       %XMM2
        SHUFPD  $0b01   ,       %XMM2   ,       %XMM2
        MULPD   %XMM0   ,       %XMM2
        MULPD   %XMM1   ,       %XMM0
        HADDPD  %XMM0   ,       %XMM0
        HSUBPD  %XMM2   ,       %XMM2
        SHUFPD  $0b10   ,       %XMM2   ,       %XMM0
        MULPD   %XMM1   ,       %XMM1
        HADDPD  %XMM1   ,       %XMM1
        DIVPD   %XMM1   ,       %XMM0
        MOVAPD  %XMM0   ,       (%RSI)
        ret

