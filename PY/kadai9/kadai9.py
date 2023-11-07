import numpy as np
import numpy.typing as npt


def lsq_line_solution(all_points: npt.NDArray[np.float64]) -> tuple[float, float]:
    X = []
    Y = []

    for point in all_points:
        X.append(point[0])
        Y.append(point[1])

    N = len(X)

    sum_x = sum(X)
    sum_y = sum(Y)
    sum_x_2 = sum(map(lambda x: x * x, X))
    sum_xy = sum(map(lambda x, y: x * y, X, Y))

    slope = (N * sum_xy - sum_x * sum_y) / (N * sum_x_2 - sum_x**2)

    intercept = (sum_y - slope * sum_x) / N

    return slope, intercept


def main():
    point_count = int(input())
    all_coords = []
    for i in range(point_count):
        coords = list(map(float, input().split(" ")))
        all_coords.append(coords)
    all_coords = np.array(all_coords)
    lsq_m, lsq_b = lsq_line_solution(all_coords)
    lsq_m = round(lsq_m, 2)
    lsq_b = round(lsq_b, 2)
    print(f"{lsq_m:.2f}")
    print(f"{lsq_b:.2f}")


if __name__ == "__main__":
    main()
