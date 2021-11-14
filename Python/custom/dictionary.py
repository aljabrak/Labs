# Dictionary and Sets.
phonebook = {'Chris': '555-1111', 'Katie': '555-2222', 'Joanne': '555-3333'}
# phonebook = dict()

key = str(input("Name: "))
value = phonebook.get(key, "Not Found.")
print(value)

for key, value in phonebook.items():
  print(key, value)

for key in phonebook.keys():
  print(key)

for value in phonebook.values():
  print(value)

key = str(input("Name: "))
value = phonebook.pop(key, "Not Found.")
print(value)
print(phonebook)

key, value = phonebook.popitem()
print(key, value)
print(phonebook)

phonebook['Katie'] = '555-2222'
phonebook['Joanne'] = '555-3333'
print(phonebook)

del phonebook['Joanne']
print(phonebook)

phonebook.clear()
print(phonebook)


integers = set([-4, -3, -2, -1, 0, 1, 2, 3, 4])
natural_numbers = set([1, 2, 3, 4, 5, 6, 7, 8])
whole_numbers = set([0, 1, 2, 3, 4, 5, 6, 7, 8])

print( whole_numbers.union(natural_numbers) )
print( natural_numbers.union(whole_numbers) )
print( integers.intersection(whole_numbers) )
print( whole_numbers.update(set([7, 8 ,9])) )
print( natural_numbers.isdisjoint(integers) )
print( natural_numbers.issubset(whole_numbers) )
print( whole_numbers.issuperset(integers) )
print( natural_numbers.difference(whole_numbers) )
print( natural_numbers.symmetric_difference(whole_numbers) )
