"""
Datatypes - used to store different types of data in Python.
int, float, str, bool, list, set, tuple, dict, None
"""

# Numbers (Integers)
integer_val = 666

# Stores numbers with points
floating_val = 3.14159

# Text values
string_val = "Hii I am a String!!"
fstring_val = f"Integer value is {integer_val}."

# True or False
boolean_val = True

# None - represents the absence of a value
none_val = None

# List - values can be changed (mutable)
list_example = [1, 2, 'abc', False, 2, 7.5]

# Tuple - cannot be changed (immutable)
tuple_example = (1, 2, 'abc', False, 2, 7.5)

# Set - every value in it is unique
set_example = {1, 2.5, 'abc', True}

# Dictionary - stores a key value pair where keys are unique
dict_example = {'a': 1, 'b': 3.14, 'c': True, 'd': "abc"}

"""
Less Commonly Used Data Types
"""

# Bytes - immutable sequences of bytes
bytes_val = b"Hello"

# Bytearray - mutable sequences of bytes
bytearray_val = bytearray(b"Hello")

# Range - represents an immutable sequence of numbers
range_val = range(10)

# Frozenset - immutable version of a set
frozenset_example = frozenset([1, 2, 3, 4, 5])

# You can change data-types easily

"""
int + float = float
1 + 2.5 = 3.5

there are more ways for data type conversions which we'll see later
"""

# you can use the type function to see the data type of any object
print(type(100))
print(type(3.14))
print(type("String"))
print(type(True))
print(type(None))
print(type(list_example))
print(type(tuple_example))
print(type(set_example))
print(type(dict_example))

# manually change datatypes
print('float(10):', type(float(10)))
print('string(10):', type(str(10)))
print('list(10, 20, 30):', type(list((10, 20, 30)))) # note we are converting a `tuple` to `list`
