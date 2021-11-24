;******************************************************************************
;* TMS320C6x C/C++ Codegen                                          PC v5.1.0 *
;* Date/Time created: Tue Jun 05 11:52:12 2007                                *
;******************************************************************************
	.compiler_opts --endian=little --mem_model:code=near --mem_model:data=far --silicon_version=6710 

;******************************************************************************
;* GLOBAL FILE PARAMETERS                                                     *
;*                                                                            *
;*   Architecture      : TMS320C671x                                          *
;*   Optimization      : Disabled                                             *
;*   Optimizing for    : Compile time, Ease of Development                    *
;*                       Based on options: no -o, no -ms                      *
;*   Endian            : Little                                               *
;*   Interrupt Thrshld : Disabled                                             *
;*   Data Access Model : Far                                                  *
;*   Pipelining        : Disabled                                             *
;*   Memory Aliases    : Presume are aliases (pessimistic)                    *
;*   Debug Info        : DWARF Debug                                          *
;*                                                                            *
;******************************************************************************

	.asg	A15, FP
	.asg	B14, DP
	.asg	B15, SP
	.global	$bss


DW$CU	.dwtag  DW_TAG_compile_unit
	.dwattr DW$CU, DW_AT_name("c6713dskinit.c")
	.dwattr DW$CU, DW_AT_producer("TMS320C6x C/C++ Codegen PC v5.1.0 Copyright (c) 1996-2005 Texas Instruments Incorporated")
	.dwattr DW$CU, DW_AT_stmt_list(0x00)
	.dwattr DW$CU, DW_AT_TI_VERSION(0x01)
;*****************************************************************************
;* CINIT RECORDS                                                             *
;*****************************************************************************
	.sect	".cinit"
	.align	8
	.field  	IR_1,32
	.field  	_AIC23CfgData+0,32
	.field  	0,32			; _AIC23CfgData._spcr @ 0
	.field  	160,32			; _AIC23CfgData._rcr @ 32
	.field  	160,32			; _AIC23CfgData._xcr @ 64
	.field  	536870913,32			; _AIC23CfgData._srgr @ 96
	.field  	0,32			; _AIC23CfgData._mcr @ 128
	.field  	0,32			; _AIC23CfgData._rcer @ 160
	.field  	0,32			; _AIC23CfgData._xcer @ 192
	.field  	3,32			; _AIC23CfgData._pcr @ 224
IR_1:	.set	32

	.sect	".cinit"
	.align	8
	.field  	IR_2,32
	.field  	_config+0,32
	.field  	23,32			; _config._regs[0] @ 0
	.field  	23,32			; _config._regs[1] @ 32
	.field  	505,32			; _config._regs[2] @ 64
	.field  	505,32			; _config._regs[3] @ 96
	.field  	21,32			; _config._regs[4] @ 128
	.field  	0,32			; _config._regs[5] @ 160
	.field  	0,32			; _config._regs[6] @ 192
	.field  	67,32			; _config._regs[7] @ 224
	.field  	129,32			; _config._regs[8] @ 256
	.field  	1,32			; _config._regs[9] @ 288
IR_2:	.set	40


DW$1	.dwtag  DW_TAG_subprogram, DW_AT_name("IRQ_map"), DW_AT_symbol_name("_IRQ_map")
	.dwattr DW$1, DW_AT_declaration(0x01)
	.dwattr DW$1, DW_AT_external(0x01)
DW$2	.dwtag  DW_TAG_formal_parameter, DW_AT_type(*DW$T$19)
DW$3	.dwtag  DW_TAG_formal_parameter, DW_AT_type(*DW$T$19)
	.dwendtag DW$1


DW$4	.dwtag  DW_TAG_subprogram, DW_AT_name("IRQ_enable"), DW_AT_symbol_name("_IRQ_enable")
	.dwattr DW$4, DW_AT_declaration(0x01)
	.dwattr DW$4, DW_AT_external(0x01)
DW$5	.dwtag  DW_TAG_formal_parameter, DW_AT_type(*DW$T$19)
	.dwendtag DW$4


DW$6	.dwtag  DW_TAG_subprogram, DW_AT_name("IRQ_reset"), DW_AT_symbol_name("_IRQ_reset")
	.dwattr DW$6, DW_AT_declaration(0x01)
	.dwattr DW$6, DW_AT_external(0x01)
DW$7	.dwtag  DW_TAG_formal_parameter, DW_AT_type(*DW$T$19)
	.dwendtag DW$6


DW$8	.dwtag  DW_TAG_subprogram, DW_AT_name("IRQ_globalEnable"), DW_AT_symbol_name("_IRQ_globalEnable")
	.dwattr DW$8, DW_AT_declaration(0x01)
	.dwattr DW$8, DW_AT_external(0x01)

DW$9	.dwtag  DW_TAG_subprogram, DW_AT_name("IRQ_globalDisable"), DW_AT_symbol_name("_IRQ_globalDisable")
	.dwattr DW$9, DW_AT_type(*DW$T$19)
	.dwattr DW$9, DW_AT_declaration(0x01)
	.dwattr DW$9, DW_AT_external(0x01)

DW$10	.dwtag  DW_TAG_subprogram, DW_AT_name("IRQ_nmiEnable"), DW_AT_symbol_name("_IRQ_nmiEnable")
	.dwattr DW$10, DW_AT_declaration(0x01)
	.dwattr DW$10, DW_AT_external(0x01)

DW$11	.dwtag  DW_TAG_subprogram, DW_AT_name("DSK6713_init"), DW_AT_symbol_name("_DSK6713_init")
	.dwattr DW$11, DW_AT_declaration(0x01)
	.dwattr DW$11, DW_AT_external(0x01)

DW$12	.dwtag  DW_TAG_subprogram, DW_AT_name("MCBSP_start"), DW_AT_symbol_name("_MCBSP_start")
	.dwattr DW$12, DW_AT_declaration(0x01)
	.dwattr DW$12, DW_AT_external(0x01)
DW$13	.dwtag  DW_TAG_formal_parameter, DW_AT_type(*DW$T$35)
DW$14	.dwtag  DW_TAG_formal_parameter, DW_AT_type(*DW$T$19)
DW$15	.dwtag  DW_TAG_formal_parameter, DW_AT_type(*DW$T$19)
	.dwendtag DW$12


DW$16	.dwtag  DW_TAG_subprogram, DW_AT_name("MCBSP_getXmtEventId"), DW_AT_symbol_name("_MCBSP_getXmtEventId")
	.dwattr DW$16, DW_AT_type(*DW$T$19)
	.dwattr DW$16, DW_AT_declaration(0x01)
	.dwattr DW$16, DW_AT_external(0x01)
DW$17	.dwtag  DW_TAG_formal_parameter, DW_AT_type(*DW$T$35)
	.dwendtag DW$16


DW$18	.dwtag  DW_TAG_subprogram, DW_AT_name("MCBSP_read"), DW_AT_symbol_name("_MCBSP_read")
	.dwattr DW$18, DW_AT_type(*DW$T$19)
	.dwattr DW$18, DW_AT_declaration(0x01)
	.dwattr DW$18, DW_AT_external(0x01)
DW$19	.dwtag  DW_TAG_formal_parameter, DW_AT_type(*DW$T$35)
	.dwendtag DW$18


DW$20	.dwtag  DW_TAG_subprogram, DW_AT_name("MCBSP_write"), DW_AT_symbol_name("_MCBSP_write")
	.dwattr DW$20, DW_AT_declaration(0x01)
	.dwattr DW$20, DW_AT_external(0x01)
DW$21	.dwtag  DW_TAG_formal_parameter, DW_AT_type(*DW$T$35)
DW$22	.dwtag  DW_TAG_formal_parameter, DW_AT_type(*DW$T$19)
	.dwendtag DW$20


DW$23	.dwtag  DW_TAG_subprogram, DW_AT_name("MCBSP_xrdy"), DW_AT_symbol_name("_MCBSP_xrdy")
	.dwattr DW$23, DW_AT_type(*DW$T$19)
	.dwattr DW$23, DW_AT_declaration(0x01)
	.dwattr DW$23, DW_AT_external(0x01)
DW$24	.dwtag  DW_TAG_formal_parameter, DW_AT_type(*DW$T$35)
	.dwendtag DW$23


DW$25	.dwtag  DW_TAG_subprogram, DW_AT_name("MCBSP_rrdy"), DW_AT_symbol_name("_MCBSP_rrdy")
	.dwattr DW$25, DW_AT_type(*DW$T$19)
	.dwattr DW$25, DW_AT_declaration(0x01)
	.dwattr DW$25, DW_AT_external(0x01)
DW$26	.dwtag  DW_TAG_formal_parameter, DW_AT_type(*DW$T$35)
	.dwendtag DW$25


DW$27	.dwtag  DW_TAG_subprogram, DW_AT_name("MCBSP_config"), DW_AT_symbol_name("_MCBSP_config")
	.dwattr DW$27, DW_AT_declaration(0x01)
	.dwattr DW$27, DW_AT_external(0x01)
DW$28	.dwtag  DW_TAG_formal_parameter, DW_AT_type(*DW$T$35)
DW$29	.dwtag  DW_TAG_formal_parameter, DW_AT_type(*DW$T$41)
	.dwendtag DW$27


DW$30	.dwtag  DW_TAG_subprogram, DW_AT_name("DSK6713_AIC23_rset"), DW_AT_symbol_name("_DSK6713_AIC23_rset")
	.dwattr DW$30, DW_AT_declaration(0x01)
	.dwattr DW$30, DW_AT_external(0x01)
DW$31	.dwtag  DW_TAG_formal_parameter, DW_AT_type(*DW$T$44)
DW$32	.dwtag  DW_TAG_formal_parameter, DW_AT_type(*DW$T$45)
DW$33	.dwtag  DW_TAG_formal_parameter, DW_AT_type(*DW$T$45)
	.dwendtag DW$30


DW$34	.dwtag  DW_TAG_subprogram, DW_AT_name("DSK6713_AIC23_openCodec"), DW_AT_symbol_name("_DSK6713_AIC23_openCodec")
	.dwattr DW$34, DW_AT_type(*DW$T$44)
	.dwattr DW$34, DW_AT_declaration(0x01)
	.dwattr DW$34, DW_AT_external(0x01)
DW$35	.dwtag  DW_TAG_formal_parameter, DW_AT_type(*DW$T$10)
DW$36	.dwtag  DW_TAG_formal_parameter, DW_AT_type(*DW$T$57)
	.dwendtag DW$34


DW$37	.dwtag  DW_TAG_subprogram, DW_AT_name("DSK6713_AIC23_setFreq"), DW_AT_symbol_name("_DSK6713_AIC23_setFreq")
	.dwattr DW$37, DW_AT_declaration(0x01)
	.dwattr DW$37, DW_AT_external(0x01)
DW$38	.dwtag  DW_TAG_formal_parameter, DW_AT_type(*DW$T$44)
DW$39	.dwtag  DW_TAG_formal_parameter, DW_AT_type(*DW$T$19)
	.dwendtag DW$37

DW$40	.dwtag  DW_TAG_variable, DW_AT_name("DSK6713_AIC23_codecdatahandle"), DW_AT_symbol_name("_DSK6713_AIC23_codecdatahandle")
	.dwattr DW$40, DW_AT_type(*DW$T$35)
	.dwattr DW$40, DW_AT_declaration(0x01)
	.dwattr DW$40, DW_AT_external(0x01)
	.global	_AIC_data
_AIC_data:	.usect	".far",4,4
DW$41	.dwtag  DW_TAG_variable, DW_AT_name("AIC_data"), DW_AT_symbol_name("_AIC_data")
	.dwattr DW$41, DW_AT_location[DW_OP_addr _AIC_data]
	.dwattr DW$41, DW_AT_type(*DW$T$27)
	.dwattr DW$41, DW_AT_external(0x01)
_CODECEventId:	.usect	".far",4,4
DW$42	.dwtag  DW_TAG_variable, DW_AT_name("CODECEventId"), DW_AT_symbol_name("_CODECEventId")
	.dwattr DW$42, DW_AT_type(*DW$T$19)
	.dwattr DW$42, DW_AT_location[DW_OP_addr _CODECEventId]
_poll:	.usect	".far",4,4
DW$43	.dwtag  DW_TAG_variable, DW_AT_name("poll"), DW_AT_symbol_name("_poll")
	.dwattr DW$43, DW_AT_type(*DW$T$19)
	.dwattr DW$43, DW_AT_location[DW_OP_addr _poll]
	.global	_AIC23CfgData
_AIC23CfgData:	.usect	".far",32,4
DW$44	.dwtag  DW_TAG_variable, DW_AT_name("AIC23CfgData"), DW_AT_symbol_name("_AIC23CfgData")
	.dwattr DW$44, DW_AT_location[DW_OP_addr _AIC23CfgData]
	.dwattr DW$44, DW_AT_type(*DW$T$40)
	.dwattr DW$44, DW_AT_external(0x01)
	.global	_config
_config:	.usect	".far",40,4
DW$45	.dwtag  DW_TAG_variable, DW_AT_name("config"), DW_AT_symbol_name("_config")
	.dwattr DW$45, DW_AT_location[DW_OP_addr _config]
	.dwattr DW$45, DW_AT_type(*DW$T$56)
	.dwattr DW$45, DW_AT_external(0x01)
	.global	_hAIC23_handle
_hAIC23_handle:	.usect	".far",4,4
DW$46	.dwtag  DW_TAG_variable, DW_AT_name("hAIC23_handle"), DW_AT_symbol_name("_hAIC23_handle")
	.dwattr DW$46, DW_AT_location[DW_OP_addr _hAIC23_handle]
	.dwattr DW$46, DW_AT_type(*DW$T$44)
	.dwattr DW$46, DW_AT_external(0x01)
DW$47	.dwtag  DW_TAG_variable, DW_AT_name("fs"), DW_AT_symbol_name("_fs")
	.dwattr DW$47, DW_AT_type(*DW$T$19)
	.dwattr DW$47, DW_AT_declaration(0x01)
	.dwattr DW$47, DW_AT_external(0x01)
DW$48	.dwtag  DW_TAG_variable, DW_AT_name("inputsource"), DW_AT_symbol_name("_inputsource")
	.dwattr DW$48, DW_AT_type(*DW$T$45)
	.dwattr DW$48, DW_AT_declaration(0x01)
	.dwattr DW$48, DW_AT_external(0x01)
;	C:\CCStudio_v3.1\C6000\cgtools\bin\acp6x.exe -@C:\DOCUME~1\Donald\LOCALS~1\Temp\TI94012 
	.sect	".text"
	.global	_c6713_dsk_init

DW$49	.dwtag  DW_TAG_subprogram, DW_AT_name("c6713_dsk_init"), DW_AT_symbol_name("_c6713_dsk_init")
	.dwattr DW$49, DW_AT_low_pc(_c6713_dsk_init)
	.dwattr DW$49, DW_AT_high_pc(0x00)
	.dwattr DW$49, DW_AT_begin_file("c6713dskinit.c")
	.dwattr DW$49, DW_AT_begin_line(0x08)
	.dwattr DW$49, DW_AT_begin_column(0x06)
	.dwpsn	"c6713dskinit.c",9,1

	.dwfde DW$CIE
;----------------------------------------------------------------------
;   8 | void c6713_dsk_init()                           //dsp-peripheral initia
;     | lization                                                               
;----------------------------------------------------------------------

;******************************************************************************
;* FUNCTION NAME: _c6713_dsk_init                                             *
;*                                                                            *
;*   Regs Modified     : A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,B0,B1,B2,B3,B4,B5,B6,  *
;*                           B7,B8,B9,SP                                      *
;*   Regs Used         : A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,B0,B1,B2,B3,B4,B5,B6,  *
;*                           B7,B8,B9,SP                                      *
;*   Local Frame Size  : 0 Args + 0 Auto + 4 Save = 4 byte                    *
;******************************************************************************
_c6713_dsk_init:
;** --------------------------------------------------------------------------*
	.dwcfa	0x0e, 0
	.dwcfa	0x09, 126, 19
           STW     .D2T2   B3,*SP--(8)       ; |9| 
           NOP             2
	.dwcfa	0x0e, 8
	.dwcfa	0x80, 19, 0
	.dwpsn	"c6713dskinit.c",10,1
