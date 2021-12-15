;Logical Shift Left and Right.
Include irvine32.inc
.stack 100h
.data
.code

main proc

call clrscr        ;Clear Screen.
call dumpregs
call crlf

mov eax,20          
call writebin      ;writes 20 in binary: 00010100.

shl eax,1          ;shift left by 1 unit in binary.
                   ;shifting 'n' units multiplies the operand a*2^(n).
call crlf          ;next line command.
call writebin      ;writes 00101000 = 40 in decimal.

shr eax,2          ;shift left by 2 unit in binary.
                   ;shifting 'n' units divides the operand a/2^(n).
call crlf          ;next line command.
call writebin      ;writes 00001010 = 10 in decimal.

exit

main ENDP
end main
