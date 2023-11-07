# import numpy as np
# let's not use numpy

# i'm reading https://lucidar.me/en/mathematics/least-squares-fitting-of-circle/
# as i write this so there might be some
# realizations that make this look unstructured

# first of all let's define what square needs to be least
# F = sum(d_i^2)
# where d_i is the distance from the point to the circle
# i.e. d_i = sqrt((x_i - a)^2 + (y_i - b)^2) - r
# where (a, b) is the center of the circle

# minimizing F with (a, b, r) is a non-linear optimization problem
# without closed form solution
# we need to use iterative method

# first
# if we have a set of x_i and y_i
# ideally when d_i = 0 we can write
# (x_i - a)^2 + (y_i - b)^2 = r^2
# x_i^2 - 2 * x_i * a + a^2 + y_i^2 - 2 * y_i * b + b^2 = r^2
# x_i^2 + y_i^2 = 2 * x_i * a + 2 * y_i * b + r^2 - a^2 - b^2
# let's say
# p = 2 * a
# q = 2 * b
# s = r^2 - a^2 - b^2
# then
# p * x_i + q * y_i + s = x_i^2 + y_i^2

# now we have a set of "linear equations"
# we can write it in matrix form
# [x_1 y_1 1] [p]   [x_1^2 + y_1^2]
# [x_2 y_2 1] [q] = [x_2^2 + y_2^2]
# [x_3 y_3 1] [s]   [x_3^2 + y_3^2]
# ...
# [x_n y_n 1]       [x_n^2 + y_n^2]

# "ideally" there should be a set of (p, q, s)
# that satisfies all the equations if there were three points

# wait a minute
# I could've just solve the equation
# as if there were three points


def solve_eq(X: list[float], Y: list[float]) -> tuple[float, float, float]:
    # [x_1 y_1 1]
    A = [[X[i], Y[i], 1] for i in range(len(X))]
    # [x_1^2 + y_1^2]
    B = [[X[i] ** 2 + Y[i] ** 2] for i in range(len(X))]
    A_inv = inverse(A)
    [p, q, s] = transpose(mult(A_inv, B))[0]

    a = p / 2
    b = q / 2
    r = (s + a**2 + b**2) ** 0.5

    return (a, b, r)


# stolen from kadai6
def mult(m1: list[list[float]], m2: list[list[float]]) -> list[list[float]]:
    m2n = len(m2[0])
    m1m = len(m1)

    prod = [[0.0 for _ in range(m2n)] for _ in range(m1m)]

    for i in range(len(m1)):
        for j in range(len(m2[0])):
            for k in range(len(m2)):
                prod[i][j] += m1[i][k] * m2[k][j]

    return prod


def reshape(arr: list[float], m: int, n: int) -> list[list[float]]:
    new_arr = [[0.0 for _ in range(n)] for _ in range(m)]
    for i in range(m):
        for j in range(n):
            # new_arr[1][2] = arr[1 * 3 + 2]
            new_arr[i][j] = arr[i * n + j]

    return new_arr


# stolen from kadai8
def minor(m: list[list[float]], i: int, j: int) -> list[list[float]]:
    # without the ith row and jth column
    new = [row[:j] + row[j + 1 :] for row in m[:i] + m[i + 1 :]]

    return new


def adj_mat(m: list[list[float]]) -> list[list[float]]:
    # (-1)^(i + j) * det(minor(m, i, j))
    # but i secretly swap i and j
    new = [
        [(-1) ** (i + j) * det(minor(m, i, j)) for i in range(len(m))]
        for j in range(len(m[0]))
    ]

    return new


def det(m: list[list[float]]) -> float:
    # probably recursion?
    n_rows = len(m)

    # hope it's == len(m[0]) w/o checking

    if n_rows == 1:
        return m[0][0]  # lol

    if n_rows == 2:
        # ad - bc
        return m[0][0] * m[1][1] - m[0][1] * m[1][0]

    return sum([m[0][j] * det(minor(m, 0, j)) * (-1) ** j for j in range(n_rows)])


def transpose(m: list[list[float]]) -> list[list[float]]:
    # swap rows and columns
    new = [[m[j][i] for j in range(len(m))] for i in range(len(m[0]))]

    return new


def flatten(m: list[list[float]]) -> list[float]:
    return [m[i][j] for i in range(len(m)) for j in range(len(m[0]))]


def inverse(m: list[list[float]]) -> list[list[float]]:
    det_m = det(m)
    adj_m = adj_mat(m)

    # m^-1 = (1 / det(m)) * adj(m)
    m_inv = [  # len(ct_m[0]) is essentially 3 but just in case
        [adj_m[i][j] / det_m for j in range(len(adj_m[0]))]
        # this too
        for i in range(len(adj_m))
    ]

    return m_inv


def convert_to_2f(x):
    return f"{x:.2f}"


def main():
    N = 3

    X = []
    Y = []

    # take N points
    for _ in range(N):
        x, y = map(float, input().split(" "))
        X.append(x)
        Y.append(y)

    (a, b, r) = solve_eq(X, Y)

    print(f"{a} {b} {r}")


if __name__ == "__main__":
    main()
