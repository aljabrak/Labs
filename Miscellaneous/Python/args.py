# Python program to illustrate
# *args with first extra argument
def myFun(arg1, *argv):
	print ("First argument :", arg1)
	for arg in argv:
		print("Next argument through *argv :", arg)

myFun('Hello', 'Welcome', 'to', 'GeeksforGeeks')
