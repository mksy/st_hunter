
#include "addr.h"

#define V_1_2_A //编译1.2a
//#define	V_1_3  //编译1.3

	RSEG	IME_HOOK
	CODE16
	LDR	R0, =IME_
	BX	R0
	
	RSEG	INPUTER_SEL_JAVA_HOOK
	CODE16
	LDR	R3, =INPUTER_SEL_JAVA_
	BLX	R3
	
	RSEG	IME_KEY1_HOOK
	CODE16
	LDR	R0, =IME_KEY1_
	BX	R0
	
	RSEG	XING_JAVA_HOOK
	CODE16
	BEQ	DO_XING_FIX	// !!! IAR计算错误，BEQ: D0
				// 所以请手动修改VKP中的FF为D0

	RSEG	KEY0_JAVA_HOOK
	CODE16
	LDR	R3, =KEY0_JAVA_
	BX	R3	
	
	RSEG	CODE
	CODE16
SEND_KEYUP_MSG
	PUSH	{R0-R7, LR}
	LDR	R0, MMI_CEPID
	LDR	R1, KEY_UP
	MOV	R2, #'1'
	LDR	R7, _GBS_SendMessage_adr
	BLX	R7
	POP	{R0-R7, PC}
SEND_LONGPRESS_MSG
	PUSH	{R0-R7, LR}
	LDR	R0, MMI_CEPID
	LDR	R1, LONG_PRESS
	MOV	R2, #'1'
	LDR	R7, _GBS_SendMessage_adr
	BLX	R7
	POP	{R0-R7, PC}

IME_
	MOV	R0, #1
	STR	R0, [SP, #0x84]
	LDR	R0, [SP, #0xA0]
	MOV	R3, #2
	LDRSH	R0, [R0, R3]
	CMP	R0, #0			//非功能键短按输入为0
	BEQ	IME_START
#ifdef	V_1_3
	CMP	R0, #0x15
	BEQ	DO_KEY_JING		//#键
#endif
EX_BACK
	LDR	R3, =DO_IME_BACK
	BX	R3
	
IME_START
	LDR	R3, [SP, #0x88]
	CMP	R3, #'1' //1
	BEQ	DO_KEY_K1
	CMP	R3, #'*'
	BEQ	DO_KEY_XING
	CMP	R3, #'9'
	BEQ	DO_KEY_K9
	CMP	R3, #'5'
	BEQ	DO_KEY_K5
	CMP	R3, #'0'
	BNE	EX_BACK
	//BEQ	DO_KEY_K0
	//B	EX_BACK

DO_KEY_K0
	CMP	R7, #1
	BEQ	DO_K0
	CMP	R7, #2
	BNE	DO_NOTHING_ALL
DO_K0
#ifdef	V_1_2_A //v1.2a
	LDR	R3, =DO_DOWN
	BX	R3
#else
	LDR	R3, =DO_RIGHT
	BX	R3
#endif
	
DO_KEY_K5
	CMP	R7, #1
	BNE	EX_BACK
	
	LDR	R0, [SP,#0xA0]
	LDR	R3, _JAVA_EDIT_KOP
	CMP	R0, R3			//判断是否在JAVA中
	BEQ	IS_JAVA_K5
	BL	SEND_KEYUP_MSG
	MOV	R7, #'1'
	LDR	R3, =DO_DIRECT_SELECT
	BX	R3
IS_JAVA_K5
	BL	SEND_LONGPRESS_MSG
	BL	SEND_KEYUP_MSG
DO_NOTHING_ALL
	LDR	R3, =DO_NOTHING
	BX	R3

#ifdef	V_1_3 //v1.3
DO_KEY_JING
	CMP	R7, #1
	BEQ	DO_JING
	CMP	R7, #2
	BNE	EX_BACK
DO_JING
	LDR	R3, =DO_DOWN
	BX	R3
	
DO_KEY_K9
	CMP	R7, #1
	BEQ	DO_K9
	CMP	R7, #2
	BNE	EX_BACK
DO_K9
	LDR	R3, =DO_UP
	BX	R3
#else
DO_KEY_K9
	CMP	R7, #1
	BEQ	DO_K9
	CMP	R7, #2
	BNE	EX_BACK
DO_K9
#ifdef	V_1_2_A //v1.2a
	LDR	R3, =DO_UP
	BX	R3
#else
	LDR	R3, =DO_DOWN
	BX	R3
#endif
#endif
DO_KEY_XING
	CMP	R7, #1
	BEQ	DO_KXING
	CMP	R7, #2
	BNE	EX_BACK
DO_KXING
#ifdef	V_1_2_A
	LDR	R3, =DO_RIGHT
	BX	R3
#else
	LDR	R3, =DO_LEFT
	BX	R3
#endif

DO_KEY_K1
	CMP	R7, #1
	BNE	EX_BACK
DO_K1
	LDR	R3, =DO_SELECT
	BX	R3

//1键处理
IME_KEY1_
	LDR	R0, [SP, #0x88]
	CMP	R0, #'1'
	BEQ	DO_K1_PP
	SUB	R0, #0x32
	CMP	R0, #7
	BHI	DO_NOTHING_ALL
	LDR	R0, =DO_KEY1_BACK
	BX	R0
	
DO_K1_PP
	LDR	R0, [SP,#0xA0]
	LDR	R3, _JAVA_EDIT_KOP
	CMP	R0, R3
	BNE	DO_K1			//不是在JAVA中，直接选择
	LDR	R3, _USE_RAM
	LDR	R0, [R3, #0]
	CMP	R0, #0			//判断是否真是从输入法选择菜单返回
	BEQ	DO_K1
	MOV	R0, #0
	STR	R0, [R3, #0]		//归零
	B	DO_NOTHING_ALL

//用于存储JAVA中输入法选择菜单状态,1表示刚打开过
INPUTER_SEL_JAVA_
	STR	R4, [SP, #0x10]
	STR	R7, [SP, #0x18]
	MOV	R3, #1
	STRB	R3, [R0, #0]
	LDR	R0, _USE_RAM
	//MOV	R3, #1
	STR	R3, [R0, #0]
	MOV	R0, LR
	ADD	R0, #4
	BX	R0

//JAVA中的0键预处理,等待输入状态则输入标点,拼音输入或选字状态则进入拼音输入法统一处理
KEY0_JAVA_
	LDR	R0, =GET_INPUT_STATE  //获取输入状态
	BLX	R0
	CMP	R0, #0 //拼音输入或选字状态
	BEQ	GOTO_IME
	MOV	R3, #1
	STR	R3, [R1,#0x1C]
	LDR	R3, =KEY0_FUNC1
	BLX	R3
	LDR	R3, =KEY0_BACK
	BX	R3
GOTO_IME
	LDR	R0, =KEY0_GOTO_IME
	BX	R0
	//NOP
	
	DATA
MMI_CEPID
	DCD	0x4209
KEY_UP
	DCD	0x194
LONG_PRESS
	DCD	0x195
_JAVA_EDIT_KOP
	DCD	JAVA_EDIT_KOP
_GBS_SendMessage_adr
	DCD	GBS_SendMessage_adr
_USE_RAM
	DCD	USE_RAM
	
	END