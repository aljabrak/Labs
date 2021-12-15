;Rotate Left and Right.
Include irvine32.inc
.stack 100h
.data
.code

main proc

call clrscr        ;Clear Screen.
call dumpregs
call crlf

mov eax,65         ;65 = 0100 0001
call writebin

rol eax,1          ;Rotate Left, rotates Highest Bit to Lowest Bit (copies Highest Bit to Lowest Bit and to carry flag).
call crlf          ;next line command
call writebin      ;writes 1000 0010

ror eax,2          ;Rotate Left, rotates Lowest Bit to Highest Bit (copies Lowest Bit to Highest Bit and to carry flag).
call crlf          ;next line command
call writebin      ;writes 1000 0000 0000 0000 0000 0000 0010 0000

exit

main ENDP
end main
