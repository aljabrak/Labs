## Integration.

from sympy.interactive import printing
printing.init_printing(use_latex=True)
from sympy import *
import sympy as sp

x = sp.Symbol('x')
y = sp.tan(x)

z = integrate(y,x)
display(z)
solve(z)


from scipy.integrate import quad

def integrand(x):
    return x**2
    ans = quad(integrand, 0, 1)
    print,ans
