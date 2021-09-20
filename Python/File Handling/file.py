with open("data.txt", 'r') as file:
    text = file.readlines()
    for line in text:
        print(line)
