# 49. Group Anagrams

def validAnagram(s: str, t: str) -> bool:
    if len(s) != len(t):
        return False
    smap = {}
    tmap = {}

    for i in range(len(s)):
        if s[i] in smap:
            smap[s[i]] += 1
        else:
            smap[s[i]] = 1
        if t[i] in tmap:
            tmap[t[i]] += 1
        else:
            tmap[t[i]] = 1

    return smap == tmap

def groupAnagrams(strs: list[str]) -> list[list[str]]:
    res = {}

    for str in strs:
        count = [0] * 26

        for ch in str:
            count[ord(ch) - ord('a')] += 1

        key = tuple(count)

        if key in res:
            res[key].append(str)
        else:
            res[key] = [str]
    return list(res.values())


strs = ["eat", "tea", "tan", "ate", "nat", "bat"]
print(groupAnagrams(strs))

"""
Time Complexity: O(m * n * 26) => O(n * m), where m is the len of strs and n is len of string.
Space Complexity: O(n), due to the dictionary of `res`
"""