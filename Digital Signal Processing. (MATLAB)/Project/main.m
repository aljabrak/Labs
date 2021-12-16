clear
clc

[y, Fs, nbits] = wavread('feynman.wav');
sound(y, Fs);

Mean = 0.00;
Variance = 0.005;
z = imnoise(y,'Gaussian', Mean, Variance);
sound(z, Fs);
