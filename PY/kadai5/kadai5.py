digits = {
    "0": 0,
    "1": 1,
    "2": 2,
    "3": 3,
    "4": 4,
    "5": 5,
    "6": 6,
    "7": 7,
    "8": 8,
    "9": 9,
}


def str_to_int(str: str):
    sign = 1
    if str[0] == "-":
        sign = -1
        str = str[1:]
    else:
        str = str[0:]

    result = 0
    for char in str:
        result = result * 10 + digits[char]

    return result * sign


def main():
    s1 = ""
    s2 = ""

    # i do this expensive maneuver
    # because idk how the input is formatted
    idk = input().split(" ")
    if len(idk) == 2:
        [s1, s2] = idk
    else:
        s1 = idk[0]
        s2 = input()

    print(str_to_int(s1) + str_to_int(s2))


if __name__ == "__main__":
    main()