;----------------------------------------------------------------------
;  10 | DSK6713_init();                         //call BSL to init DSK-EMIF,PLL
;     | )                                                                      
;----------------------------------------------------------------------
           CALL    .S1     _DSK6713_init     ; |10| 
           MVKL    .S2     RL0,B3            ; |10| 
           MVKH    .S2     RL0,B3            ; |10| 
           NOP             3
RL0:       ; CALL OCCURS {_DSK6713_init}     ; |10| 
	.dwpsn	"c6713dskinit.c",12,1
;----------------------------------------------------------------------
;  12 | hAIC23_handle=DSK6713_AIC23_openCodec(0, &config);//handle(pointer) to
;     | codec                                                                  
;----------------------------------------------------------------------
           CALL    .S1     _DSK6713_AIC23_openCodec ; |12| 
           MVKL    .S1     _config,A3        ; |12| 
           MVKH    .S1     _config,A3        ; |12| 
           MVKL    .S2     RL1,B3            ; |12| 
           MV      .L2X    A3,B4             ; |12| 

           MVKH    .S2     RL1,B3            ; |12| 
||         ZERO    .L1     A4                ; |12| 

RL1:       ; CALL OCCURS {_DSK6713_AIC23_openCodec}  ; |12| 
           MVKL    .S1     _hAIC23_handle,A3 ; |12| 

           MV      .L2X    A4,B4             ; |12| 
||         MVKH    .S1     _hAIC23_handle,A3 ; |12| 

           STW     .D1T2   B4,*A3            ; |12| 
           NOP             2
	.dwpsn	"c6713dskinit.c",13,1
;----------------------------------------------------------------------
;  13 | DSK6713_AIC23_setFreq(hAIC23_handle, fs);  //set sample rate           
;----------------------------------------------------------------------
           MVKL    .S1     _hAIC23_handle,A3 ; |13| 

           MVKH    .S1     _hAIC23_handle,A3 ; |13| 
||         MVKL    .S2     _fs,B4            ; |13| 

           CALL    .S1     _DSK6713_AIC23_setFreq ; |13| 
||         MVKH    .S2     _fs,B4            ; |13| 

           LDW     .D1T1   *A3,A4            ; |13| 
||         LDW     .D2T2   *B4,B4            ; |13| 

           MVKL    .S2     RL2,B3            ; |13| 
           MVKH    .S2     RL2,B3            ; |13| 
           NOP             2
RL2:       ; CALL OCCURS {_DSK6713_AIC23_setFreq}  ; |13| 
	.dwpsn	"c6713dskinit.c",14,1
;----------------------------------------------------------------------
;  14 | DSK6713_AIC23_rset(hAIC23_handle, 0x0004, inputsource);  // choose mic
;     | or line in                                                             
;----------------------------------------------------------------------
           MVKL    .S1     _inputsource,A3   ; |14| 

           MVKL    .S2     _hAIC23_handle,B5 ; |14| 
||         MVKH    .S1     _inputsource,A3   ; |14| 

           CALL    .S1     _DSK6713_AIC23_rset ; |14| 
||         LDHU    .D1T1   *A3,A6            ; |14| 
||         MVKH    .S2     _hAIC23_handle,B5 ; |14| 

           LDW     .D2T1   *B5,A4            ; |14| 
           MVKL    .S2     RL3,B3            ; |14| 
           MVK     .S2     0x4,B4            ; |14| 
           MVKH    .S2     RL3,B3            ; |14| 
           NOP             1
RL3:       ; CALL OCCURS {_DSK6713_AIC23_rset}  ; |14| 
	.dwpsn	"c6713dskinit.c",15,1
;----------------------------------------------------------------------
;  15 | MCBSP_config(DSK6713_AIC23_DATAHANDLE,&AIC23CfgData);//interface 32 bit
;     | s toAIC23                                                              
;----------------------------------------------------------------------

           MVKL    .S2     _DSK6713_AIC23_codecdatahandle,B5 ; |15| 
||         MVKL    .S1     _MCBSP_config,A3  ; |15| 

           MVKH    .S2     _DSK6713_AIC23_codecdatahandle,B5 ; |15| 
||         MVKH    .S1     _MCBSP_config,A3  ; |15| 

           CALL    .S2X    A3                ; |15| 
           LDW     .D2T1   *B5,A4            ; |15| 
           MVKL    .S2     RL4,B3            ; |15| 
           MVKL    .S2     _AIC23CfgData,B4  ; |15| 
           MVKH    .S2     RL4,B3            ; |15| 
           MVKH    .S2     _AIC23CfgData,B4  ; |15| 
RL4:       ; CALL OCCURS {_MCBSP_config}     ; |15| 
	.dwpsn	"c6713dskinit.c",17,1
;----------------------------------------------------------------------
;  17 | MCBSP_start(DSK6713_AIC23_DATAHANDLE, MCBSP_XMIT_START | MCBSP_RCV_STAR
;     | T |                                                                    
;  18 | MCBSP_SRGR_START | MCBSP_SRGR_FRAMESYNC, 220);//start data channel agai
;     | n                                                                      
;----------------------------------------------------------------------
           MVKL    .S2     _MCBSP_start,B5   ; |17| 

           MVKH    .S2     _MCBSP_start,B5   ; |17| 
||         MVKL    .S1     _DSK6713_AIC23_codecdatahandle,A3 ; |17| 

           CALL    .S2     B5                ; |17| 
||         MVKH    .S1     _DSK6713_AIC23_codecdatahandle,A3 ; |17| 

           LDW     .D1T1   *A3,A4            ; |17| 
           MVKL    .S2     RL5,B3            ; |17| 
           MVK     .S2     0xf,B4            ; |17| 
           MVK     .S1     0xdc,A6           ; |17| 
           MVKH    .S2     RL5,B3            ; |17| 
RL5:       ; CALL OCCURS {_MCBSP_start}      ; |17| 
	.dwpsn	"c6713dskinit.c",19,1
           LDW     .D2T2   *++SP(8),B3       ; |19| 
           NOP             4
	.dwcfa	0xc0, 19
	.dwcfa	0x0e, 0
           RET     .S2     B3                ; |19| 
           NOP             5
           ; BRANCH OCCURS {B3}              ; |19| 
	.dwattr DW$49, DW_AT_end_file("c6713dskinit.c")
	.dwattr DW$49, DW_AT_end_line(0x13)
	.dwattr DW$49, DW_AT_end_column(0x01)
	.dwendentry
	.dwendtag DW$49

	.sect	".text"
	.global	_comm_poll

DW$50	.dwtag  DW_TAG_subprogram, DW_AT_name("comm_poll"), DW_AT_symbol_name("_comm_poll")
	.dwattr DW$50, DW_AT_low_pc(_comm_poll)
	.dwattr DW$50, DW_AT_high_pc(0x00)
	.dwattr DW$50, DW_AT_begin_file("c6713dskinit.c")
	.dwattr DW$50, DW_AT_begin_line(0x15)
	.dwattr DW$50, DW_AT_begin_column(0x06)
	.dwpsn	"c6713dskinit.c",22,1

	.dwfde DW$CIE
;----------------------------------------------------------------------
;  21 | void comm_poll()
;     |  //added for communication/init using polling                          
;----------------------------------------------------------------------

;******************************************************************************
;* FUNCTION NAME: _comm_poll                                                  *
;*                                                                            *
;*   Regs Modified     : A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,B0,B1,B2,B3,B4,B5,B6,  *
;*                           B7,B8,B9,SP                                      *
;*   Regs Used         : A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,B0,B1,B2,B3,B4,B5,B6,  *
;*                           B7,B8,B9,SP                                      *
;*   Local Frame Size  : 0 Args + 0 Auto + 4 Save = 4 byte                    *
;******************************************************************************
_comm_poll:
;** --------------------------------------------------------------------------*
	.dwcfa	0x0e, 0
	.dwcfa	0x09, 126, 19
           STW     .D2T2   B3,*SP--(8)       ; |22| 
           NOP             2
	.dwcfa	0x0e, 8
	.dwcfa	0x80, 19, 0
	.dwpsn	"c6713dskinit.c",23,2
;----------------------------------------------------------------------
;  23 | poll=1;                                         //1 if using polling   
;----------------------------------------------------------------------
           MVKL    .S1     _poll,A3          ; |23| 

           MVKH    .S1     _poll,A3          ; |23| 
||         MVK     .S2     1,B4              ; |23| 

           STW     .D1T2   B4,*A3            ; |23| 
           NOP             2
	.dwpsn	"c6713dskinit.c",24,4
;----------------------------------------------------------------------
;  24 | c6713_dsk_init();                                    //init DSP and cod
;     | ec                                                                     
;----------------------------------------------------------------------
           CALL    .S1     _c6713_dsk_init   ; |24| 
           MVKL    .S2     RL6,B3            ; |24| 
           MVKH    .S2     RL6,B3            ; |24| 
           NOP             3
RL6:       ; CALL OCCURS {_c6713_dsk_init}   ; |24| 
	.dwpsn	"c6713dskinit.c",25,1
           LDW     .D2T2   *++SP(8),B3       ; |25| 
           NOP             4
	.dwcfa	0xc0, 19
	.dwcfa	0x0e, 0
           RET     .S2     B3                ; |25| 
           NOP             5
           ; BRANCH OCCURS {B3}              ; |25| 
	.dwattr DW$50, DW_AT_end_file("c6713dskinit.c")
	.dwattr DW$50, DW_AT_end_line(0x19)
	.dwattr DW$50, DW_AT_end_column(0x01)
	.dwendentry
	.dwendtag DW$50

	.sect	".text"
	.global	_comm_intr

DW$51	.dwtag  DW_TAG_subprogram, DW_AT_name("comm_intr"), DW_AT_symbol_name("_comm_intr")
	.dwattr DW$51, DW_AT_low_pc(_comm_intr)
	.dwattr DW$51, DW_AT_high_pc(0x00)
	.dwattr DW$51, DW_AT_begin_file("c6713dskinit.c")
	.dwattr DW$51, DW_AT_begin_line(0x1b)
	.dwattr DW$51, DW_AT_begin_column(0x06)
	.dwpsn	"c6713dskinit.c",28,1

	.dwfde DW$CIE
;----------------------------------------------------------------------
;  27 | void comm_intr()
;     |  //for communication/init using interrupt                              
;----------------------------------------------------------------------

;******************************************************************************
;* FUNCTION NAME: _comm_intr                                                  *
;*                                                                            *
;*   Regs Modified     : A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,B0,B1,B2,B3,B4,B5,B6,  *
;*                           B7,B8,B9,SP                                      *
;*   Regs Used         : A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,B0,B1,B2,B3,B4,B5,B6,  *
;*                           B7,B8,B9,SP                                      *
;*   Local Frame Size  : 0 Args + 0 Auto + 4 Save = 4 byte                    *
;******************************************************************************
_comm_intr:
;** --------------------------------------------------------------------------*
	.dwcfa	0x0e, 0
	.dwcfa	0x09, 126, 19
           STW     .D2T2   B3,*SP--(8)       ; |28| 
           NOP             2
	.dwcfa	0x0e, 8
	.dwcfa	0x80, 19, 0
	.dwpsn	"c6713dskinit.c",29,2
;----------------------------------------------------------------------
;  29 | poll=0;                         //0 since not polling                  
;----------------------------------------------------------------------
           MVKL    .S2     _poll,B4          ; |29| 

           MVKH    .S2     _poll,B4          ; |29| 
||         ZERO    .L2     B5                ; |29| 

           STW     .D2T2   B5,*B4            ; |29| 
           NOP             2
	.dwpsn	"c6713dskinit.c",30,4
;----------------------------------------------------------------------
;  30 | IRQ_globalDisable();                 //disable interrupts              
;----------------------------------------------------------------------
           MVKL    .S1     _IRQ_globalDisable,A3 ; |30| 
           MVKH    .S1     _IRQ_globalDisable,A3 ; |30| 
           CALL    .S2X    A3                ; |30| 
           MVKL    .S2     RL7,B3            ; |30| 
           MVKH    .S2     RL7,B3            ; |30| 
           NOP             3
RL7:       ; CALL OCCURS {_IRQ_globalDisable}  ; |30| 
	.dwpsn	"c6713dskinit.c",31,2
;----------------------------------------------------------------------
;  31 | c6713_dsk_init();                                       //init DSP and
;     | codec                                                                  
;----------------------------------------------------------------------
           CALL    .S1     _c6713_dsk_init   ; |31| 
           MVKL    .S2     RL8,B3            ; |31| 
           MVKH    .S2     RL8,B3            ; |31| 
           NOP             3
RL8:       ; CALL OCCURS {_c6713_dsk_init}   ; |31| 
	.dwpsn	"c6713dskinit.c",32,2
;----------------------------------------------------------------------
;  32 | CODECEventId=MCBSP_getXmtEventId(DSK6713_AIC23_codecdatahandle);//McBSP
;     | 1 Xmit                                                                 
;  34 | #ifndef using_bios                                              //do no
;     | t need to point to vector table                                        
;  35 | IRQ_setVecs(vectors);                           //point to the IRQ vect
;     | or table                                                               
;  36 | #endif
;     |          //since interrupt vector handles this                         
;----------------------------------------------------------------------
           MVKL    .S1     _MCBSP_getXmtEventId,A3 ; |32| 
           MVKL    .S1     _DSK6713_AIC23_codecdatahandle,A4 ; |32| 
           MVKH    .S1     _MCBSP_getXmtEventId,A3 ; |32| 

           CALL    .S2X    A3                ; |32| 
||         MVKH    .S1     _DSK6713_AIC23_codecdatahandle,A4 ; |32| 

           LDW     .D1T1   *A4,A4            ; |32| 
           MVKL    .S2     RL9,B3            ; |32| 
           MVKH    .S2     RL9,B3            ; |32| 
           NOP             2
RL9:       ; CALL OCCURS {_MCBSP_getXmtEventId}  ; |32| 
           MVKL    .S2     _CODECEventId,B4  ; |32| 
           MVKH    .S2     _CODECEventId,B4  ; |32| 
           STW     .D2T1   A4,*B4            ; |32| 
           NOP             2
	.dwpsn	"c6713dskinit.c",38,4
;----------------------------------------------------------------------
;  38 | IRQ_map(CODECEventId, 11);                      //map McBSP1 Xmit to IN
;     | T11                                                                    
;----------------------------------------------------------------------

           MVKL    .S2     _CODECEventId,B4  ; |38| 
||         MVKL    .S1     _IRQ_map,A3       ; |38| 

           MVKH    .S2     _CODECEventId,B4  ; |38| 
||         MVKH    .S1     _IRQ_map,A3       ; |38| 

           CALL    .S2X    A3                ; |38| 
           LDW     .D2T1   *B4,A4            ; |38| 
           MVKL    .S2     RL10,B3           ; |38| 
           MVKH    .S2     RL10,B3           ; |38| 
           MVK     .S2     0xb,B4            ; |38| 
           NOP             1
RL10:      ; CALL OCCURS {_IRQ_map}          ; |38| 
	.dwpsn	"c6713dskinit.c",39,4
;----------------------------------------------------------------------
;  39 | IRQ_reset(CODECEventId);                //reset codec INT 11           
;----------------------------------------------------------------------
           MVKL    .S2     _IRQ_reset,B4     ; |39| 

           MVKH    .S2     _IRQ_reset,B4     ; |39| 
||         MVKL    .S1     _CODECEventId,A3  ; |39| 

           CALL    .S2     B4                ; |39| 
||         MVKH    .S1     _CODECEventId,A3  ; |39| 

           LDW     .D1T1   *A3,A4            ; |39| 
           MVKL    .S2     RL11,B3           ; |39| 
           MVKH    .S2     RL11,B3           ; |39| 
           NOP             2
RL11:      ; CALL OCCURS {_IRQ_reset}        ; |39| 
	.dwpsn	"c6713dskinit.c",40,4
;----------------------------------------------------------------------
;  40 | IRQ_globalEnable();                          //globally enable interrup
;     | ts                                                                     
;----------------------------------------------------------------------
           MVKL    .S1     _IRQ_globalEnable,A3 ; |40| 
           MVKH    .S1     _IRQ_globalEnable,A3 ; |40| 
           CALL    .S2X    A3                ; |40| 
           MVKL    .S2     RL12,B3           ; |40| 
           MVKH    .S2     RL12,B3           ; |40| 
           NOP             3
RL12:      ; CALL OCCURS {_IRQ_globalEnable}  ; |40| 
	.dwpsn	"c6713dskinit.c",41,4
