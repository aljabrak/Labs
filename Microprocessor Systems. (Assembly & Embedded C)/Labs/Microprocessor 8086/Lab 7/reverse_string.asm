Include irvine32.inc
.model small
.stack 100h

.data
prompt1 db "Original String : ",0
prompt2 db "Reversed String : ",0
var1 db "This is lab week 9 task 1",0
.code
Main Proc ;instructions go here
mov edx,offset prompt1
call writestring
mov edx,offset var1
call writestring
call crlf

mov esi,0
mov ecx,lengthof var1
dec ecx
L1:
movzx ax,var1[esi] ;moving to register before pushing on stack
push ax
inc esi
loop L1

mov esi,0
mov ecx,lengthof var1
dec ecx

L2:
;pop returns last element first so string is reversed
pop ax 
mov var1[esi],al
inc esi
loop L2

mov edx,offset prompt2
call writestring
mov edx,offset var1
call writestring

Exit
Main endp
End main
