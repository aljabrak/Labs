from numpy import *
from matplotlib.pyplot import *


def markov_chain(A, x, n):
    x = transpose(x)
    P = []

    for a in range(n):
        x = dot(x, A)
        for value in x:
            P.append(value)
    return x, P

A = [[0.2, 0.6, 0.2], [0.3, 0, 0.7], [0.5, 0, 0.5]]
x = [1/2, 1/4, 1/4]
n = 1000 #100000

[s, P] = markov_chain(A, x, n)
print(s)

hist(P, ec = "black", rwidth = 0.9)
show()
