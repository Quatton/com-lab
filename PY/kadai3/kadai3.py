def main():
    target = int(input())
    nums = list(map(int, input().split(" ")))

    # two pointers

    i = 0
    j = len(nums) - 1

    while nums[i] + nums[j] != target:
        if nums[i] + nums[j] > target:
            j -= 1
        else:
            i += 1

    print(f"[{i} {j}]")


if __name__ == "__main__":
    main()
