# 2593. Find Score of an Array After Marking All Elements

import heapq

def findScore(self, nums: list[int]) -> int:
    n = len(nums)
    score = 0
    seen = set()
    heap = []

    for i, val in enumerate(nums):
        heapq.heappush(heap, (val, i))  # heap => (value, index)


    while heap:
        val, i = heapq.heappop(heap)

        if i in seen:
            continue

        score += val
        seen.add(i)
        if i - 1 >= 0:
            seen.add(i - 1)
        if i + 1 < n:
            seen.add(i + 1)

    return score