;----------------------------------------------------------------------
;  41 | IRQ_nmiEnable();                                //enable NMI interrupt 
;----------------------------------------------------------------------
           MVKL    .S1     _IRQ_nmiEnable,A3 ; |41| 
           MVKH    .S1     _IRQ_nmiEnable,A3 ; |41| 
           CALL    .S2X    A3                ; |41| 
           MVKL    .S2     RL13,B3           ; |41| 
           MVKH    .S2     RL13,B3           ; |41| 
           NOP             3
RL13:      ; CALL OCCURS {_IRQ_nmiEnable}    ; |41| 
	.dwpsn	"c6713dskinit.c",42,4
;----------------------------------------------------------------------
;  42 | IRQ_enable(CODECEventId);                    //enable CODEC eventXmit I
;     | NT11                                                                   
;----------------------------------------------------------------------

           MVKL    .S2     _CODECEventId,B4  ; |42| 
||         MVKL    .S1     _IRQ_enable,A3    ; |42| 

           MVKH    .S2     _CODECEventId,B4  ; |42| 
||         MVKH    .S1     _IRQ_enable,A3    ; |42| 

           CALL    .S2X    A3                ; |42| 
           LDW     .D2T1   *B4,A4            ; |42| 
           MVKL    .S2     RL14,B3           ; |42| 
           MVKH    .S2     RL14,B3           ; |42| 
           NOP             2
RL14:      ; CALL OCCURS {_IRQ_enable}       ; |42| 
	.dwpsn	"c6713dskinit.c",44,2
;----------------------------------------------------------------------
;  44 | output_sample(0);                               //start McBSP interrupt
;     |  outputting a sample                                                   
;----------------------------------------------------------------------
           CALL    .S1     _output_sample    ; |44| 
           MVKL    .S2     RL15,B3           ; |44| 
           MVKH    .S2     RL15,B3           ; |44| 
           ZERO    .L1     A4                ; |44| 
           NOP             2
RL15:      ; CALL OCCURS {_output_sample}    ; |44| 
	.dwpsn	"c6713dskinit.c",45,1
           LDW     .D2T2   *++SP(8),B3       ; |45| 
           NOP             4
	.dwcfa	0xc0, 19
	.dwcfa	0x0e, 0
           RET     .S2     B3                ; |45| 
           NOP             5
           ; BRANCH OCCURS {B3}              ; |45| 
	.dwattr DW$51, DW_AT_end_file("c6713dskinit.c")
	.dwattr DW$51, DW_AT_end_line(0x2d)
	.dwattr DW$51, DW_AT_end_column(0x01)
	.dwendentry
	.dwendtag DW$51

	.sect	".text"
	.global	_output_sample

DW$52	.dwtag  DW_TAG_subprogram, DW_AT_name("output_sample"), DW_AT_symbol_name("_output_sample")
	.dwattr DW$52, DW_AT_low_pc(_output_sample)
	.dwattr DW$52, DW_AT_high_pc(0x00)
	.dwattr DW$52, DW_AT_begin_file("c6713dskinit.c")
	.dwattr DW$52, DW_AT_begin_line(0x2f)
	.dwattr DW$52, DW_AT_begin_column(0x06)
	.dwpsn	"c6713dskinit.c",48,1

	.dwfde DW$CIE
;----------------------------------------------------------------------
;  47 | void output_sample(int out_data)    //for out to Left and Right channel
;     | s                                                                      
;----------------------------------------------------------------------

;******************************************************************************
;* FUNCTION NAME: _output_sample                                              *
;*                                                                            *
;*   Regs Modified     : A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,B0,B1,B2,B3,B4,B5,B6,  *
;*                           B7,B8,B9,SP                                      *
;*   Regs Used         : A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,B0,B1,B2,B3,B4,B5,B6,  *
;*                           B7,B8,B9,SP                                      *
;*   Local Frame Size  : 0 Args + 8 Auto + 4 Save = 12 byte                   *
;******************************************************************************
_output_sample:
;** --------------------------------------------------------------------------*
	.dwcfa	0x0e, 0
	.dwcfa	0x09, 126, 19
           STW     .D2T2   B3,*SP--(16)      ; |48| 
           NOP             2
	.dwcfa	0x0e, 16
	.dwcfa	0x80, 19, 0
DW$53	.dwtag  DW_TAG_formal_parameter, DW_AT_name("out_data"), DW_AT_symbol_name("_out_data")
	.dwattr DW$53, DW_AT_type(*DW$T$10)
	.dwattr DW$53, DW_AT_location[DW_OP_reg4]
DW$54	.dwtag  DW_TAG_variable, DW_AT_name("out_data"), DW_AT_symbol_name("_out_data")
	.dwattr DW$54, DW_AT_type(*DW$T$10)
	.dwattr DW$54, DW_AT_location[DW_OP_breg31 4]
DW$55	.dwtag  DW_TAG_variable, DW_AT_name("CHANNEL_data"), DW_AT_symbol_name("_CHANNEL_data")
	.dwattr DW$55, DW_AT_type(*DW$T$8)
	.dwattr DW$55, DW_AT_location[DW_OP_breg31 8]
;----------------------------------------------------------------------
;  49 | short CHANNEL_data;                                                    
;----------------------------------------------------------------------
           STW     .D2T1   A4,*+SP(4)        ; |48| 
           NOP             2
	.dwpsn	"c6713dskinit.c",51,2
;----------------------------------------------------------------------
;  51 | AIC_data.uint=0;                 //clear data structure                
;----------------------------------------------------------------------
           MVKL    .S2     _AIC_data,B4      ; |51| 

           MVKH    .S2     _AIC_data,B4      ; |51| 
||         ZERO    .L2     B5                ; |51| 

           STW     .D2T2   B5,*B4            ; |51| 
           NOP             2
	.dwpsn	"c6713dskinit.c",52,2
;----------------------------------------------------------------------
;  52 | AIC_data.uint=out_data;          //32-bit data -->data structure       
;  54 | //The existing interface defaults to right channel. To default instead
;     | to the                                                                 
;  55 | //left channel and use output_sample(short), left and right channels ar
;     | e swapped                                                              
;  56 | //In main source program use LEFT 0 and RIGHT 1 (opposite of what is us
;     | ed here)                                                               
;----------------------------------------------------------------------
           LDW     .D2T1   *+SP(4),A4        ; |52| 
           MVKL    .S1     _AIC_data,A3      ; |52| 
           MVKH    .S1     _AIC_data,A3      ; |52| 
           NOP             2
           STW     .D1T1   A4,*A3            ; |52| 
           NOP             2
	.dwpsn	"c6713dskinit.c",57,2
;----------------------------------------------------------------------
;  57 | CHANNEL_data=AIC_data.channel[RIGHT];                   //swap left and
;     |  right channels                                                        
;----------------------------------------------------------------------
           MVKL    .S2     _AIC_data,B4      ; |57| 
           MVKH    .S2     _AIC_data,B4      ; |57| 
           LDH     .D2T2   *B4,B4            ; |57| 
           NOP             4
           STH     .D2T2   B4,*+SP(8)        ; |57| 
           NOP             2
	.dwpsn	"c6713dskinit.c",58,2
;----------------------------------------------------------------------
;  58 | AIC_data.channel[RIGHT]=AIC_data.channel[LEFT];                        
;----------------------------------------------------------------------
           MVKL    .S1     _AIC_data+2,A3    ; |58| 
           MVKH    .S1     _AIC_data+2,A3    ; |58| 
           LDH     .D1T1   *A3,A3            ; |58| 
           MVKL    .S2     _AIC_data,B4      ; |58| 
           MVKH    .S2     _AIC_data,B4      ; |58| 
           NOP             2
           STH     .D2T1   A3,*B4            ; |58| 
           NOP             2
	.dwpsn	"c6713dskinit.c",59,2
;----------------------------------------------------------------------
;  59 | AIC_data.channel[LEFT]=CHANNEL_data;                                   
;----------------------------------------------------------------------
           LDH     .D2T2   *+SP(8),B4        ; |59| 
           MVKL    .S1     _AIC_data+2,A3    ; |59| 
           MVKH    .S1     _AIC_data+2,A3    ; |59| 
           NOP             2
           STH     .D1T2   B4,*A3            ; |59| 
           NOP             2
	.dwpsn	"c6713dskinit.c",60,4
;----------------------------------------------------------------------
;  60 | if (poll) while(!MCBSP_xrdy(DSK6713_AIC23_DATAHANDLE));//if ready to tr
;     | ansmit                                                                 
;----------------------------------------------------------------------
           MVKL    .S2     _poll,B4          ; |60| 
           MVKH    .S2     _poll,B4          ; |60| 
           LDW     .D2T2   *B4,B0            ; |60| 
           NOP             4
   [!B0]   B       .S1     L2                ; |60| 
           NOP             5
           ; BRANCHCC OCCURS {L2}            ; |60| 
;** --------------------------------------------------------------------------*
	.dwpsn	"c6713dskinit.c",60,20
           MVKL    .S2     _MCBSP_xrdy,B4    ; |60| 

           MVKH    .S2     _MCBSP_xrdy,B4    ; |60| 
||         MVKL    .S1     _DSK6713_AIC23_codecdatahandle,A3 ; |60| 

           CALL    .S2     B4                ; |60| 
||         MVKH    .S1     _DSK6713_AIC23_codecdatahandle,A3 ; |60| 

           LDW     .D1T1   *A3,A4            ; |60| 
           MVKL    .S2     RL16,B3           ; |60| 
           MVKH    .S2     RL16,B3           ; |60| 
           NOP             2
RL16:      ; CALL OCCURS {_MCBSP_xrdy}       ; |60| 
           MV      .L1     A4,A1             ; |60| 
   [ A1]   B       .S1     L2                ; |60| 
           NOP             5
           ; BRANCHCC OCCURS {L2}            ; |60| 
;*----------------------------------------------------------------------------*
;*   SOFTWARE PIPELINE INFORMATION
;*      Disqualified loop: Software pipelining disabled
;*----------------------------------------------------------------------------*
L1:    
DW$L$_output_sample$3$B:
           MVKL    .S2     _MCBSP_xrdy,B4    ; |60| 

           MVKH    .S2     _MCBSP_xrdy,B4    ; |60| 
||         MVKL    .S1     _DSK6713_AIC23_codecdatahandle,A3 ; |60| 

           CALL    .S2     B4                ; |60| 
||         MVKH    .S1     _DSK6713_AIC23_codecdatahandle,A3 ; |60| 

           LDW     .D1T1   *A3,A4            ; |60| 
           MVKL    .S2     RL17,B3           ; |60| 
           MVKH    .S2     RL17,B3           ; |60| 
           NOP             2
RL17:      ; CALL OCCURS {_MCBSP_xrdy}       ; |60| 
           MV      .L1     A4,A1             ; |60| 
   [!A1]   B       .S1     L1                ; |60| 
           NOP             5
           ; BRANCHCC OCCURS {L1}            ; |60| 
DW$L$_output_sample$3$E:
;** --------------------------------------------------------------------------*
L2:    
	.dwpsn	"c6713dskinit.c",61,3
;----------------------------------------------------------------------
;  61 | MCBSP_write(DSK6713_AIC23_DATAHANDLE,AIC_data.uint);//write/output data
;----------------------------------------------------------------------
           MVKL    .S1     _MCBSP_write,A3   ; |61| 

           MVKL    .S1     _AIC_data,A4      ; |61| 
||         MVKL    .S2     _DSK6713_AIC23_codecdatahandle,B4 ; |61| 

           MVKH    .S2     _DSK6713_AIC23_codecdatahandle,B4 ; |61| 
||         MVKH    .S1     _MCBSP_write,A3   ; |61| 

           CALL    .S2X    A3                ; |61| 
||         MVKH    .S1     _AIC_data,A4      ; |61| 

           LDW     .D2T1   *B4,A4            ; |61| 
||         LDW     .D1T2   *A4,B4            ; |61| 

           MVKL    .S2     RL18,B3           ; |61| 
           MVKH    .S2     RL18,B3           ; |61| 
           NOP             2
RL18:      ; CALL OCCURS {_MCBSP_write}      ; |61| 
	.dwpsn	"c6713dskinit.c",62,1
           LDW     .D2T2   *++SP(16),B3      ; |62| 
           NOP             4
	.dwcfa	0xc0, 19
	.dwcfa	0x0e, 0
           RET     .S2     B3                ; |62| 
           NOP             5
           ; BRANCH OCCURS {B3}              ; |62| 

DW$56	.dwtag  DW_TAG_loop
	.dwattr DW$56, DW_AT_name("C:\CCStudio_v3.1\finalmyprojects\Support\c6713dskinit.asm:L1:1:1181040732")
	.dwattr DW$56, DW_AT_begin_file("c6713dskinit.c")
	.dwattr DW$56, DW_AT_begin_line(0x3c)
	.dwattr DW$56, DW_AT_end_line(0x3c)
DW$57	.dwtag  DW_TAG_loop_range
	.dwattr DW$57, DW_AT_low_pc(DW$L$_output_sample$3$B)
	.dwattr DW$57, DW_AT_high_pc(DW$L$_output_sample$3$E)
	.dwendtag DW$56

	.dwattr DW$52, DW_AT_end_file("c6713dskinit.c")
	.dwattr DW$52, DW_AT_end_line(0x3e)
	.dwattr DW$52, DW_AT_end_column(0x01)
	.dwendentry
	.dwendtag DW$52

	.sect	".text"
	.global	_output_left_sample

DW$58	.dwtag  DW_TAG_subprogram, DW_AT_name("output_left_sample"), DW_AT_symbol_name("_output_left_sample")
	.dwattr DW$58, DW_AT_low_pc(_output_left_sample)
	.dwattr DW$58, DW_AT_high_pc(0x00)
	.dwattr DW$58, DW_AT_begin_file("c6713dskinit.c")
	.dwattr DW$58, DW_AT_begin_line(0x40)
	.dwattr DW$58, DW_AT_begin_column(0x06)
	.dwpsn	"c6713dskinit.c",65,1

	.dwfde DW$CIE
;----------------------------------------------------------------------
;  64 | void output_left_sample(short out_data)                  //for output f
;     | rom left channel                                                       
;----------------------------------------------------------------------

;******************************************************************************
;* FUNCTION NAME: _output_left_sample                                         *
;*                                                                            *
;*   Regs Modified     : A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,B0,B1,B2,B3,B4,B5,B6,  *
;*                           B7,B8,B9,SP                                      *
;*   Regs Used         : A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,B0,B1,B2,B3,B4,B5,B6,  *
;*                           B7,B8,B9,SP                                      *
;*   Local Frame Size  : 0 Args + 4 Auto + 4 Save = 8 byte                    *
;******************************************************************************
_output_left_sample:
;** --------------------------------------------------------------------------*
	.dwcfa	0x0e, 0
	.dwcfa	0x09, 126, 19
           STW     .D2T2   B3,*SP--(8)       ; |65| 
           NOP             2
	.dwcfa	0x0e, 8
	.dwcfa	0x80, 19, 0
DW$59	.dwtag  DW_TAG_formal_parameter, DW_AT_name("out_data"), DW_AT_symbol_name("_out_data")
	.dwattr DW$59, DW_AT_type(*DW$T$8)
	.dwattr DW$59, DW_AT_location[DW_OP_reg4]
DW$60	.dwtag  DW_TAG_variable, DW_AT_name("out_data"), DW_AT_symbol_name("_out_data")
	.dwattr DW$60, DW_AT_type(*DW$T$8)
	.dwattr DW$60, DW_AT_location[DW_OP_breg31 4]
           STH     .D2T1   A4,*+SP(4)        ; |65| 
           NOP             2
	.dwpsn	"c6713dskinit.c",66,2
;----------------------------------------------------------------------
;  66 | AIC_data.uint=0;                              //clear data structure   
;----------------------------------------------------------------------
           MVKL    .S1     _AIC_data,A3      ; |66| 

           MVKH    .S1     _AIC_data,A3      ; |66| 
||         ZERO    .L1     A4                ; |66| 

           STW     .D1T1   A4,*A3            ; |66| 
           NOP             2
	.dwpsn	"c6713dskinit.c",67,2
