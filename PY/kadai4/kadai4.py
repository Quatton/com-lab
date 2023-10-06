def main():
    target = int(input())

    if target < 0:
        print("NG")

    # Newton's method
    # f(x) = x^2 - target = 0 -> find root
    # f'(x) = 2x

    guess = target
    tolerance = 0.1

    while abs(guess * guess - target) >= tolerance:
        guess = guess - (guess * guess - target) / (2 * guess)

    print(f"{int(guess)}")


if __name__ == "__main__":
    main()
