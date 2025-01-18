# python ignores the whitespaces and empty lines

"""
Code 1:
```
print('Line 1')
print('Line 2')
```

will work the same as ->

Code 2:
```
print(   'Line 1'    )

print(        'Line 2')
```
"""

# but python will not be happy for unexpected indentation

"""
Code 1:
```
print("Hello")
```

but this will raise an error

Code 2:
```
    print("Hello")
```
"""

# if you want to run multiple statements in a single line use ';'
print("Hello"); print("World")

# above is one physical line but two logical lines

# you can also do the opposite with '\'
sum = 1 + 2 + 3 + \
4 + 5
print('Sum:', sum)

# above is 2 physical lines but one logical line