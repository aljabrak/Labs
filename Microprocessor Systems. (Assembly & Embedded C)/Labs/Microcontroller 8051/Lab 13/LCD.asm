;LCD Interfacing.

org 00h
mov p1,#00000000b       ;making p1 output port
mov p3,#00000000b       ;making p3 output port
mov a,#38h              ;lcd working in 2 line 5*7 8-bit mode
mov p1,a                ;moving a into p2 output port
acall command
acall delay
mov a,#0eh              ;for display blinking cursor
mov p1,a                ;moving a into p2 output port
acall command
acall delay
mov a,#06h              ;shift cursor to first position
mov p1,a
acall command
acall delay
mov a,#80h              ;force cursor to begin from start position of first line
mov p1,a
acall command
acall delay
mov a,#14h              ;for 1 space
mov p1,a                ;moving a into p2 output port
acall command
acall delay
mov a,#'K'              ;moving ascii of a into acumulator
mov p1,a
acall data1
acall delay
mov a,#'E'
mov p1,a
acall data1
acall delay
mov a,#'Y'
mov p1,a
acall data1
acall delay
mov a,#'P'
mov p1,a
acall data1
acall delay
mov a,#'R'
mov p1,a
acall data1
acall delay
mov a,#'E'
mov p1,a
acall data1
acall delay
mov a,#'S'
mov p1,a
acall data1
acall delay
mov a,#'S'
mov p1,a
acall data1
acall delay
mov a,#':'
mov p1,a
acall data1
acall delay
next:                     ;first compairing the rows
 mov p2,#11111000b        ;moving logic 0 to p2.0,p2.1,p2.2
 jnb p2.6,row1            ;jump to row1 when bit is unset when bit is set go to next instruction
 jnb p2.5,row2            ;jump to row2 when bit is unset when bit is set go to next instruction
 jnb p2.4,row3            ;jump to row3 when bit is unset when bit is set go to next instruction
 jnb p2.3,row4            ;jump to row4 when bit is unset when bit is set go to next instruction

 jmp next                 ;continue process
row1:
 mov p2,#0ffh             ;making port 2 input port or logic 1
 mov p2,#00000111b        ;making port p2.0,p2.1,p2.2 logic 1
 jnb p2.2,l1              ;jump to l1 if p2.2 is not set and when set goto next intruction
 jnb p2.1,l2              ;jump to l2 if p2.1 is not set and when set goto next intruction
 jnb p2.0,l3              ;jump to l3 if p2.1 is not set and when set goto next intruction
 jmp next                 ;continue process
row2:
 mov p2,#0ffh             ;making port 2 input port or logic 1
 mov p2,#00000111b        ;making port p2.0,p2.1,p2.2 logic 0
 jnb p2.2,l4              ;jump to l4 if p2.2 is not set and when set goto next intruction
 jnb p2.1,l5              ;jump to l5 if p2.1 is not set and when set goto next intruction
 jnb p2.0,l6              ;jump to l6 if p2.1 is not set and when set goto next intruction
 jmp next                 ;continue process
row3:
 mov p2,#0ffh             ;making port 2 input port or logic 1
 mov p2,#00000111b        ;making port p2.0,p2.1,p2.2 logic 0
 jnb p2.2,l7              ;jump to l7 if p2.2 is not and when set goto next instruction
 jnb p2.1,l8              ;jump to l8 if p2.1 is not and when set goto next instruction
 jnb p2.0,l9              ;jump to l9 if p2.1 is not and when set goto next instruction
 jmp next                 ;continue process
row4:
 mov p2,#0ffh             ;making port 2 input port or logic 1
 mov p2,#00000111b        ;making port p2.0,p2.1,p2.2 logic 0
 jnb p2.2,star            ;jump to star if p2.2 is not and when set goto next instruction
 jnb p2.1,zero            ;jump to zero if p2.1 is not and when set goto next instruction
 jnb p2.0,hash            ;jump to hash if p2.1 is not and when set goto next instruction
 jmp next                 ;continue process
l1:
mov a,#'1'
acall write_disp
jmp next
l2:
mov a,#'2'
acall write_disp
jmp next
l3:
 mov a,#'3'
acall write_disp
jmp next
l4:
 mov a,#'4'
acall write_disp
jmp next
l5:
 mov a,#'5'
acall write_disp
jmp next
l6:
 mov a,#'6'
acall write_disp
jmp next
l7:
 mov a,#'7'
acall write_disp
jmp next
l8:
 mov a,#'8'
acall write_disp
jmp next
l9:
 mov a,#'9'
acall write_disp
jmp next
star:
 mov a,#'*'
acall write_disp
jmp next
zero:
 mov a,#'0'
acall write_disp
jmp next
hash:
 mov a,#'#'
acall write_disp
 jmp next
clr_disp:
mov a,#10h            ;for clearing dispaly screen
mov p1,a
acall command
acall delay
 ret
write_disp:
mov p1,a
acall data1
acall delay
acall clr_disp
ret


;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;subroutine : command for commanding LCD;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

command:
 clr p3.0                  ;RS (RS=register selection)---> p2.0 for command mode of lcd RS=0
 clr p3.1                  ;R/W'(read/write selections)---> p2.1 for command mode of lcd R/W'=0
                           ;should be a pulse of at least 450msec at E (enable selection) --> p2.2 in data as well as
 ; command mode
 setb p3.2                 ;giving logic '1' to p2.2
 acall delay               ;calling subroutine
 clr p3.2                  ;giving logic '0' to p2.2
 ret
;subroutine : data for LCD
data1:
 setb p3.0                 ;RS (RS=register selection)---> p2.0 for data mode of lcd RS=1
 clr p3.1                  ;R/W'(read/write selections)---> p2.1 for data mode of lcd R/W'=0
                           ;should be a pulse of atleast 450msec at E (enable selection) --> p2.2 in data as well as
 ;command mode
 setb p3.2
 acall delay
 clr p3.2
 ret
delay:
mov r5,#255
ML1:
mov r6,#2
ML2:
mov r7,#70                ;this will give a delay of 563uSec
djnz r7,$                 ;$ sign will tell microcontroller to repeat instruction on same location untill
                          ;the condition is achieved
djnz r6,ML2
djnz r5,ML1
ret
end
