# import numpy as np
# let's not use numpy for this one


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


def main():
    inp = list(map(float, input().split(" ")))
    [m1m, m1n, *m1] = inp
    m1 = reshape(m1, int(m1m), int(m1n))
    inp2 = list(map(float, input().split(" ")))
    [m2m, m2n, *m2] = inp2
    m2 = reshape(m2, int(m2m), int(m2n))

    if m1n != m2m:
        assert ValueError("invalid input")
        print("invalid input")
        return

    prod = mult(m1, m2)

    # maybe i should flatten it back
    print(
        " ".join(
            [str(m1m), str(m2n)]
            + [str(prod[i][j]) for i in range(len(prod)) for j in range(len(prod[0]))]
        )
    )

    # test
    # [[1, 2, 3], [4, 5, 6]] * [[7, 8], [9, 10], [11, 12]]
    # [[58, 64], [139, 154]]


if __name__ == "__main__":
    main()
