function [x, t] = cosfunc(A, w, k, dur)
f = w/(2*pi);
t = 0: dur/(20*f): dur;
x = A*cos(w*t + k);
plot(t, x);

end