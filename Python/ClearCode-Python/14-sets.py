# Sets are dictionaries with just values, and every value is unique - duplicates are deleted

my_set = {1, 2, 3, 4, 4}

my_set.add(5)
my_set.remove(1)

print('set:', my_set)
print('len:', len(my_set))

# NOTE: set indexing and slicing doesn't work
# print(my_set[0]) -> TypeError: 'set' object is not subscriptable

print(my_set.pop())    # pops out the first element in the set and removes it from the set
print(my_set)          # you'll see that the set doesn't has the popped element now

# converting the set to list and indexing and slicing
print(list(my_set)[0])
print(list(my_set)[1:])

# What's the usecase of sets - they are very good at comparisions
A = {1, 2, 3, 4}
B = {3, 4, 5, 6, 7}

print(f"{A = }") # A
print(f"{B = }") # B
print(f"{A.union(B) = }") # A U B
print(f"{A.intersection(B) = }") # A n B
print(f"{A.difference(B) = }") # A - B
print(f"{B.difference(A) = }\n") # B - A

print(f"{A | B = }")
print(f"{A & B = }")
print(f"{A - B = }")
print(f"{B - A = }")

# You are given a list can you figure out if it has duplicates using sets or not ?
long_list_1 = [12, 15, 22, 12, 30, 45, 22, 18, 25, 30, 40, 12, 50, 18, 25, 60, 70, 80, 90, 45, 22, 30, 12, 15, 25, 18, 90, 100, 110, 120, 130]

print(f"{len(long_list_1) = }\n{len(set(long_list_1)) = }") # lengths are not same -> contains duplicates
print(f"List 1: {len(long_list_1) == len(set(long_list_1))}\n")

long_list_2 = [12, 15, 18, 22, 25, 30, 40, 45, 50, 60, 70, 80, 90, 100, 110, 120, 130]

print(f"{len(long_list_2) = }\n{len(set(long_list_2)) = }") # lengths are same -> contains unique elements
print(f"List 1: {len(long_list_2) == len(set(long_list_2))}\n")

# They are used in databases and data-analysis tasks (not much oftenly used like lists and tuples)