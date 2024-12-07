# 2554. Maximum Number of Integers to Choose From a Range I

def maxCount(banned: list[int], n: int, maxSum: int) -> int:

    banned = set(banned) # Convert to set for O(1) lookups

    sum = 0
    count = 0

    for i in range(1, n + 1):
        if i in banned:
            continue
        sum += i
        if sum > maxSum:
            break
        count += 1

    return count

banned = [11]
n = 7
maxSum = 50

print(maxCount(banned, n, maxSum))

"""
Time Complexity: O(n)
Space Complexity: O(n)
"""