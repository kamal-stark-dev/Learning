# List Comprehension - way to create lists with just one line of code

# making a list of nums from 0 to 20
"""
my_list = []
for n in range(0, 21):
    my_list.append(n)
"""
# we can do the same in just one line
my_list = [num for num in range(0, 21)]
print(my_list)

# squares of nums from 1 to 10
squares = [num ** 2 for num in range(1, 11)]
print(squares)

# you can also use if-else statements to filter lists

# storing all the even numbers from (1 - 20) in a tuple
evens = tuple(num for num in range(1, 21) if num % 2 == 0)
print(evens)

inventory_names = ['Screws', 'Wheels', 'Metal Parts', 'Rubber Bits', 'Screwdrivers', 'Wood']
inventory_numbers = [43, 12, 95, 421, 23, 43]

# make a list of items with parts less than 25
replenish_list = [(name, count) for name, count in zip(inventory_names, inventory_numbers) if count < 25]
print(replenish_list)

# combined list comprehension
combined = [[(x, y) for x in range(5)] for y in range(3)]
print('Combined:')
for row in combined:
    print(row)

# Exercise:
# Create fields for chess board: abcdefgh and 12345678
print("\nCHESS BOARD:")
chess_board = [[f'{letter}{number}' for number in range(1, 9)] for letter in "ABCDEFGH"[::-1]]
for row in chess_board:
    print(row)
print()

# besides lists you can also do these for tuples, dictionaries and sets
print({num for num in range(1, 11)})
print({num: num ** 2 for num in range(1, 11)})
print(tuple(num ** 3 for num in range(1, 11)))