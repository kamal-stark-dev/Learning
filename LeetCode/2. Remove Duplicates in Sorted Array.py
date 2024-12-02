# 26. Remove Duplicates from Sorted Array

def removeDuplicates(nums):
    j = 1
    n = len(nums)
    for i in range(1, n):
        if nums[i] != nums[i - 1]:
            nums[j] = prev = nums[i]
            j += 1
    return j

nums = [0, 0, 1, 1, 1, 1, 2, 2, 3, 4, 4]

print(removeDuplicates(nums))