# functions - reusable blocks of code that perform a specific task

# user defined funcitons
def greet(name):
    return "Hello, " + name + "!"

def add(a, b):
    return a + b

def factorial(n):
    if n == 0:
        return 1
    else:
        return n * factorial(n-1)

"""
`print` itself is a funciton and we have more function like `len`, `abs` and more...

syntax ->
    # defining a function
    def function_name(parameters):
        # code
        return value

    # calling a function
    function_name(arguments)
"""

# len function
text = "Python is Cool!!"
print('The length of text:', len(text))

# max function
max_num = max(10, 30, 15, 25)
print('Max Number:', max_num)

# can you try the same for `min` approach ?

# Example usage of user defined functions
print(greet("Luffytaro"))
print('Sum of 3 and 5:', add(3, 5))
print('Factorial of 5:', factorial(5))

"""
methods - funcitons that are attatched to an object

> methods are always attatched to an object with a "."

syntax -
    object.method(arguments)
"""

# upper method
name = "Roronoa Zoro"
print('Name with upper case:', name.upper())

# lower method
print("Name with lower case:", name.lower())

# title method
name = "RoROnOA zoRO".title()
print('name.title():', name)

"""
Q. But why we do we have methods for objects and not functions ?
--> Let's see with an example -
    we have methods as they are for `objects` because having a function for `uppercasing` a number will not make sense

NOTE: you can call nest functions inside of functions and you can also use multiple methods.
"""

# striping and uppercasing
text = "   Hello World!  "
print('text.strip().upper():', text.strip().upper())

# striping characters
text = "roRoNOA ZorOxxx".lower().strip('x').title() # order of calling methods - lower -> strip -> title
print('Formatting Name:', text)

# to see possible methods for an object use the `dir` function
print(dir(text))

# isalpha, isalnum, isspace, islower, isupper
text = "Hello"
print('"Hello".isalpha():', text.isalpha())

text = "Hello123"
print('"Hello123".isalnum():', text.isalnum())

print('" ".isspace():', " ".isspace())
print('"\\t".isspace():', "\t".isspace())
print('"\\n".isspace():', "\n".isspace())

print("123.isdecimal():", "123".isdecimal())

print('"HELLO".isupper():', "HELLO".isupper())
print('"hello".isupper():', "hello".islower())

# replace in string
example_string = "I like your style"
print(example_string.replace("style", "MOM <3"))

# replace multiple times
example_string = "I like Coding Coding Coding".replace("Coding", "Python", 2) # 2 is the count of how many times you want to replace
print(example_string)

"""
returning values - any operation returns a value, for example - `2 + 2` returns `4`

functions and methods returns values -  upper() method returns uppercase string and abs() returns the magnitude a number
"""

# can you tell what will be the returns value for this
print(abs(len("Hello") * -5))
