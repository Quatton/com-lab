def Sqrt(target):
    if target < 0:
        return "NG"

    # Newton's method
    # f(x) = x^2 - target = 0 -> find root
    # f'(x) = 2x

    guess = target
    tolerance = 0.5

    while abs(guess * guess - target) >= tolerance:
        guess = guess - (guess * guess - target) / (2 * guess)
        # here's why it's going to loop forever:
        #

    return int(guess)


def main():
    input_num = int(input())
    sqrt_root = Sqrt(input_num)
    print(f"{sqrt_root}")


if __name__ == "__main__":
    main()
