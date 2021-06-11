Include irvine32.inc
.stack 100h
.data
.code

main proc
call clrscr
call dumpregs

mov eax,-1000
call writehex            ;writes in Hexadecimal.
call crlf                ;next line command.
call writedec            ;writes in decimal.
call crlf
call writebin            ;writes in binary.
call crlf
call writeint            ;writes in integer.
call crlf
exit

main ENDP
end main
