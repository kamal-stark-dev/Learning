# Decorators are functions that 'decorate' other functions, we wrap a function inside another function.

def func():
    print('function')

def wrapper(func):
    print('\ncalling func()')
    func()
    print('done!!')

func()
wrapper(func)

def func_generator():
    def new_function():
        print('\nNew Function')
    return new_function

new_func = func_generator()
new_func()

# making a decorator
def decorator(func):
    def wrapper():
        print('\ndecorator begins')
        func()
        print('decorator ends')
    return wrapper

@decorator   # is same as say_hello = decorator(say_hello)
def say_hello():
    print('Hello World ~\n')

func = decorator(say_hello)
say_hello()

# Let's see how they can be helpful
import time

def duration_decorator(func):
    def wrapper():
        start_time = time.time()
        func()
        duration = time.time() - start_time
        print(f'Duration: {duration}')
    return wrapper

def call_twice_decorator(func):
    def wrapper():
        func()
        func()
    return wrapper

@decorator # you can add multiple decorators like this
@call_twice_decorator # try changing the order of this decorator
@duration_decorator
def greet():
    print(f'Hello User!!')
    time.sleep(0.1)

greet()

# What if you want to add decorator to a function with parameters

def param_decorator(func):
    def wrapper(*args, **kwargs): # these parameters allows our decorator to accept any kind of function
        print('\ndecorator begins')
        # just pass the `parameter` of `wrapper` which will be `argument` for `func`
        func(*args, **kwargs)
        print('decorator ends')
    return wrapper

@param_decorator
def display(message):
    print(message)

display('Hello World')
print()

# you can also pass arguments to your decorator

def repetition_decorator(repetitions):
    def decorator(func):
        def wrapper():
            for r in range(repetitions):
                func()
        return wrapper
    return decorator

# @repetition_decorator(3)
def foo():
    print('function')

# if you don't use `@repetition_decorator(3)` the alternative of that would be
foo = repetition_decorator(3)(foo) # which looks confusing
foo()

"""
foo = repetition_decorator(3)(foo)

as `repetition_decorator(n)` returns a `decorator`

becomes -> foo = decorator(foo)
"""

"""
Exercise: Create a decorator that -
    1. Runs the func `n` number of times
    2. The func should take any number of arguments
    3. The return values of function should be stored in a list
    4. The `results` should be returned by the func
"""

def repeat_decorator(n):
    def decorator(func):
        def wrapper(*args, **kwargs):
            results = []
            for _ in range(n):
                res = func(*args, **kwargs)
                results.append(res)
            return results
        return wrapper
    return decorator

@repeat_decorator(3)
def names(name):
    return f"Hello, {name}!"

# let's see what it's returning
print('\nRepeat Decorator Returned:')
print(names('Kamalveer'))