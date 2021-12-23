clc
T = 0.5;
fs = 5000;
L = fs * T;
t = linspace(0, T, L);
m = (square(2*pi*10*t) + 1)/2;
c1 = sin(2*pi*50*t);
c2 = sin(2*pi*20*t);
s = zeros(1, L);

for i = 1:L
    if (m(i) == 1)
        s(i) = c1(i);
    else
        s(i) = c2(i);
    end
end

plot(t, s);
grid on
title('FSK Modulation.');
xlabel('t');
ylabel('s(t)');


demod_s = zeros(1, L);

for i = 1: L
    if(s(i) == c1(i))
        demod_s(i)=1;
    else
        demod_s(i)=0;
    end
end

subplot(2, 1, 1);
plot(t, m);
grid on;
title('Message Signal.');
xlabel('t');
ylabel('m(t)');
subplot(2, 1, 2);
plot(t, demod_s);
grid on;
title('FSK Demodulated Signal.');
xlabel('t');
ylabel('x(t)');
