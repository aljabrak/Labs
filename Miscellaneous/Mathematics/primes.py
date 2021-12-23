from numpy import *
from math import *
from matplotlib.pyplot import *


def Prime(N):
    P = []
    for p in range(0, N + 1):
        if p > 1:
            for a in range(2, p):
                if (p % a) == 0:
                    break
            else:
                P.append(p)
    P = list(dict.fromkeys(P))
    return P


def main():
    N = int(input("Enter Number: N = "))
    # primes = Prime(N)
    # print(primes)
    # natural = [i for i in range(1, N + 1)]
    # figure, axis = subplots(2, 1)
    # axis[0].stem(primes)
    # axis[1].stem(natural)
    # show()

    P = [] # Probability of number of primes in given range of natural numbers.
    for j in range(1, N + 1):
        primes = Prime(j)
        n = len(primes)
        p = n/j
        P.append(p)
    
    print("P = ", P)
    plot(P)
    xlim([1, N])
    ylabel("Probability.")
    xlabel("N")
    grid()
    savefig("primes.png")
    show()
    
    figure, axis = subplots(2, 2)
    axis[0, 0].plot(P[:20])
    axis[0, 1].plot(P[:50])
    axis[1, 0].plot(P[:500])
    axis[1, 1].plot(P)
    xlim([1, N])
    savefig("probability.png")
    show()



main()
