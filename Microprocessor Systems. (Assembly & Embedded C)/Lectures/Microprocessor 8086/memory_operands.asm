Include irvine32.inc
.stack 100h
.data  
value DWORD 10000h 
.code

main proc           

call clrscr          
call dumpregs       

mov eax,[value]
mov edx,value
call dumpregs

exit
main endp
end main
