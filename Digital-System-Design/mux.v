module mux(x0, x1, s, y);

input x0, x1, s;
output reg y;

always @(x0, x1, s)
begin
if (s == 1)
y = x0;
else
y = x1;
end
endmodule 