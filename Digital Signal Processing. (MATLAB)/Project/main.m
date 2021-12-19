clear all;
clc

[y, Fs] = audioread('feynman.wav');
sound(y, Fs);
% pause(30);

% Mean = 0.00;
% Variance = 0.0005;
% z = imnoise(y,'Gaussian', Mean, Variance);
% sound(z, Fs);
pause(30);

x = quantization(y, 8);
sound(x, Fs);
