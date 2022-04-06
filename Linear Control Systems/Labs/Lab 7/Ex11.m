% Excercise: 11

G1 = tf(1, [1, 1, 1]);
G2 = tf([1, 1], [1, 1, 1]);
G = [G1, G2];

for a = 1 : length(G)
    step(G(a));
    grid on;
    damp(G(a));
    disp(stepinfo(G(a)));
    pause(20);
end