% Excercise: 13

G1 = tf(5, [1, 2, 5]);
G2 = tf(5, [1, 3, 7, 5]);
G3 = tf(25, [1, 7, 15, 25]);
G4 = tf(100, [1, 22, 25, 100]);


G = [G1, G2, G3, G4];

for a = 1 : length(G)
    hold on;
    grid on;
    step(G(a));
    legend('G_{1}','G_{2}','G_{3}','G_{4}');
    damp(G(a));
    disp(stepinfo(G(a)));
end