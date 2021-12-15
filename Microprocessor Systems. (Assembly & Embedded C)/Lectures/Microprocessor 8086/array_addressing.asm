Include irvine32.inc
.stack 100h
.data
variable DWORD 1000h,2000h,3000h,4000h
.code

main proc

call clrscr              ;clear Screen.
mov eax,[variable]       ;1000h
call writehex
call crlf
mov eax,variable+4       ;2000h
call writehex
call crlf
mov eax,[variable+8]       ;3000h
call writehex
call crlf
mov eax,variable[12]       ;4000h
call writehex
call crlf

exit

main ENDP
end main
