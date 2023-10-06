import numpy as np


def main():
    inp = list(map(int, input().split(" ")))
    m1 = np.matrix(inp[0:4]).reshape(2, 2)  # omg lol this worked thank god
    m2 = np.matrix(inp[4:8]).reshape(2, 2)
    prod: np.matrix = np.matmul(m1, m2)

    print(" ".join(map(str, prod.flatten().tolist()[0])))


if __name__ == "__main__":
    main()
