"""
Digital Signal Processing Lab 1 diffeqn(x, a) function to solve difference equation (Matlab).
https://github.com/aljabrak/LABS-Projects/blob/main/Matlab/Digital%20Signal%20Processing/Lab%201/diffeqn.m
"""

from numpy import *
from matplotlib.pyplot import *

def diffeq(x, a):
    y = []
    for k in range(len(x)):
        if k == 0:
            y.append(x[0])
        
        else:
            y.append(a*y[k-1] + x[k])
    
    print(y)
    stem(range(len(x)), y)
    show()

x = [2, 3, -1, 2, -3]
for i in zeros(5,):
    x.append(i)

diffeq(x, 2)




