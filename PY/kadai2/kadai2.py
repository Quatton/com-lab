def Mean(numbers):
    return float(sum(numbers) / len(numbers))


def Var(numbers):
    # n^2 mean - mean n ^2
    return Mean(list(map(lambda x: x * x, numbers))) - (Mean(numbers) ** 2)


# fmt: off
def main():
    count = 0
    numbers = list(map(int, input().split(" ")))
    mean_val = Mean(numbers)
    var_val = Var(numbers)
    print(f"{mean_val:.2f} {var_val:.2f}")
if __name__ == "__main__":
    main()
