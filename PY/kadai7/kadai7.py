# import numpy as np
# let's not use numpy!


def convert_to_2f(x):
    return f"{x:.2f}"


def main():
    m = list(map(float, input().split(" ")))
    v = list(map(float, input().split(" ")))

    # 2x2 matrix
    m = [[m[0], m[1]], [m[2], m[3]]]

    # x = m^-1 * v
    # m^-1 = [[d, -b], [-c, a]] / (ad - bc)
    m_inv = [[m[1][1], -m[0][1]], [-m[1][0], m[0][0]]]
    det = m[0][0] * m[1][1] - m[0][1] * m[1][0]

    # i should've converted that to a matrix
    for i in range(len(m_inv)):
        for j in range(len(m_inv[0])):
            m_inv[i][j] /= det

    x = [
        # 0 * 0 + 1 * 1
        m_inv[0][0] * v[0] + m_inv[0][1] * v[1],
        m_inv[1][0] * v[0] + m_inv[1][1] * v[1],
    ]

    print("\n".join(map(convert_to_2f, x)))


if __name__ == "__main__":
    main()
