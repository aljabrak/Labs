% Excercise: 12

G1 = tf(1, [1, 1]);
G2 = tf(2, [1, 3, 2]);
G3 = tf(10, [1, 11, 10]);
G4 = tf(20, [1, 21, 20]);
G5 = tf(125, [1, 21, 145, 125]);

G = [G1, G2, G3, G4, G5];

for a = 1 : length(G)
    hold on;
    grid on;
    step(G(a));
    legend('G_{1}','G_{2}','G_{3}','G_{4}', 'G_{5}');
    damp(G(a));
    disp(stepinfo(G(a)));
end