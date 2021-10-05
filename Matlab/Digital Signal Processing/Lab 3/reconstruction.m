clear
clc
load lighthouse

p = 3;
img = uint8(255*mat2gray(xx));
xx3 = img(1:p:end, 1:p:end);
imshow(xx3);
L = size(xx3);  
n1 = 1:L(1);   
tti = 1:1/3:L(1);
down_sampled = double(xx3);
linear = interp1(n1,down_sampled,tti);
size(linear)
n2 = 1:L(2);   
tti2 = 1:1/3:L(2); 
xxlinear = interp1(n2, linear', tti2);   
xxlinear2 = uint8(xxlinear);
imshow(xxlinear2');
xlabel('Reconstructed Image.');
       
