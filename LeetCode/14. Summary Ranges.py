# 228. Summary Ranges

def summaryRanges(nums: list[int]) -> list[str]:
    ans = []
    i = 0

    while i < len(nums):
        start = nums[i]

        while i < len(nums) - 1 and nums[i] + 1 == nums[i + 1]:
            i += 1

        if start == nums[i]:
            ans.append(f"{start}")
        else:
            ans.append(f"{start}->{nums[i]}")
        i += 1

    return ans

nums = [0, 1, 2, 4, 5, 7]
print(summaryRanges(nums))


"""
Time Complexity: O(n) => if you think it should be O(n^2) then refe r to this -> https://youtu.be/ZHJDwbfqoa8?si=kGt0EW8Q2WbuqA8s&t=294
Space Complexity: O(n) [O(1) apart from the result]
"""