    .ref    _c_int00
    .global RESET_RST
        
FLASH_START   .equ    0x90000400        ;flash start address
CODE_START    .equ    0x00000400        ;start of non boot code
CODE_SIZE     .equ    0x00003000        ;application code size in byte
  
	.sect "vectors"
RESET_RST:
    
    NOP  ; mvkl .S2 _c_int00, B0
    NOP  ; mvkh .S2 _c_int00, B0
    NOP  ; B    .S2 B0
	NOP
	NOP
	NOP
	NOP
    NOP
    
NMI_RST:    
    NOP
	NOP
	NOP
	NOP
	NOP
	NOP
	NOP
	NOP

RESV1:
    NOP
	NOP
	NOP
	NOP
	NOP
	NOP
	NOP
	NOP

RESV2:
    NOP
	NOP
	NOP
	NOP
	NOP
	NOP
	NOP
	NOP

INT4:
    NOP
	NOP
	NOP
	NOP
	NOP
	NOP
	NOP
	NOP

INT5:
    NOP
	NOP
	NOP
	NOP
	NOP
	NOP
	NOP
	NOP
                   
INT6:
    NOP
	NOP
	NOP
	NOP
	NOP
	NOP
	NOP
	NOP

INT7:
    NOP
	NOP
	NOP
	NOP
	NOP
	NOP
	NOP
	NOP

INT8:
    NOP
	NOP
	NOP
	NOP
	NOP
	NOP
	NOP
	NOP

INT9:
    NOP
	NOP
	NOP
	NOP
	NOP
	NOP
	NOP
	NOP

INT10:
    NOP
	NOP
	NOP
	NOP
	NOP
	NOP
	NOP
	NOP

INT11:
    NOP
	NOP
	NOP
	NOP
	NOP
	NOP
	NOP
	NOP

INT12:
    NOP
	NOP
	NOP
	NOP
	NOP
	NOP
	NOP
	NOP

INT13:
    NOP
	NOP
	NOP
	NOP
	NOP
	NOP
	NOP
	NOP

INT14:
    NOP
	NOP
	NOP
	NOP
	NOP
	NOP
	NOP
	NOP

INT15:
    NOP 
	NOP
	NOP
	NOP
	NOP
	NOP
	NOP
	NOP
 
	.sect "bootload"
	
_boot_start:
    mvkl  FLASH_START,B4 ;flash start address ->B4
    mvkh  FLASH_START,B4   
      	
	mvkl  CODE_START,A4 ;apps code start address ->A4
	mvkh  CODE_START,A4
	zero  A1
	
_boot_loop1:
	ldb   *B4++,B5       ; flash read
	mvkl  CODE_SIZE-4,B6 ; B6 = BOOT_SIZE -1024
	
	add   1,A1,A1          ;A1+=1,inc outer counter
	||    mvkh  CODE_SIZE-4,B6
	
	cmplt  A1,B6,B0
	nop    
	stb   B5,*A4++
	[B0]  b     _boot_loop1
	nop   5
	
	mvkl .S2 _c_int00, B0
	mvkh .S2 _c_int00, B0
	B    .S2 B0
	nop   5	


