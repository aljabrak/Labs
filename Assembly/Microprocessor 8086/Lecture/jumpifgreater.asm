Include irvine32.inc
.stack 100h
.data
.code

main proc
call clrscr

call readdec
mov ebx,eax

call readdec
mov ecx,eax

;  if(a<=b){
;           c = 10;
;           }
;  else{
;       d = 6;
;       }


cmp ebx,ecx
jg elif       ;jump if greater.

mov eax,10
call writedec
call crlf
jmp next

elif:
      mov eax,6
      call writedec
      call crlf

next:

exit

main ENDP
end main
