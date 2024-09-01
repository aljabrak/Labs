module D_latch(clk, D, Q);

input clk, D;
output reg Q;

always @(clk, D)
begin
if (clk)
Q = D;
end

endmodule 
