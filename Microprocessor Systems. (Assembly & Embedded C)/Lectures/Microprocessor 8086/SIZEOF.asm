Include irvine32.inc
.stack 100h
.data
array1 WORD 30 DUP(?),0,0
array2 WORD 5 DUP(3 DUP(?))      ;15 DUP(?)
array3 DWORD 1,2,3,4
digit_ BYTE "123456",0
.code

main proc
call clrscr
call dumpregs

mov eax, SIZEOF array1 ;2x32 = 40h
mov ebx, SIZEOF array2 ;2x15 = 1Eh
mov ecx, SIZEOF array3 ;4x4 = 10h
mov edx, SIZEOF digit_ ;1x7 = 07h
call dumpregs

exit
main ENDP
end main
