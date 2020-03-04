	RSEG	DATA_N
	RSEG	SWILIB_FUNC1B8_1BB:CODE
	EXTERN	EXT2_AREA
	EXTERN	pngtop
	EXTERN	pLIB_TOP
	DCD	EXT2_AREA
	DCD	pngtop
	DCD	pLIB_TOP
	DCD	SFE(DATA_N)

defadr	MACRO	a,b
	PUBLIC	a
a	EQU	b
	ENDM

        RSEG	CODE:CODE

	PUBLIC	OldOnClose
OldOnClose:
	DCD	0xA0929C4E+1  //0xA17143F0+1  //10B5041C0320????????201C7030
	
	PUBLIC	OldOnCreate
OldOnCreate:
	DCD	0xA0929AA4+1  //0xA171422C+1  //FEB5041C0020????????????00270460
        
	PUBLIC	ESIOld
ESIOld:
	DCD	0xA1216DA2+1  //0xA1559B4C+1  //07DB????904204D00A1C211C00F0
        
        PUBLIC	PITgetN
PITgetN:
	DCD	0xA00DDC0A+1  //0xA0CB75A6+1  //DA48192189014018C068808A704710B5
	
	PUBLIC	PITret
PITret:
	DCD	0xA00DDC20+1  //0xA0CB75BC+1  //A04205D9????????0069E100401810BD
        
        PUBLIC	KEYBret
KEYBret:
	DCD	0xA00F225A+1  //0xA0CACD02+1 //381CFF38C8382FD1301C????????0028 
        
        PUBLIC	KEYBfunc
KEYBfunc:
	DCD	0xA00E2EF4+1  //0xA0CB8F60+1  //FEB5041C00680D1CC668206D02AA311C          
        
	PUBLIC	FReadOld
FReadOld:
	DCD	0xA121A1CC  //0xA113B364  //FE402DE90270A0E10160A0E10350A0E10040A0E1????????0030E0E304308DE500508DE530C090E50000A0E3
        
        PUBLIC	FWriteOld
FWriteOld:
	DCD	0xA121A2B4  //0xA113B44C  //FE402DE90270A0E10160A0E10350A0E10040A0E1????????0030E0E304308DE500508DE55CC090E50000A0E3       
        
        defadr	StoreErrInfoAndAbort,0xA121AD00  //0xA113BE98  //F04D2DE90040A0E190029FE50080A0E30260A0E10150A0E1
	defadr	StoreErrString,0xA121AB24  //0xA113BCBC  //0A10A0E3E9FFFFEA10402DE9F410A0E33C049FE5

	END