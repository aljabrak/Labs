from scipy import random
import numpy as np
import matplotlib.pyplot as plt

a = 0
b = np.pi
N = 100000
xrand = random.uniform(a,b,N)

integral = 0.0
for i in range(N):
    integral += np.sin(xrand[i])

ans = ((b-a)/float(N))*integral
print("integration of sine(x) over a period is: ", ans)
