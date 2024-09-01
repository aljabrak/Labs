module main(SW, LEDR);

//Master & Slave D-flip flop.

input [1:0]SW;
output [1:0]LEDR;
wire w0, w1;

assign D = SW[0];
assign clk = SW[1];

D_latch master(~clk, D, w0, w1);
D_latch slave(clk, w0, LEDR[0], LEDR[1]);

endmodule



module D_latch(clk, D, Q_a, Q_b);

input clk, D;
output Q_a, Q_b;
wire w0, w1, Q_a, Q_b;

nand(w0, clk, D);
nand(w1, clk, ~D);
nand(Q_a, w0, Q_b);
nand(Q_b, w1, Q_a);


endmodule 
