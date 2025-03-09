# 1455. Check If a Word Occurs As a Prefix of Any Word in a Sentence

def isPrefixOfWord(sentence, searchWord):
    """
    :type sentence: str
    :type searchWord: str
    :rtype: int
    """
    words = sentence.split(" ")
    for i, word in enumerate(words):
        if searchWord in word[0: len(searchWord)]:
            return i + 1
    return -1

sentence = "i love eating burger"
searchWord = "burg"
print(isPrefixOfWord(sentence, searchWord)) # should be 4