from numpy import *


def fixed_point_method(c, g, n):
    f = c - g(c)
    iterations = 0

    if f == 0:
        pass
    
    else:
        for a in range(0, n):
            iterations += 1
            c = g(c)
            if f == 0:
                print("Iterations: {a:.0f}".format(a = iterations))
                break
    return c.real


g = lambda x: (4*x - 1)**(1/3)
n = 1000
c = 0

x = fixed_point_method(c, g, n)
print(x)
print(x - g(x))
