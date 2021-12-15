;xor calculator.
Include irvine32.inc
.stack 100h
.data
a DWORD ?
b DWORD ?
.code

main proc
call clrscr
call dumpregs

call readdec
mov a,eax
call crlf
call readdec
mov b,eax
call crlf

mov eax,a
mov ebx,b
xor eax,ebx
call writebin
call crlf
call writedec
call crlf
call writehex
call crlf

exit

main ENDP
end main
