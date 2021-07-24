phonebook = {}
# phonebook = dict()
x = True
while x is True:
    number = str(input("Contact Number: "))
    name = str(input("Save Contact As: "))
    phonebook[name] = number
    x = int(input("Press 1 To Save. "))
    if x == 1:
        x = False
        print("Saving...")
    else:
        x = True

print(phonebook)
