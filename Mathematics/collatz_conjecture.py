"""
An orbit is what you get if you start with
a number and apply a function repeatedly, taking
each output and feeding it back into the function
as a new input. There are infinitely many numbers
whose Collatz orbits pass through 1.
https://www.quantamagazine.org/why-mathematicians-still-cant-solve-the-collatz-conjecture-20200922/
"""


def f(n):
    if n % 2 == 0:
        a = n / 2
        print(a)
        f(a)

    elif n == 1:
        n = n
        
    else:
        a = 3 * n + 1
        print(a)
        f(a)

N = 10**20
f(N)
