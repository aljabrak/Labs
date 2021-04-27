##Monte Carlo Integration

from scipy import random
import numpy as np
import matplotlib.pyplot as plt

a = 0
b = np.pi  ## Limits of the integral.
N = 10000
xrand = random.uniform(a,b,N)

def func(x):
    return np.sin(x)
    integral = 0.0
    for i in range(N):
        integral += func(xrand[i])
        answer = (b-a)/float(N)*integral
        print ("The integral of sin(x) = ", answer)
