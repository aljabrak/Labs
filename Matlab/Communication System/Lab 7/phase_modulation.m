% Frequency Modulation.

t = 0:0.001:1;
fc = 10;
fm = 2;
Am = 1;
Ac = 1;
Ct = Ac*cos(2*pi*fc*t);
Mt = Am*cos(2*pi*fm*t);
kp = 2;
St = Ac*cos(2*pi*fc*t+kp*Mt);

subplot(3,1,1)
plot(t, Mt)
ylabel('Amplitude');
xlabel('Time Index');
title('Message Signal');

subplot(3,1,2)
plot(t, Ct)
ylabel('Amplitude');
xlabel('Time Index');
title('Carrier Signal');

subplot(3,1,3)
plot(t, St)
ylabel('Amplitude');
xlabel('Time Index');
title('Phase Modulated Signal');
