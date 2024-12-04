# 2825. Make String a Subsequence Using Cyclic Increments - MEDIUM

def canMakeSubsequence(source: str, target: str) -> bool:
    src_len = len(source)
    tgt_len = len(target)

    src, tgt = 0, 0

    while tgt < tgt_len and src < src_len:
        if (target[tgt] == source[src] or (target[tgt] == "a" and source[src] == "z") or ord(target[tgt]) == ord(source[src]) + 1 ):
             tgt += 1
        src += 1

    return tgt == tgt_len


str1 = "dby"
str2 = "z"
print(canMakeSubsequence(str1, str2))

"""
Time Complexity: O(n) = O(t + s)
Space Complexity: O(1)
"""