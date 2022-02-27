from numpy import *


def newtons_method(f, df, x0, n):
    """
    f(x) : Function,
    df(x) : Derivative of function,
    x0 : Inspected (guessed) root,
    n : Number of iterations.
    """
    x = x0
    iterations = 0
    
    for a in range(1, n):
        iterations += 1
        x -= f(x) / df(x)
        
        if f(x) / df(x) == 0:
            print("Iterations: {a:.0f}".format(a = iterations))
            break
            
    return x


f = lambda x: 4 * exp(-x) * sin(x) - 1
df = lambda x: 4 * exp(-x) * (cos(x) - sin(x))
x0 = 0.25
n = 100

x = newtons_method(f, df, x0, n)
print("(", x, ", ", f(x), ")", sep="")
