Include irvine32.inc
.stack 100h
.data
a DWORD ?
even_num BYTE "The number is Even!",0
odd_num BYTE "The number is Odd!",0
.code
main proc
call clrscr
call dumpregs

call readdec           ;user input.
mov a,eax
call crlf
L:
    test eax,1         ;test bit zero is 1.
    jz L2

L1:
    mov edx,OFFSET odd_num
    call writestring
    exit

L2:
    mov edx,OFFSET even_num
    call writestring

exit

main ENDP
end main
