;writestring
Include irvine32.inc
.stack 100h
.data
text BYTE "Assembly Language x86",0
.code

main proc
call clrscr
call dumpregs

mov edx,OFFSET text
call writestring
exit

main ENDP
end main
