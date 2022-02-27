from numpy import *


def regula_falsi_method(f, R, n):
    a = R[0]
    b = R[1]
    iterations = 0

    if f(a) * f(b) < 0:
        for i in range(0, n):
            iterations += 1
            p = (a * f(b) - b * f(a)) / (f(b) - f(a))
            if f(a) * f(p) < 0:
                b = p

            elif f(b) * f(p) < 0:
                a = p
            
            elif round(f(a) * f(b), 10) == 0:
                print("Iterations: {a:.0f}".format(a = iterations))
                break

            else:
                break
    else:
        raise Exception("Regula-Falsi Method Can't Work!")
    
    return p



f = lambda x: x**3 - 4*x + 1
R = [0, 1]
n = 1
x = regula_falsi_method(f, R, n)
print("(", x, ", ", f(x), ")", sep="")
