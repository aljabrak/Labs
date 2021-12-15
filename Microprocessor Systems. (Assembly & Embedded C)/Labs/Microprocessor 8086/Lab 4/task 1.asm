Include irvine32.inc
.model small
.stack 100h
.data                ;variable declaration goes here.
.code

main proc            ;instructions go here.

call clrscr          ;clear the screen.

call dumpregs        ;displays the results on the screen by displaying all registers values.

mov eax,0h           ;initialize EAX with value 0.

call dumpregs        

mov al,0ah
call writechar

call dumpregs

mov al,'?'
call writechar

call readchar
mov dl,03h

mov al,0ah
call writechar

mov al,dl
call writechar

call dumpregs

call waitmsg

exit
main endp
end main
