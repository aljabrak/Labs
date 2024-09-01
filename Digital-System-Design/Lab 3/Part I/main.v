module main(SW, HEX0, HEX1);

input [3:0]SW;
output [6:0] HEX0, HEX1;
wire z;
wire [3:0] A, U;


// Comparator.
assign z = (SW[2] & SW[3]) | (SW[1] & SW[3]);

// Circuit A Logic.
assign A[0] = (SW[0] & SW[2] & SW[3]) | (SW[0] & SW[1] & SW[3]);
assign A[1] = (~SW[1] & SW[2] & SW[3]);
assign A[2] = (SW[1] & SW[2] & SW[3]);
assign A[3] = 0;

mux m(SW[3:0], A, z, U);
decoder4X7 d0(U, HEX0);
decoder1X7 d1(z, HEX1);

endmodule


module mux(V, A, z, S);

input [3:0] V, A;
input z;
output [3:0]S;

assign S[0] = (~z & V[0]) | (z & A[0]);
assign S[1] = (~z & V[1]) | (z & A[1]);
assign S[2] = (~z & V[2]) | (z & A[2]);
assign S[3] = (~z & V[3]) | (z & A[3]);

endmodule


module decoder1X7(z, X);

input z;
output [6:0]X;

assign X[0] = ~z;
assign X[1] = 1;
assign X[2] = 1;
assign X[3] = ~z;
assign X[4] = ~z;
assign X[5] = ~z;
assign X[6] = 0;

endmodule


module decoder4X7(S, Y);

input [3:0]S;
output [6:0]Y;

assign Y[0] = (~S[0] & ~S[2]) | (S[1]) | (S[3]) | (S[0] & S[2]);
assign Y[1] = (~S[0] & ~S[1]) | (~S[2]) | (S[0] & S[1]);
assign Y[2] = (~S[1]) | (S[2]) | (S[0]);
assign Y[3] = (~S[0] & ~S[2]) | (~S[0] & S[1]) | (S[3]) | (S[0] & ~S[1] & S[2]) | (S[1] & ~S[2]);
assign Y[4] = (~S[0] & ~S[2]) | (~S[0] & S[1]);
assign Y[5] = (~S[0] & ~S[1]) | (~S[0] & S[2]) | (S[3]) | (~S[1] & S[2]);
assign Y[6] = (S[3]) | (~S[1] & S[2]) | (S[1] & ~S[2]) | (~S[0] & S[2]);

endmodule