;----------------------------------------------------------------------
;  67 | AIC_data.channel[LEFT]=out_data;   //data from Left channel -->data str
;     | ucture                                                                 
;----------------------------------------------------------------------
           LDH     .D2T2   *+SP(4),B4        ; |67| 
           MVKL    .S1     _AIC_data+2,A3    ; |67| 
           MVKH    .S1     _AIC_data+2,A3    ; |67| 
           NOP             2
           STH     .D1T2   B4,*A3            ; |67| 
           NOP             2
	.dwpsn	"c6713dskinit.c",69,2
;----------------------------------------------------------------------
;  69 | if (poll) while(!MCBSP_xrdy(DSK6713_AIC23_DATAHANDLE));//if ready to tr
;     | ansmit                                                                 
;----------------------------------------------------------------------
           MVKL    .S2     _poll,B4          ; |69| 
           MVKH    .S2     _poll,B4          ; |69| 
           LDW     .D2T2   *B4,B0            ; |69| 
           NOP             4
   [!B0]   B       .S1     L4                ; |69| 
           NOP             5
           ; BRANCHCC OCCURS {L4}            ; |69| 
;** --------------------------------------------------------------------------*
	.dwpsn	"c6713dskinit.c",69,18
           MVKL    .S2     _MCBSP_xrdy,B4    ; |69| 

           MVKH    .S2     _MCBSP_xrdy,B4    ; |69| 
||         MVKL    .S1     _DSK6713_AIC23_codecdatahandle,A3 ; |69| 

           CALL    .S2     B4                ; |69| 
||         MVKH    .S1     _DSK6713_AIC23_codecdatahandle,A3 ; |69| 

           LDW     .D1T1   *A3,A4            ; |69| 
           MVKL    .S2     RL19,B3           ; |69| 
           MVKH    .S2     RL19,B3           ; |69| 
           NOP             2
RL19:      ; CALL OCCURS {_MCBSP_xrdy}       ; |69| 
           MV      .L1     A4,A1             ; |69| 
   [ A1]   B       .S1     L4                ; |69| 
           NOP             5
           ; BRANCHCC OCCURS {L4}            ; |69| 
;*----------------------------------------------------------------------------*
;*   SOFTWARE PIPELINE INFORMATION
;*      Disqualified loop: Software pipelining disabled
;*----------------------------------------------------------------------------*
L3:    
DW$L$_output_left_sample$3$B:
           MVKL    .S2     _MCBSP_xrdy,B4    ; |69| 

           MVKH    .S2     _MCBSP_xrdy,B4    ; |69| 
||         MVKL    .S1     _DSK6713_AIC23_codecdatahandle,A3 ; |69| 

           CALL    .S2     B4                ; |69| 
||         MVKH    .S1     _DSK6713_AIC23_codecdatahandle,A3 ; |69| 

           LDW     .D1T1   *A3,A4            ; |69| 
           MVKL    .S2     RL20,B3           ; |69| 
           MVKH    .S2     RL20,B3           ; |69| 
           NOP             2
RL20:      ; CALL OCCURS {_MCBSP_xrdy}       ; |69| 
           MV      .L1     A4,A1             ; |69| 
   [!A1]   B       .S1     L3                ; |69| 
           NOP             5
           ; BRANCHCC OCCURS {L3}            ; |69| 
DW$L$_output_left_sample$3$E:
;** --------------------------------------------------------------------------*
L4:    
	.dwpsn	"c6713dskinit.c",70,3
;----------------------------------------------------------------------
;  70 | MCBSP_write(DSK6713_AIC23_DATAHANDLE,AIC_data.uint);//output left chann
;     | el                                                                     
;----------------------------------------------------------------------
           MVKL    .S1     _MCBSP_write,A3   ; |70| 

           MVKL    .S1     _AIC_data,A4      ; |70| 
||         MVKL    .S2     _DSK6713_AIC23_codecdatahandle,B4 ; |70| 

           MVKH    .S2     _DSK6713_AIC23_codecdatahandle,B4 ; |70| 
||         MVKH    .S1     _MCBSP_write,A3   ; |70| 

           CALL    .S2X    A3                ; |70| 
||         MVKH    .S1     _AIC_data,A4      ; |70| 

           LDW     .D2T1   *B4,A4            ; |70| 
||         LDW     .D1T2   *A4,B4            ; |70| 

           MVKL    .S2     RL21,B3           ; |70| 
           MVKH    .S2     RL21,B3           ; |70| 
           NOP             2
RL21:      ; CALL OCCURS {_MCBSP_write}      ; |70| 
	.dwpsn	"c6713dskinit.c",71,1
           LDW     .D2T2   *++SP(8),B3       ; |71| 
           NOP             4
	.dwcfa	0xc0, 19
	.dwcfa	0x0e, 0
           RET     .S2     B3                ; |71| 
           NOP             5
           ; BRANCH OCCURS {B3}              ; |71| 

DW$61	.dwtag  DW_TAG_loop
	.dwattr DW$61, DW_AT_name("C:\CCStudio_v3.1\finalmyprojects\Support\c6713dskinit.asm:L3:1:1181040732")
	.dwattr DW$61, DW_AT_begin_file("c6713dskinit.c")
	.dwattr DW$61, DW_AT_begin_line(0x45)
	.dwattr DW$61, DW_AT_end_line(0x45)
DW$62	.dwtag  DW_TAG_loop_range
	.dwattr DW$62, DW_AT_low_pc(DW$L$_output_left_sample$3$B)
	.dwattr DW$62, DW_AT_high_pc(DW$L$_output_left_sample$3$E)
	.dwendtag DW$61

	.dwattr DW$58, DW_AT_end_file("c6713dskinit.c")
	.dwattr DW$58, DW_AT_end_line(0x47)
	.dwattr DW$58, DW_AT_end_column(0x01)
	.dwendentry
	.dwendtag DW$58

	.sect	".text"
	.global	_output_right_sample

DW$63	.dwtag  DW_TAG_subprogram, DW_AT_name("output_right_sample"), DW_AT_symbol_name("_output_right_sample")
	.dwattr DW$63, DW_AT_low_pc(_output_right_sample)
	.dwattr DW$63, DW_AT_high_pc(0x00)
	.dwattr DW$63, DW_AT_begin_file("c6713dskinit.c")
	.dwattr DW$63, DW_AT_begin_line(0x49)
	.dwattr DW$63, DW_AT_begin_column(0x06)
	.dwpsn	"c6713dskinit.c",74,1

	.dwfde DW$CIE
;----------------------------------------------------------------------
;  73 | void output_right_sample(short out_data)                //for output fr
;     | om right channel                                                       
;----------------------------------------------------------------------

;******************************************************************************
;* FUNCTION NAME: _output_right_sample                                        *
;*                                                                            *
;*   Regs Modified     : A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,B0,B1,B2,B3,B4,B5,B6,  *
;*                           B7,B8,B9,SP                                      *
;*   Regs Used         : A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,B0,B1,B2,B3,B4,B5,B6,  *
;*                           B7,B8,B9,SP                                      *
;*   Local Frame Size  : 0 Args + 4 Auto + 4 Save = 8 byte                    *
;******************************************************************************
_output_right_sample:
;** --------------------------------------------------------------------------*
	.dwcfa	0x0e, 0
	.dwcfa	0x09, 126, 19
           STW     .D2T2   B3,*SP--(8)       ; |74| 
           NOP             2
	.dwcfa	0x0e, 8
	.dwcfa	0x80, 19, 0
DW$64	.dwtag  DW_TAG_formal_parameter, DW_AT_name("out_data"), DW_AT_symbol_name("_out_data")
	.dwattr DW$64, DW_AT_type(*DW$T$8)
	.dwattr DW$64, DW_AT_location[DW_OP_reg4]
DW$65	.dwtag  DW_TAG_variable, DW_AT_name("out_data"), DW_AT_symbol_name("_out_data")
	.dwattr DW$65, DW_AT_type(*DW$T$8)
	.dwattr DW$65, DW_AT_location[DW_OP_breg31 4]
           STH     .D2T1   A4,*+SP(4)        ; |74| 
           NOP             2
	.dwpsn	"c6713dskinit.c",75,2
;----------------------------------------------------------------------
;  75 | AIC_data.uint=0;                             //clear data structure    
;----------------------------------------------------------------------
           MVKL    .S1     _AIC_data,A3      ; |75| 

           MVKH    .S1     _AIC_data,A3      ; |75| 
||         ZERO    .L1     A4                ; |75| 

           STW     .D1T1   A4,*A3            ; |75| 
           NOP             2
	.dwpsn	"c6713dskinit.c",76,2
;----------------------------------------------------------------------
;  76 | AIC_data.channel[RIGHT]=out_data; //data from Right channel -->data str
;     | ucture                                                                 
;----------------------------------------------------------------------
           LDH     .D2T2   *+SP(4),B4        ; |76| 
           MVKL    .S1     _AIC_data,A3      ; |76| 
           MVKH    .S1     _AIC_data,A3      ; |76| 
           NOP             2
           STH     .D1T2   B4,*A3            ; |76| 
           NOP             2
	.dwpsn	"c6713dskinit.c",78,2
;----------------------------------------------------------------------
;  78 | if (poll) while(!MCBSP_xrdy(DSK6713_AIC23_DATAHANDLE));//if ready to tr
;     | ansmit                                                                 
;----------------------------------------------------------------------
           MVKL    .S2     _poll,B4          ; |78| 
           MVKH    .S2     _poll,B4          ; |78| 
           LDW     .D2T2   *B4,B0            ; |78| 
           NOP             4
   [!B0]   B       .S1     L6                ; |78| 
           NOP             5
           ; BRANCHCC OCCURS {L6}            ; |78| 
;** --------------------------------------------------------------------------*
	.dwpsn	"c6713dskinit.c",78,18
           MVKL    .S2     _MCBSP_xrdy,B4    ; |78| 

           MVKH    .S2     _MCBSP_xrdy,B4    ; |78| 
||         MVKL    .S1     _DSK6713_AIC23_codecdatahandle,A3 ; |78| 

           CALL    .S2     B4                ; |78| 
||         MVKH    .S1     _DSK6713_AIC23_codecdatahandle,A3 ; |78| 

           LDW     .D1T1   *A3,A4            ; |78| 
           MVKL    .S2     RL22,B3           ; |78| 
           MVKH    .S2     RL22,B3           ; |78| 
           NOP             2
RL22:      ; CALL OCCURS {_MCBSP_xrdy}       ; |78| 
           MV      .L1     A4,A1             ; |78| 
   [ A1]   B       .S1     L6                ; |78| 
           NOP             5
           ; BRANCHCC OCCURS {L6}            ; |78| 
;*----------------------------------------------------------------------------*
;*   SOFTWARE PIPELINE INFORMATION
;*      Disqualified loop: Software pipelining disabled
;*----------------------------------------------------------------------------*
L5:    
DW$L$_output_right_sample$3$B:
           MVKL    .S2     _MCBSP_xrdy,B4    ; |78| 

           MVKH    .S2     _MCBSP_xrdy,B4    ; |78| 
||         MVKL    .S1     _DSK6713_AIC23_codecdatahandle,A3 ; |78| 

           CALL    .S2     B4                ; |78| 
||         MVKH    .S1     _DSK6713_AIC23_codecdatahandle,A3 ; |78| 

           LDW     .D1T1   *A3,A4            ; |78| 
           MVKL    .S2     RL23,B3           ; |78| 
           MVKH    .S2     RL23,B3           ; |78| 
           NOP             2
RL23:      ; CALL OCCURS {_MCBSP_xrdy}       ; |78| 
           MV      .L1     A4,A1             ; |78| 
   [!A1]   B       .S1     L5                ; |78| 
           NOP             5
           ; BRANCHCC OCCURS {L5}            ; |78| 
DW$L$_output_right_sample$3$E:
;** --------------------------------------------------------------------------*
L6:    
	.dwpsn	"c6713dskinit.c",79,3
;----------------------------------------------------------------------
;  79 | MCBSP_write(DSK6713_AIC23_DATAHANDLE,AIC_data.uint);//output right chan
;     | nel                                                                    
;----------------------------------------------------------------------
           MVKL    .S1     _MCBSP_write,A3   ; |79| 

           MVKL    .S1     _AIC_data,A4      ; |79| 
||         MVKL    .S2     _DSK6713_AIC23_codecdatahandle,B4 ; |79| 

           MVKH    .S2     _DSK6713_AIC23_codecdatahandle,B4 ; |79| 
||         MVKH    .S1     _MCBSP_write,A3   ; |79| 

           CALL    .S2X    A3                ; |79| 
||         MVKH    .S1     _AIC_data,A4      ; |79| 

           LDW     .D2T1   *B4,A4            ; |79| 
||         LDW     .D1T2   *A4,B4            ; |79| 

           MVKL    .S2     RL24,B3           ; |79| 
           MVKH    .S2     RL24,B3           ; |79| 
           NOP             2
RL24:      ; CALL OCCURS {_MCBSP_write}      ; |79| 
	.dwpsn	"c6713dskinit.c",80,1
           LDW     .D2T2   *++SP(8),B3       ; |80| 
           NOP             4
	.dwcfa	0xc0, 19
	.dwcfa	0x0e, 0
           RET     .S2     B3                ; |80| 
           NOP             5
           ; BRANCH OCCURS {B3}              ; |80| 

DW$66	.dwtag  DW_TAG_loop
	.dwattr DW$66, DW_AT_name("C:\CCStudio_v3.1\finalmyprojects\Support\c6713dskinit.asm:L5:1:1181040732")
	.dwattr DW$66, DW_AT_begin_file("c6713dskinit.c")
	.dwattr DW$66, DW_AT_begin_line(0x4e)
	.dwattr DW$66, DW_AT_end_line(0x4e)
DW$67	.dwtag  DW_TAG_loop_range
	.dwattr DW$67, DW_AT_low_pc(DW$L$_output_right_sample$3$B)
	.dwattr DW$67, DW_AT_high_pc(DW$L$_output_right_sample$3$E)
	.dwendtag DW$66

	.dwattr DW$63, DW_AT_end_file("c6713dskinit.c")
	.dwattr DW$63, DW_AT_end_line(0x50)
	.dwattr DW$63, DW_AT_end_column(0x01)
	.dwendentry
	.dwendtag DW$63

	.sect	".text"
	.global	_input_sample

DW$68	.dwtag  DW_TAG_subprogram, DW_AT_name("input_sample"), DW_AT_symbol_name("_input_sample")
	.dwattr DW$68, DW_AT_low_pc(_input_sample)
	.dwattr DW$68, DW_AT_high_pc(0x00)
	.dwattr DW$68, DW_AT_begin_file("c6713dskinit.c")
	.dwattr DW$68, DW_AT_begin_line(0x52)
	.dwattr DW$68, DW_AT_begin_column(0x08)
	.dwpsn	"c6713dskinit.c",83,1

	.dwfde DW$CIE
;----------------------------------------------------------------------
;  82 | Uint32 input_sample()                                   //for 32-bit in
;     | put                                                                    
;----------------------------------------------------------------------

;******************************************************************************
;* FUNCTION NAME: _input_sample                                               *
;*                                                                            *
;*   Regs Modified     : A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,B0,B1,B2,B3,B4,B5,B6,  *
;*                           B7,B8,B9,SP                                      *
;*   Regs Used         : A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,B0,B1,B2,B3,B4,B5,B6,  *
;*                           B7,B8,B9,SP                                      *
;*   Local Frame Size  : 0 Args + 4 Auto + 4 Save = 8 byte                    *
;******************************************************************************
_input_sample:
;** --------------------------------------------------------------------------*
;----------------------------------------------------------------------
;  84 | short CHANNEL_data;                                                    
;----------------------------------------------------------------------
	.dwcfa	0x0e, 0
	.dwcfa	0x09, 126, 19
           STW     .D2T2   B3,*SP--(8)       ; |83| 
           NOP             2
	.dwcfa	0x0e, 8
	.dwcfa	0x80, 19, 0
DW$69	.dwtag  DW_TAG_variable, DW_AT_name("CHANNEL_data"), DW_AT_symbol_name("_CHANNEL_data")
	.dwattr DW$69, DW_AT_type(*DW$T$8)
	.dwattr DW$69, DW_AT_location[DW_OP_breg31 4]
	.dwpsn	"c6713dskinit.c",86,2
;----------------------------------------------------------------------
;  86 | if (poll) while(!MCBSP_rrdy(DSK6713_AIC23_DATAHANDLE));//if ready to re
;     | ceive                                                                  
;----------------------------------------------------------------------
           MVKL    .S1     _poll,A3          ; |86| 
           MVKH    .S1     _poll,A3          ; |86| 
           LDW     .D1T1   *A3,A1            ; |86| 
           NOP             4
   [!A1]   B       .S1     L8                ; |86| 
           NOP             5
           ; BRANCHCC OCCURS {L8}            ; |86| 
