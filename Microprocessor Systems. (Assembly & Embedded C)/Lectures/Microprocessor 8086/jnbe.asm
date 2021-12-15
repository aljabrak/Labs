Include irvine32.inc
.stack 100h
.data

a DWORD ?
b DWORD ?
text1 BYTE "a <= b",0
text2 BYTE "a > b",0
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

if_condition:
    mov eax,a
    mov ebx,b
    cmp eax,ebx
    jnbe else_condition                ;jump if not below or equal: a > b.
    mov edx,OFFSET text1
    call writestring
    jmp next


else_condition:
      mov edx,OFFSET text2
      call writestring

next:
     

exit

main ENDP
end main
