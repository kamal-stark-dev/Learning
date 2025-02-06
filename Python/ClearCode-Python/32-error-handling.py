# your code should handle some common errors that might interrupt your program

# print(1 / 0) - ZeroDivisionError: division by zero

try:
    print(1 / 0)
except:
    print('An error occured ._.')

# you can be more specific with handling special errors

try:
    print(a)
    print(1 / 0)
except ZeroDivisionError:
    print('Error: Can\'t divide by zero')
except NameError:
    print('Error: Trying to print something which does not exist.')

# NOTE: you'll see the NameError executed and then the execution will stop so no code after that will be executed

# There are a lot of in-built exceptions which you can handle beforhand

# else and finally

try:
    print('Hello World')
except ZeroDivisionError:
    print('You can\'t divide by 0')
except:
    print('an error ocurred (._.)')
else: # will run if no error occured
    print('ELSE: this runs when no error has occured!')
finally:
    print('FINALLY: This will execute even if any Exception occurs!')

# you can raise your own exceptions
must_be_string = 'test string'
if isinstance(must_be_string, str):
    print(f"{must_be_string = }")
else:
    raise TypeError('must be of string type')

# assert - assert is like a stronger if statement which has a bool which when false stops the entire program with `AssertionError`

a = 10
assert a == 10 # will not raise an AssertionError

# try, except, else, finally, raise, assert