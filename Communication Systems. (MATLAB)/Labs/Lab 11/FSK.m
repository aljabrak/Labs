% Frequency Shift Keying(FSK).

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