;** --------------------------------------------------------------------------*
	.dwpsn	"c6713dskinit.c",86,18
           MVKL    .S2     _MCBSP_rrdy,B4    ; |86| 

           MVKH    .S2     _MCBSP_rrdy,B4    ; |86| 
||         MVKL    .S1     _DSK6713_AIC23_codecdatahandle,A3 ; |86| 

           CALL    .S2     B4                ; |86| 
||         MVKH    .S1     _DSK6713_AIC23_codecdatahandle,A3 ; |86| 

           LDW     .D1T1   *A3,A4            ; |86| 
           MVKL    .S2     RL25,B3           ; |86| 
           MVKH    .S2     RL25,B3           ; |86| 
           NOP             2
RL25:      ; CALL OCCURS {_MCBSP_rrdy}       ; |86| 
           MV      .L1     A4,A1             ; |86| 
   [ A1]   B       .S1     L8                ; |86| 
           NOP             5
           ; BRANCHCC OCCURS {L8}            ; |86| 
;*----------------------------------------------------------------------------*
;*   SOFTWARE PIPELINE INFORMATION
;*      Disqualified loop: Software pipelining disabled
;*----------------------------------------------------------------------------*
L7:    
DW$L$_input_sample$3$B:
           MVKL    .S2     _MCBSP_rrdy,B4    ; |86| 

           MVKH    .S2     _MCBSP_rrdy,B4    ; |86| 
||         MVKL    .S1     _DSK6713_AIC23_codecdatahandle,A3 ; |86| 

           CALL    .S2     B4                ; |86| 
||         MVKH    .S1     _DSK6713_AIC23_codecdatahandle,A3 ; |86| 

           LDW     .D1T1   *A3,A4            ; |86| 
           MVKL    .S2     RL26,B3           ; |86| 
           MVKH    .S2     RL26,B3           ; |86| 
           NOP             2
RL26:      ; CALL OCCURS {_MCBSP_rrdy}       ; |86| 
           MV      .L1     A4,A1             ; |86| 
   [!A1]   B       .S1     L7                ; |86| 
           NOP             5
           ; BRANCHCC OCCURS {L7}            ; |86| 
DW$L$_input_sample$3$E:
;** --------------------------------------------------------------------------*
L8:    
	.dwpsn	"c6713dskinit.c",87,4
;----------------------------------------------------------------------
;  87 | AIC_data.uint=MCBSP_read(DSK6713_AIC23_DATAHANDLE);//read data         
;  89 | //Swapping left and right channels (see comments in output_sample())   
;----------------------------------------------------------------------
           MVKL    .S2     _MCBSP_read,B4    ; |87| 

           MVKH    .S2     _MCBSP_read,B4    ; |87| 
||         MVKL    .S1     _DSK6713_AIC23_codecdatahandle,A3 ; |87| 

           CALL    .S2     B4                ; |87| 
||         MVKH    .S1     _DSK6713_AIC23_codecdatahandle,A3 ; |87| 

           LDW     .D1T1   *A3,A4            ; |87| 
           MVKL    .S2     RL27,B3           ; |87| 
           MVKH    .S2     RL27,B3           ; |87| 
           NOP             2
RL27:      ; CALL OCCURS {_MCBSP_read}       ; |87| 
           MVKL    .S2     _AIC_data,B4      ; |87| 
           MVKH    .S2     _AIC_data,B4      ; |87| 
           STW     .D2T1   A4,*B4            ; |87| 
           NOP             2
	.dwpsn	"c6713dskinit.c",90,2
;----------------------------------------------------------------------
;  90 | CHANNEL_data=AIC_data.channel[RIGHT];                   //swap left and
;     |  right channel                                                         
;----------------------------------------------------------------------
           MVKL    .S2     _AIC_data,B4      ; |90| 
           MVKH    .S2     _AIC_data,B4      ; |90| 
           LDH     .D2T2   *B4,B4            ; |90| 
           NOP             4
           STH     .D2T2   B4,*+SP(4)        ; |90| 
           NOP             2
	.dwpsn	"c6713dskinit.c",91,2
;----------------------------------------------------------------------
;  91 | AIC_data.channel[RIGHT]=AIC_data.channel[LEFT];                        
;----------------------------------------------------------------------
           MVKL    .S2     _AIC_data+2,B4    ; |91| 
           MVKH    .S2     _AIC_data+2,B4    ; |91| 
           LDH     .D2T2   *B4,B4            ; |91| 
           MVKL    .S1     _AIC_data,A3      ; |91| 
           MVKH    .S1     _AIC_data,A3      ; |91| 
           NOP             2
           STH     .D1T2   B4,*A3            ; |91| 
           NOP             2
	.dwpsn	"c6713dskinit.c",92,2
;----------------------------------------------------------------------
;  92 | AIC_data.channel[LEFT]=CHANNEL_data;                                   
;----------------------------------------------------------------------
           LDH     .D2T2   *+SP(4),B4        ; |92| 
           MVKL    .S1     _AIC_data+2,A3    ; |92| 
           MVKH    .S1     _AIC_data+2,A3    ; |92| 
           NOP             2
           STH     .D1T2   B4,*A3            ; |92| 
           NOP             2
	.dwpsn	"c6713dskinit.c",94,2
;----------------------------------------------------------------------
;  94 | return(AIC_data.uint);                                                 
;----------------------------------------------------------------------
           MVKL    .S1     _AIC_data,A3      ; |94| 
           MVKH    .S1     _AIC_data,A3      ; |94| 
           LDW     .D1T1   *A3,A4            ; |94| 
           NOP             4
	.dwpsn	"c6713dskinit.c",95,1
           LDW     .D2T2   *++SP(8),B3       ; |95| 
           NOP             4
	.dwcfa	0xc0, 19
	.dwcfa	0x0e, 0
           RET     .S2     B3                ; |95| 
           NOP             5
           ; BRANCH OCCURS {B3}              ; |95| 

DW$70	.dwtag  DW_TAG_loop
	.dwattr DW$70, DW_AT_name("C:\CCStudio_v3.1\finalmyprojects\Support\c6713dskinit.asm:L7:1:1181040732")
	.dwattr DW$70, DW_AT_begin_file("c6713dskinit.c")
	.dwattr DW$70, DW_AT_begin_line(0x56)
	.dwattr DW$70, DW_AT_end_line(0x56)
DW$71	.dwtag  DW_TAG_loop_range
	.dwattr DW$71, DW_AT_low_pc(DW$L$_input_sample$3$B)
	.dwattr DW$71, DW_AT_high_pc(DW$L$_input_sample$3$E)
	.dwendtag DW$70

	.dwattr DW$68, DW_AT_end_file("c6713dskinit.c")
	.dwattr DW$68, DW_AT_end_line(0x5f)
	.dwattr DW$68, DW_AT_end_column(0x01)
	.dwendentry
	.dwendtag DW$68

	.sect	".text"
	.global	_input_left_sample

DW$72	.dwtag  DW_TAG_subprogram, DW_AT_name("input_left_sample"), DW_AT_symbol_name("_input_left_sample")
	.dwattr DW$72, DW_AT_low_pc(_input_left_sample)
	.dwattr DW$72, DW_AT_high_pc(0x00)
	.dwattr DW$72, DW_AT_begin_file("c6713dskinit.c")
	.dwattr DW$72, DW_AT_begin_line(0x61)
	.dwattr DW$72, DW_AT_begin_column(0x07)
	.dwpsn	"c6713dskinit.c",98,1

	.dwfde DW$CIE
;----------------------------------------------------------------------
;  97 | short input_left_sample()                               //input to left
;     |  channel                                                               
;----------------------------------------------------------------------

;******************************************************************************
;* FUNCTION NAME: _input_left_sample                                          *
;*                                                                            *
;*   Regs Modified     : A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,B0,B1,B2,B3,B4,B5,B6,  *
;*                           B7,B8,B9,SP                                      *
;*   Regs Used         : A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,B0,B1,B2,B3,B4,B5,B6,  *
;*                           B7,B8,B9,SP                                      *
;*   Local Frame Size  : 0 Args + 0 Auto + 4 Save = 4 byte                    *
;******************************************************************************
_input_left_sample:
;** --------------------------------------------------------------------------*
	.dwcfa	0x0e, 0
	.dwcfa	0x09, 126, 19
           STW     .D2T2   B3,*SP--(8)       ; |98| 
           NOP             2
	.dwcfa	0x0e, 8
	.dwcfa	0x80, 19, 0
	.dwpsn	"c6713dskinit.c",99,2
;----------------------------------------------------------------------
;  99 | if (poll) while(!MCBSP_rrdy(DSK6713_AIC23_DATAHANDLE));//if ready to re
;     | ceive                                                                  
;----------------------------------------------------------------------
           MVKL    .S1     _poll,A3          ; |99| 
           MVKH    .S1     _poll,A3          ; |99| 
           LDW     .D1T1   *A3,A1            ; |99| 
           NOP             4
   [!A1]   B       .S1     L10               ; |99| 
           NOP             5
           ; BRANCHCC OCCURS {L10}           ; |99| 
;** --------------------------------------------------------------------------*
	.dwpsn	"c6713dskinit.c",99,18
           MVKL    .S2     _MCBSP_rrdy,B4    ; |99| 

           MVKH    .S2     _MCBSP_rrdy,B4    ; |99| 
||         MVKL    .S1     _DSK6713_AIC23_codecdatahandle,A3 ; |99| 

           CALL    .S2     B4                ; |99| 
||         MVKH    .S1     _DSK6713_AIC23_codecdatahandle,A3 ; |99| 

           LDW     .D1T1   *A3,A4            ; |99| 
           MVKL    .S2     RL28,B3           ; |99| 
           MVKH    .S2     RL28,B3           ; |99| 
           NOP             2
RL28:      ; CALL OCCURS {_MCBSP_rrdy}       ; |99| 
           MV      .L1     A4,A1             ; |99| 
   [ A1]   B       .S1     L10               ; |99| 
           NOP             5
           ; BRANCHCC OCCURS {L10}           ; |99| 
;*----------------------------------------------------------------------------*
;*   SOFTWARE PIPELINE INFORMATION
;*      Disqualified loop: Software pipelining disabled
;*----------------------------------------------------------------------------*
L9:    
DW$L$_input_left_sample$3$B:
           MVKL    .S2     _MCBSP_rrdy,B4    ; |99| 

           MVKH    .S2     _MCBSP_rrdy,B4    ; |99| 
||         MVKL    .S1     _DSK6713_AIC23_codecdatahandle,A3 ; |99| 

           CALL    .S2     B4                ; |99| 
||         MVKH    .S1     _DSK6713_AIC23_codecdatahandle,A3 ; |99| 

           LDW     .D1T1   *A3,A4            ; |99| 
           MVKL    .S2     RL29,B3           ; |99| 
           MVKH    .S2     RL29,B3           ; |99| 
           NOP             2
RL29:      ; CALL OCCURS {_MCBSP_rrdy}       ; |99| 
           MV      .L1     A4,A1             ; |99| 
   [!A1]   B       .S1     L9                ; |99| 
           NOP             5
           ; BRANCHCC OCCURS {L9}            ; |99| 
DW$L$_input_left_sample$3$E:
;** --------------------------------------------------------------------------*
L10:    
	.dwpsn	"c6713dskinit.c",100,3
;----------------------------------------------------------------------
; 100 | AIC_data.uint=MCBSP_read(DSK6713_AIC23_DATAHANDLE);//read into left cha
;     | nnel                                                                   
;----------------------------------------------------------------------
           MVKL    .S1     _MCBSP_read,A5    ; |100| 
           MVKL    .S1     _DSK6713_AIC23_codecdatahandle,A3 ; |100| 
           MVKH    .S1     _MCBSP_read,A5    ; |100| 

           CALL    .S2X    A5                ; |100| 
||         MVKH    .S1     _DSK6713_AIC23_codecdatahandle,A3 ; |100| 

           LDW     .D1T1   *A3,A4            ; |100| 
           MVKL    .S2     RL30,B3           ; |100| 
           MVKH    .S2     RL30,B3           ; |100| 
           NOP             2
RL30:      ; CALL OCCURS {_MCBSP_read}       ; |100| 
           MVKL    .S2     _AIC_data,B4      ; |100| 
           MVKH    .S2     _AIC_data,B4      ; |100| 
           STW     .D2T1   A4,*B4            ; |100| 
           NOP             2
	.dwpsn	"c6713dskinit.c",101,2
;----------------------------------------------------------------------
; 101 | return(AIC_data.channel[LEFT]);                                 //retur
;     | n left channel data                                                    
;----------------------------------------------------------------------
           MVKL    .S2     _AIC_data+2,B4    ; |101| 
           MVKH    .S2     _AIC_data+2,B4    ; |101| 
           LDH     .D2T1   *B4,A4            ; |101| 
           NOP             4
	.dwpsn	"c6713dskinit.c",102,1
           LDW     .D2T2   *++SP(8),B3       ; |102| 
           NOP             4
	.dwcfa	0xc0, 19
	.dwcfa	0x0e, 0
           RET     .S2     B3                ; |102| 
           NOP             5
           ; BRANCH OCCURS {B3}              ; |102| 

DW$73	.dwtag  DW_TAG_loop
	.dwattr DW$73, DW_AT_name("C:\CCStudio_v3.1\finalmyprojects\Support\c6713dskinit.asm:L9:1:1181040732")
	.dwattr DW$73, DW_AT_begin_file("c6713dskinit.c")
	.dwattr DW$73, DW_AT_begin_line(0x63)
	.dwattr DW$73, DW_AT_end_line(0x63)
DW$74	.dwtag  DW_TAG_loop_range
	.dwattr DW$74, DW_AT_low_pc(DW$L$_input_left_sample$3$B)
	.dwattr DW$74, DW_AT_high_pc(DW$L$_input_left_sample$3$E)
	.dwendtag DW$73

	.dwattr DW$72, DW_AT_end_file("c6713dskinit.c")
	.dwattr DW$72, DW_AT_end_line(0x66)
	.dwattr DW$72, DW_AT_end_column(0x01)
	.dwendentry
	.dwendtag DW$72

	.sect	".text"
	.global	_input_right_sample

DW$75	.dwtag  DW_TAG_subprogram, DW_AT_name("input_right_sample"), DW_AT_symbol_name("_input_right_sample")
	.dwattr DW$75, DW_AT_low_pc(_input_right_sample)
	.dwattr DW$75, DW_AT_high_pc(0x00)
	.dwattr DW$75, DW_AT_begin_file("c6713dskinit.c")
	.dwattr DW$75, DW_AT_begin_line(0x68)
	.dwattr DW$75, DW_AT_begin_column(0x07)
	.dwpsn	"c6713dskinit.c",105,1

	.dwfde DW$CIE
;----------------------------------------------------------------------
; 104 | short input_right_sample()                              //input to righ
;     | t channel                                                              
;----------------------------------------------------------------------

;******************************************************************************
;* FUNCTION NAME: _input_right_sample                                         *
;*                                                                            *
;*   Regs Modified     : A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,B0,B1,B2,B3,B4,B5,B6,  *
;*                           B7,B8,B9,SP                                      *
;*   Regs Used         : A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,B0,B1,B2,B3,B4,B5,B6,  *
;*                           B7,B8,B9,SP                                      *
;*   Local Frame Size  : 0 Args + 0 Auto + 4 Save = 4 byte                    *
;******************************************************************************
_input_right_sample:
;** --------------------------------------------------------------------------*
	.dwcfa	0x0e, 0
	.dwcfa	0x09, 126, 19
           STW     .D2T2   B3,*SP--(8)       ; |105| 
           NOP             2
	.dwcfa	0x0e, 8
	.dwcfa	0x80, 19, 0
	.dwpsn	"c6713dskinit.c",106,2
;----------------------------------------------------------------------
; 106 | if (poll) while(!MCBSP_rrdy(DSK6713_AIC23_DATAHANDLE));//if ready to re
;     | ceive                                                                  
;----------------------------------------------------------------------
           MVKL    .S1     _poll,A3          ; |106| 
           MVKH    .S1     _poll,A3          ; |106| 
           LDW     .D1T1   *A3,A1            ; |106| 
           NOP             4
   [!A1]   B       .S1     L12               ; |106| 
           NOP             5
           ; BRANCHCC OCCURS {L12}           ; |106| 
