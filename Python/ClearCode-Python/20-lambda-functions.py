# single exprssion function that can only be used once
# lambda parameters: expression

a = lambda x: x + 1
print(f"{a(10) = }")

sum = lambda a, b: a + b
print(f"{sum(10, 5) = }")

"""
Why use them?
- Some functions wants other functions as argument
- graphical user interfaces (Tkinter button functions)
"""

test = lambda x: "hello"if x > 5 else "bye"
print(f"{test(7) = }")
print(f"{test(4) = }")