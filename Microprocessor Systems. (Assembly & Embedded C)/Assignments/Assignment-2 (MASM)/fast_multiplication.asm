Include macros.inc
Include irvine32.inc
.stack 100h
.data
string  BYTE  "Fast  Multiplication  Program",0dh,0ah,0dh,0ah,0

.code

FastMultiply  PROC

mov  edx,0
mov  ecx,32

L1:

test  ebx,1
jz  L2
add  edx,eax
jc  L3

L2:
shr  ebx,1
shl  eax,1
jc  L3
loop  L1
L3:
mov  eax,edx
ret 
FastMultiply ENDP

main  PROC
call  clrscr
mov  edx,  offset  string
call  WriteString

 
L1:

mWrite  "Enter  an  unsigned  integer  (0  to  quit):  "
call  readdec
.IF  CARRY?
mwrite  <"Error:  Integer  is  out  of  range",0dh,0ah>
jmp  L1
 
.ELSE
mov  ebx,eax
 
.ENDIF
cmp  eax,0
je  quit
 
L2:

mwrite  "Enter  an  unsigned  integer:  "
call  readdec
.IF  CARRY?
mwrite  <"Error:  Integer  is  out  of  Range",0dh,0ah>
jmp  L2
 
.ENDIF

mwrite  <" 	",0dh,0ah>
call  FastMultiply

mwrite  "The  Product  is	"
call  writedec
call  crlf
call  crlf
jmp  L1

quit:
exit

main  ENDP
END main
