def missing_number(nums):
    """
    :type nums: List[int]
    :rtype: int
    """

    n = len(nums)
    sum = n*(n+1)//2

    for num in nums: sum -= num

    return sum


if __name__ == "__main__":
    nums = [0,1,2,3,5,6]

    print(missing_number(nums))