clc
clear

format long
f = [1, 0, -4, 1];
a = 0; b = 1;
iter = 100;
[x, n] = regula_falsi_method(f, a, b, iter);
disp(x);
disp(n);
