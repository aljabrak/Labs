clc

a = [1, 0, -1];
b = [1, -0.90, 0.81];
[H, w] = freqz(a, b);
plot(w/(2*pi), abs(H));
grid on
title('Magnitude-Frequency Response.');
H_max = max(abs(H));
H_dB = 0.707*H_max;
disp(H_max);
disp(H_dB);
