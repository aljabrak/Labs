Include irvine32.inc
.model small
.stack 100h
.data  
.code

main proc           

call clrscr          
call dumpregs       

mov ax,-100
call dumpregs

add ax,0
call dumpregs

sub ax,10
call dumpregs

sub ax,50
call dumpregs 

exit
main endp
end main
