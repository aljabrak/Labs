def newtons_method(f, df, x0, n):
    """
    f(x) : Function,
    df(x) : Derivative of function,
    x0 : Inspected (guessed) root,
    n : Number of iterations.
    """
    x = x0
    for a in range(1, n):
        x -= f(x) / df(x)
    
    return x


f = lambda x: 2*x**3 + x - 2
df = lambda x: 6*x**2 + 1
x0 = 0.5
n = 10000
x = newtons_method(f, df, x0, n)
print(x)
root = 0.835122345

err = abs(1 - x/root) * 100
print("Error = {a:.2f}%".format(a = err))
