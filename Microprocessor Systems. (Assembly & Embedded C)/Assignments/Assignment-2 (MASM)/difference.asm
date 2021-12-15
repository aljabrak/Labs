Include irvine32.inc
.stack 100h
.data

num1 QWORD 0dDC61A2700875294Ah
num2 QWORD 000047E3AE8B102F1h
difference QWORD 1 DUP(0)
msg BYTE "Difference = ",0

.code

Extended_Sub PROC
pushad
clc

L2:
mov eax,[esi]	
sbb eax,[edi]	
pushfd		
mov [ebx],eax	
add esi,4	    
add edi,4 
add ebx,4
popfd	
loop L2
 
sbb WORD ptr [ebx],0
popad
ret


Extended_Sub ENDP

main PROC


mov esi , offset num1	
mov edi , offset num2	
mov ebx , offset difference
mov ecx, dword

mov edx, offset msg
call writestring
mov esi,offset difference	
add esi, dword * 4
mov ecx, dword

L1:
sub esi, TYPE DWORD
mov eax, [esi]
call writehex
loop L1


call crlf 
exit

main ENDP
END main