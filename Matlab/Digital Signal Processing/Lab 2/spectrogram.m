t = 0:0.001:2;
f1 = 1;
f2 = 2;
f3 = 3;

x1 = sin(2*pi*f1*t);
x2 = sin(2*pi*f2*t);
x3 = sin(2*pi*f3*t);

test_t = [t t t];
final_t = 0:0.001:6.002;
final_x = [x1 x2 x3];

plot(final_t, final_x);
xlabel('Time.');
ylabel('Concatenated Signal.')

spectrogram(final_x, 128, 120, 128, 1e3, 'yaxis');
colormap jet


