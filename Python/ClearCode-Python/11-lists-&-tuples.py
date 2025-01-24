# LISTS AND TUPLES

"""
Lists and Tuples are simple ways to store data.

- Both can store multiple items in a single variable.
- Lists are mutable, meaning their elements can be changed  after creation.
- Tuples are immutable, meaning their elements cannot be changed once created.

# Example of a list
my_list = [1, 2, 3, 4, 5]
print("Original list:", my_list)
my_list[0] = 10
print("Modified list:", my_list)
my_list.append(value) -> works

# Example of a tuple
my_tuple = (1, 2, 3, 4, 5)
print("Tuple:", my_tuple)
my_tuple[0] = 10   # will raise an error
my_tuple.append(value) -> won't work
"""

# LISTS
my_list = [1, 3.14, 'hello', True, ['list']]
print('List:', my_list)
print('Len of List:', len(my_list))

# append -> add element at the end of list
my_list.append(('tuple'))
print('List.append((\'tuple\')):', my_list)

# reverse the list
my_list.reverse()
print('List.reverse():', my_list)

# clear the list -> removes all elements
my_list.clear()
print('List.clear():', my_list, '\n')

# TUPLES
my_tuple = (1, 3.14, 'hello', True, ('tuple'))
print('Tuple:', my_tuple)
print('Len of Tuple:', len(my_tuple), '\n')

# NOTE: You don't actually have to use `()` for creating a tuple, but it's a good practice

# my_tuple.append(10) # ==> AttributeError: 'tuple' object has no attribute 'append'

# How to pick elements from lists and tuples -> INDEXING / SLICING
"""
Indexing -
    [1, 2, 3, 4][1] = 2
     0  1  2  3
It works on lists, tuples and strings but not on dictionaries and sets
"""
print('[1, 2, 3, 4][1]:', [1, 2, 3, 4][1])
print('my_tuple[1]:', my_tuple[1]) # should be `3.14`

my_list = [1, 3.14, ['a', 'b', 'c'], 'last-element']
print('my_list[2]:', my_list[2])
print('my_list[2][0]:', my_list[2][0])
print('my_list[-1]:', my_list[-1], '\n')    # first element from the last

"""
Slicing -
    [1, 2, 3, 4][1:3] = [2, 3]
     0  1  2  3

[a:b] -> indexe a is inclusive and index b is not
[start:end:step] -> example: [4:10:2]
"""
print('[1, 2, 3, 4][1:3]:', [1, 2, 3, 4][1:3])
print('my_list[1:3]:', my_list[1:3], '\n')

# slicing can also include a 3rd number telling the direction and increment
text = 'ILikeYourMom<3'
print('text[1:12]:', text[1:12]) # indexes: 1 2 3 4 5 6 7 8 9 10 11
print('text[1:12:2]:', text[1:12:2]) # indexes: 1 3 5 7 9 11
print('text[::-1]:', text[::-1], '\n') # reverse the list: -1 -2 ... -14

# if you want to go from the first index you can use [:n] instead of [0:n]
print('text[0:5]:', text[0:5])
print('text[:5]:', text[:5])

# similarly if you want till the last element [n:] instead of [n:last]
print('text[5:14]:', text[5:14])
print('text[5:]:', text[5:])

print('text[:]:', text[:]) # print all elements
print('text[::-1]:', text[::-1]) # print all elements in reverse
print('text[::2]:', text[::2], '\n') # print evert second element

# UNPACKING
a, b = [10, 20] # 10 gets assigned to 1 and 20 to b
print(f'a: {a}\nb: {b}')

p, q, r = (5, 3.14, False)
print(f'p: {p}\nq: {q}\nr: {r}')

# multiple variables assignment in single line -> basically tuple unpacking
name, age, isAdult = "Sam", 19, True

# swapping the values of two variables
var_1 = 10
var_2 = 20

var_1, var_2 = var_2, var_1
print('var_1:', var_1, '\nvar_2:', var_2)