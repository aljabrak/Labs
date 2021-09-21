n = -5:1:5;
disp(n);

x = [zeros(1, 5), 2, 3, -1, 2, -3, 0];
disp(x);

% time reversal
x_reverse = fliplr(x);

%even component
xe = 0.5*(x + x_reverse);

%odd component
xo = 0.5*(x - x_reverse);


subplot(3,1,1);
stem(n, x);
title('Signal x[n]');

subplot(3,1,2); 
stem(n, xe);
title('Even Signal');

subplot(3,1,3);
stem(n, xo);
title('Odd Signal');
