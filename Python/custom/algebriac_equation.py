import numpy as np
import scipy as sp
import cmath

print("1) Linear Equations. \n 2) Quadratic Equations. \n 3) Cubic Equations.")
x = int(input("Enter Type: "))

def cbrt(x):
    x = complex(x)
    return (x)**(1/3)                     #complex cube root.

def sqrt(x):
    return np.lib.scimath.sqrt(x)         #complex square root.

def inverse(A):
    return np.linalg.inv(A)               #inverse of a matrix.

if x == 1:
    print("Linear Equations.")
    a = float(input("a = "))
    b = float(input("b = "))
    r1 = float(input("r1 = "))
    c = float(input("c = "))
    d = float(input("d = "))
    r2 = float(input("r2 = "))
    A = np.array([[a,b],[c,d]])
    B = np.array([[r1],[r2]])
    X = inverse(A).dot(B)
    print("X =", X, sep=" ")

elif x == 2:
    print("Quadratic Equation.")
    a = float(input("a = "))
    b = float(input("b = "))
    c = float(input("c = "))
    x1 = (- b +  sqrt(b**2 - 4*a*c))/(2*a)
    x2 = (- b -  sqrt(b**2 - 4*a*c))/(2*a)
    print("x1 =", x1, sep=" ")
    print("x2 =", x2, sep=" ")
    
elif x == 3:
        print("Cubic Equation.")
        p = float(input("p = "))
        q = float(input("q = "))
        #cardan's formula.
        x0 = cbrt( (-q/2) + sqrt( (q**2)/4 + (p**3)/27 ) ) + cbrt( (-q/2) - sqrt( (q**2)/4 + (p**3)/27 ) )
        x1 = (- x0/2 +  sqrt( (x0**2)/4 + q/x0 ))
        x2 = (- x0/2 -  sqrt( (x0**2)/4 + q/x0 ))
        print(x0,x1,x2, sep=" ")

else:
    print("Syntax Error.")
