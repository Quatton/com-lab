import numpy as np


def convert_to_2f(x):
    return f"{x:.2f}"


def main():
    m = list(map(int, input().split(" ")))
    v = list(map(int, input().split(" ")))

    # 2x2 matrix
    m = np.matrix(m).reshape(2, 2)

    # 2x1 vector
    v = np.matrix(v).reshape(2, 1)

    # x = m^-1 * v
    # https://numpy.org/doc/stable/reference/generated/numpy.linalg.inv.html
    m_inv = np.linalg.inv(m)

    x = np.matmul(m_inv, v)

    print("\n".join(map(convert_to_2f, x.flatten().tolist()[0])))


if __name__ == "__main__":
    main()
