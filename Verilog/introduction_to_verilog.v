module p(sum, carry, A, B);
input A, B;
output sum, carry;
wire w1;	//Output of first NOT Gate
wire w2;	//Output of Second NOT Gate
wire w3;	//Output of first AND Gate
wire w4;	//Output of second AND Gate
not(w1, a);
not(w2, b);
and(w3, w1, b);
and(w4, a, w2);
and(carry, a, b); 			//Output of upper circuit i.e carry
or(sum, w3, w4);			//Output of lower circuit i.e sum.
endmodule

//***************************************************/

module main;
reg a,b;
wire sum, carry;
p test(sum, carry, a, b);
initial begin
a=0; b=0; #100;
a=1; b=0; #100;
a=0; b=1; #100;
a=1; b=1; #100;
end
endmodule
