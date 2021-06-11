
;Shift Left & Right Double.
Include irvine32.inc
.stack 100h
.data
variable DWORD  9BA6h
.code

main proc

call clrscr        ;clear Screen.
call dumpregs
call crlf
mov eax,0000h

mov eax,variable
call writehex
call crlf

mov eax,0AC36h
call writehex
shld variable, eax, 4        ;replace the lowest 4 bits of variable with the highest 4 bits of eax.
call crlf

mov eax,variable
call writehex                ;writes 0000BA6A.
call crlf

mov eax,0000h
mov ax,234Bh
mov dx,7654h
shrd ax, dx, 4              ;replace the highest 4 bits of variable with the lowest 4 bits of eax.
call writehex               ;writes 00004234.

exit

main ENDP
end main
