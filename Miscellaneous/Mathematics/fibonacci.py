from numpy import *


def Fibonacci(N):
    a = 0
    b = 1
    F = [a, b]
    for j in range(1, N + 1):
        c = a + b
        a = b
        b = c
        F.append(c)
    
    return F
        

def main():
    N = int(input("N = "))
    S = Fibonacci(N)
    print(S)


main()
