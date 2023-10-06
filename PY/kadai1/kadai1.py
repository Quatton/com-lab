def not_empty_pop(arr: list):
    if len(arr) == 0:
        return None
    else:
        return arr.pop()


def main():
    mem = dict()
    while True:
        arr = input().split()
        arr.reverse()
        command = not_empty_pop(arr)
        arg1 = not_empty_pop(arr)
        arg2 = not_empty_pop(arr)
        if command == "quit":
            break
        elif command == "insert":
            mem[arg1] = arg2
        elif command == "search":
            if arg1 in mem:
                print(mem[arg1])
            else:
                print("(not found)")
        elif command == "delete":
            del mem[arg1]


if __name__ == "__main__":
    main()
