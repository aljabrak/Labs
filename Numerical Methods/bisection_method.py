from numpy import *


def bisection_method(f, R, n):
    """
    f(x) : Function,
    R = [a, b]: Range of f(x) in which it changes its sign at least once,
    n : Number of iterations.
    """
    a = R[0]
    b = R[1]
    iterations = 0
    
    if f(a) * f(b) < 0:
        
        for i in range(0, n):
            iterations += 1
            c = (a + b) / 2
            
            if f(a) * f(c) < 0:
                b = c

            elif f(b) * f(c) < 0:
                a = c
            
            elif round(f(a) * f(b), 4) == 0:
                print("Iterations: {a:.0f}".format(a = iterations))
                break

            else:
                break
    else:
        raise Exception("Bisection Method Can't Work!")
    
    return c


f = lambda x: 0.5 + 2*exp(3*x) - 1*exp(-1*x) 
R = [-0.5, 0]
n = 300

x = bisection_method(f, R, n)
print("(", x, ", ", abs(f(x)), ")", sep="")
