% Excercise: 4

p = -5;
K = 1;
z = [-1, -2, -5, -10];


for c = 1 : length(z)
    sys = zpk(z(c), p, K);
    hold on;
    grid on;
    step(ss(sys));
    legend({'z = -1','z = -2','z = -5','z = -10'});
    fprintf("z = " + string(z(c)) + "\n");
    disp(stepinfo(ss(sys)));
end