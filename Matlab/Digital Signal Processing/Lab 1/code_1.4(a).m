n = 1:1:10;
disp(n);
x = [2, 3, -1, 2, -3, zeros(1, 5)];
disp(x);
 
xe = x_even(x);
xo = x_odd(x);
 
subplot(3, 1, 1);
stem(n, x);
title('Signal x[n]');
 
subplot(3, 1, 2);
stem(n, xe);
title('x_{even}[n]');
 
subplot(3, 1, 3);
stem(n, xo);
title('x_{odd}[n]');
