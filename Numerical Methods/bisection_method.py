def bisection_method(f, R, n):
    """
    f(x) : Function,
    R = [a, b]: Range of f(x) in which it changes its sign at least once,
    n : Number of iterations.
    """
    a = R[0]
    b = R[1]
    if f(a) * f(b) < 0:
        for i in range(0, n):
            c = (a + b) / 2
            if f(a) * f(c) < 0:
                b = c

            elif f(b) * f(c) < 0:
                a = c

            else:
                break
    else:
        raise Exception("Bisection Method Can't Work!")
    
    return c


f = lambda x: 2*x**3 + x - 2
R = [0, 1]
n = 4
x = bisection_method(f, R, n)
print(x)
root = 0.835122345

err = abs(1 - x/root) * 100
print("Error = {a:.2f}%".format(a = err))
