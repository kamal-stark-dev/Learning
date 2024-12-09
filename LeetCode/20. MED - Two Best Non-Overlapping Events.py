# 2054. Two Best Non-Overlapping Events

def maxTwoEvents(events: list[list[int]]) -> int:
    # event -> [start_time, end_time, value]
    # can join at max 2 events and need to maximize the value

    n  = len(events)
    events.sort(key=lambda i: i[0])

    print("Events:", events)

    suffixMax = [0] * n
    suffixMax[n - 1] = events[n - 1][2]    # adding the value of the last event after sorting

    for i in range(n - 2, -1, -1):    # from 2nd last to the first element - reverse order
        suffixMax[i] = max(events[i][2], suffixMax[i + 1])

    print("SuffixMax:", suffixMax)

    maxSum = 0

    for i in range(n):
        left, right = i + 1, n - 1
        nextEventIndex = -1

        while left <= right:
            mid = left + (right - left) // 2
            if events[mid][0] > events[i][1]:
                nextEventIndex = mid
                right = mid - 1
            else:
                left = mid + 1

        if nextEventIndex != -1:
            maxSum = max(maxSum, events[i][2] + suffixMax[nextEventIndex])

        maxSum = max(maxSum, events[i][2])

    return maxSum



events = [[1, 3, 2], [4, 5, 2], [2, 4, 3]]
# events = [[10,83,53],[63,87,45],[97,100,32],[51,61,16]]
print(maxTwoEvents(events))

"""
Time Complexity: O(n * log n)  -  Sorting the array also when we apply binary search for each element it also gives - O(n * logn)
Space Complexity: O(n)         -  Suffix List
"""