;Analog Clock on TASM.


.model small
.stack 100h
.data
        Second_Angle    dw      ?
	Minute_Angle	dw      ?
	Hour_Angle	dw      ?
        Minute          db      ?
	Second          db      ?
	hour            db      ?
        check           db      0
        x_center        dw      300
        y_center        dw      250
        CircleRadius    dw      200
        sin_x           dw      ?
        sin_xx          dw      ?
        x               dw      ?
        y               dw      ?
        ExtricateMode       db      ?
	AngleCheck      db      ?
	
	
.code
main proc
mov ax,@data
mov ds,ax
mov ah,0Fh
int 10h
mov ExtricateMode,al   ;extricating video mode

mov ah,0
mov al,11h
int 10h
MainLoop:
mov dx,y_center
mov cx,x_center
call Dial
call clockBoundary
call centre_Point
call Get_time
call HourAngle
call HourHand
call MinuteAngle
call MinuteHand
call SecondAngle
call SecondHand


;http://vitaly_filatov.tripod.com/ng/asm/asm_026.13.html
mov cx,0Fh     ;1 sec delay
mov dx,4240h
mov ah,86h
int 15h
call clrscr

loop MainLoop
main endp

Dial proc
mov dh,5
mov dl,36
mov ah,02h
mov bh,0
int 10h
mov ah,2
mov dl,'X'
int 21h
mov dh,5
mov dl,37
mov ah,02h
mov bh,0
int 10h
mov ah,2
mov dl,'I'
int 21h

mov dh,5
mov dl,38
mov ah,02h
mov bh,0
int 10h
mov ah,2
mov dl,'I'
int 21h

mov dh,6
mov dl,48
mov ah,02h
mov bh,0
int 10h
mov ah,2
mov dl,'I'
int 21h

mov dh,10
mov dl,55
mov ah,02h
mov bh,0
int 10h
mov ah,2
mov dl,'I'
int 21h

mov dh,10
mov dl,56
mov ah,02h
mov bh,0
int 10h
mov ah,2
mov dl,'I'
int 21h

mov dh,15
mov dl,58
mov ah,02h
mov bh,0
int 10h
mov ah,2
mov dl,'I'
int 21h

mov dh,15
mov dl,59
mov ah,02h
mov bh,0
int 10h
mov ah,2
mov dl,'I'
int 21h

mov dh,15
mov dl,60
mov ah,02h
mov bh,0
int 10h
mov ah,2
mov dl,'I'
int 21h

mov dh,21
mov dl,55
mov ah,02h
mov bh,0
int 10h
mov ah,2
mov dl,'I'
int 21h

mov dh,21
mov dl,56
mov ah,02h
mov bh,0
int 10h
mov ah,2
mov dl,'V'
int 21h

mov dh,25
mov dl,48
mov ah,02h
mov bh,0
int 10h
mov ah,2
mov dl,'V'
int 21h

mov dh,26
mov dl,37
mov ah,02h
mov bh,0
int 10h
mov ah,2
mov dl,'V'
int 21h

mov dh,26
mov dl,38
mov ah,02h
mov bh,0
int 10h
mov ah,2
mov dl,'I'
int 21h

mov dh,25
mov dl,27
mov ah,02h
mov bh,0
int 10h
mov ah,2
mov dl,'V'
int 21h

mov dh,25
mov dl,28
mov ah,02h
mov bh,0
int 10h
mov ah,2
mov dl,'I'
int 21h

mov dh,25
mov dl,29
mov ah,02h
mov bh,0
int 10h
mov ah,2
mov dl,'I'
int 21h

mov dh,21
mov dl,18
mov ah,02h
mov bh,0
int 10h
mov ah,2
mov dl,'V'
int 21h

mov dh,21
mov dl,19
mov ah,02h
mov bh,0
int 10h
mov ah,2
mov dl,'I'
int 21h

mov dh,21
mov dl,20
mov ah,02h
mov bh,0
int 10h
mov ah,2
mov dl,'I'
int 21h

