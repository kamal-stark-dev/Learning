a = 10
del a
# print(a) --> NameError: name 'a' is not defined

# you could remove a variable but this is not what delete is mostly used for ~

# removing items from a list
my_list = [1, 2, 3, 4, 5]

# del (removes an item by it's index)
del my_list[1] # 2 will be removed
print('del my_list[1]:', my_list)

# remove (removes an item by value)
my_list.remove(3)
print('my_list.remove(3):', my_list)

# pop (removes an item by index -> by default -1)
popped_item = my_list.pop()
print('popped_item:', popped_item)
print('my_list.pop():', my_list)

# clear - clear the entire list
my_list.clear()
print('my_list.clear():', my_list)