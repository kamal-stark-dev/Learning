"""
Dictionaries: Key-Value pair.

NOTE: Keys are always unique, and both keys and values can be of any datatype.
> If you add the same key to another value then the previous value will be over-written.

syntax:
    {key: value}
"""

test_dict = {'a': 10, 'b': [1, 2, 3], 123: 'String'}
print('Dict:', test_dict)
print('Keys:', test_dict.keys())
print('Values:', test_dict.values())
print('Items:', test_dict.items())
print('Length:', len(test_dict))

# converting to list, tuples
print(list(test_dict))
print(tuple(test_dict))

# indexing in dictionaries - dict[key]
print(test_dict['a'])
print(test_dict.get(123))

"""
Which one is better for indexing `[]` or `get()` method ?
-> get() is better because if we pass a key that does not exists in `[]` then we'll get an error but get will just return 'None'

dict[X]       -->    returns error if it cannot find the key
dict.get(X)   -->    returns None if it cannot find the key

So, if you're not sure that key exists or not then use get() method.
"""

# Adding pairs to dictionaries
test_dict['new key'] = 'new value' # can also use `test_dict.update('new key' = 'new value')`
print(test_dict)

# use the update method to add multiple pairs
test_dict.update({'city': 'Delhi', 'age': 20})
# test_dict.update(city = 'Delhi', age = 20)
print(test_dict)

