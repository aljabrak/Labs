# Starting Out with Python (4th Edition).
# Tony Gaddis.
# Chapter:3 
# Q.1 Number Analyzer.

print("Enter An Integer: ", end=" ")
x = int(input())

if x > 0:
    print("Positive.")
    if x%2 == 0:
        print("Even.")
        
    else:
        print("Odd.")

elif x < 0:
    print("Negative.")
    if x%2 == 0:
        print("Even.")
    
    else:
        print("Odd.")

else:
    print("Zero.")
    print("Even.")
