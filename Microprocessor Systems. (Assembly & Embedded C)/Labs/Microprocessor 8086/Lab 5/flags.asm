Include irvine32.inc
.model small
.stack 100h
.data  
.code

main proc           

call clrscr          
call dumpregs       

mov al,-100
call dumpregs

add al,0
call dumpregs

sub al,10
call dumpregs

sub al,50
call dumpregs 

exit
main endp
end main
