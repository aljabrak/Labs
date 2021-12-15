Include irvine32.inc
.stack 100h
.data 
variable BYTE ?
.code

main proc           

call clrscr          
call dumpregs       

mov al,08Fh
call dumpregs

lahf                        ;loads FLAG into AH.
mov ah,variable             ;save them in a variable.
call dumpregs

mov ah,variable             ;loads variable into AH.
sahf                        ;copy AH into FLAGS Register.
call dumpregs

exit
main endp
end main
