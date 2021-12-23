from numpy import *
from math import *
from matplotlib.pyplot import *

def Prime(N):
    P = []
    for p in range(2, N + 1):
        if p > 1:
            for a in range(2, N + 1):
                if p % a == 0 and p != 2:
                    # print(p)
                    break
                else:
                    # print("P = ", p)
                    P.append(p)
    
    P = list(dict.fromkeys(P))
    return P

def main():
    N = int(input("Enter Number: N = "))
    primes = Prime(N)
    print(primes)


main()
