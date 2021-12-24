from numpy import *


def Fibonacci(N):
    a = 0
    b = 1
    F = []
    for j in range(1, N + 1):
        c = a + b
        a = b
        b = c
        F.append(c)
    
    return F
        

def main():
    N = int(input("N = "))
    n = Fibonacci(N)
    j = len(n)

    golden_mean = 1 + n[j - 2]/n[j - 1]
    phi = (1 + sqrt(5))/2
    print(golden_mean)
    print("Error = ", phi - golden_mean)



main()
