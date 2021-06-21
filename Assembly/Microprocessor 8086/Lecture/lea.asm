Include irvine32.inc
.stack 100h
.data
text BYTE "Hello World!",0
.code

main proc
call clrscr
mov eax, blue + green
call SetTextColor
lea edx,text                 ;lea loads the address of text in EDX.
call writestring
call crlf

exit

main ENDP
end main
