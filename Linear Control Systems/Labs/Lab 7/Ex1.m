clc
clear

% Excercise: 1

G1 = tf([2, 2], [1, 9, 20]);
G2 = tf([1, 1],[1, 12, 47, 60]);
G3 = tf(1, [1, 10]);
G = [G1, G2, G3];

for a = 1:3
    info = stepinfo(G(a));
    err = abs(1-dcgain(G(a)));
    fprintf("Transfer Function: G(" + string(a) + ")");
    display(info);
    display(err);
    pause(20)
end