def isArraySpecial(nums: list[int], queries: list[list[int]]) -> list[bool]:

    num_len = len(nums)
    counter_prefix = [0] * num_len

    for i in range(1, num_len):
        if nums[i] % 2 == nums[i - 1] % 2:
            counter_prefix[i] = counter_prefix[i - 1] + 1      # previous prefix count plus one
        else:
            counter_prefix[i] = counter_prefix[i - 1]

    results = []
    for start, end in queries:
        if counter_prefix[start] - counter_prefix[end] == 0:   # no same parity in between
            results.append(True)
        else:
            results.append(False)

    return results

nums = [4, 3, 1, 6]
queries = [[0, 2], [2, 3]]
print(isArraySpecial(nums, queries))