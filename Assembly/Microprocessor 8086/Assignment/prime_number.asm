Include irvine32.inc
.stack 100h
.data


titlemsg BYTE " PRIME NUMBER PROGRAM	", 0dh, 0ah, 0dh ,0ah ,0
prompt BYTE " Please enter any integer or enter 0 to quit: ", 0
msgPrime BYTE " The number you entered is a prime number. " ,0dh ,0ah ,0
msgNotPrime BYTE " The number you entered is not a prime number. " ,0dh ,0ah ,0

.code

IsDivisible PROC

push eax 
push edx
mov edx,0
div ebx
cmp edx,0
pop edx 
pop eax
ret
IsDivisible ENDP

IsPrime PROC

pusha
cmp eax,2
jbe P3


mov ecx,eax
shr ecx,1
mov ebx,2


P1:
call isDivisible
 
jz P4

inc ebx
loop P1

P3:
test eax,0
jmp P5

P4:
or eax,0
jmp P5

P5:
popa
ret

IsPrime ENDP

main PROC


call clrscr
mov edx,offset titlemsg
call writestring

L1:
call crlf
mov edx, offset prompt 
call writestring
call readInt
call crlf
cmp eax,0 
jle quit

call IsPrime
.IF ZERO?

mov edx, offset msgPrime
.ELSE
mov edx,offset msgNotPrime
.ENDIF

call writeString

jmp L1

quit:

call clrscr
exit

main ENDP
end main 