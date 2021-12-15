Include irvine32.inc
.stack 100h
.data
.code

main proc
call clrscr
call dumpregs

call readint
mov ebx,eax
call readint
cmp eax,ebx       ;compare EAX with EBX.
call dumpregs
 


exit

main ENDP
end main
