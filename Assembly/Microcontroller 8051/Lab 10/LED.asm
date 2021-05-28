org 00h
mov p2,#0
mov a,#10101010b
mov b,#01010101b

label1:
mov p2,a
call delay
mov p2,b
call delay
jmp label1

delay:
mov r5,#255

ML1:
    mov r6,#4
             ML2:
             mov r7,#255
             djnz r7,$
    djnz r6,ML2
djnz r5,ML1

ret
end
