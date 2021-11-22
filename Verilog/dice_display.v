module dice(A,B,C,a,b,c,d,e,f,g);
input A,B,C;
output a,b,c,d,e,f,g;
wire w1,w2,w3,w4,w5,w6,w7,w8,w9,w10,w11,w12;
assign w1=!A;assign w2=!B;assign w3=!C;
assign w4=A&w2;assign w5=B&w3;
assign w6=w1&B&C;assign w7=A&w2&C;assign w8=A&B&w3;
assign w9=A&w2;assign w10=A&w3;assign w11=w1&B;
assign w12=w2&C;
assign g=w10;
assign d=w11||w12;
assign e=w10;assign b=w6||w7||w8;
assign a=w4||w5;assign f=w6||w7||w8;assign c=w9||w10;
endmodule

module saud;
reg A,B,C;
wire a,b,c,d,e,f,g;
dice l1(A,B,C,a,b,c,d,e,f,g);
initial 
begin
#100 A=1'b0;B=1'b0;C=1'b0;
#100 A=1'b0;B=1'b0;C=1'b1;
#100 A=1'b0;B=1'b1;C=1'b0;
#100 A=1'b0;B=1'b1;C=1'b1;
#100 A=1'b1;B=1'b0;C=1'b0;
#100 A=1'b1;B=1'b0;C=1'b1;
#100 A=1'b1;B=1'b1;C=1'b0;
#100 A=1'b1;B=1'b1;C=1'b1;

end
endmodule
