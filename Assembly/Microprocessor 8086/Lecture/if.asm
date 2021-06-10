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

if_condition:
    mov eax,a
    mov ebx,b
    cmp eax,ebx            ;compare a & b; (a - b)
    jne else_condition     ;jump if not equal ==> (a != b).
    mov eax,1              ;(a == b) print 1.
    call writedec
    jmp next


else_condition:
      mov eax,2           ;(a != b) print 2.
      call writedec

next:
     

exit

main ENDP
end main
