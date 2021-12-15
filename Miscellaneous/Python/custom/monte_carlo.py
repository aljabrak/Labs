from scipy import random
import numpy as np
import matplotlib.pyplot as plt


a = 0
b = np.pi
N = 2000

def sin(x):
	return np.sin(x)

plots = []

for i in range(N):
	xrand = np.zeros(N)

	for i in range (len(xrand)):
		xrand[i] = random.uniform(a,b)
	integral = 0.0

	for i in xrand:
		integral += sin(i)

	ans = (b-a)/float(N)*integral
	plots.append(ans)

plt.title("Monte Carlo Integration.")
plt.hist (plots, bins=30, ec="black")
plt.xlabel("Areas.")
plt.ylabel("Density.")
plt.savefig("monte_carlo.png")
plt.show()
