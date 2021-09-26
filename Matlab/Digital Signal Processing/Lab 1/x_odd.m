function xo = x_odd(x)
x_reverse = fliplr(x);% time reversal
xo = 0.5*(x - x_reverse); %odd component

end