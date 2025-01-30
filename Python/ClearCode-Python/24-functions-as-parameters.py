# you can pass one function inside another as an argument

list_1 = [3, 2, 4, 5, 1]
print(f"{sorted(list_1) = }")
print(f"{sorted(list_1, reverse=True) = }")

# key argument
list_2 = [('a', 7), ('b', 10), ('c', 4), ('d', 2)]
print(f"\n{sorted(list_2) = }")

def sorted_function(item) -> int:
    return item[1]

print(f"{sorted(list_2, key=sorted_function) = }") # NOTE: you do not add `()` to the function

# usually you do all that with lambda funtion
print(f"{sorted(list_2, key=lambda item: item[1]) = }")

# Exercise:
inventory_names = ['Screws', 'Wheels', 'Metal Parts', 'Rubber Bits', 'Screwdrivers', 'Wood']
inventory_numbers = [43, 12, 95, 421, 23, 43]
combined_list = list(zip(inventory_names, inventory_numbers))

# 1. sort this list by inventory numbers
num_sorted_list = sorted(combined_list, key=lambda item: item[1])
print(f"\n{num_sorted_list}")

# 2. sort the combined list by length of inventory names
name_len_sorted = sorted(combined_list, key=lambda item: len(item[0]))
print(name_len_sorted)

# there is also `map` and `filter` functions
my_list = [1, 2, 3, 4, 5]

# map - changes values with function inside an iterable
# map(key, iterable)

def square_function(num):
    return num ** 2

print(f"\n{list(map(square_function, my_list)) = }")

# lambda alternative for the same
print(f"{list(map(lambda num: num ** 2, my_list)) = }")

# filter - filters out values form a condition
filtered_list = list(filter(lambda num: num < 4, my_list))
print((f"\n{filtered_list = }"))

# well these functionalities can be replaced by list comprehension
print([item ** 2 for item in my_list])
print([item < 4 for item in my_list])
print([item for item in my_list if item < 4])