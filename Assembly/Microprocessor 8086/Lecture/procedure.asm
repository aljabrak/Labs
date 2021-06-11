Include irvine32.inc
.stack 100h
.data
text1 BYTE "Microprocessor 8086.",0
text2 BYTE "Irvine32.inc",0
.code

main proc
call clrscr
call dumpregs

call GetMSeconds        ;EAX = milliseconds since midnight.
mov eax,lightblue
call SetTextColor
mov edx,OFFSET text1
call writestring
call crlf
mov eax,1000            ;1000 milliseconds.
call delay              ;pause for 1 second.
mov edx,OFFSET text2
call writestring
call crlf
mov eax,red
call SetTextColor
call WaitMsg            ;Press [Enter] to Continue...
mov eax,blue*10
call SetTextColor
call dumpregs

exit

main ENDP
end main
