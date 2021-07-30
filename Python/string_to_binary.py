import math


def stringtobinary(a):
  l,m=[],[]
  for i in a:
    l.append(ord(i))
  for i in l:
    m.append(int(bin(i)[2:]))
  return m

print("Hello World!") 
text = stringtobinary("Hello World!")
print(text)
