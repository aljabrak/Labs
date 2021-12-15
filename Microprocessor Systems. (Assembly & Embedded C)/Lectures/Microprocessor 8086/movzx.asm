Include irvine32.inc
.stack 100h
.data 
.code

main proc           

call clrscr          
call dumpregs       

mov al,8Fh
call dumpregs

movzx eax,al            ;extends the upper part of the destination with zeros.
call dumpregs

exit
main endp
end main