;** --------------------------------------------------------------------------*
	.dwpsn	"c6713dskinit.c",106,18
           MVKL    .S2     _MCBSP_rrdy,B4    ; |106| 

           MVKH    .S2     _MCBSP_rrdy,B4    ; |106| 
||         MVKL    .S1     _DSK6713_AIC23_codecdatahandle,A3 ; |106| 

           CALL    .S2     B4                ; |106| 
||         MVKH    .S1     _DSK6713_AIC23_codecdatahandle,A3 ; |106| 

           LDW     .D1T1   *A3,A4            ; |106| 
           MVKL    .S2     RL31,B3           ; |106| 
           MVKH    .S2     RL31,B3           ; |106| 
           NOP             2
RL31:      ; CALL OCCURS {_MCBSP_rrdy}       ; |106| 
           MV      .L1     A4,A1             ; |106| 
   [ A1]   B       .S1     L12               ; |106| 
           NOP             5
           ; BRANCHCC OCCURS {L12}           ; |106| 
;*----------------------------------------------------------------------------*
;*   SOFTWARE PIPELINE INFORMATION
;*      Disqualified loop: Software pipelining disabled
;*----------------------------------------------------------------------------*
L11:    
DW$L$_input_right_sample$3$B:
           MVKL    .S2     _MCBSP_rrdy,B4    ; |106| 

           MVKH    .S2     _MCBSP_rrdy,B4    ; |106| 
||         MVKL    .S1     _DSK6713_AIC23_codecdatahandle,A3 ; |106| 

           CALL    .S2     B4                ; |106| 
||         MVKH    .S1     _DSK6713_AIC23_codecdatahandle,A3 ; |106| 

           LDW     .D1T1   *A3,A4            ; |106| 
           MVKL    .S2     RL32,B3           ; |106| 
           MVKH    .S2     RL32,B3           ; |106| 
           NOP             2
RL32:      ; CALL OCCURS {_MCBSP_rrdy}       ; |106| 
           MV      .L1     A4,A1             ; |106| 
   [!A1]   B       .S1     L11               ; |106| 
           NOP             5
           ; BRANCHCC OCCURS {L11}           ; |106| 
DW$L$_input_right_sample$3$E:
;** --------------------------------------------------------------------------*
L12:    
	.dwpsn	"c6713dskinit.c",107,3
;----------------------------------------------------------------------
; 107 | AIC_data.uint=MCBSP_read(DSK6713_AIC23_DATAHANDLE);//read into right ch
;     | annel                                                                  
;----------------------------------------------------------------------
           MVKL    .S1     _MCBSP_read,A5    ; |107| 
           MVKL    .S1     _DSK6713_AIC23_codecdatahandle,A3 ; |107| 
           MVKH    .S1     _MCBSP_read,A5    ; |107| 

           CALL    .S2X    A5                ; |107| 
||         MVKH    .S1     _DSK6713_AIC23_codecdatahandle,A3 ; |107| 

           LDW     .D1T1   *A3,A4            ; |107| 
           MVKL    .S2     RL33,B3           ; |107| 
           MVKH    .S2     RL33,B3           ; |107| 
           NOP             2
RL33:      ; CALL OCCURS {_MCBSP_read}       ; |107| 
           MVKL    .S2     _AIC_data,B4      ; |107| 
           MVKH    .S2     _AIC_data,B4      ; |107| 
           STW     .D2T1   A4,*B4            ; |107| 
           NOP             2
	.dwpsn	"c6713dskinit.c",108,2
;----------------------------------------------------------------------
; 108 | return(AIC_data.channel[RIGHT]);                                //retur
;     | n right channel data                                                   
;----------------------------------------------------------------------
           MVKL    .S2     _AIC_data,B4      ; |108| 
           MVKH    .S2     _AIC_data,B4      ; |108| 
           LDH     .D2T1   *B4,A4            ; |108| 
           NOP             4
	.dwpsn	"c6713dskinit.c",109,1
           LDW     .D2T2   *++SP(8),B3       ; |109| 
           NOP             4
	.dwcfa	0xc0, 19
	.dwcfa	0x0e, 0
           RET     .S2     B3                ; |109| 
           NOP             5
           ; BRANCH OCCURS {B3}              ; |109| 

DW$76	.dwtag  DW_TAG_loop
	.dwattr DW$76, DW_AT_name("C:\CCStudio_v3.1\finalmyprojects\Support\c6713dskinit.asm:L11:1:1181040732")
	.dwattr DW$76, DW_AT_begin_file("c6713dskinit.c")
	.dwattr DW$76, DW_AT_begin_line(0x6a)
	.dwattr DW$76, DW_AT_end_line(0x6a)
DW$77	.dwtag  DW_TAG_loop_range
	.dwattr DW$77, DW_AT_low_pc(DW$L$_input_right_sample$3$B)
	.dwattr DW$77, DW_AT_high_pc(DW$L$_input_right_sample$3$E)
	.dwendtag DW$76

	.dwattr DW$75, DW_AT_end_file("c6713dskinit.c")
	.dwattr DW$75, DW_AT_end_line(0x6d)
	.dwattr DW$75, DW_AT_end_column(0x01)
	.dwendentry
	.dwendtag DW$75

;******************************************************************************
;* UNDEFINED EXTERNAL REFERENCES                                              *
;******************************************************************************
	.global	_IRQ_map
	.global	_IRQ_enable
	.global	_IRQ_reset
	.global	_IRQ_globalEnable
	.global	_IRQ_globalDisable
	.global	_IRQ_nmiEnable
	.global	_DSK6713_init
	.global	_MCBSP_start
	.global	_MCBSP_getXmtEventId
	.global	_MCBSP_read
	.global	_MCBSP_write
	.global	_MCBSP_xrdy
	.global	_MCBSP_rrdy
	.global	_MCBSP_config
	.global	_DSK6713_AIC23_rset
	.global	_DSK6713_AIC23_openCodec
	.global	_DSK6713_AIC23_setFreq
	.global	_DSK6713_AIC23_codecdatahandle
	.global	_fs
	.global	_inputsource

;******************************************************************************
;* TYPE INFORMATION                                                           *
;******************************************************************************

DW$T$28	.dwtag  DW_TAG_subroutine_type
	.dwattr DW$T$28, DW_AT_language(DW_LANG_C)
DW$78	.dwtag  DW_TAG_formal_parameter, DW_AT_type(*DW$T$19)
DW$79	.dwtag  DW_TAG_formal_parameter, DW_AT_type(*DW$T$19)
	.dwendtag DW$T$28


DW$T$30	.dwtag  DW_TAG_subroutine_type
	.dwattr DW$T$30, DW_AT_language(DW_LANG_C)
DW$80	.dwtag  DW_TAG_formal_parameter, DW_AT_type(*DW$T$19)
	.dwendtag DW$T$30


DW$T$32	.dwtag  DW_TAG_subroutine_type
	.dwattr DW$T$32, DW_AT_language(DW_LANG_C)

DW$T$36	.dwtag  DW_TAG_subroutine_type
	.dwattr DW$T$36, DW_AT_language(DW_LANG_C)
DW$81	.dwtag  DW_TAG_formal_parameter, DW_AT_type(*DW$T$35)
DW$82	.dwtag  DW_TAG_formal_parameter, DW_AT_type(*DW$T$19)
DW$83	.dwtag  DW_TAG_formal_parameter, DW_AT_type(*DW$T$19)
	.dwendtag DW$T$36


DW$T$38	.dwtag  DW_TAG_subroutine_type
	.dwattr DW$T$38, DW_AT_language(DW_LANG_C)
DW$84	.dwtag  DW_TAG_formal_parameter, DW_AT_type(*DW$T$35)
DW$85	.dwtag  DW_TAG_formal_parameter, DW_AT_type(*DW$T$19)
	.dwendtag DW$T$38


DW$T$42	.dwtag  DW_TAG_subroutine_type
	.dwattr DW$T$42, DW_AT_language(DW_LANG_C)
DW$86	.dwtag  DW_TAG_formal_parameter, DW_AT_type(*DW$T$35)
DW$87	.dwtag  DW_TAG_formal_parameter, DW_AT_type(*DW$T$41)
	.dwendtag DW$T$42


DW$T$46	.dwtag  DW_TAG_subroutine_type
	.dwattr DW$T$46, DW_AT_language(DW_LANG_C)
DW$88	.dwtag  DW_TAG_formal_parameter, DW_AT_type(*DW$T$44)
DW$89	.dwtag  DW_TAG_formal_parameter, DW_AT_type(*DW$T$45)
DW$90	.dwtag  DW_TAG_formal_parameter, DW_AT_type(*DW$T$45)
	.dwendtag DW$T$46


DW$T$48	.dwtag  DW_TAG_subroutine_type
	.dwattr DW$T$48, DW_AT_language(DW_LANG_C)
DW$91	.dwtag  DW_TAG_formal_parameter, DW_AT_type(*DW$T$44)
DW$92	.dwtag  DW_TAG_formal_parameter, DW_AT_type(*DW$T$19)
	.dwendtag DW$T$48


DW$T$50	.dwtag  DW_TAG_subroutine_type
	.dwattr DW$T$50, DW_AT_language(DW_LANG_C)
DW$93	.dwtag  DW_TAG_formal_parameter, DW_AT_type(*DW$T$10)
	.dwendtag DW$T$50


DW$T$52	.dwtag  DW_TAG_subroutine_type
	.dwattr DW$T$52, DW_AT_language(DW_LANG_C)
DW$94	.dwtag  DW_TAG_formal_parameter, DW_AT_type(*DW$T$8)
	.dwendtag DW$T$52

DW$T$8	.dwtag  DW_TAG_base_type, DW_AT_name("short")
	.dwattr DW$T$8, DW_AT_encoding(DW_ATE_signed)
	.dwattr DW$T$8, DW_AT_byte_size(0x02)

DW$T$53	.dwtag  DW_TAG_subroutine_type, DW_AT_type(*DW$T$8)
	.dwattr DW$T$53, DW_AT_language(DW_LANG_C)
DW$T$45	.dwtag  DW_TAG_typedef, DW_AT_name("Uint16"), DW_AT_type(*DW$T$9)
	.dwattr DW$T$45, DW_AT_language(DW_LANG_C)
DW$T$10	.dwtag  DW_TAG_base_type, DW_AT_name("int")
	.dwattr DW$T$10, DW_AT_encoding(DW_ATE_signed)
	.dwattr DW$T$10, DW_AT_byte_size(0x04)
DW$T$44	.dwtag  DW_TAG_typedef, DW_AT_name("DSK6713_AIC23_CodecHandle"), DW_AT_type(*DW$T$10)
	.dwattr DW$T$44, DW_AT_language(DW_LANG_C)

DW$T$58	.dwtag  DW_TAG_subroutine_type, DW_AT_type(*DW$T$44)
	.dwattr DW$T$58, DW_AT_language(DW_LANG_C)
DW$95	.dwtag  DW_TAG_formal_parameter, DW_AT_type(*DW$T$10)
DW$96	.dwtag  DW_TAG_formal_parameter, DW_AT_type(*DW$T$57)
	.dwendtag DW$T$58

DW$T$19	.dwtag  DW_TAG_typedef, DW_AT_name("Uint32"), DW_AT_type(*DW$T$11)
	.dwattr DW$T$19, DW_AT_language(DW_LANG_C)

DW$T$60	.dwtag  DW_TAG_subroutine_type, DW_AT_type(*DW$T$19)
	.dwattr DW$T$60, DW_AT_language(DW_LANG_C)

DW$T$62	.dwtag  DW_TAG_subroutine_type, DW_AT_type(*DW$T$19)
	.dwattr DW$T$62, DW_AT_language(DW_LANG_C)
DW$97	.dwtag  DW_TAG_formal_parameter, DW_AT_type(*DW$T$35)
	.dwendtag DW$T$62

DW$T$35	.dwtag  DW_TAG_typedef, DW_AT_name("MCBSP_Handle"), DW_AT_type(*DW$T$34)
	.dwattr DW$T$35, DW_AT_language(DW_LANG_C)
DW$T$40	.dwtag  DW_TAG_typedef, DW_AT_name("MCBSP_Config"), DW_AT_type(*DW$T$23)
	.dwattr DW$T$40, DW_AT_language(DW_LANG_C)
DW$T$41	.dwtag  DW_TAG_pointer_type, DW_AT_type(*DW$T$40)
	.dwattr DW$T$41, DW_AT_address_class(0x20)
DW$T$56	.dwtag  DW_TAG_typedef, DW_AT_name("DSK6713_AIC23_Config"), DW_AT_type(*DW$T$25)
	.dwattr DW$T$56, DW_AT_language(DW_LANG_C)
DW$T$57	.dwtag  DW_TAG_pointer_type, DW_AT_type(*DW$T$56)
	.dwattr DW$T$57, DW_AT_address_class(0x20)

DW$T$27	.dwtag  DW_TAG_union_type
	.dwattr DW$T$27, DW_AT_byte_size(0x04)
DW$98	.dwtag  DW_TAG_member, DW_AT_type(*DW$T$19)
	.dwattr DW$98, DW_AT_name("uint"), DW_AT_symbol_name("_uint")
	.dwattr DW$98, DW_AT_data_member_location[DW_OP_plus_uconst 0x0]
	.dwattr DW$98, DW_AT_accessibility(DW_ACCESS_public)
DW$99	.dwtag  DW_TAG_member, DW_AT_type(*DW$T$26)
	.dwattr DW$99, DW_AT_name("channel"), DW_AT_symbol_name("_channel")
	.dwattr DW$99, DW_AT_data_member_location[DW_OP_plus_uconst 0x0]
	.dwattr DW$99, DW_AT_accessibility(DW_ACCESS_public)
	.dwendtag DW$T$27


DW$T$26	.dwtag  DW_TAG_array_type, DW_AT_type(*DW$T$8)
	.dwattr DW$T$26, DW_AT_language(DW_LANG_C)
	.dwattr DW$T$26, DW_AT_byte_size(0x04)
DW$100	.dwtag  DW_TAG_subrange_type
	.dwattr DW$100, DW_AT_upper_bound(0x01)
	.dwendtag DW$T$26

DW$T$9	.dwtag  DW_TAG_base_type, DW_AT_name("unsigned short")
	.dwattr DW$T$9, DW_AT_encoding(DW_ATE_unsigned)
	.dwattr DW$T$9, DW_AT_byte_size(0x02)
DW$T$11	.dwtag  DW_TAG_base_type, DW_AT_name("unsigned int")
	.dwattr DW$T$11, DW_AT_encoding(DW_ATE_unsigned)
	.dwattr DW$T$11, DW_AT_byte_size(0x04)
DW$T$34	.dwtag  DW_TAG_pointer_type, DW_AT_type(*DW$T$22)
	.dwattr DW$T$34, DW_AT_address_class(0x20)

DW$T$23	.dwtag  DW_TAG_structure_type
	.dwattr DW$T$23, DW_AT_byte_size(0x20)
DW$101	.dwtag  DW_TAG_member, DW_AT_type(*DW$T$19)
	.dwattr DW$101, DW_AT_name("spcr"), DW_AT_symbol_name("_spcr")
	.dwattr DW$101, DW_AT_data_member_location[DW_OP_plus_uconst 0x0]
	.dwattr DW$101, DW_AT_accessibility(DW_ACCESS_public)
DW$102	.dwtag  DW_TAG_member, DW_AT_type(*DW$T$19)
	.dwattr DW$102, DW_AT_name("rcr"), DW_AT_symbol_name("_rcr")
	.dwattr DW$102, DW_AT_data_member_location[DW_OP_plus_uconst 0x4]
	.dwattr DW$102, DW_AT_accessibility(DW_ACCESS_public)
DW$103	.dwtag  DW_TAG_member, DW_AT_type(*DW$T$19)
	.dwattr DW$103, DW_AT_name("xcr"), DW_AT_symbol_name("_xcr")
	.dwattr DW$103, DW_AT_data_member_location[DW_OP_plus_uconst 0x8]
	.dwattr DW$103, DW_AT_accessibility(DW_ACCESS_public)
DW$104	.dwtag  DW_TAG_member, DW_AT_type(*DW$T$19)
	.dwattr DW$104, DW_AT_name("srgr"), DW_AT_symbol_name("_srgr")
	.dwattr DW$104, DW_AT_data_member_location[DW_OP_plus_uconst 0xc]
	.dwattr DW$104, DW_AT_accessibility(DW_ACCESS_public)
