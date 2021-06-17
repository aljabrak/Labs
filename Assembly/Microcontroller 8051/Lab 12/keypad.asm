;Keypad Interfacing.

org 00h
mov p1,#00000000b	                ;making p1 output port.

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;ROW CHECK;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

next:	                            ;first compairing the rows.
mov p2,#11111000b	                ;moving logic 0 to p2.2 p2.1 p2.0.
jnb p2.6,row1	                    ;jump to row1 when bit is unset when bit is set go to next instruction.
jnb p2.5,row2	                    ;jump to row2 when bit is unset when bit is set go to next instruction.
jnb p2.4,row3	                    ;jump to row3 when bit is unset when bit is set go to next instruction.
jnb p2.3,row4	                    ;jump to row4 when bit is unset when bit is set go to next instruction.		
jmp next	                        ;continue process.

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;COLUMN CHECK;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

row1:
mov p2,#0ffh	                    ;making port 2 input port or logic 1.	
mov p2,#00000111b                 ;making port p2.0,p2.1,p2.2 logic 1.
jnb p2.2,l1	                      ;jump to l1 if p2.2 is not set and when set goto next instruction.
jnb p2.1,l2		                    ;jump to l2 if p2.1 is not set and when set goto next instruction.
jnb p2.0,l3	                      ;jump to l3 if p2.1 is not set and when set goto next instruction.
jmp next	                        ;continue process row2:

row2:
mov p2,#0ffh	                    ;making port 2 input port or logic 1.
mov p2,#00000111b	                ;making port p2.0,p2.1,p2.2 logic 0.
jnb p2.2,l4	                      ;jump to l4 if p2.2 is not set and when set goto next instruction.
jnb p2.1,l5		                    ;jump to l5 if p2.1 is not set and when set goto next instruction.
jnb p2.0,l6	                      ;jump to l6 if p2.1 is not set and when set goto next instruction.
jmp next	                        ;continue process.

row3:
mov p2,#0ffh		                  ;making port 2 input port or logic 1.
mov p2,#00000111b	                ;making port p2.0,p2.1,p2.2 logic 0.
jnb p2.2,l7	                      ;jump to l7 if p2.2 is not and when set goto next instruction.
jnb p2.1,l8                       ;jump to l8 if p2.1 is not and when set goto next instruction.
jnb p2.0,l9	                      ;jump to l9 if p2.1 is not and when set goto next instruction.
jmp next	                        ;continue process row4:

row4:
mov p2,#0ffh	                    ;making port 2 input port or logic 1.
mov p2,#00000111b                 ;making port p2.0,p2.1,p2.2 logic 0.
jnb p2.2,star		                  ;jump to star if p2.2 is not and when set goto next instruction.
jnb p2.1,zero	                    ;jump to zero if p2.1 is not and when set goto next instruction.
jnb p2.0,hash	                    ;jump to hash if p2.1 is not and when set goto next instruction.
jmp next	                        ;continue process l1:
mov p1,#11111001b	                ;giving 1 to port p1
jmp next

l2:
mov p1,#10100100b	                ;giving 2 to port p1.
jmp next

l3:
mov p1,#10110000b	                ;giving 3 to port p1.
jmp next

l4:
mov p1,#10011001b	                ;giving 4 to port p1.
jmp next

l5:
mov p1,#10010010b	                ;giving 5 to port p1.
jmp next

l6:
mov p1,#10000010b	                ;giving 6 to port p1.
jmp next

l7:
mov p1,#11111000b	                ;giving 7 to port p1.
jmp next

l8:
mov p1,#10000000b	                ;giving 8 to port p1.
jmp next

l9:
mov p1,#10010000b	                ;giving 9 to port p1.
jmp next

star:
mov p1,#10111111b	                ;giving * to port p1.
jmp next

zero:
mov p1,#11000000b	                ;giving 0 to port p1.
jmp next

hash: port p1mov p1,#10111111b	                ;giving # to port p1.
jmp next

end
