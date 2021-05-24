Include irvine32.inc
.stack 100h
.data  
val1 DWORD 10000h
val2 DWORD 40000h
val3 DWORD 20000h
finalval DWORD ?              ;variable declaration goes here.

.code

main proc            ;instructions go here.

call clrscr          ;clear the screen.

call dumpregs        ;displays the results on the screen by displaying all registers values.

mov eax,val1
add eax,val2
sub eax,val3
mov finalval,eax

call dumpregs        

exit
main endp
end main