DW$105	.dwtag  DW_TAG_member, DW_AT_type(*DW$T$19)
	.dwattr DW$105, DW_AT_name("mcr"), DW_AT_symbol_name("_mcr")
	.dwattr DW$105, DW_AT_data_member_location[DW_OP_plus_uconst 0x10]
	.dwattr DW$105, DW_AT_accessibility(DW_ACCESS_public)
DW$106	.dwtag  DW_TAG_member, DW_AT_type(*DW$T$19)
	.dwattr DW$106, DW_AT_name("rcer"), DW_AT_symbol_name("_rcer")
	.dwattr DW$106, DW_AT_data_member_location[DW_OP_plus_uconst 0x14]
	.dwattr DW$106, DW_AT_accessibility(DW_ACCESS_public)
DW$107	.dwtag  DW_TAG_member, DW_AT_type(*DW$T$19)
	.dwattr DW$107, DW_AT_name("xcer"), DW_AT_symbol_name("_xcer")
	.dwattr DW$107, DW_AT_data_member_location[DW_OP_plus_uconst 0x18]
	.dwattr DW$107, DW_AT_accessibility(DW_ACCESS_public)
DW$108	.dwtag  DW_TAG_member, DW_AT_type(*DW$T$19)
	.dwattr DW$108, DW_AT_name("pcr"), DW_AT_symbol_name("_pcr")
	.dwattr DW$108, DW_AT_data_member_location[DW_OP_plus_uconst 0x1c]
	.dwattr DW$108, DW_AT_accessibility(DW_ACCESS_public)
	.dwendtag DW$T$23


DW$T$25	.dwtag  DW_TAG_structure_type
	.dwattr DW$T$25, DW_AT_name("DSK6713_AIC23_Config")
	.dwattr DW$T$25, DW_AT_byte_size(0x28)
DW$109	.dwtag  DW_TAG_member, DW_AT_type(*DW$T$24)
	.dwattr DW$109, DW_AT_name("regs"), DW_AT_symbol_name("_regs")
	.dwattr DW$109, DW_AT_data_member_location[DW_OP_plus_uconst 0x0]
	.dwattr DW$109, DW_AT_accessibility(DW_ACCESS_public)
	.dwendtag DW$T$25


DW$T$24	.dwtag  DW_TAG_array_type, DW_AT_type(*DW$T$10)
	.dwattr DW$T$24, DW_AT_language(DW_LANG_C)
	.dwattr DW$T$24, DW_AT_byte_size(0x28)
DW$110	.dwtag  DW_TAG_subrange_type
	.dwattr DW$110, DW_AT_upper_bound(0x09)
	.dwendtag DW$T$24


DW$T$22	.dwtag  DW_TAG_structure_type
	.dwattr DW$T$22, DW_AT_byte_size(0x18)
DW$111	.dwtag  DW_TAG_member, DW_AT_type(*DW$T$19)
	.dwattr DW$111, DW_AT_name("allocated"), DW_AT_symbol_name("_allocated")
	.dwattr DW$111, DW_AT_data_member_location[DW_OP_plus_uconst 0x0]
	.dwattr DW$111, DW_AT_accessibility(DW_ACCESS_public)
DW$112	.dwtag  DW_TAG_member, DW_AT_type(*DW$T$19)
	.dwattr DW$112, DW_AT_name("xmtEventId"), DW_AT_symbol_name("_xmtEventId")
	.dwattr DW$112, DW_AT_data_member_location[DW_OP_plus_uconst 0x4]
	.dwattr DW$112, DW_AT_accessibility(DW_ACCESS_public)
DW$113	.dwtag  DW_TAG_member, DW_AT_type(*DW$T$19)
	.dwattr DW$113, DW_AT_name("rcvEventId"), DW_AT_symbol_name("_rcvEventId")
	.dwattr DW$113, DW_AT_data_member_location[DW_OP_plus_uconst 0x8]
	.dwattr DW$113, DW_AT_accessibility(DW_ACCESS_public)
DW$114	.dwtag  DW_TAG_member, DW_AT_type(*DW$T$21)
	.dwattr DW$114, DW_AT_name("baseAddr"), DW_AT_symbol_name("_baseAddr")
	.dwattr DW$114, DW_AT_data_member_location[DW_OP_plus_uconst 0xc]
	.dwattr DW$114, DW_AT_accessibility(DW_ACCESS_public)
DW$115	.dwtag  DW_TAG_member, DW_AT_type(*DW$T$19)
	.dwattr DW$115, DW_AT_name("drrAddr"), DW_AT_symbol_name("_drrAddr")
	.dwattr DW$115, DW_AT_data_member_location[DW_OP_plus_uconst 0x10]
	.dwattr DW$115, DW_AT_accessibility(DW_ACCESS_public)
DW$116	.dwtag  DW_TAG_member, DW_AT_type(*DW$T$19)
	.dwattr DW$116, DW_AT_name("dxrAddr"), DW_AT_symbol_name("_dxrAddr")
	.dwattr DW$116, DW_AT_data_member_location[DW_OP_plus_uconst 0x14]
	.dwattr DW$116, DW_AT_accessibility(DW_ACCESS_public)
	.dwendtag DW$T$22

DW$T$21	.dwtag  DW_TAG_pointer_type, DW_AT_type(*DW$T$20)
	.dwattr DW$T$21, DW_AT_address_class(0x20)
DW$T$20	.dwtag  DW_TAG_volatile_type
	.dwattr DW$T$20, DW_AT_type(*DW$T$19)

	.dwattr DW$49, DW_AT_external(0x01)
	.dwattr DW$51, DW_AT_external(0x01)
	.dwattr DW$50, DW_AT_external(0x01)
	.dwattr DW$72, DW_AT_external(0x01)
	.dwattr DW$72, DW_AT_type(*DW$T$8)
	.dwattr DW$75, DW_AT_external(0x01)
	.dwattr DW$75, DW_AT_type(*DW$T$8)
	.dwattr DW$68, DW_AT_external(0x01)
	.dwattr DW$68, DW_AT_type(*DW$T$19)
	.dwattr DW$58, DW_AT_external(0x01)
	.dwattr DW$63, DW_AT_external(0x01)
	.dwattr DW$52, DW_AT_external(0x01)
	.dwattr DW$CU, DW_AT_language(DW_LANG_C)

;***************************************************************
;* DWARF CIE ENTRIES                                           *
;***************************************************************

DW$CIE	.dwcie 1, 126
	.dwcfa	0x0c, 31, 0
	.dwcfa	0x07, 0
	.dwcfa	0x07, 1
	.dwcfa	0x07, 2
	.dwcfa	0x07, 3
	.dwcfa	0x07, 4
	.dwcfa	0x07, 5
	.dwcfa	0x07, 6
	.dwcfa	0x07, 7
	.dwcfa	0x07, 8
	.dwcfa	0x07, 9
	.dwcfa	0x08, 10
	.dwcfa	0x08, 11
	.dwcfa	0x08, 12
	.dwcfa	0x08, 13
	.dwcfa	0x08, 14
	.dwcfa	0x08, 15
	.dwcfa	0x07, 16
	.dwcfa	0x07, 17
	.dwcfa	0x07, 18
	.dwcfa	0x07, 19
	.dwcfa	0x07, 20
	.dwcfa	0x07, 21
	.dwcfa	0x07, 22
	.dwcfa	0x07, 23
	.dwcfa	0x07, 24
	.dwcfa	0x07, 25
	.dwcfa	0x08, 26
	.dwcfa	0x08, 27
	.dwcfa	0x08, 28
	.dwcfa	0x08, 29
	.dwcfa	0x08, 30
	.dwcfa	0x08, 31
	.dwcfa	0x08, 32
	.dwcfa	0x07, 33
	.dwcfa	0x07, 34
	.dwcfa	0x07, 35
	.dwcfa	0x07, 36
	.dwcfa	0x07, 37
	.dwcfa	0x07, 38
	.dwcfa	0x07, 39
	.dwcfa	0x07, 40
	.dwcfa	0x07, 41
	.dwcfa	0x07, 42
	.dwcfa	0x07, 43
	.dwcfa	0x07, 44
	.dwcfa	0x07, 45
	.dwcfa	0x07, 46
	.dwcfa	0x07, 47
	.dwcfa	0x07, 48
	.dwcfa	0x07, 49
	.dwcfa	0x07, 50
	.dwcfa	0x07, 51
	.dwcfa	0x07, 52
	.dwcfa	0x07, 53
	.dwcfa	0x07, 54
	.dwcfa	0x07, 55
	.dwcfa	0x07, 56
	.dwcfa	0x07, 57
	.dwcfa	0x07, 58
	.dwcfa	0x07, 59
	.dwcfa	0x07, 60
	.dwcfa	0x07, 61
	.dwcfa	0x07, 62
	.dwcfa	0x07, 63
	.dwcfa	0x07, 64
	.dwcfa	0x07, 65
	.dwcfa	0x07, 66
	.dwcfa	0x07, 67
	.dwcfa	0x07, 68
	.dwcfa	0x07, 69
	.dwcfa	0x07, 70
	.dwcfa	0x07, 71
	.dwcfa	0x07, 72
	.dwcfa	0x07, 73
	.dwcfa	0x07, 74
	.dwcfa	0x07, 75
	.dwcfa	0x07, 76
	.dwcfa	0x07, 77
	.dwcfa	0x07, 78
	.dwcfa	0x07, 79
	.dwcfa	0x07, 80
	.dwcfa	0x07, 81
	.dwcfa	0x07, 82
	.dwcfa	0x07, 83
	.dwcfa	0x07, 84
	.dwcfa	0x07, 85
	.dwcfa	0x07, 86
	.dwcfa	0x07, 87
	.dwcfa	0x07, 88
	.dwcfa	0x07, 89
	.dwcfa	0x07, 90
	.dwcfa	0x07, 91
	.dwcfa	0x07, 92
	.dwcfa	0x07, 93
	.dwcfa	0x07, 94
	.dwcfa	0x07, 95
	.dwcfa	0x07, 96
	.dwcfa	0x07, 97
	.dwcfa	0x07, 98
	.dwcfa	0x07, 99
	.dwcfa	0x07, 100
	.dwcfa	0x07, 101
	.dwcfa	0x07, 102
	.dwcfa	0x07, 103
	.dwcfa	0x07, 104
	.dwcfa	0x07, 105
	.dwcfa	0x07, 106
	.dwcfa	0x07, 107
	.dwcfa	0x07, 108
	.dwcfa	0x07, 109
	.dwcfa	0x07, 110
	.dwcfa	0x07, 111
	.dwcfa	0x07, 112
	.dwcfa	0x07, 113
	.dwcfa	0x07, 114
	.dwcfa	0x07, 115
	.dwcfa	0x07, 116
	.dwcfa	0x07, 117
	.dwcfa	0x07, 118
	.dwcfa	0x07, 119
	.dwcfa	0x07, 120
	.dwcfa	0x07, 121
	.dwcfa	0x07, 122
	.dwcfa	0x07, 123
	.dwcfa	0x07, 124
	.dwcfa	0x07, 125
	.dwcfa	0x07, 126

;***************************************************************
;* DWARF REGISTER MAP                                          *
;***************************************************************

DW$117	.dwtag  DW_TAG_assign_register, DW_AT_name("A0")
	.dwattr DW$117, DW_AT_location[DW_OP_reg0]
DW$118	.dwtag  DW_TAG_assign_register, DW_AT_name("A1")
	.dwattr DW$118, DW_AT_location[DW_OP_reg1]
DW$119	.dwtag  DW_TAG_assign_register, DW_AT_name("A2")
	.dwattr DW$119, DW_AT_location[DW_OP_reg2]
DW$120	.dwtag  DW_TAG_assign_register, DW_AT_name("A3")
	.dwattr DW$120, DW_AT_location[DW_OP_reg3]
DW$121	.dwtag  DW_TAG_assign_register, DW_AT_name("A4")
	.dwattr DW$121, DW_AT_location[DW_OP_reg4]
DW$122	.dwtag  DW_TAG_assign_register, DW_AT_name("A5")
	.dwattr DW$122, DW_AT_location[DW_OP_reg5]
DW$123	.dwtag  DW_TAG_assign_register, DW_AT_name("A6")
	.dwattr DW$123, DW_AT_location[DW_OP_reg6]
DW$124	.dwtag  DW_TAG_assign_register, DW_AT_name("A7")
	.dwattr DW$124, DW_AT_location[DW_OP_reg7]
DW$125	.dwtag  DW_TAG_assign_register, DW_AT_name("A8")
	.dwattr DW$125, DW_AT_location[DW_OP_reg8]
DW$126	.dwtag  DW_TAG_assign_register, DW_AT_name("A9")
	.dwattr DW$126, DW_AT_location[DW_OP_reg9]
DW$127	.dwtag  DW_TAG_assign_register, DW_AT_name("A10")
	.dwattr DW$127, DW_AT_location[DW_OP_reg10]
DW$128	.dwtag  DW_TAG_assign_register, DW_AT_name("A11")
	.dwattr DW$128, DW_AT_location[DW_OP_reg11]
DW$129	.dwtag  DW_TAG_assign_register, DW_AT_name("A12")
	.dwattr DW$129, DW_AT_location[DW_OP_reg12]
DW$130	.dwtag  DW_TAG_assign_register, DW_AT_name("A13")
	.dwattr DW$130, DW_AT_location[DW_OP_reg13]
DW$131	.dwtag  DW_TAG_assign_register, DW_AT_name("A14")
	.dwattr DW$131, DW_AT_location[DW_OP_reg14]
DW$132	.dwtag  DW_TAG_assign_register, DW_AT_name("A15")
	.dwattr DW$132, DW_AT_location[DW_OP_reg15]
DW$133	.dwtag  DW_TAG_assign_register, DW_AT_name("B0")
	.dwattr DW$133, DW_AT_location[DW_OP_reg16]
DW$134	.dwtag  DW_TAG_assign_register, DW_AT_name("B1")
	.dwattr DW$134, DW_AT_location[DW_OP_reg17]
DW$135	.dwtag  DW_TAG_assign_register, DW_AT_name("B2")
	.dwattr DW$135, DW_AT_location[DW_OP_reg18]
DW$136	.dwtag  DW_TAG_assign_register, DW_AT_name("B3")
	.dwattr DW$136, DW_AT_location[DW_OP_reg19]
DW$137	.dwtag  DW_TAG_assign_register, DW_AT_name("B4")
	.dwattr DW$137, DW_AT_location[DW_OP_reg20]
DW$138	.dwtag  DW_TAG_assign_register, DW_AT_name("B5")
	.dwattr DW$138, DW_AT_location[DW_OP_reg21]
DW$139	.dwtag  DW_TAG_assign_register, DW_AT_name("B6")
	.dwattr DW$139, DW_AT_location[DW_OP_reg22]
DW$140	.dwtag  DW_TAG_assign_register, DW_AT_name("B7")
	.dwattr DW$140, DW_AT_location[DW_OP_reg23]
DW$141	.dwtag  DW_TAG_assign_register, DW_AT_name("B8")
	.dwattr DW$141, DW_AT_location[DW_OP_reg24]
DW$142	.dwtag  DW_TAG_assign_register, DW_AT_name("B9")
	.dwattr DW$142, DW_AT_location[DW_OP_reg25]
DW$143	.dwtag  DW_TAG_assign_register, DW_AT_name("B10")
	.dwattr DW$143, DW_AT_location[DW_OP_reg26]
DW$144	.dwtag  DW_TAG_assign_register, DW_AT_name("B11")
	.dwattr DW$144, DW_AT_location[DW_OP_reg27]
DW$145	.dwtag  DW_TAG_assign_register, DW_AT_name("B12")
	.dwattr DW$145, DW_AT_location[DW_OP_reg28]
DW$146	.dwtag  DW_TAG_assign_register, DW_AT_name("B13")
	.dwattr DW$146, DW_AT_location[DW_OP_reg29]
DW$147	.dwtag  DW_TAG_assign_register, DW_AT_name("DP")
	.dwattr DW$147, DW_AT_location[DW_OP_reg30]
DW$148	.dwtag  DW_TAG_assign_register, DW_AT_name("SP")
	.dwattr DW$148, DW_AT_location[DW_OP_reg31]
