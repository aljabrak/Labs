clc

syms s theta1 theta2 theta3 T;

A = [15*s^2+7*s+10, -10, 0; -10, 15*s^2+7*s+10, -7*s; 0, -7*s, 15*s^2+14*s];
% B = [theta1; theta2; theta3];
C = [T; 0; 0];
B = A\C; % inv(A) * C

theta1 = B(1);
theta2 = B(2);
theta3 = B(3);

G1 = theta1 / T;
G2 = theta2 / T;
G3 = theta3 / T;

disp(G1);
disp(G2);
disp(G3);
