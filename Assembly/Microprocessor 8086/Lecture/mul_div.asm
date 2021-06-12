;Multiplication and Division (Unsigned).
Include irvine32.inc
.stack 100h
.data
a DWORD ?
b DWORD ?
m DWORD ?
d DWORD ?
r DWORD ?
text1 BYTE "a = ",0
text2 BYTE "b = ",0
text3 BYTE "c = ",0
text4 BYTE "d = ",0
product BYTE "a x b = ",0 
division BYTE "c/d = ",0
remainder BYTE "remainder: ",0
.code

main proc

call clrscr              ;clear Screen.
call dumpregs
call crlf

;Multiplication.
mov edx,OFFSET text1
call writestring         ;a = 
call readdec             ;user input (number 1).
mov a,eax                ;move number 1 value to a.
call crlf                ;next line command.
mov edx,OFFSET text2
call writestring         ;b = 
call readdec             ;user input (number 2).
call crlf
mul a                    ;multiplies operand a with eax (MUL multiplies operand with al,ax and eax).
mov edx,OFFSET product
call writestring         ;a x b = 
call writedec            ;writes the product: a*eax.
call crlf
call crlf

;Division.
mov edx,OFFSET text3
call writestring         ;c =
call readdec             ;user input (number 1).
mov m,eax
call crlf
mov edx,OFFSET text4
call writestring         ;d = 
call readdec             ;user input (number 2).
mov d,eax
mov eax,m
call crlf
xor edx,edx              ;edx = 0.
div d                    ;eax div d, eax = c.
mov r,edx                ;move edx in r. edx = remainder. 
mov edx,0        
mov edx,OFFSET division
call writestring         ;c/d =
mov d,eax                ;d = eax = c div d.
mov eax,d                ;eax div d moved to eax.
call writedec            ;writes c/d in decimal.
call crlf
mov edx,OFFSET remainder
call writestring         ;remainder =
mov eax,r                ;eax = r = edx (remainder).
call writedec


exit

main ENDP
end main
