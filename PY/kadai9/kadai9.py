# import numpy as np


def convert_to_2f(x):
    return f"{x:.2f}"


def main():
    N = 4

    X = []
    Y = []

    # take N points
    for _ in range(N):
        x, y = map(float, input().split(" "))
        X.append(x)
        Y.append(y)

    sum_x = sum(X)
    sum_y = sum(Y)
    sum_x_2 = sum(map(lambda x: x * x, X))
    sum_xy = sum(map(lambda x, y: x * y, X, Y))

    b = (N * sum_xy - sum_x * sum_y) / (N * sum_x_2 - sum_x**2)

    a = (sum_y - b * sum_x) / N

    print(f"{a:.2f} {b:.2f}")


if __name__ == "__main__":
    main()
