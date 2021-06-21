;Random Range.

Include irvine32.inc
.stack 100h
.data
.code

main proc
call clrscr
call dumpregs

mov ecx,5                   ;loop counter.
L:         
  mov eax,100               ;range 0 to 99.
  call randomrange          ;eax = random integer.
  call writedec             ;write in decimal.
  call crlf                 ;one number per line.
  loop L
exit

main ENDP
end main
