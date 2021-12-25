function [y, Frequency] = FFT(x, Fs)
length_x = length(x);
y_transform = fft((x));
y = fftshift(y_transform);
Frequency = Fs/length_x*(-length_x/2: length_x/2-1);
end