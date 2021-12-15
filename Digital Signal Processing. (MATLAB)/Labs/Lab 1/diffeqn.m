function [y] = diffeqn(x, a)
y = zeros(1, length(x));

for k = 1 : length(x)
    if k == 1
        y(1) = x(1);
    else
        y(k) = a*y(k-1) + x(k);
    end
end
end