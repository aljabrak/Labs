from scipy import random
import numpy as np

a = 0
b = np.pi
N = 100000
xrand = random.uniform(a,b,N)

integral = 0.0
for i in range(N):
    integral += np.sin(xrand[i])

ans = ((b-a)/float(N))*integral                       #exact ans is 2.
print("integration of sin(x) on [0,pi] is: ", ans)
