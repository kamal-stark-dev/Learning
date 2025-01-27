# FUNCTIONS
"""
Function - Block of code that can be reused :)

1. Definition --> Creating of function
2. Calling -----> Executing of function

A function can be called multiple times and we can also customize it.
"""

# definition
def test_function():
    print('Inside Test Function :)')
    test = 1 + 2
    print('test value:', test)

# calling - multiple times
test_function()
test_function()
test_function()

# greet function
def greet(name):
    print(f"Hello {name}!!")

greet('Jake')
greet('Rakhi')
greet('Sameer')

# add function
def add(a, b):
    return a + b
print(f"{add(3, 4) = }")
print(f"{add(5, 20) = }")

# NOTE: the variables like `a` and `b` are inside of the function block and can't be accessed outside the function
# print(a) --> NameError: name 'a' is not defined

"""
Parameters are the variable_names used in the function definition.
    `def function_name(parameter1, parameter2):`

Arguments are the actual values that is passed to the function when called.
    `function_name('abd', 12)`
"""

def hcf(a, b):
    while(b != 0):
        rem = a % b
        a = b
        b = rem
    return a

print(f"{hcf(16, 20) = }")

def printVals(a, b, c):
    print(f"{a = }\n{b = }\n{c = }\n")

# positional arguments
printVals(10, 20, 30)
printVals(30, 10, 20)    # result will not be same for positional

# keywords arguments
printVals(a = 10, b = 20, c = 30)
printVals(c = 30, a = 10, b = 20)    # here result will be same

# positional + keyword arguments
printVals(10, c = 30, b = 20)

# NOTE: you can't use positional arguments after using keywords

# Default values
def greeter(name = "there"):
    print(f"Hi {name}")

greeter()
greeter('Jake')

# What if you don't know the number of arguments

# one way is to use lists
def print_all(arguments):
    for arg in arguments:
        print(arg, end=" ")
    print()

print_all([10, 20, 'Hello', True, 30])
print_all([10, 20, 'Hello', True, 30, 40, 'World', False])

# list unpacking
def print_all_2(*arguments):
    for arg in arguments:
        print(arg, end=" ")
    print()

print_all_2(10, 20, 'Hello', True, 30)
print_all_2(10, 20, 'Hello', True, 30, 40, 'World', False)

# you can use this with other parameters
def print_data(a, b, c, *args):
    print(f"{a = }, {b = }, {c = }", end=", ")
    print('Other args:', args)

print_data(10, 'B', 3.33, True, [1, 2, 3], 'abc')

# keyword unpacking - returns a dict of each keyword pair
def print_keyword(**args):
    print(f"{args = }\n")

print_keyword(a = 'apple', b = 100, c = False, list_d = [1, 2, 3])

# function that uses all tupes of arguments
def complex_function(pos1, pos2, *args, kw1=None, kw2=None, **kwargs):
    print(f"pos1 = {pos1}, pos2 = {pos2}")
    print("args:", args)
    print(f"kw1 = {kw1}, kw2 = {kw2}")
    print("kwargs:", kwargs)

complex_function(1, 2, 3, 4, 5, kw1="keyword1", kw2="keyword2", extra1="extra1", extra2="extra2")

# Exercise: make a function that returns the sum of unlimited numbers
def sum_unlimited(*args):
    sum = 0
    for arg in args: sum += arg
    return sum
    # you can use return sum(args)

print(sum_unlimited(10, 20, 30, 40, 50))