# DOCUMENTING FUNCTIONS IS REALLY GOOD PRACTICE
"""
1. Adding an explainer-text to the function, this is called docstring
2. You can also hint what types of data you expect for parameters and return value
"""

def sum(a: int, b: int = 0) -> int:
    '''A simple function that returns the sum of 2 numbers `a` and `b` passed to it :)
    a: int
    b: int {0 by default}
    return: int
    '''
    return a + b

print(sum(10, 5))
print(sum.__doc__)
help(sum)

# NOTE: type hinting doesn't changes anything, you could still pass strings in sum function :)
print(sum('hello', ' world'))