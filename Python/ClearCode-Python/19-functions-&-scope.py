a = 10 # glocal variable

def test_func():
    # you can't modify the variable `a` here :)
    # a += 10 --> UnboundLocalError: local variable 'a' referenced before assignment
    # local variable
    a = 5
    print(f"test_1: {a = }") # this time python prints `a = 5`

def test_func_2():
    a = 100
    b = 20
    print(f"test_2: {a = }")


print(f"global: {a = }")
test_func()
test_func_2()
# you can't access the variable `b` outside the funciton
# print(b) --> NameError: name 'b' is not defined

"""
Q. Why this concept of scope ?
-> There are multiple reasons for the same
1. Functions are supposed to be separate from the code
2. For large projects its easier to run out of relevant variable names
    ex - both a car and a truck may have a variable `tank_capacity`
3. Local scopes helps us keep things organised

RULES:
- Every function has its own local scope and each local scope is separate
- Global variables can be accessed in the local scope but can't be changed
"""

def test_func_3():
    global a # tells that var `a` is global --> not used often (is generally avoided)
    a += 10
    print(f"test_3: {a = }") # accessing the global variable inside local scope

def test_func_4(a): # passing the variable as a parameter
    a += 5
    print(f"test_4: {a = }")

test_func_3()
test_func_4(a)

multiplier, has_calculated = 10, False

def multiply_calculator(num):
        global has_calculated
        result = num * multiplier
        has_calculated = True
        return result

# NOTE: `return` ends the execution of the block when it runs ~ so the code below it will not be executed when its executed

# Notice double tabs in the indentation ? Yeah you can do that :)

print(multiply_calculator(5), has_calculated)