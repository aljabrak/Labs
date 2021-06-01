Include irvine32.inc
.stack 100h
.data
variable DWORD 12345678h
array BYTE 00h,10h,20h,30h
.code

main proc
call clrscr
call dumpregs
                          ;Syntax: TYPE PTR variable
                          ;From large source to smaller destination
mov al, BYTE PTR variable ;eax = 78h
mov bx, WORD PTR variable ;ebx = 5678h
mov ecx, DWORD PTR variable ;ecx = 12345678h
mov edx, DWORD PTR array ;edx = 30201000h
call dumpregs

exit
main ENDP
end main
