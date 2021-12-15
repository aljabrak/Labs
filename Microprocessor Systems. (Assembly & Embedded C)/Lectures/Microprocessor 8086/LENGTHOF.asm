Include irvine32.inc
.stack 100h
.data
array1 WORD 30 DUP(?),0,0
array2 WORD 5 DUP(3 DUP(?))     ;15 DUP(?)
array3 DWORD 1,2,3,4
digit_ BYTE "123456",0
.code

main proc
call clrscr
call dumpregs

mov eax, LENGTHOF array1 ;32 = 20h
mov ebx, LENGTHOF array2 ;15 = 0Fh
mov ecx, LENGTHOF array3 ;04 = 04h
mov edx, LENGTHOF digit_ ;07 = 07h
call dumpregs

exit
main ENDP
end main
