Include irvine32.inc
.stack 100h
.data 
arrayW WORD 1020h,3040h,5060h 
arrayD DWORD 1,2,3,4 
.code

main proc           

call clrscr          
call dumpregs       

mov dx,arrayW+2
mov eax,[arrayD+4]
call dumpregs


exit
main endp
end main
