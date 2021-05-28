Include irvine32.inc
.stack 100h
.data 
COUNT DWORD 500
.code

main proc           

call clrscr          
call dumpregs       

mov eax,COUNT
call dumpregs


exit
main endp
end main
