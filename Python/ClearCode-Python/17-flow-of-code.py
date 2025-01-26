"""
So, far we have executed our code from top to bottom.

But sometimes you want to -
-> run only if some condition is true
-> run a code multiple times
-> run code for every item in a list
"""

"""
But before that we need to know how python groups a block of code -> Indentation

if condition is True then:
    line 1
    line 2
    line 3
line 4
line 5

in the above example only line 1, 2, and 3 belongs to one block.

1, 2, 3 lines will only run if the condition is True but 4, 5 lines will always run.
"""

"""
There are 4 major ways to determine the flow of code -
1. If elif else statements
2. Match statements
3. While loops
4. For loops

There are also keywords like `break` or `next` to have more control.
"""

# IF ELIF ELSE
num = 10
if num > 10:
    print(f"{num} is greater than 10.")
elif num == 10:
    print(f"{num} is equal to 10.")
else:
    print(f"{num} is smaller than 10.")
print("This will always run!!")

# you can add multiple `elif` statements to your code

# you can add multiple conditions and can also nest multiple statements
num = 15
if (num > 10 and num < 20):
    if (num == 15):
        print("Num is 15 :)")
    else:
        print(f"Num is {num}.")

"""
AND OR NOT ==>
AND -> all the conditions should be true
OR -> at least one of the conditions should be true
NOT -> toggles the boolean (T -> F and F -> T)
"""

hasMoney = False
bhandaraNearby = True
hungry = True

if (hungry and hasMoney) or (hungry and bhandaraNearby):
    print("It's food time!!")
    hungry = False
else:
    print("Arrange money or find bhandara nearby ~")

# MATCH CASE
"""
if 'hungry':        match 'mood':
    code...             case 'hungry':
elif 'sad':                 code...
    code...             case 'sad':
elif 'bored':               code...
    code...             case 'bored':
                            code...

It's a tiny bit longer but more readable.
"""

mood = 'hungry'

# match case is about as efficient as if else statements
match mood:
    case 'hungry':
        print('Go eat something!!')
    case 'sad':
        print('Watch One Piece ~')
    case 'bored':
        print('Watch a Movie :)')
    case _: # default
        print('Go for a walk!!')

# WHILE LOOP
x = 1
while x <= 10:
    if x == 5:
        print('Five')
        x += 1
        continue
    print(f"{x = }")
    x += 1

x = 0
even_nums = []
while x < 101:
    even_nums.append(x)
    x += 2
print(even_nums)

# FOR LOOP

# range
my_list = range(1, 11)
for i in my_list:
    print(f"{i = }", end=", ")
print()

# dictionaries
my_dict = {1 : 'one', 2 : 'two', 3 : 'three'}

print("\nDict Items:")
for item in my_dict.items():
    print(item)
print("\nDict Keys:")
for key in my_dict.keys():
    print(key)
print("\nDict Values:")
for value in my_dict.values():
    print(value)

# strings
print("\nWords in string: ")
string = "I Like your MoM <3"
for word in string.split():
    print(word)

name = "Jake"
print("\nFor loop with range for indexing:")
for idx in range(len(name)):
    print(f"{name[idx] = }")

# even numbers using for loop and range
till = 50
for i in range(0, till + 1, 2):
    print(i, end=" ")

"""
practice_list = [[10, 40, 20, 50], [2, 42, 10], [101, 10, 4]]
1. use for loop to only print number below 50
2. skip values below 10
3. end the entire loop if you find number greater than 100
"""
practice_list = [[10, 40, 20, 50], [2, 42, 10], [101, 10, 4]]

print("\nPractice List:")
for sub_list in practice_list:
    for num in sub_list:
        if num > 100:
            break
        if num < 10:
            continue
        if num < 50:
            print(num)

# below code is also correct
num = 5
if num == 5: print('num is 5')
else: print('num is not 5')

# ternary operator
"""
This is a readable and efficient way to create single line if statements ->
    `True value` if `expression` else `False value`
"""
num = 8
color = 'red' if num < 0 else 'blue'
print(color)

# you can add these in f-strings or lists
x = 5
print(f"The color is: {'red' if x < 10 else 'blue'}")

my_list = ['red' if x < 10 else 'blue', 'green', 'orange']
print(f"{my_list = }")
