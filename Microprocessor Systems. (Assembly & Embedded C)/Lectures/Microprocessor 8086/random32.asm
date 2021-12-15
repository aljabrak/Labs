;Random32.

Include irvine32.inc
.stack 100h
.data
.code

main proc
call clrscr
call dumpregs

mov ecx,10                   ;loop counter.
L:         
  call random32             ;eax = random 32-bit integer.
  call writedec             ;write in decimal.
  call crlf                 ;one number per line.
  loop L
exit

main ENDP
end main
