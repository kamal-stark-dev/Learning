# 56. Merge Intervals

def merge(intervals: list[list[int]]) -> list[list[int]]:

    intervals.sort(key = lambda i : i[0])

    output = [intervals[0]]

    for start, end in intervals[1:]:
        last_end = output[-1][1]

        if last_end >= start:
            output[-1][1] = max(end, last_end)
        else:
            output.append([start, end])

    return output

intervals = [[1, 3], [2, 6], [8, 10], [15, 18]]
# intervals = [[1, 3], [3, 5], [5, 10]]    # expected: [[1, 10]]
print(merge(intervals))

"""
Time Complexity: O(n logn) -> due to sorting
Space Complexity: O(n) if you add the output's space
"""