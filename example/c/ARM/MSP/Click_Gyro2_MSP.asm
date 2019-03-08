_systemInit:
;Click_Gyro2_MSP.c,38 :: 		void systemInit()
SUB	SP, SP, #4
STR	LR, [SP, #0]
;Click_Gyro2_MSP.c,40 :: 		mikrobus_gpioInit( _MIKROBUS1, _MIKROBUS_INT_PIN, _GPIO_INPUT );
MOVS	R2, #1
MOVS	R1, #7
MOVS	R0, #0
BL	_mikrobus_gpioInit+0
;Click_Gyro2_MSP.c,41 :: 		mikrobus_gpioInit( _MIKROBUS1, _MIKROBUS_RST_PIN, _GPIO_OUTPUT );
MOVS	R2, #0
MOVS	R1, #1
MOVS	R0, #0
BL	_mikrobus_gpioInit+0
;Click_Gyro2_MSP.c,42 :: 		mikrobus_gpioInit( _MIKROBUS1, _MIKROBUS_CS_PIN, _GPIO_OUTPUT );
MOVS	R2, #0
MOVS	R1, #2
MOVS	R0, #0
BL	_mikrobus_gpioInit+0
;Click_Gyro2_MSP.c,43 :: 		mikrobus_gpioInit( _MIKROBUS1, _MIKROBUS_AN_PIN, _GPIO_OUTPUT );
MOVS	R2, #0
MOVS	R1, #0
MOVS	R0, #0
BL	_mikrobus_gpioInit+0
;Click_Gyro2_MSP.c,44 :: 		mikrobus_gpioInit( _MIKROBUS1, _MIKROBUS_PWM_PIN, _GPIO_INPUT );
MOVS	R2, #1
MOVS	R1, #6
MOVS	R0, #0
BL	_mikrobus_gpioInit+0
;Click_Gyro2_MSP.c,47 :: 		mikrobus_i2cInit( _MIKROBUS1, &_GYRO2_I2C_CFG[0] );
MOVW	R0, #lo_addr(__GYRO2_I2C_CFG+0)
MOVT	R0, #hi_addr(__GYRO2_I2C_CFG+0)
MOV	R1, R0
MOVS	R0, #0
BL	_mikrobus_i2cInit+0
;Click_Gyro2_MSP.c,50 :: 		mikrobus_logInit( _MIKROBUS2, 9600 );
MOVW	R1, #9600
MOVS	R0, #1
BL	_mikrobus_logInit+0
;Click_Gyro2_MSP.c,52 :: 		Delay_ms( 100 );
MOVW	R7, #20349
MOVT	R7, #18
NOP
NOP
L_systemInit0:
SUBS	R7, R7, #1
BNE	L_systemInit0
NOP
NOP
NOP
;Click_Gyro2_MSP.c,53 :: 		}
L_end_systemInit:
LDR	LR, [SP, #0]
ADD	SP, SP, #4
BX	LR
; end of _systemInit
_applicationInit:
;Click_Gyro2_MSP.c,55 :: 		void applicationInit()
SUB	SP, SP, #4
STR	LR, [SP, #0]
;Click_Gyro2_MSP.c,58 :: 		gyro2_i2cDriverInit( (T_GYRO2_P)&_MIKROBUS1_GPIO, (T_GYRO2_P)&_MIKROBUS1_I2C, GYRO2_ADDR1 );
MOVW	R0, #lo_addr(_GYRO2_ADDR1+0)
MOVT	R0, #hi_addr(_GYRO2_ADDR1+0)
LDRB	R0, [R0, #0]
UXTB	R2, R0
MOVW	R1, #lo_addr(__MIKROBUS1_I2C+0)
MOVT	R1, #hi_addr(__MIKROBUS1_I2C+0)
MOVW	R0, #lo_addr(__MIKROBUS1_GPIO+0)
MOVT	R0, #hi_addr(__MIKROBUS1_GPIO+0)
BL	_gyro2_i2cDriverInit+0
;Click_Gyro2_MSP.c,62 :: 		mikrobus_logWrite("+++ System Initialized +++",_LOG_LINE);
MOVW	R0, #lo_addr(?lstr1_Click_Gyro2_MSP+0)
MOVT	R0, #hi_addr(?lstr1_Click_Gyro2_MSP+0)
MOVS	R1, #2
BL	_mikrobus_logWrite+0
;Click_Gyro2_MSP.c,63 :: 		Delay_ms(1000);
MOVW	R7, #6909
MOVT	R7, #183
NOP
NOP
L_applicationInit2:
SUBS	R7, R7, #1
BNE	L_applicationInit2
NOP
NOP
NOP
;Click_Gyro2_MSP.c,65 :: 		if(gyro2_getID() == 0xD7)
BL	_gyro2_getID+0
CMP	R0, #215
IT	NE
BNE	L_applicationInit4
;Click_Gyro2_MSP.c,67 :: 		mikrobus_logWrite("Gyro 2 click present",_LOG_LINE);
MOVW	R0, #lo_addr(?lstr2_Click_Gyro2_MSP+0)
MOVT	R0, #hi_addr(?lstr2_Click_Gyro2_MSP+0)
MOVS	R1, #2
BL	_mikrobus_logWrite+0
;Click_Gyro2_MSP.c,68 :: 		gyro2_interruptEventgeneration(GYRO2_RT_CFG_ZTEFE | GYRO2_RT_CFG_YTEFE | GYRO2_RT_CFG_XTEFE);
MOVW	R0, #lo_addr(_GYRO2_RT_CFG_YTEFE+0)
MOVT	R0, #hi_addr(_GYRO2_RT_CFG_YTEFE+0)
LDRB	R1, [R0, #0]
MOVW	R0, #lo_addr(_GYRO2_RT_CFG_ZTEFE+0)
MOVT	R0, #hi_addr(_GYRO2_RT_CFG_ZTEFE+0)
LDRB	R0, [R0, #0]
ORR	R1, R0, R1, LSL #0
UXTB	R1, R1
MOVW	R0, #lo_addr(_GYRO2_RT_CFG_XTEFE+0)
MOVT	R0, #hi_addr(_GYRO2_RT_CFG_XTEFE+0)
LDRB	R0, [R0, #0]
ORR	R0, R1, R0, LSL #0
BL	_gyro2_interruptEventgeneration+0
;Click_Gyro2_MSP.c,69 :: 		gyro2_sensitivity(10);
MOVS	R0, #10
BL	_gyro2_sensitivity+0
;Click_Gyro2_MSP.c,70 :: 		gyro2_setOpmode(GYRO2_Active);
MOVW	R0, #lo_addr(_GYRO2_Active+0)
MOVT	R0, #hi_addr(_GYRO2_Active+0)
LDRB	R0, [R0, #0]
BL	_gyro2_setOpmode+0
;Click_Gyro2_MSP.c,71 :: 		gyro2_setDR(GYRO2_DR_100Hz);
MOVW	R0, #lo_addr(_GYRO2_DR_100Hz+0)
MOVT	R0, #hi_addr(_GYRO2_DR_100Hz+0)
LDRB	R0, [R0, #0]
BL	_gyro2_setDR+0
;Click_Gyro2_MSP.c,72 :: 		gyro2_interruptCfg( GYRO2_INT_CFG_FIFO_INT1, GYRO2_INT_EN_FIFO | GYRO2_INT_EN_DRDY, GYRO2_IPOL_ACTIVE_HI );
MOVW	R0, #lo_addr(_GYRO2_IPOL_ACTIVE_HI+0)
MOVT	R0, #hi_addr(_GYRO2_IPOL_ACTIVE_HI+0)
LDRB	R2, [R0, #0]
MOVW	R0, #lo_addr(_GYRO2_INT_EN_DRDY+0)
MOVT	R0, #hi_addr(_GYRO2_INT_EN_DRDY+0)
LDRB	R1, [R0, #0]
MOVW	R0, #lo_addr(_GYRO2_INT_EN_FIFO+0)
MOVT	R0, #hi_addr(_GYRO2_INT_EN_FIFO+0)
LDRB	R0, [R0, #0]
ORR	R1, R0, R1, LSL #0
MOVW	R0, #lo_addr(_GYRO2_INT_CFG_FIFO_INT1+0)
MOVT	R0, #hi_addr(_GYRO2_INT_CFG_FIFO_INT1+0)
LDRB	R0, [R0, #0]
BL	_gyro2_interruptCfg+0
;Click_Gyro2_MSP.c,73 :: 		gyro2_frSetup(GYRO2_LO_PASS_MOD2, GYRO2_HI_PASS_OFF, GYRO2_SCALE_3);
MOVW	R0, #lo_addr(_GYRO2_SCALE_3+0)
MOVT	R0, #hi_addr(_GYRO2_SCALE_3+0)
LDRB	R2, [R0, #0]
MOVW	R0, #lo_addr(_GYRO2_HI_PASS_OFF+0)
MOVT	R0, #hi_addr(_GYRO2_HI_PASS_OFF+0)
LDRB	R1, [R0, #0]
MOVW	R0, #lo_addr(_GYRO2_LO_PASS_MOD2+0)
MOVT	R0, #hi_addr(_GYRO2_LO_PASS_MOD2+0)
LDRB	R0, [R0, #0]
BL	_gyro2_frSetup+0
;Click_Gyro2_MSP.c,74 :: 		}
IT	AL
BAL	L_applicationInit5
L_applicationInit4:
;Click_Gyro2_MSP.c,77 :: 		mikrobus_logWrite("error",_LOG_LINE);
MOVW	R0, #lo_addr(?lstr3_Click_Gyro2_MSP+0)
MOVT	R0, #hi_addr(?lstr3_Click_Gyro2_MSP+0)
MOVS	R1, #2
BL	_mikrobus_logWrite+0
;Click_Gyro2_MSP.c,78 :: 		while(1);
L_applicationInit6:
IT	AL
BAL	L_applicationInit6
;Click_Gyro2_MSP.c,79 :: 		}
L_applicationInit5:
;Click_Gyro2_MSP.c,80 :: 		Delay_ms(1000);
MOVW	R7, #6909
MOVT	R7, #183
NOP
NOP
L_applicationInit8:
SUBS	R7, R7, #1
BNE	L_applicationInit8
NOP
NOP
NOP
;Click_Gyro2_MSP.c,81 :: 		}
L_end_applicationInit:
LDR	LR, [SP, #0]
ADD	SP, SP, #4
BX	LR
; end of _applicationInit
_applicationTask:
;Click_Gyro2_MSP.c,83 :: 		void applicationTask()
SUB	SP, SP, #4
STR	LR, [SP, #0]
;Click_Gyro2_MSP.c,85 :: 		if(gyro2_pwmPin())
BL	_gyro2_pwmPin+0
CMP	R0, #0
IT	EQ
BEQ	L_applicationTask10
;Click_Gyro2_MSP.c,87 :: 		gyro2_getAxisraw(&axisDatatmp[0]);
MOVW	R0, #lo_addr(_axisDatatmp+0)
MOVT	R0, #hi_addr(_axisDatatmp+0)
BL	_gyro2_getAxisraw+0
;Click_Gyro2_MSP.c,88 :: 		gyro2_calcAxis(&axisDatatmp[0]);
MOVW	R0, #lo_addr(_axisDatatmp+0)
MOVT	R0, #hi_addr(_axisDatatmp+0)
BL	_gyro2_calcAxis+0
;Click_Gyro2_MSP.c,90 :: 		IntToStr( axisDatatmp[0], text);
MOVW	R0, #lo_addr(_axisDatatmp+0)
MOVT	R0, #hi_addr(_axisDatatmp+0)
LDRSH	R0, [R0, #0]
MOVW	R1, #lo_addr(_text+0)
MOVT	R1, #hi_addr(_text+0)
BL	_IntToStr+0
;Click_Gyro2_MSP.c,91 :: 		mikrobus_logWrite( "X: ",_LOG_TEXT);
MOVW	R0, #lo_addr(?lstr4_Click_Gyro2_MSP+0)
MOVT	R0, #hi_addr(?lstr4_Click_Gyro2_MSP+0)
MOVS	R1, #1
BL	_mikrobus_logWrite+0
;Click_Gyro2_MSP.c,92 :: 		Ltrim(text);
MOVW	R0, #lo_addr(_text+0)
MOVT	R0, #hi_addr(_text+0)
BL	_Ltrim+0
;Click_Gyro2_MSP.c,93 :: 		mikrobus_logWrite( text,_LOG_LINE);
MOVS	R1, #2
MOVW	R0, #lo_addr(_text+0)
MOVT	R0, #hi_addr(_text+0)
BL	_mikrobus_logWrite+0
;Click_Gyro2_MSP.c,94 :: 		IntToStr( axisDatatmp[1], text);
MOVW	R0, #lo_addr(_axisDatatmp+2)
MOVT	R0, #hi_addr(_axisDatatmp+2)
LDRSH	R0, [R0, #0]
MOVW	R1, #lo_addr(_text+0)
MOVT	R1, #hi_addr(_text+0)
BL	_IntToStr+0
;Click_Gyro2_MSP.c,95 :: 		mikrobus_logWrite( "Y: ",_LOG_TEXT);
MOVW	R0, #lo_addr(?lstr5_Click_Gyro2_MSP+0)
MOVT	R0, #hi_addr(?lstr5_Click_Gyro2_MSP+0)
MOVS	R1, #1
BL	_mikrobus_logWrite+0
;Click_Gyro2_MSP.c,96 :: 		Ltrim(text);
MOVW	R0, #lo_addr(_text+0)
MOVT	R0, #hi_addr(_text+0)
BL	_Ltrim+0
;Click_Gyro2_MSP.c,97 :: 		mikrobus_logWrite( text,_LOG_LINE);
MOVS	R1, #2
MOVW	R0, #lo_addr(_text+0)
MOVT	R0, #hi_addr(_text+0)
BL	_mikrobus_logWrite+0
;Click_Gyro2_MSP.c,98 :: 		IntToStr( axisDatatmp[2], text);
MOVW	R0, #lo_addr(_axisDatatmp+4)
MOVT	R0, #hi_addr(_axisDatatmp+4)
LDRSH	R0, [R0, #0]
MOVW	R1, #lo_addr(_text+0)
MOVT	R1, #hi_addr(_text+0)
BL	_IntToStr+0
;Click_Gyro2_MSP.c,99 :: 		mikrobus_logWrite( "Z: ",_LOG_TEXT);
MOVW	R0, #lo_addr(?lstr6_Click_Gyro2_MSP+0)
MOVT	R0, #hi_addr(?lstr6_Click_Gyro2_MSP+0)
MOVS	R1, #1
BL	_mikrobus_logWrite+0
;Click_Gyro2_MSP.c,100 :: 		Ltrim(text);
MOVW	R0, #lo_addr(_text+0)
MOVT	R0, #hi_addr(_text+0)
BL	_Ltrim+0
;Click_Gyro2_MSP.c,101 :: 		mikrobus_logWrite( text,_LOG_LINE);
MOVS	R1, #2
MOVW	R0, #lo_addr(_text+0)
MOVT	R0, #hi_addr(_text+0)
BL	_mikrobus_logWrite+0
;Click_Gyro2_MSP.c,102 :: 		mikrobus_logWrite("---",_LOG_LINE);
MOVW	R0, #lo_addr(?lstr7_Click_Gyro2_MSP+0)
MOVT	R0, #hi_addr(?lstr7_Click_Gyro2_MSP+0)
MOVS	R1, #2
BL	_mikrobus_logWrite+0
;Click_Gyro2_MSP.c,103 :: 		}
L_applicationTask10:
;Click_Gyro2_MSP.c,104 :: 		}
L_end_applicationTask:
LDR	LR, [SP, #0]
ADD	SP, SP, #4
BX	LR
; end of _applicationTask
_main:
;Click_Gyro2_MSP.c,106 :: 		void main()
SUB	SP, SP, #4
;Click_Gyro2_MSP.c,108 :: 		systemInit();
BL	_systemInit+0
;Click_Gyro2_MSP.c,109 :: 		applicationInit();
BL	_applicationInit+0
;Click_Gyro2_MSP.c,111 :: 		while (1)
L_main11:
;Click_Gyro2_MSP.c,113 :: 		applicationTask();
BL	_applicationTask+0
;Click_Gyro2_MSP.c,114 :: 		}
IT	AL
BAL	L_main11
;Click_Gyro2_MSP.c,115 :: 		}
L_end_main:
L__main_end_loop:
B	L__main_end_loop
; end of _main
