from numpy import *


def eigen_vector(A, x0, n):
    x = x0
    iter = 0
    for a in range(n):
        iter += 1
        x = dot(A, x)
        v = [x[0]/x[1], 1]
        a = dot(dot(A, x), x) / dot(x, x)

        if (dot(A, v) - dot(a, v)).all() == 0:
            print("Iterations: {a:.0f}".format(a = iter))
            break 

    return v, a


# def power_method(A, x0, n):
#     x = x0
#     for a in range(n):
#         x = dot(A, x)
#
#     x = [x[0]/x[1], 1]
#     return x


# def rayleigh_quotient(A, x0, n):
#     x = x0
#     for a in range(n):
#         x = dot(A, x)
    
#     eigen_value = dot(dot(A, x), x) / dot(x, x)

#     return eigen_value



A = [[2, -12], [1, -5]]
x0 = [1, 1]
n = 1000

[v, a] = eigen_vector(A, x0, n)
print("Eigen-vector: ", v)
print("Eigen-value: ", a)
