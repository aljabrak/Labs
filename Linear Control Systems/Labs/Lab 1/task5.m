clc
 
M = 0.5;
m = 0.5;
b = 0.1;
L = 0.3;
I = 0.006;
q = (M + m)*(I + m*L^2) - (m*L)^2;
g = 9.80665;
disp(q);
 
 
syms s;
H = ((m*L/q)*s^2)/(s^4 + (b*(I + m*L^2)/q)*s^3 - (M + m)*(m*g*L/q)*s^2 - (m*g*L/q)*s);
h = ilaplace(H);
disp(h);
disp(H);
% pretty(H);
