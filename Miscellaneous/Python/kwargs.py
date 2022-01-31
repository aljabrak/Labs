# Python program to illustrate
# *args with first extra argument.

def myFun(arg1, *argv):
	print ("First argument :", arg1)
	for arg in argv:
		print("Next argument through *argv :", arg)

myFun('Hello', 'Welcome', 'to', 'GeeksforGeeks')



# Python program to illustrate
# *kwargs for variable number of keyword arguments

def myFun(**kwargs):
	for key, value in kwargs.items():
		print ("%s == %s" %(key, value))

# Driver code
myFun(first ='Geeks', mid ='for', last='Geeks')
