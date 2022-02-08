import numpy as np


def newtons_method(f, df, x0, n):
    """
    f(x) = Function,
    df(x) = Derivative of function,
    x0 = Inspected (guessed) root,
    n = Number of iterations.
    """
    x = x0
    for a in range(1, n):
        x -= f(x) / df(x)
    
    return x


f = lambda x: x**2 + 4*x + 1
df = lambda x: 2*x + 4
x0 = 0
n = 10000
root = newtons_method(f, df, x0, n)
print(root)

err = (1 - (root / (-2 + np.sqrt(3)))) * 100
print("Error = {a:.3e}%".format(a = err))
