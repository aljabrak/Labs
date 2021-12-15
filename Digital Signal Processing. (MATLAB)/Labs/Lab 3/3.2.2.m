clc

xr1 = (-2).^(0:6);
L = length(xr1);
nn = ceil((0.999:1:4*L)/4);
xr1hold = xr1(nn);
plot(xr1hold);

n1 = 0:6;
xr1 = (-2).^n1;
tti = 0:0.1:6;
xlinear = interp1(n1, xr1, tti);
stem(tti, xlinear);
