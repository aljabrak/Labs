% Excercise: 2

 p = [-1, -2, -5, -10];

for a = 1 : length(p)
    sys = zpk([], p(a), -p(a));
    hold on;
    grid on;
    step(ss(sys));
    legend({'p = -1','p = -2','p = -5','p = -10'});
    fprintf("p = " + string(p(a)) + "\n");
    disp(stepinfo(ss(sys)));
end