print("Subject: Literature.", end=" ")
print("Instructor: Dr. Suarez")
print("------ Quiz: 01 ------")
print("Total Marks: 10", end=" ")
print("Obtained Marks:", end=" ")
x = float(input())
percentage = x*10

if percentage >= 90:
    print("Grade: A")

elif percentage >= 80 and percentage <= 89:
    print("Grade: B")

elif percentage >= 70 and percentage <= 79:
    print("Grade: C")

elif percentage >= 60 and percentage <= 69:
    print("Grade: D")

elif percentage < 60:
    print("Grade: F")

else:
    print("Enter Correct Obtained Marks.")
