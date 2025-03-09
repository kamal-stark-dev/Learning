# 392. Is Subsequence

def isSubsequence(s: str, t: str) -> bool:
    i, j = 0, 0

    len_s = len(s)
    len_t = len(t)

    while i < len_s and j < len_t:
        if s[i] == t[j]:
            i += 1
        j += 1

        """ the above block is equilvalent to -
        if s[i] == t[j]:
            i += 1
            j += 1
        else:
            j += 1
        """

    return True if i == len_s else False


s = "ace"
t = "abcde"
print(isSubsequence(s, t))

"""
Time Complexity - O(n) = O(s + t)
"""