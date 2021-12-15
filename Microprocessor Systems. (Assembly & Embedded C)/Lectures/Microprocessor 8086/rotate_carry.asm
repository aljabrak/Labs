;Rotate Carry Left and Right.
Include irvine32.inc
.stack 100h
.data
.code

main proc

call clrscr        ;clear Screen.
call dumpregs
call crlf

clc                 ;clear carry.
mov eax,88h         ;88h = 0000 0000 0000 0000 0000 0000 1000 1000.
call writebin
call crlf
rcl eax,1           ;rotate carry left: highest bit is set carry and lowest bit is set with previous.
call writebin       ;writes 0000 0000 0000 0000 0000 0001 0001 0000.
call crlf
rcl eax,2           ;rotate carry left.
call writebin       ;writes 0000 0000 0000 0000 0000 0100 0100 0000. 
call crlf
rcr eax,4           ;rotate carry right: lowest bit is set carry and highest bit is set with previous.
call writebin       ;writes 0000 0000 0000 0000 0000 0000 0100 0100. 

exit

main ENDP
end main
