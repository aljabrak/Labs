.model small
.stack 100h
.data
        alphabet  db  65
.code
main  proc

mov ax,@data
mov ds,ax

mov cx,26
mov dl,65

L1:
mov ah,2
int 21h
inc dl
LOOP L1

mov ah,4ch
int 21h

main endp
end main
