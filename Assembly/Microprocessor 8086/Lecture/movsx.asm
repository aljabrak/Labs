Include irvine32.inc
.stack 100h
.data 
.code

main proc           

call clrscr          
call dumpregs       

mov al,8Fh
call dumpregs

movsx eax,al            ;extends the upper part of the destination with copy of source operands signed bit.
call dumpregs

exit
main endp
end main
