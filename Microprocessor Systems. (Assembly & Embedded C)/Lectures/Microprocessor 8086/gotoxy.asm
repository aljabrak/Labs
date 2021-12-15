Include irvine32.inc
.stack 100h
.data
text BYTE "Microprocessor 8086",0
.code

main proc
call clrscr
call dumpregs

mov dh,10              ;row number = 10
mov dl,10              ;column number = 10
call gotoxy            ;go to row x and column y
mov edx,OFFSET text
call writestring
call crlf

exit

main ENDP
end main
