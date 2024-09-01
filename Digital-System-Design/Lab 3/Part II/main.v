module main(SW, LEDR);

input [8:0]SW;
output [4:0]LEDR;

full_adder A0(SW[4], SW[0], SW[8], LEDR[0], x);
full_adder A1(SW[5], SW[1], x, LEDR[1], y);
full_adder A2(SW[6], SW[2], y, LEDR[2], z);
full_adder A3(SW[7], SW[3], z, LEDR[3], LEDR[4]);

endmodule



module full_adder(a, b, cin, s, cout);

input a, b, cin;
output cout, s;

assign g = a ^ b;
assign s = g ^ cin;
assign cout = (~g & b) | (g & cin);

endmodule 
