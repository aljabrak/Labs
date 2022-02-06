clc
 
syms s;
G1 = 1 / (s * (s + 2) * (s + 3));
g1 = ilaplace(G1);
disp(g1);
 
G2 = 10 / ((s + 1)^2 *  (s + 3));
g2 = ilaplace(G2);
disp(g2);
 
G3 = 2 * (s + 1) / (s * (s^2 + s + 2));
g3 = ilaplace(G3);
disp(g3);
 
G4 = (s + 1) / (s * (s + 1) * (s^2 + 2*s + 2));
g4 = ilaplace(G4);
disp(g4);
