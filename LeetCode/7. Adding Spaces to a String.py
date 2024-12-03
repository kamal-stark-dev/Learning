# 2109. Adding Spaces to a String

def addSpaces(s: str, spaces: list[int]) -> str:
    """
    result_list = list(s)
    Inefficient : (
    for space in spaces[::-1]:
        result_list.insert(space, " ")
    return "".join(result_list)


    Inefficient : (
    result_list = list(s)
    i = 0
    for space in spaces:
        result_list.insert(space + i, " ")
        i += 1
    return "".join(result_list)
    """

    # for this we need a "Two Pointer" approach and create a new string.
    res = []

    i, j = 0, 0

    while i < len(s) and j < len(spaces):
        if i < spaces[j]:
            res.append(s[i])
            i += 1
        else:
            res.append(" ")
            j += 1

    if i < len(s):
        res.append(s[i:])

    return "".join(res)


s = "HahaCargovroomvroomboomboombrrrr...."
spaces = [4, 7, 9, 14, 19, 23, 27]
print(addSpaces(s, spaces))

