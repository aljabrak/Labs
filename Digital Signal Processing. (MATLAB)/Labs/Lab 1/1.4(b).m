n = 1:1:10;
disp(n);
x = [2, 3, -1, 2, -3, zeros(1, 5)];
disp(x);
a = 2;
 
y = diffeqn(x, a);
disp(y);
stem(n, y);
