from numpy import *
import os

W_n = []
N = int(input('Enter Period: N = '))
for i in range(0, N+1):
    z = complex(cos(2*pi/N), sin(2*pi/N))
    W_n.append(z)

#print(W_n)

with open("fft.txt", 'w') as file:
    for a in W_n:
        file.writelines(str(a))

with open("fft.txt", 'r') as file:
    text = file.readlines()
    for line in text:
        print(line)
