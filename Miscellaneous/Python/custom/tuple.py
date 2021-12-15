# List and Tuples.

numbers = []

for number in range(5):
  numbers.append(number)

item = int(input("x = "))

try:
  numbers.index(item)
  print(numbers)

except ValueError as err:
  print(err)


numbers.insert(2, 5)
print(numbers)

numbers.sort()
print(numbers)

numbers.reverse()
print(numbers)
numbers.reverse()

item = int(input("x = "))
numbers.remove(item)
print(numbers)

print(min(numbers))
print(max(numbers))

numbers = tuple(numbers)
print(numbers)
numbers = list(numbers)
print(numbers)

del numbers
