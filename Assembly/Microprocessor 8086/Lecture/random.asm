;Random numbers.
Include irvine32.inc
.stack 100h
.data
.code

main proc
call clrscr
call dumpregs

mov ecx,5                   ;loop counter.
L:         
  mov eax,3000h              ;range 0 to 3000h.
  call randomrange          ;eax = random integer. (random32 for 32 bit random number.)
  call writebin             ;write in binary.
  call crlf                 ;one number per line.
  loop L
exit

main ENDP
end main
