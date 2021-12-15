clear
clc
load lighthouse
imshow(xx);
ww200 = xx(200,:);
disp(ww200);

stem(ww200);
p = 2;
wp = xx(1:p:end, 1:p:end);
imshow(wp);