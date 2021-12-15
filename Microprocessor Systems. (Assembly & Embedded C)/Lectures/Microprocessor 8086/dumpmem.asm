Include irvine32.inc
.stack 100h
.data
array WORD 2 DUP(0, 10, 1234, 3CFFH)
.code

main proc
call clrscr
call dumpregs

mov esi,OFFSET array
mov ecx,LENGTHOF array
mov ebx, TYPE array
call dumpmem
exit

main ENDP
end main
