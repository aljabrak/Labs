function [u] = uncompress(x, Fs, p)
Fs_new = p*Fs;
[P, Q] = rat(Fs_new/Fs);
u = resample(x, P, Q);
end

