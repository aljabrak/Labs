## Differential Equations (jupyter notebook).
from sympy.interactive import printing
printing.init_printing(use_latex=True)
from sympy import *
import sympy as sp

x = sp.Symbol('x')
y = sp.Function('y')(x)

diffeq = Eq(y.diff(x,x),x**(1/2))
display(diffeq)

dsolve(diffeq,y)
