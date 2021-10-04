clear
clc
load lighthouse
imshow(xx);
ww200 = xx(200,:);
disp(ww200);

stem(ww200);
p = 3;
xx3 = xx(1:p:end, 1:p:end);
imshow(xx3);


xr1 = (-2).^(0:6);
L = length(xr1);
nn = ceil((0.999:1:4*L)/4);
xr1hold = xr1(nn);
plot(xr1hold);
