from numpy import *


def absolute_error(xt, x):
    if len(xt) and len(x) != 1:
        E = []
        for a, b in zip(xt, x):
            E.append(
                abs(a - b)
            )
        return E
    
    else:
        return abs(xt - x)

      
def relative_error(xt, x):
    if len(xt) and len(x) != 1:
        E = []
        for a, b in zip(xt, x):
            E.append(
                abs(1 - b/a)
            )
        return E
    
    else:
        return abs(1- x/xt)

      
def percentage_error(xt, x):
    if len(xt) and len(x) != 1:
        E = []
        for a, b in zip(xt, x):
            E.append(
                abs(1 - b/a) * 100
            )
        return E
    
    else:
        relative_error(xt, x) * 100

        
def approximate_error(x2, x1):
    if len(x2) and len(x1) != 1:
        E = []
        for a, b in zip(x2, x1):
            E.append(
                abs(a/b - 1) * 100
            )
        return E
    
    else:
        return abs(
            (x1 - x2) / x2
        )
