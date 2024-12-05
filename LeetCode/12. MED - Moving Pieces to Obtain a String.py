# 2337. Move Pieces to Obtain a String

def canChange(start: str, target: str) -> bool:
    if start.replace("_", "") != target.replace("_", ""):
        return False

    start_len = len(start)
    i = j = 0

    while i < start_len and j < start_len:
        while i < start_len and start[i] == "_":
            i += 1
        while j < start_len and target[j] == "_":
            j += 1

        if i == start_len and j == start_len:
            return True
        if i == start_len or j == start_len:
            return False

        if start[i] != target[j]:
            return False

        if start[i] == "L" and i < j:
            return False
        if start[i] == "R" and i > j:
            return False

        i += 1
        j += 1

    return True

start  = "_L__R__R_"
target = "L______RR"

print(canChange(start, target))

"""
Time Complexity = O(n)
Space Complexity = O(n)
Note: if you want to reduce the space complexity you can remove the replace operation, doing this will make it O(1)
"""


""" MY FIRST ATTEMPT -> WORKS BUT NOT OPTIMAL
    if start == target:
        return True

    start = list(start)
    target = list(target)

    start_len = len(start)

    while start != target:
        i, j = 0, 1
        swaps = 0
        while i < start_len and j < start_len:
            if start == target:
                return True
            if start[i] == "_" and start[j] == "L":
                start[i] = "L"
                start[j] = "_"
                swaps += 1
            elif start[i] == "R" and start[j] == "_":
                start[i] = "_"
                start[j] = "R"
                swaps += 1
            # print(start, i, j)
            i += 1
            j += 1

        if swaps == 0:
            return False
    """