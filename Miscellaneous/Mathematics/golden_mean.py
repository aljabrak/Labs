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
    j = len(S)
    golden_mean = 1 + S[j - 2]/S[j - 1]
    phi = (1 + sqrt(5))/2
    
    print(S)
    print(golden_mean)
    print("Error = ", phi - golden_mean)



main()