mov dh,21
mov dl,21
mov ah,02h
mov bh,0
int 10h
mov ah,2
mov dl,'I'
int 21h

mov dh,15
mov dl,15
mov ah,02h
mov bh,0
int 10h
mov ah,2
mov dl,'I'
int 21h

mov dh,15
mov dl,16
mov ah,02h
mov bh,0
int 10h
mov ah,2
mov dl,'X'
int 21h

mov dh,10
mov dl,18
mov ah,02h
mov bh,0
int 10h
mov ah,2
mov dl,'X'
int 21h


mov dh,6
mov dl,26
mov ah,02h
mov bh,0
int 10h
mov ah,2
mov dl,'X'
int 21h

mov dh,6
mov dl,27
mov ah,02h
mov bh,0
int 10h
mov ah,2
mov dl,'I'
int 21h
ret
Dial endp

;----------------------------------------
;Write graphics pixel AH=0Ch
;here al=Clour,bh=page number
;cx=x,  dx=y
;----------------------------------------
graphic_pixel proc
mov ah,0ch
mov al,2
mov bh,0
int 10h
ret
graphic_pixel endp



clockBoundary proc
call DialLine
mov cx,360
mov ax,0
Boundary:
push cx
mov bx,CircleRadius
mov cx,y_center
mov dx,x_center
push ax
call position
mov cx,x
mov dx,y
call graphic_pixel
pop ax
inc ax
pop cx
loop Boundary
ret
clockBoundary endp

centre_Point proc
push cx
push dx
call graphic_pixel
inc cx
call graphic_pixel
sub cx,2
call graphic_pixel
add cx,1
dec dx
call graphic_pixel
add dx,2
call graphic_pixel
pop dx
pop cx
ret
centre_Point endp


DialLine proc
mov cx,12
mov ax,0
mov bx,CircleRadius
L1:
push cx
push bx
mov cx,10
L2:
push cx
mov cx,y_center
mov dx,x_center
push ax
call position
mov cx,x
mov dx,y
call graphic_pixel
pop ax
pop cx
sub bx,1
loop L2
add ax,30
pop bx
pop cx
loop L1
ret
DialLine endp


Get_time proc
mov ah,2ch
int 21h
mov Minute,cl
mov Second,dh
cmp ch,12
ja above12
jmp below12
above12:
sub ch,12
mov hour,ch
jmp ret4
below12:
mov hour,ch
ret4:
ret
Get_time endp


HourAngle proc
cmp hour,3
jb below3
jmp above3
below3:
mov Hour_Angle,270
mov al,hour
mov bl,30
mul bl
add Hour_Angle,ax
mov al,Minute
xor ah,ah
mov bl,12
div bl
xor ah,ah
mov bl,6
mul bl
add Hour_Angle,ax
jmp ret3
above3:
mov al,hour
sub al,3
mov bl,30
mul bl
mov Hour_Angle,ax
mov al,Minute
xor ah,ah
mov bl,12
div bl
xor ah,ah
mov bl,6
mul bl
add Hour_Angle,ax
ret3:
ret
HourAngle endp

HourHand proc
mov ax,Hour_Angle
mov bx,CircleRadius
sub bx,100
mov cx,bx
A1:
push cx
mov bx,cx
mov cx,y_center
mov dx,x_center
push ax
call position
mov cx,x
mov dx,y
call centre_Point
pop ax
pop cx
loop A1
ret
HourHand endp


MinuteAngle proc
cmp Minute,15
jb below15m

jmp above15m

below15m:
mov Minute_Angle,270
cmp Minute,60
je m60
jmp not60m
m60:
jmp ret2
not60m:
mov al,Minute
mov bl,6
mul bl
add Minute_Angle,ax
jmp ret2
above15m:
mov bl,Minute
sub bl,15
mov al,6
mul bl
mov Minute_Angle,ax
ret2:
ret
MinuteAngle endp

