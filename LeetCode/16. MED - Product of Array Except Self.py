# 238. Product of Array Except Self

def productExceptSelf(nums: list[int]) -> list[int]:
    nums_len = len(nums)
    res = [1] * nums_len

    left = 1
    for i in range(nums_len):
        res[i] = left
        left *= nums[i]

    right = 1
    for i in range(nums_len - 1, -1, -1):
        res[i] *= right
        right *= nums[i]

    return res

nums = [1, 2, 3, 4, 5]
print(productExceptSelf(nums))

"""
Time Complexity: O(n)
Space Complexity: O(1)
"""
