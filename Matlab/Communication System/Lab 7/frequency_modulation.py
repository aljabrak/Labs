% Frequency Modulation.

t = 0: 0.001: 1;
fc = 500;
fm = 35;
Am = 1;
Ac = 1;
c = Ac*cos(2*pi*fc*t);
m = Am*cos(2*pi*fm*t);
kf = 70;
s = fmmod(m, fm, 3*fm, kf);

subplot(3,1,1)
plot(t, m)
ylabel('Amplitude');
xlabel('Time');
title('Message Signal');

subplot(3,1,2)
plot(t, c)
ylabel('Amplitude');
xlabel('Time');
title('Carrier Signal');

subplot(3,1,3)
plot(t, s)
ylabel('Amplitude');
xlabel('Time');
title('Phase Modulated Signal');
