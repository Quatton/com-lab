import numpy as np


def convert_to_2f(x):
    converted = f"{x:.2f}"
    # idk why python have -0.00
    # but i don't want it
    if converted == "-0.00":
        converted = "0.00"

    return converted


# why i type my functions?
# because dealing with matrices is really mentally taxing
# i often make mistakes when indexing a deeply nested list
# so i type my functions to make sure i don't make mistakes
# spoiler stil do


def reshape(arr, m, n):
    new_arr = [[0.0 for _ in range(n)] for _ in range(m)]
    for i in range(m):
        for j in range(n):
            # new_arr[1][2] = arr[1 * 3 + 2]
            new_arr[i][j] = arr[i * n + j]

    return new_arr


def minor(m, i, j):
    # without the ith row and jth column
    new = [row[:j] + row[j + 1 :] for row in m[:i] + m[i + 1 :]]

    return new


def adj_mat(m):
    # (-1)^(i + j) * det(minor(m, i, j))
    # but i secretly swap i and j
    new = [
        [(-1) ** (i + j) * det(minor(m, i, j)) for i in range(len(m))]
        for j in range(len(m[0]))
    ]

    return new


def det(m):
    # probably recursion?
    n_rows = len(m)

    # hope it's == len(m[0]) w/o checking

    if n_rows == 1:
        return m[0][0]  # lol

    if n_rows == 2:
        # ad - bc
        return m[0][0] * m[1][1] - m[0][1] * m[1][0]

    return sum([m[0][j] * det(minor(m, 0, j)) * (-1) ** j for j in range(n_rows)])


def transpose(m):
    # swap rows and columns
    new = [[m[j][i] for j in range(len(m))] for i in range(len(m[0]))]

    return new


def flatten(m):
    return [m[i][j] for i in range(len(m)) for j in range(len(m[0]))]


def Inv_x(m_np):
    m = m_np.tolist()

    det_m = det(m)
    adj_m = adj_mat(m)

    # m^-1 = (1 / det(m)) * adj(m)
    m_inv = [  # len(ct_m[0]) is essentially 3 but just in case
        [adj_m[i][j] / det_m for j in range(len(adj_m[0]))]
        # this too
        for i in range(len(adj_m))
    ]

    return np.array(m_inv)


def main():
    x_info = list(map(int, input().split(" ")))
    x = np.array(x_info).reshape(3, 3)
    result = Inv_x(x)
    for i in range(result.shape[0]):
        for j in range(result.shape[1]):
            print(f"{result[i,j]:.3f}")


if __name__ == "__main__":
    main()
