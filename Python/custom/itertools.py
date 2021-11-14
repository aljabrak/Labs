# Itertools.
# There are two types of iterators:
# 1) Infinite Iterators. (count, cycle, repeat)
# 2) Finite Iterators. (chain, compress, dropwhile)

from itertools import *
from functools import *
from operator import *

even = count(start=0, step=2)

for number in even:
  if number < 10:
    print(number)
  else:
    break

natural = [1, 2, 3, 4]
fibbonnaci = [1, 1, 2, 3, 5, 8, 13, 21]

for a, b in zip(cycle(natural), fibbonnaci):
  print(a, b)

text = repeat("Hello, world!", times = 4)
for word in text:
  print(word)

numbers = chain(natural, fibbonnaci)
for number in numbers:
  print(number)

whole = [0, 1, -2, 2, -3]
check = [True, True, False, True, False]

for number in compress(whole, check):
  print(number)

numbers = [0, 0, 1, 2, 0, 3]

for elements in dropwhile(lambda x: x == 0, numbers):
  print (elements)
