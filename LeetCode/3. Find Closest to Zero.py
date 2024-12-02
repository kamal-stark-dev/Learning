# 2239. Find Closest Number to Zero

def findClosestNumber(nums):

        min = nums[0]

        for i in range(1, len(nums)):
            if abs(nums[i]) < abs(min):
                min = nums[i]

        if min < 0 and abs(min) in nums:    # if the min is let's say -2 and we have 2 in the list then we return 2 as the difference in both will be the same
            return abs(min)

        return min

arr = [-2, -1, -1, 3]
print(findClosestNumber(arr))