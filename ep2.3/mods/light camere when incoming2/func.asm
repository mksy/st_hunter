	PUBLIC	ELF_BEGIN
	RSEG	ELFBEGIN:DATA
ELF_BEGIN

	RSEG	CODE:CODE
	PUBLIC	kill_data
	CODE32
kill_data
	BX	R1
        PUBLIC  seqkill
seqkill
        BX      R3



defadr	MACRO	a,b
	PUBLIC	a
a	EQU	b
	ENDM
        

//eska        defadr CameraLightOnOff,0xA032EBB7,0xA032EBB7
        defadr CameraLightOnOff,0xA06F6617
       
       
       END
	