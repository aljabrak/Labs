from numpy import *
from matplotlib.pyplot import *
from math import *


def fourier_series(x, n, a0, a, b):
    y = a0/2
    for i in range(0, n):
        if i < n:
            y += a[i]*cos((i+1)*x) + b[i]*sin((i+1)*x)
        else:
            break
    return y

  
y = lambda x: fourier_series(x, 100, 0, [0 for k in range(0, 100)], [(2/pi * (-1)**(i+2)/(i+1)) for i in range(0, 100)])
x = [i for i in arange(-100, 100, 0.1)]
print(x)
plot(x, y)
show()



