% Excercise: 6

G1 = tf(5, [1, -4, 5]);
G2 = tf(2, [1, -2, 2]);
G3 = tf(5, [1, -2, 5]);
G = [G1, G2, G3];

for a = 1:3
    damp(G(a));  % Damping Ratio.
end