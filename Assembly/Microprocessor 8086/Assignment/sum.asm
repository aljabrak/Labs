Include irvine32.inc
.stack 100h
.data

num1 QWORD 0DC61A2700875294Ah, 07F96E3E60F52D2C6h, 091C1A7F1EA129105h, 0ffA78F65585B9bBAh
num2 QWORD 000047E3AE8B102F1h, 0E5B83B13B31BE64Dh, 047D2B509F4ABF5EFh, 0C5A68825DDCF554Ch
sum DWORD 9 DUP (0)
msg BYTE "Sum = ",0 
.code

Extended_Add PROC
 	
pushad
clc	                   

L2:
mov eax,[esi]	  
adc eax,[edi]
pushfd
mov [ebx],eax
add esi,4	         
add edi,4
add ebx,4
popfd	         
loop L2	   

adc WORD ptr [ebx],0
popad
ret 
Extended_Add ENDP


main PROC


mov esi,offset num1	    
mov edi,offset num2	   
mov ebx,offset sum	 
mov ecx,8	            
call Extended_Add


mov edx,offset msg	 
call writestring

mov esi,offset sum
add esi,8 * TYPE sum
mov ecx, length sum

L1:
mov eax,[esi]	        
call writehex	      
sub esi, TYPE sum
loop L1

call crlf
exit

main ENDP
END main