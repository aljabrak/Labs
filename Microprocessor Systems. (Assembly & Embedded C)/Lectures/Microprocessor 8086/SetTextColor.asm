Include irvine32.inc
.stack 100h
.data
text BYTE "Microprocessor 8086.",0
.code

main proc
call clrscr
call dumpregs

mov eax,lightblue*10
call SetTextColor
mov edx,OFFSET text
call writestring
exit

main ENDP
end main
