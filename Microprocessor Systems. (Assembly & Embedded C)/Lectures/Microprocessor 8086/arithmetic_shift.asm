;Shift Arithmetic Left and Right.
Include irvine32.inc
.stack 100h
.data
.code

main proc

call clrscr        ;Clear Screen.
call dumpregs
call crlf

mov eax,-10          
call writebin      ;writes -10 in binary: 1111 1111 1111 1111 1111 1111 1111 0110.

sal eax,1          ;shift arithmetic left is same as shift left.
call crlf          ;next line command.
call writebin      ;writes 1111 1111 1111 1111 1111 1111 1110 1100.

sar eax,2          ;fills the newly created sign bit with the copy of sign bit.
                   ;shift arithmetic right preserves the sign of number.
call crlf          ;next line command.
call writebin      ;writes 1111 1111 1111 1111 1111 1111 1111 1011.

exit

main ENDP
end main
