t = 0: 0.01: 10;
Z = 4 + 3j;
V1 = 10*sin(2*pi*t);

I1 = V1/Z;
a = input('Enter Transformation Ratio: a = ');
% a = 2 (Step Down Transformer).

subplot(3, 2, 1);
plot(t, V1);
xlabel('t');
ylabel('V_{1}');
title('Primary Voltage.');
subplot(3, 2, 2);
plot(t, I1);
xlabel('t');
ylabel('I_{1}');
title('Primary Current.');

[V2, I2] = transformer_func(V1, I1, a);

subplot(3, 2, 3);
plot(t, V2)
xlabel('t');
ylabel('V_{2}');
title('Secondary Voltage.');
subplot(3, 2, 4);
plot(t, I2);
xlabel('t');
ylabel('I_{2}');
title('Secondary Current.');

subplot(3, 2, 5);
plot(V1, V2)
xlabel('V_{1}');
ylabel('V_{2}');
subplot(3, 2, 6);
plot(I1, I2);
xlabel('I_{1}');
ylabel('I_{2}');
