
"""
None -> absence of values

sequence -> to get a range of numbers

bytes, complex numbers, memoryview, frozensets --> used for highly specific purposes
"""

# NoneType: Represents the absence of a value
var = None
print(var)  # Output: None

# range: Represents a sequence of numbers
r = range(5)
print(list(r))  # Output: [0, 1, 2, 3, 4]

# bytes: Represents a sequence of bytes
b = bytes([65, 66, 67])
print(b)  # Output: b'ABC'

# complex: Represents a complex number
c = 3 + 4j
print(c)  # Output: (3+4j)

# memoryview: Allows access to the internal data of an object that supports the buffer protocol without copying
mv = memoryview(b'ABC')
print(mv[0])  # Output: 65

# frozenset: Represents an immutable set - tuples for set
fs = frozenset([1, 2, 3, 2, 1])
print(fs)  # Output: frozenset({1, 2, 3})

"""
+-------------+----------------------------------+
| Data Type   | Example                          |
+-------------+----------------------------------+
| int         | x = 10                           |
| float       | y = 20.5                         |
| complex     | z = 2 + 3j                       |
| str         | s = "Hello"                      |
| list        | my_list = [1, 2, 3]              |
| tuple       | my_tuple = (1, 2, 3)             |
| dict        | my_dict = {"key": "value"}       |
| set         | my_set = {1, 2, 3}               |
| frozenset   | my_frozenset = frozenset({1, 2}) |
| bool        | is_valid = True                  |
| bytes       | b = b"Hello"                     |
| bytearray   | ba = bytearray(5)                |
| memoryview  | mv = memoryview(b"Hello")        |
| NoneType    | x = None                         |
| Custom Class| obj = MyClass()                  |
+-------------+----------------------------------+
"""
