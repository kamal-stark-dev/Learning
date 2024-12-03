# 13. Roman to Integer

def romanToInt(s: str) -> int:
    romanMap = {'I': 1, 'V': 5, 'X': 10, 'L': 50, 'C': 100, 'D': 500, 'M': 1000}

    int_value = romanMap[s[len(s) - 1]]

    for i in range(len(s) - 1, 0, -1):
        print(i)
        if romanMap[s[i]] > romanMap[s[i - 1]]:
            int_value -= romanMap[s[i - 1]]
        else:
            int_value += romanMap[s[i - 1]]

    """ If you want to start from 0
    int_value = 0

    for i in range(len(s) - 1):
        if romanMap[s[i]] < romanMap[s[i + 1]]:
            int_value -= romanMap[s[i]]
        else:
            int_value += romanMap[s[i]]
    int_value += romanMap[s[len(s) - 1]]
    """

    return int_value

"""
for i in ['I', 'V', 'X', 'L', 'C', 'D', 'M']:
    print(romanToInt(i))
"""

# print(romanToInt("LIV")) # 54
# print(romanToInt("MCMXCIV")) # 1994
print(romanToInt("LVIII")) # 58