DW$149	.dwtag  DW_TAG_assign_register, DW_AT_name("FP")
	.dwattr DW$149, DW_AT_location[DW_OP_regx 0x20]
DW$150	.dwtag  DW_TAG_assign_register, DW_AT_name("PC")
	.dwattr DW$150, DW_AT_location[DW_OP_regx 0x21]
DW$151	.dwtag  DW_TAG_assign_register, DW_AT_name("IRP")
	.dwattr DW$151, DW_AT_location[DW_OP_regx 0x22]
DW$152	.dwtag  DW_TAG_assign_register, DW_AT_name("IFR")
	.dwattr DW$152, DW_AT_location[DW_OP_regx 0x23]
DW$153	.dwtag  DW_TAG_assign_register, DW_AT_name("NRP")
	.dwattr DW$153, DW_AT_location[DW_OP_regx 0x24]
DW$154	.dwtag  DW_TAG_assign_register, DW_AT_name("A16")
	.dwattr DW$154, DW_AT_location[DW_OP_regx 0x25]
DW$155	.dwtag  DW_TAG_assign_register, DW_AT_name("A17")
	.dwattr DW$155, DW_AT_location[DW_OP_regx 0x26]
DW$156	.dwtag  DW_TAG_assign_register, DW_AT_name("A18")
	.dwattr DW$156, DW_AT_location[DW_OP_regx 0x27]
DW$157	.dwtag  DW_TAG_assign_register, DW_AT_name("A19")
	.dwattr DW$157, DW_AT_location[DW_OP_regx 0x28]
DW$158	.dwtag  DW_TAG_assign_register, DW_AT_name("A20")
	.dwattr DW$158, DW_AT_location[DW_OP_regx 0x29]
DW$159	.dwtag  DW_TAG_assign_register, DW_AT_name("A21")
	.dwattr DW$159, DW_AT_location[DW_OP_regx 0x2a]
DW$160	.dwtag  DW_TAG_assign_register, DW_AT_name("A22")
	.dwattr DW$160, DW_AT_location[DW_OP_regx 0x2b]
DW$161	.dwtag  DW_TAG_assign_register, DW_AT_name("A23")
	.dwattr DW$161, DW_AT_location[DW_OP_regx 0x2c]
DW$162	.dwtag  DW_TAG_assign_register, DW_AT_name("A24")
	.dwattr DW$162, DW_AT_location[DW_OP_regx 0x2d]
DW$163	.dwtag  DW_TAG_assign_register, DW_AT_name("A25")
	.dwattr DW$163, DW_AT_location[DW_OP_regx 0x2e]
DW$164	.dwtag  DW_TAG_assign_register, DW_AT_name("A26")
	.dwattr DW$164, DW_AT_location[DW_OP_regx 0x2f]
DW$165	.dwtag  DW_TAG_assign_register, DW_AT_name("A27")
	.dwattr DW$165, DW_AT_location[DW_OP_regx 0x30]
DW$166	.dwtag  DW_TAG_assign_register, DW_AT_name("A28")
	.dwattr DW$166, DW_AT_location[DW_OP_regx 0x31]
DW$167	.dwtag  DW_TAG_assign_register, DW_AT_name("A29")
	.dwattr DW$167, DW_AT_location[DW_OP_regx 0x32]
DW$168	.dwtag  DW_TAG_assign_register, DW_AT_name("A30")
	.dwattr DW$168, DW_AT_location[DW_OP_regx 0x33]
DW$169	.dwtag  DW_TAG_assign_register, DW_AT_name("A31")
	.dwattr DW$169, DW_AT_location[DW_OP_regx 0x34]
DW$170	.dwtag  DW_TAG_assign_register, DW_AT_name("B16")
	.dwattr DW$170, DW_AT_location[DW_OP_regx 0x35]
DW$171	.dwtag  DW_TAG_assign_register, DW_AT_name("B17")
	.dwattr DW$171, DW_AT_location[DW_OP_regx 0x36]
DW$172	.dwtag  DW_TAG_assign_register, DW_AT_name("B18")
	.dwattr DW$172, DW_AT_location[DW_OP_regx 0x37]
DW$173	.dwtag  DW_TAG_assign_register, DW_AT_name("B19")
	.dwattr DW$173, DW_AT_location[DW_OP_regx 0x38]
DW$174	.dwtag  DW_TAG_assign_register, DW_AT_name("B20")
	.dwattr DW$174, DW_AT_location[DW_OP_regx 0x39]
DW$175	.dwtag  DW_TAG_assign_register, DW_AT_name("B21")
	.dwattr DW$175, DW_AT_location[DW_OP_regx 0x3a]
DW$176	.dwtag  DW_TAG_assign_register, DW_AT_name("B22")
	.dwattr DW$176, DW_AT_location[DW_OP_regx 0x3b]
DW$177	.dwtag  DW_TAG_assign_register, DW_AT_name("B23")
	.dwattr DW$177, DW_AT_location[DW_OP_regx 0x3c]
DW$178	.dwtag  DW_TAG_assign_register, DW_AT_name("B24")
	.dwattr DW$178, DW_AT_location[DW_OP_regx 0x3d]
DW$179	.dwtag  DW_TAG_assign_register, DW_AT_name("B25")
	.dwattr DW$179, DW_AT_location[DW_OP_regx 0x3e]
DW$180	.dwtag  DW_TAG_assign_register, DW_AT_name("B26")
	.dwattr DW$180, DW_AT_location[DW_OP_regx 0x3f]
DW$181	.dwtag  DW_TAG_assign_register, DW_AT_name("B27")
	.dwattr DW$181, DW_AT_location[DW_OP_regx 0x40]
DW$182	.dwtag  DW_TAG_assign_register, DW_AT_name("B28")
	.dwattr DW$182, DW_AT_location[DW_OP_regx 0x41]
DW$183	.dwtag  DW_TAG_assign_register, DW_AT_name("B29")
	.dwattr DW$183, DW_AT_location[DW_OP_regx 0x42]
DW$184	.dwtag  DW_TAG_assign_register, DW_AT_name("B30")
	.dwattr DW$184, DW_AT_location[DW_OP_regx 0x43]
DW$185	.dwtag  DW_TAG_assign_register, DW_AT_name("B31")
	.dwattr DW$185, DW_AT_location[DW_OP_regx 0x44]
DW$186	.dwtag  DW_TAG_assign_register, DW_AT_name("AMR")
	.dwattr DW$186, DW_AT_location[DW_OP_regx 0x45]
DW$187	.dwtag  DW_TAG_assign_register, DW_AT_name("CSR")
	.dwattr DW$187, DW_AT_location[DW_OP_regx 0x46]
DW$188	.dwtag  DW_TAG_assign_register, DW_AT_name("ISR")
	.dwattr DW$188, DW_AT_location[DW_OP_regx 0x47]
DW$189	.dwtag  DW_TAG_assign_register, DW_AT_name("ICR")
	.dwattr DW$189, DW_AT_location[DW_OP_regx 0x48]
DW$190	.dwtag  DW_TAG_assign_register, DW_AT_name("IER")
	.dwattr DW$190, DW_AT_location[DW_OP_regx 0x49]
DW$191	.dwtag  DW_TAG_assign_register, DW_AT_name("ISTP")
	.dwattr DW$191, DW_AT_location[DW_OP_regx 0x4a]
DW$192	.dwtag  DW_TAG_assign_register, DW_AT_name("IN")
	.dwattr DW$192, DW_AT_location[DW_OP_regx 0x4b]
DW$193	.dwtag  DW_TAG_assign_register, DW_AT_name("OUT")
	.dwattr DW$193, DW_AT_location[DW_OP_regx 0x4c]
DW$194	.dwtag  DW_TAG_assign_register, DW_AT_name("ACR")
	.dwattr DW$194, DW_AT_location[DW_OP_regx 0x4d]
DW$195	.dwtag  DW_TAG_assign_register, DW_AT_name("ADR")
	.dwattr DW$195, DW_AT_location[DW_OP_regx 0x4e]
DW$196	.dwtag  DW_TAG_assign_register, DW_AT_name("FADCR")
	.dwattr DW$196, DW_AT_location[DW_OP_regx 0x4f]
DW$197	.dwtag  DW_TAG_assign_register, DW_AT_name("FAUCR")
	.dwattr DW$197, DW_AT_location[DW_OP_regx 0x50]
DW$198	.dwtag  DW_TAG_assign_register, DW_AT_name("FMCR")
	.dwattr DW$198, DW_AT_location[DW_OP_regx 0x51]
DW$199	.dwtag  DW_TAG_assign_register, DW_AT_name("GFPGFR")
	.dwattr DW$199, DW_AT_location[DW_OP_regx 0x52]
DW$200	.dwtag  DW_TAG_assign_register, DW_AT_name("DIER")
	.dwattr DW$200, DW_AT_location[DW_OP_regx 0x53]
DW$201	.dwtag  DW_TAG_assign_register, DW_AT_name("REP")
	.dwattr DW$201, DW_AT_location[DW_OP_regx 0x54]
DW$202	.dwtag  DW_TAG_assign_register, DW_AT_name("TSCL")
	.dwattr DW$202, DW_AT_location[DW_OP_regx 0x55]
DW$203	.dwtag  DW_TAG_assign_register, DW_AT_name("TSCH")
	.dwattr DW$203, DW_AT_location[DW_OP_regx 0x56]
DW$204	.dwtag  DW_TAG_assign_register, DW_AT_name("ARP")
	.dwattr DW$204, DW_AT_location[DW_OP_regx 0x57]
DW$205	.dwtag  DW_TAG_assign_register, DW_AT_name("ILC")
	.dwattr DW$205, DW_AT_location[DW_OP_regx 0x58]
DW$206	.dwtag  DW_TAG_assign_register, DW_AT_name("RILC")
	.dwattr DW$206, DW_AT_location[DW_OP_regx 0x59]
DW$207	.dwtag  DW_TAG_assign_register, DW_AT_name("DNUM")
	.dwattr DW$207, DW_AT_location[DW_OP_regx 0x5a]
DW$208	.dwtag  DW_TAG_assign_register, DW_AT_name("SSR")
	.dwattr DW$208, DW_AT_location[DW_OP_regx 0x5b]
DW$209	.dwtag  DW_TAG_assign_register, DW_AT_name("GPLYA")
	.dwattr DW$209, DW_AT_location[DW_OP_regx 0x5c]
DW$210	.dwtag  DW_TAG_assign_register, DW_AT_name("GPLYB")
	.dwattr DW$210, DW_AT_location[DW_OP_regx 0x5d]
DW$211	.dwtag  DW_TAG_assign_register, DW_AT_name("TSR")
	.dwattr DW$211, DW_AT_location[DW_OP_regx 0x5e]
DW$212	.dwtag  DW_TAG_assign_register, DW_AT_name("ITSR")
	.dwattr DW$212, DW_AT_location[DW_OP_regx 0x5f]
DW$213	.dwtag  DW_TAG_assign_register, DW_AT_name("NTSR")
	.dwattr DW$213, DW_AT_location[DW_OP_regx 0x60]
DW$214	.dwtag  DW_TAG_assign_register, DW_AT_name("EFR")
	.dwattr DW$214, DW_AT_location[DW_OP_regx 0x61]
DW$215	.dwtag  DW_TAG_assign_register, DW_AT_name("ECR")
	.dwattr DW$215, DW_AT_location[DW_OP_regx 0x62]
DW$216	.dwtag  DW_TAG_assign_register, DW_AT_name("IERR")
	.dwattr DW$216, DW_AT_location[DW_OP_regx 0x63]
DW$217	.dwtag  DW_TAG_assign_register, DW_AT_name("DMSG")
	.dwattr DW$217, DW_AT_location[DW_OP_regx 0x64]
DW$218	.dwtag  DW_TAG_assign_register, DW_AT_name("CMSG")
	.dwattr DW$218, DW_AT_location[DW_OP_regx 0x65]
DW$219	.dwtag  DW_TAG_assign_register, DW_AT_name("DT_DMA_ADDR")
	.dwattr DW$219, DW_AT_location[DW_OP_regx 0x66]
DW$220	.dwtag  DW_TAG_assign_register, DW_AT_name("DT_DMA_DATA")
	.dwattr DW$220, DW_AT_location[DW_OP_regx 0x67]
DW$221	.dwtag  DW_TAG_assign_register, DW_AT_name("DT_DMA_CNTL")
	.dwattr DW$221, DW_AT_location[DW_OP_regx 0x68]
DW$222	.dwtag  DW_TAG_assign_register, DW_AT_name("TCU_CNTL")
	.dwattr DW$222, DW_AT_location[DW_OP_regx 0x69]
DW$223	.dwtag  DW_TAG_assign_register, DW_AT_name("RTDX_REC_CNTL")
	.dwattr DW$223, DW_AT_location[DW_OP_regx 0x6a]
DW$224	.dwtag  DW_TAG_assign_register, DW_AT_name("RTDX_XMT_CNTL")
	.dwattr DW$224, DW_AT_location[DW_OP_regx 0x6b]
DW$225	.dwtag  DW_TAG_assign_register, DW_AT_name("RTDX_CFG")
	.dwattr DW$225, DW_AT_location[DW_OP_regx 0x6c]
DW$226	.dwtag  DW_TAG_assign_register, DW_AT_name("RTDX_RDATA")
	.dwattr DW$226, DW_AT_location[DW_OP_regx 0x6d]
DW$227	.dwtag  DW_TAG_assign_register, DW_AT_name("RTDX_WDATA")
	.dwattr DW$227, DW_AT_location[DW_OP_regx 0x6e]
DW$228	.dwtag  DW_TAG_assign_register, DW_AT_name("RTDX_RADDR")
	.dwattr DW$228, DW_AT_location[DW_OP_regx 0x6f]
DW$229	.dwtag  DW_TAG_assign_register, DW_AT_name("RTDX_WADDR")
	.dwattr DW$229, DW_AT_location[DW_OP_regx 0x70]
DW$230	.dwtag  DW_TAG_assign_register, DW_AT_name("MFREG0")
	.dwattr DW$230, DW_AT_location[DW_OP_regx 0x71]
DW$231	.dwtag  DW_TAG_assign_register, DW_AT_name("DBG_STAT")
	.dwattr DW$231, DW_AT_location[DW_OP_regx 0x72]
DW$232	.dwtag  DW_TAG_assign_register, DW_AT_name("BRK_EN")
	.dwattr DW$232, DW_AT_location[DW_OP_regx 0x73]
DW$233	.dwtag  DW_TAG_assign_register, DW_AT_name("HWBP0_CNT")
	.dwattr DW$233, DW_AT_location[DW_OP_regx 0x74]
DW$234	.dwtag  DW_TAG_assign_register, DW_AT_name("HWBP0")
	.dwattr DW$234, DW_AT_location[DW_OP_regx 0x75]
DW$235	.dwtag  DW_TAG_assign_register, DW_AT_name("HWBP1")
	.dwattr DW$235, DW_AT_location[DW_OP_regx 0x76]
DW$236	.dwtag  DW_TAG_assign_register, DW_AT_name("HWBP2")
	.dwattr DW$236, DW_AT_location[DW_OP_regx 0x77]
DW$237	.dwtag  DW_TAG_assign_register, DW_AT_name("HWBP3")
	.dwattr DW$237, DW_AT_location[DW_OP_regx 0x78]
DW$238	.dwtag  DW_TAG_assign_register, DW_AT_name("OVERLAY")
	.dwattr DW$238, DW_AT_location[DW_OP_regx 0x79]
DW$239	.dwtag  DW_TAG_assign_register, DW_AT_name("PC_PROF")
	.dwattr DW$239, DW_AT_location[DW_OP_regx 0x7a]
DW$240	.dwtag  DW_TAG_assign_register, DW_AT_name("ATSR")
	.dwattr DW$240, DW_AT_location[DW_OP_regx 0x7b]
DW$241	.dwtag  DW_TAG_assign_register, DW_AT_name("TRR")
	.dwattr DW$241, DW_AT_location[DW_OP_regx 0x7c]
DW$242	.dwtag  DW_TAG_assign_register, DW_AT_name("TCRR")
	.dwattr DW$242, DW_AT_location[DW_OP_regx 0x7d]
DW$243	.dwtag  DW_TAG_assign_register, DW_AT_name("CIE_RETA")
	.dwattr DW$243, DW_AT_location[DW_OP_regx 0x7e]
	.dwendtag DW$CU

