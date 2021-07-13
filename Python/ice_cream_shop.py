# Feynman's Ice Cream Shop.

flavours = ['Vanilla', 'Chocolate', 'Cookies N Cream', 'Mint Chocolate Chip', 'Chocolate Chip Cookie Dough', 'Buttered Pecan', 'Cookie Dough', 'Strawberry', 'Mango', 'Banana', 'Orange']
scoop_prices = {'One' : 'Rs. 60', 'Two' : 'Rs. 120', 'Three' : 'Rs. 150', 'Four' : 'Rs. 200', 'Five' : 'Rs. 230'}

print('\tWelcome to\n')
print("\t\033[1;35;40mFeynman's \033[0;37;46mIce-Cream \033[0;37;40m\n")
flavours.sort()

for x in range(len(flavours)):
    print(x + 1, '-', '\033[1;41;37m', flavours[x], ' \033[0;37;40m')

print('\n')

flavour_number = int(input('Enter Flavour Number...\t'))

if flavour_number >= 0 or flavour_number <= len(flavours):
    print(flavours[flavour_number - 1], 'Flavour is Available.')
    
    scoop = int(input('Scoops? '))
    
    if scoop == 1:
        scoop = 'One'
    elif scoop == 2:
        scoop = 'Two'
    elif scoop == 3:
        scoop = 'Three'
    elif scoop == 4:
        scoop = 'Four'
    elif scoop == 5:
        scoop = 'Five'
    else:
        print('\nFamily Pack is Available.')

    if scoop in scoop_prices:
        print('\nPrice of', scoop, 'scoop is:\033[1;35;40m', scoop_prices[scoop], '\033[0;37;40m')
    
    else:
        print('Price of Family Pack is: Rs. 500')

else:
    print('Not Available.')
