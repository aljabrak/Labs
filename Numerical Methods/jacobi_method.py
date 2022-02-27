from numpy import *
from error import relative_error, percentage_error


def jacobi_method(A, b, x0, n):
    x = [x0[0], x0[1], x0[2]]
    iterations = 0

    if (dot(A, x) - b).all() == 0:
        pass
      
    else:
        for a in range(0, n):
            iterations += 1
            x[0] = (b[0] - A[0][1]*x[1] - A[0][2]*x[2]) / A[0][0]
            x[1] = (b[1] - A[1][0]*x[0] - A[1][2]*x[2]) / A[1][1]
            x[2] = (b[2] - A[2][0]*x[0] - A[2][1]*x[1]) / A[2][2]
            if (dot(A, x) - b).all() == 0:
                print("Iterations: {a:.0f}".format(a = iterations))
                break
    return x

A = [[10, 3, 1], [3, 10, 2], [1, 2, 10]]
b = [19, 29, 35]
x0 = [0, 0, 0]
xt = [1, 2, 3]
n = 5

x = jacobi_method(A, b, x0, n)
print(x, percentage_error(xt, x))
