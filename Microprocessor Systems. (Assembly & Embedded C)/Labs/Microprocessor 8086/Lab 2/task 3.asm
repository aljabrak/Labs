.model small
.stack 100ah
.data
.code
main proc

mov ah,2
mov bh,'a'

sub bh,32
mov dl,bh
mov ah,2
int 21h

mov ah,4ch
int 21h
main endp
end main
