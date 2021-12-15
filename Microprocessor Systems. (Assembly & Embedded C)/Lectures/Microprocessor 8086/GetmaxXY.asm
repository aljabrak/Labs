Include irvine32.inc
.stack 100h
.data
row BYTE ?
column BYTE ?
.code

main proc
call clrscr
call dumpregs

call GetMaxXY           ;Returns the number of rows and columns in Console Window buffer.
mov row,dh
call writedec
call crlf
mov column,dl
call writedec

exit

main ENDP
end main
