% Excercise: 9
% Set: 1
a = 0;
b = [1, 2, 5];


for k = 1 : length(b)
    sys = transfer_function(a, b(k));
    hold on;
    grid on;
    step(sys);
    fprintf("omega_" + string(b(k)) + "\n");
    disp(stepinfo(sys));
    legend('\omega_{1} = 1','\omega_{2} = 2','\omega_{3} = 5');
end



% Set: 2
a = 1;
b = [1, 2, 5];


for k = 1 : length(b)
    sys = transfer_function(a, b(k));
    hold on;
    grid on;
    step(sys);
    fprintf("omega_" + string(b(k)) + "\n");
    disp(stepinfo(sys));
    legend('\omega_{1} = 1','\omega_{2} = 2','\omega_{3} = 5');
end



% Set: 3
a = [0, 0.5, 1, 2];
b = 1;


for k = 1 : length(a)
    sys = transfer_function(a(k), b);
    hold on;
    grid on;
    step(sys);
    fprintf("damping_ratio_" + string(a(k)) + "\n");
    disp(stepinfo(sys));
    legend('\zeta_{1} = 0', '\zeta_{2} = 0.5', '\zeta_{3} = 1', '\zeta_{4} = 2');
end