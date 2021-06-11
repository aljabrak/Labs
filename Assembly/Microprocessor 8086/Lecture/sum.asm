;sum
Include irvine32.inc
.stack 100h
.data
a DWORD ?
b DWORD ?
n DWORD ?
s DWORD ?
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
call readdec
mov n,eax
call crlf

mov eax,a
mov ebx,b
mov ecx,n

call sum
mov s,eax
mov eax,s
call writedec

exit

main ENDP

sum PROC
add eax,ebx
add eax,ecx
ret
sum ENDP

end main
