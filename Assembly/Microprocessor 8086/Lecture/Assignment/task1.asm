; Modify the Extended_Add procedure to add two 256-bit integers


INCLUDE irvine32.inc


.data
; Two 256-bit integers are stored in Little Endian order


; op1: D98709374FDECAA06453DC973294BFE2B457AFD8BC939321A2B2A40674981234h
; op2: 2974BC9397320002E6749332BFE253DCFBC974FDDC97B2A4A010870000234502h


op1 QWORD 0A2B2A40674981234h,0B457AFD8BC939321h,06453DC973294BFE2h,0D98709374FDECAA0h
op2 QWORD 0A010870000234502h,0FBC974FDDC97B2A4h,0E6749332BFE253DCh,02974BC9397320002h
sum DWORD 9 DUP (0)
; sum = 0000000102FBC5CAE710CAA34AC86FC9F27713BFB02124D6992B45C642C32B0674BB5736h


msg BYTE "The Sum of two 256-bit integers is ",0
 
.code
main PROC


mov esi,offset op1	;first operand
mov edi,offset op2	;second operand
mov ebx,offset sum	;sum
mov ecx,8	;Number of doublewords
call Extended_Add


mov edx,offset msg	;message to display call WriteString

mov esi,offset sum		;starting address of sum add esi,8 * TYPE sum	;get to the last dword in sum mov ecx, length sum		;number of doublewords

L1:
mov eax,[esi]	;get 32 bits of sum
call WriteHex	;display to the screen
sub esi, TYPE sum	;previous dword (little endian order)
loop L1




call CRLF exit

main ENDP


; 	
 
Extended_Add PROC
;
; Calculates the sum of two extended integers that are
; stored as an array of doublewords.
; Receives: ESI and EDI point to the two integers,
; EBX points to a variable that will hold the sum, and
; ECX indicates the number of doublewords to be added.
; 	


pushad
clc	;clear the Carry Flag


L2:
mov eax,[esi]	;get the first integer
adc eax,[edi]	;get the second integer pushfd		;save the Carry Flag mov [ebx], eax	;store partial sum
add esi,4	;advancing all three pointers add edi,4
add ebx,4
popfd	;restore the Carry Flag loop L2	;repeat the loop

adc WORD ptr [ebx],0	;add any leftover carry popad
ret Extended_Add ENDP

END main
