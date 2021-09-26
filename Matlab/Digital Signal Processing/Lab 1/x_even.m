function xe = x_even(x)
x_reverse = fliplr(x);% time reversal
xe = 0.5*(x + x_reverse); %even component

end