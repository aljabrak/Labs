% Excercise: 3


p = -5;
K = [1, 2, 5, 10];


for b = 1 : length(K)
    sys = zpk([], p, K(b));
    hold on;
    grid on;
    step(ss(sys));
    legend({'K = 1','K = 2','K = 5','K = 10'});
end