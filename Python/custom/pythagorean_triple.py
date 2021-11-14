from math import *

def pythagorean_triple(a, b):
    c = sqrt(a**2 + b**2)
    if float(c)%int(c) == 0:
        print("Pythagorean Triple: (a,b,c) = ", "(", a, ",", b, ",", int(c), ")")
    else:
        print("Not Pythagorean Triple.")
    
print("A Pythagorean Triple (a,b,c) contains \n three positive integers which satisfy \n Pythagoras Theorem: a^2 + b^2 = c^2")
a = int(input("a = "))
b = int(input("b = "))
pythagorean_triple(a,b)
