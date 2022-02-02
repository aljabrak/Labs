"""
An orbit is what you get if you start with
a number and apply a function repeatedly, taking
each output and feeding it back into the function
as a new input. There are infinitely many numbers
whose Collatz orbits pass through 1.
https://www.quantamagazine.org/why-mathematicians-still-cant-solve-the-collatz-conjecture-20200922/
"""


from matplotlib.pyplot import *
from itertools import *


def f(n):
    y = [n]
    step = 0
    for i in count(0, 2):
        if n % 2 == 0:
            n = n/2
            y.append(n)
            step += 1

        elif n == 1:
            break
        
        else:
            n = 3 * n + 1
            y.append(n)
            step += 1
    
    return y, step



X = f(9341972891)[0]
n = f(9341972891)[1]

print(X)
print(n)

plot(X)
grid(True)
show()
