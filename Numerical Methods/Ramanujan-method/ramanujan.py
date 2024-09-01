def reverse(array):
	return [a for a in reversed(array)]


def ramanujan_method(C, n):
    """
    An iterative procedure to determine the
    smallest root of equation f(x) = 0, where
    f(x) is of the form:
    f(x) = a[n]x^(n) + a[n - 1]x^(n - 1) + ... + a[1]x + a[0]
    C is vector containing polynomial coefficient.
    C = [a[n], a[n - 1], ..., a[1], a[0]]
    n is the number of iterations.
    """
    C = reverse(C)
    a = []
    for c in C:
        a.append(
           - c / C[0]
        )
    
    for i in range(n):
        a.append(0)

    b = [0, 1]
    
    for i in range(2, n + 1):
        value = 0
        for j in range(1, i):
            if j < i:
                value += a[i - j] * b[j]
        b.append(value)
    
    return b[n - 1] / b[n]


def main():
    a = [1, -9, 26, -24]
    n = 9
    print(
        ramanujan_method(a, n)
    )

main()




"""
Srinivasa Ramanujan (1887-1920) described
an iterative procedure to determine the
smallest root of equation f(x) = 0, where
f(x) is of the form:
f(x) = 1 - (a[1]x + a[2]x^2 + a[3]x^3 + ...)
"""