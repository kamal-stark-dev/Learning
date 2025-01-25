# Booleans are either True or False

# Python has reserved keywords for booleans
true = True
false = False

# We can make booleans via various methods

# comparisons
print(f"{5 < 10 = }")
print(f"{5 == 10 = }")
print(f"{5 != 10 = }")
print(f"{5 > 10 = }")
print(f"{not 5 > 10 = }\n")

# methods that returns boolean
print(f"{'ABC123'.isalnum() = }")
print(f"{'$Money$'.isalnum() = }\n")

# you can check if values are in list, tuples, sets, or dicts
print(f"{10 in [10, 20, 30] = }")
print(f"{15 in (10, 20, 30) = }")
print(f"{15 not in (10, 20, 30) = }")
test_dict = {'a': 10, 'b': 20, 'c': 30}
print(f"{20 in test_dict = }")
print(f"{20 in test_dict.values() = }\n")

# comparing sets
A = {1, 2, 3}
B = {3, 3, 4}

print(f"{A == B = }")
print(f"{A & B == {3} = }\n")

"""
Falsy values -
    0 or 0.0    - integer or float
    ''          - empty string
    [], (), {}  - empty list, tuple, set
    None        - absence of value

Truthy values -
    all the values that are not Falsy
"""

# bool() -> can accept any number, string, tupe of containers and return true
print(f"{bool(10) = }")
print(f"{bool(-5.5) = }")
print(f"{bool(0.0) = }\n")

print(f"{bool('hello') = }")
print(f"{bool(' ') = }")
print(f"{bool('') = }\n")

print(f"{bool([]) = }")
print(f"{bool(()) = }")
print(f"{bool({}) = }")
print(f"{bool([0.0]) = }\n")

print(f"{bool(None) = }")