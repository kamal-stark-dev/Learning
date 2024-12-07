# 1760. Minimum Limit of Balls in a Bag

from math import ceil

def minimumSize(nums, maxOperations):
    def can_divide(balls):
        ops = 0

        for i in nums:
            ops += ceil(i / balls) - 1
            if ops > maxOperations:
                return False

        return True

    left, right = 1, max(nums)
    result = right

    while left < right:
        mid = left + (right - left) // 2
        if can_divide(mid):
            right = mid
            result = right
        else:
            left = mid + 1

    return result

nums = [7, 17]
maxOperations = 2

print(minimumSize(nums, maxOperations))

"""
We are using binary search for the same and also each time it goes to the "can_divide" function which takes n time.

Time Complexity: O(n logn)
Space Complexity: O(1)
"""