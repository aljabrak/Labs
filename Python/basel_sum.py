from numpy import *

basel = 0.0

for x in range(10000000):
    basel += 1/float( (x + 1)**2 )
print("Basel Sum = ", basel)
error = (pi**2/6) - basel
print("Error: ", error)
