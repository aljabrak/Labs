% Frequency Modulation.

t = 0: 0.0001: 0.1;
fc = 500;
fm = 35;
Am = 1;
Ac = 1;
c = Ac*cos(2*pi*fc*t);
m = Am*cos(2*pi*fm*t);
kf = 70;
s = fmmod(m, fc, 3*fc, kf);
demod = fmdemod(s, fc, 3*fc, kf);

subplot(4,1,1);
plot(t, m);
ylabel('Amplitude');
xlabel('Time');
title('Message Signal');
grid on

subplot(4,1,2);
plot(t, c);
ylabel('Amplitude');
xlabel('Time');
title('Carrier Signal');
grid on

subplot(4,1,3);
plot(t, s);
ylabel('Amplitude');
xlabel('Time');
title('Phase Modulated Signal');
grid on

subplot(4,1,4);
plot(t, demod);
ylabel('Amplitude');
ylim([-1, 1]);
xlabel('Time');
title('Phase Demodulated Signal');
grid on
