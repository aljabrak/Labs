% Speech Compression Using FFT.

clear all;
clc
[x, Fs] = audioread('feynman.wav');
L = length(x);
ts = 1/Fs;
tcomplete = (L - 1)*ts;
t = 0 : ts : tcomplete;
sound(x, Fs);
pause(25);

% FFT of Speech Signal.
[y1, F1] = FFT(x(:,1), Fs);
[y2, F2] = FFT(x(:,2), Fs);
F = F1;

% Compression of Speech.
z_1 = compress(y1, F);
z_2 = compress(y2, F);
z = [z_1; z_2]';
p = input('Enter Compression Coefficient: p = ');


if isempty(p)
    p = 3/2;
else
    p;
end

compressed_audio = sample(z, p);
Lc = length(compressed_audio);
tcomp = (Lc - 1)*ts;
t_c = 0: ts : tcomp;
sound(compressed_audio, Fs);
pause(15);


% Uncompression of Compressed Speech.
u = uncompress(compressed_audio, Fs, p);
Lu = length(u);
t_uncomp = (Lu - 1)*ts;
t_u = 0: ts : t_uncomp;
sound(u, Fs);


% Size of Compressed Audio and Reconstructed Audio.
disp(size(x));
disp(size(compressed_audio));
disp(size(u));



% Graphs.
[y, F] = FFT(x, Fs);
z = real(fftshift(fft(compressed_audio)));
Fc = Fs/Lc*(-Lc/2: Lc/2-1);

figure(1);
subplot(2, 1, 1);
plot(F, real(y), 'r');
xlim([-5000, 5000]);
title('Frequency Spectrum of Audio Signal.');
xlabel('F(Hz)');
ylabel('Y(jw)');
grid on;

subplot(2, 1, 2);
plot(Fc, z, 'm');
xlim([-5000, 5000]);
title('Frequency Spectrum of Compressed Audio Signal.');
xlabel('F(Hz)');
ylabel('Y(jw)');
grid on;



figure(2);
subplot(3, 1, 1);
plot(t, x, 'r');
ylim([-0.8, 0.8]);
title('Audio Signal.'); 
xlabel('Time (t).');  
ylabel('Amplitude.');
grid on;

subplot(3, 1, 2);
plot(t_c, compressed_audio, 'g');
ylim([-0.8, 0.8]);
xlim([0, 25]);
title('Compressed Audio Signal.');
xlabel('Time (t).');
ylabel('Amplitude.');
grid on;

subplot(3, 1, 3);
plot(t_u, u, 'b');
ylim([-0.8, 0.8]);
xlim([0, 25]);
title('Recontructed Compressed Audio Signal.');
xlabel('Time (t).');
ylabel('Amplitude.');
grid on;