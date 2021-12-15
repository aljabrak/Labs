.model small
.stack 100h
.data
        count  db  48
.code
main  proc

mov ax,@data
mov ds,ax

mov cx,10
mov dl,48

L1:
mov ah,2
int 21h
inc dl
LOOP L1

mov ah,4ch
int 21h

main endp
end main
