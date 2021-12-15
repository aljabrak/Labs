Include irvine32.inc
.stack 100h
COUNT = 4
.data

array DWORD 7f0287c6h, 589d7426h, 62d06968h, 1a4fae8fh, 1046746eh

.code

ShiftDoublewords PROC

mov esi,offset array
 
mov ecx, (lengthof array) - 1


L1:
push ecx 
mov eax,[esi + type DWORD]
mov cl,bl
shrd [esi], eax, cl
add esi, type DWORD
pop ecx
loop L1
 
shr DWORD PTR [esi], COUNT

ret

ShiftDoublewords ENDP


main PROC


mov bl,COUNT
call ShiftDoublewords

mov esi, offset array
mov ecx, lengthof array 
mov ebx, type array 
call DumpMem

exit

main ENDP
end main