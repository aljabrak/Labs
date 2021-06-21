Include irvine32.inc
.stack 100h
.data
text BYTE 'Hello World!',0
ese  BYTE "I'm preparing for ESEs... ;(",0
.code

main proc

call clrscr              ;clear Screen.
mov edx,OFFSET text
call writestring
call crlf
mov edx,OFFSET ese
call writestring
call crlf

exit

main ENDP
end main
