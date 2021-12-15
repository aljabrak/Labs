Include irvine32.inc
.stack 100h
.data

time WORD 0101001001110111b
sec BYTE ? 
min BYTE ? 
hour BYTE ?
msg BYTE "Time hh:mm:ss = ",0

.code

ShowFileTime PROC

mov bh,ah
shr bh,3
mov hour,bh
 
mov bx,ax
shr bx,5
and bl,00111111b
mov min,bl

and al,00011111b
mov ah,0
mov bl,2
mul bl 
mov sec,al

mov edx,offset msg
call writestring

mov al,hour
xor ah,ah
mov bl,10
div bl
add al,48
call writechar
mov al,ah
add al,48
call writechar

mov al,':'
call writechar

mov al,min
xor ah,ah
mov bl,10
div bl
add al,48
call writechar
mov al,ah
add al,48
call writechar

mov al,':'
call writechar

mov al,sec
xor ah,ah
mov bl,10 
div bl
add al,48
call WriteChar 
mov al,ah
add al,48
call writechar

ret
ShowFileTime ENDP

main PROC


mov ax,time
call ShowFileTime

exit

main ENDP
END main