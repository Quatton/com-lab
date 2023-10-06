import numpy as np


def convert_to_2f(x):
    return f"{x:.2f}"


def main():
    m = list(map(int, input().split(" ")))

    # 2x2 matrix
    m = np.matrix(m).reshape(3, 3)
    m_inv: np.matrix = np.linalg.inv(m)

    print(" ".join(map(str, m_inv.flatten().tolist()[0])))


if __name__ == "__main__":
    main()