MinuteHand proc
mov ax,Minute_Angle
mov bx,CircleRadius
sub bx,50
mov cx,bx
B1:
push cx
mov bx,cx
mov cx,y_center
mov dx,x_center
push ax
call position
mov cx,x
mov dx,y
call centre_Point
pop ax
pop cx
loop B1
ret
MinuteHand endp

SecondAngle proc
cmp Second,15
jb below15s

jmp above15s

below15s:
mov Second_Angle,270
cmp Second,60
je s60
jmp not60s
s60:
jmp ret1
not60s:
mov al,Second
mov bl,6
mul bl
add Second_Angle,ax
jmp ret1
above15s:
mov bl,Second
sub bl,15
mov al,6
mul bl
mov Second_Angle,ax
ret1:
ret
SecondAngle endp

SecondHand proc
mov ax,Second_Angle
mov bx,CircleRadius
sub bx,50
mov cx,bx
S1:
push cx
mov bx,cx
mov cx,y_center
mov dx,x_center
push ax
call position
mov cx,x
mov dx,y
call graphic_pixel
pop ax
pop cx
loop S1
ret
SecondHand endp

position proc
push dx
push ax
push cx
call sin
mov dx,0
mov cx,bx
mul cx
mov cx,10000
div cx
pop cx
cmp AngleCheck,1
je P1

add ax,cx
jmp P2

P1:
sub cx,ax
mov ax,cx

P2:
mov y,ax
pop ax
call cos
mov dx,0
mov cx,bx
mul cx
mov cx,10000
div cx
cmp AngleCheck,1
je P3
add ax,x_center
jmp P4

P3:
mov cx,x_center
sub cx,ax
mov ax,cx
P4:
mov x,ax
pop dx
ret
position endp

cos proc
add ax,90
call sin
ret
cos endp

sin proc
push cx
push dx
push bx

SINSTART:
cmp ax,90
ja ANGLEABOVE90

ANGLE_0_TO_90:
mov AngleCheck,0
jmp CALCULATE

ANGLEABOVE90:
cmp ax,180
jbe ANGLE_91_TO_180
JMP ANGLEABOVE180

ANGLE_91_TO_180:
mov cx,180
sub cx,ax
mov ax,cx
mov AngleCheck,0
jmp CALCULATE

ANGLEABOVE180:
cmp ax,270
jbe ANGLE_181_TO_270
jmp ANGLE_271_TO_360

ANGLE_181_TO_270:
sub ax,180
mov AngleCheck,1
jmp CALCULATE

ANGLE_271_TO_360:
cmp ax,359
ja ANGLEABOVE359
mov cx,360
sub cx,ax
mov ax,cx
mov AngleCheck,1
jmp CALCULATE

ANGLEABOVE359:
sub ax,360
JMP SINSTART

CALCULATE:
mov cx,175
xor dx,dx
mul cx
mov sin_x,ax
xor dx,dx
mov cx,ax
mul cx
mov cx,10000
div cx
mov sin_xx,ax
xor dx,dx
mov cx,120
div cx
mov bx,1677
call MODAMINUSB
mov cx,sin_xx
xor dx,dx
mul cx
mov cx,10000
div cx
mov cx,10000
mov dl,0
cmp dl,check
je C1
sub cx,ax
mov ax,cx
jmp C2

C1:
add ax,cx

C2:
mov cx,sin_x
xor dx,dx
mul cx
mov cx,10000
div cx
pop bx
pop dx
pop cx
mov check,0
ret
SIN endp

MODAMINUSB proc
cmp ax,bx
jae AMINUSB
xor check,1
xchg ax,bx

AMINUSB:
sub ax,bx
ret
MODAMINUSB endp 




CLRSCR PROC
                mov ah, 06h           ; scroll up

                mov al, 0             ; entire window

                mov ch, 0             ; upper left row

                mov cl, 0             ; upper left col

                mov dh, 30            ; lower right row

                mov dl, 79            ; lower right col

                int 10h               ; white: RGB=111=7

                ret

CLRSCR endp


end main
