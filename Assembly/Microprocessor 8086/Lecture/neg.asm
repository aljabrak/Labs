Include irvine32.inc
.stack 100h
.data
value DWORD  20
.code

main proc

call clrscr              ;clear screen.
NEG value                ;Negates value.
mov eax,value
call writeint            ;writes -20 (integer).

exit

main ENDP
end main
