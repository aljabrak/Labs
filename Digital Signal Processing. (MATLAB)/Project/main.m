clear all;
clc
[x, Fs] = audioread('feynman.wav');
sound(x, Fs);
pause(30);
[y, F] = FFT(x, Fs);
compressed_audio = compress(y, F);
sound(compressed_audio, Fs);
graphs(Fs, x);
