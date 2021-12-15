.model small
.stack 100h
.data
.code
main proc

mov ah,2
add ah,48
mov dl,ah
mov ah,2
int 21h

mov dl,0ah
int 21h
mov dl,0dh
int 21h

mov bh,3
add bh,48
mov dl,bh
mov ah,2
int 21h

mov dl,0ah
int 21h
mov dl,0dh
int 21h


add ch,ah
add ch,48
mov dl,ch
mov ah,2
int 21h

mov dl,0ah
int 21h
mov dl,0dh
int 21h


add dh,ah
add dh,48
mov dl,dh
mov ah,2
int 21h

mov dl,0ah
int 21h
mov dl,0dh
int 21h


mov bh,3
add ah,bh
add ah,48
mov dl,ah
mov ah,2
int 21h

mov dl,0ah
int 21h
mov dl,0dh
int 21h

mov ah,5
add bh,ah
add bh,48
mov dl,bh
mov ah,2
int 21h

mov ah,4ch
int 21h

main endp
end main
