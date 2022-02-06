clc
 
syms t;
g1 = t*sin(2*t) + exp(-2*t);
G1 = laplace(g1);
disp(G1);
 
g2 = sin(2*t)*cos(2*t);
G2 = laplace(g2);
disp(G2);
 
g3 = exp(-t)*cos(3*t);
G3 = laplace(g3);
disp(G3);
 
g4 = -exp(-t) + 9*t*exp(-t) + 5*exp(-2*t) + t - 2;
G4 = laplace(g4);
disp(G4);
 
g5 = 5*t^(2)*cos(3*t + 45);
G5 = laplace(g5);
disp(G5);
