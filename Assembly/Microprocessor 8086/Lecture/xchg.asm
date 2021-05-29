Include irvine32.inc
.stack 100h
.data 
variable1 DWORD 10000h
variable2 DWORD 20000h
.code

main proc           

call clrscr          
call dumpregs       

mov eax,variable1
call dumpregs

mov edx,variable2
call dumpregs

xchg eax,edx         ;exchanges the values of Register.
call dumpregs

exit
main endp
end main
