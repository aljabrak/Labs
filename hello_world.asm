.model small
.stack 100h
.data
       text1  db  'Hello$'
       text2  db  'World!$'
.code
main proc

mov ax, @data
mov ds,ax

mov dx, offset text1
mov ah,9
int 21h

mov ah,2
mov dl,0ah
int 21h

mov dx, offset text2
mov ah,9
int 21h

mov ah, 4ch
int 21h

main endp
end main
