# 242. Valid Anagram

def validAnagram(s: str, t: str) -> bool:
    if len(s) != len(t):
            return False

    sMap = {}
    tMap = {}

    for i in range(len(s)):
        if s[i] in sMap:
            sMap[s[i]] += 1
        else:
            sMap[s[i]] = 1
        if t[i] in tMap:
            tMap[t[i]] += 1
        else:
            tMap[t[i]] = 1

    return sMap == tMap


s = "kamalveer"
t = "lamakreev"
print(validAnagram(s, t))

"""
Time Complexity: O(n)
Space Complexity: O(n) = O(s + t)
"""