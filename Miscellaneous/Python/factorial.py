# Starting Out with Python (4th Edition).
# Tony Gaddis.
# Page 227.
# Programming Exercise.
# Q 12. Calculating Factorial of a Number.

print("Factorial: n! = n(n-1)(n-2)(n-3)...")
print("Enter the number.")
n = int(input("n = "))

if n >= 0:
    # since n! = n(n-1)(n-2)(n-3) and n! = n(n-1)!;
    # so n! = n(n-1)(n-2)(n-3)...0! and 0! = 1.
    f = 1                       
    for x in range(0, n, 1):
        f *= (n-x)             #f = n(n-1)(n-2)(n-3)...0!
    
    print("n! = ", f)
else:
    print("Factorial of Negative Numbers is not defined.")
