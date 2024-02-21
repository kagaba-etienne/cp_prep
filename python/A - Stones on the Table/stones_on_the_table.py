def find_minimum(num, stones_arr):
    removed_stones = 0
    prev_stone = stones_arr[0]
    i = 1

    while i < num:
        if stones_arr[i] == prev_stone:
            removed_stones += 1
        else:
            prev_stone = stones_arr[i]
        i += 1
    return removed_stones


if __name__ == "__main__":
    n = int(input())
    stones = input()
    print(find_minimum(n, stones))
