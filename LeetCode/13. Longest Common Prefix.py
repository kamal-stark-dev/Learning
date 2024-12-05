# 14. Longest Common Prefix

def longestCommonPrefix(strs: list[str]) -> str:
    v = sorted(strs)

    first = v[0]
    last = v[-1]
    common = ""

    for i in range(min(len(first), len(last))):
        if first[i] == last[i]:
            common += first[i]
        else:
            break
    return common
