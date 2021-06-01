Include irvine32.inc
.stack 100h
.data
variable1 BYTE ?
variable2 WORD ?
variable3 DWORD ?
variable4 QWORD ?
.code

main proc
call clrscr
call dumpregs
                        ;TYPE operator tells the size in bytes of single element in data declaration.
mov eax, TYPE variable1 ;eax = 1
mov ebx, TYPE variable2 ;ebx = 2
mov ecx, TYPE variable3 ;ecx = 4
mov edx, TYPE variable4 ;edx = 8
call dumpregs

exit
main ENDP
end main
