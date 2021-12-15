phonebook = {}

def show_contact_list():
    if phonebook != dict():
        print("Your Contact List: ")
        for key in phonebook:
            print(key, phonebook[key])
    else:
        print("Your Contact List is Empty!")

def delete_contact():
    name = str(input("Enter Name: "))
    number = phonebook.get(name, 'Contact Not Found!')
    print(name, " : ", number)
    if number in phonebook:
        y = int(input("Press 1 to Delete Contact. "))
        if y == 1:
            del phonebook[name]
            print('Contact Deleted.')
    
def delete_contact_list():
    phonebook.clear()
    print("Your Contact List is Deleted!\n")
    print("Your Contact List is Empty!", phonebook)

def save_new_contact():
    number = str(input("Contact Number: "))
    name = str(input("Save Contact As: "))
    phonebook[name] = number
    y = int(input("Press 1 To Save. "))
    if y == 1:
        print("Contact Saved.")
        print(name, " : ", number)

y = True
while y is True:
    print("1) Contact List. \n 2) Save Contact. \n 3) Delete Contact. \n 4) Delete Contact List.")
    i = int(input("Press: "))

    if i == 1:
        show_contact_list()
        y = True
    elif i == 2:
        save_new_contact()
        y = True
    elif i == 3:
        delete_contact()
        y = True
    elif i == 4:
        delete_contact_list()
        y = True
    else:
        y = True
