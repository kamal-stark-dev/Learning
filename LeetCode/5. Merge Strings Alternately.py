# 1768. Merge Strings Alternately

def mergeAlternately(word1, word2):
    result = [] # using list rather than string for efficiency
    till = min(len(word1), len(word2))
    for i in range(till):
        result.append(word1[i] + word2[i])

    result.append(word1[till:] or word2[till:])
    return "".join(result)

word1 = "abc"
word2 = "pqrs"

print(mergeAlternately(word1, word2))