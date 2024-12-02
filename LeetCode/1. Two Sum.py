# 1. Two Sum

# nums: List[int]   ==> we are having a list (nums) of integers
# target: int       ==> tells that the target parameter will be of int type
# -> List[int]      ==> it's the return type and tells that this function will return a list of integers

from typing import List

def twoSum(nums: List[int], target: int) -> List[int]:
    prevMap = {} # value : index --> this is how our map will look like

    for i, n in enumerate(nums):
        diff = target - n
        if diff in prevMap:    # parsing dictionaries is of constant time O(1) because of "hashmaps" usage in them
            return [i, prevMap[diff]]
        prevMap[n] = i
    return

arr = [1, 2, 3, 4, 5, 6, 7, 8, 9]
target = 14

print(twoSum(arr, target))

"""
Time Complexity: O(n)
Space Complexity: O(n)
"""