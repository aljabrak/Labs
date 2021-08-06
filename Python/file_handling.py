file = open('file', 'w')
file.write('Hello, world!')
file.close()

file = open('file', 'w')
try:
	file.write('Hello, world!')
finally:
	file.close()


with open('file', 'w') as file:
	file.write('Hello, world!')
