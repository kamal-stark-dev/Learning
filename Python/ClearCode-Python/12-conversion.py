# string to list/tuple
test = "Hii this is a test string!!"

print(test.split())
print(type(test.split())) # list

list_str = list(test)
print(list_str)

list_words = test.split()
print(list_words)

tuple_words = tuple(test.split())
print(tuple_words)

# list/tuple to string
str_list = "-".join(['Hii', 'there', 'I', 'am', 'list.']) # "-" -> sets the gap as `-`, if you use " " it'll be spaces
print(str_list)

# NOTE: the list shouldn't have non-strings in it

str_tuples = " ".join(('Hii', 'there', 'I', 'am', 'tuple.'))
print(str_tuples)

# can you extract only `1 2 3 4` from the list -> [1, 2, 3, 4] (without loops)
nums = [1, 2, 3, 4]
str_nums = str(nums)

result = str_nums.strip('[').strip(']').replace(',', '')
print('Result:', result)

"""
functions to change datatypes ->
int(), float(), str(), list(), tuple(), set(), dict(), bool()
"""