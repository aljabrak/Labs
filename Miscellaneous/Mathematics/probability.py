"""
Suppose two numbers are chosen at random from the
range [0, 1], according to the uniform distribution.
Suppose 'p' is the probability that the ratio of the
first number to the second rounds down to an even number.
"""


from numpy import *
from matplotlib.pyplot import *

N = 10**6
x = random.random(N)
y = random.random(N)

a = x / y 
print(a)

p = (floor(a) % 2 == 0 ).mean()
print("Probability: ", p)
# Probability = (1/2)(2 - ln(2)) = 0.6534264097200273

hist(a, range(0, 20), rwidth = 0.9)
show()
