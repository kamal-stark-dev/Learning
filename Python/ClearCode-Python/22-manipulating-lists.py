inventory_names = ['Screws', 'Wheels', 'Metal Parts', 'Rubber Bits', 'Screwdrivers', 'Wood']
inventory_numbers = [43, 12, 95, 421, 23, 43]

# we want to use data from both the lists at the same time - zip()
print(zip(inventory_names, inventory_numbers))
print(list(zip(inventory_names, inventory_numbers)))

for item in zip(inventory_names, inventory_numbers):
    print(item[0], '-', item[1], end="    ")
print() # for new line

for name, count in zip(inventory_names, inventory_numbers):
    print(name, '-', count, end="    ")
print()

# enumerate function
print(enumerate(inventory_names))
print(list(enumerate(inventory_names)))

for i, name in enumerate(inventory_names):
    if i % 2 == 0:
        continue
    print(f"idx: {i} -> {name}")

# Exercise:
# Combine zip and enumerate to get 'Screws [id : 0] - inventory: 43'
print(list(zip(enumerate(inventory_names), inventory_numbers)))

# for (idx, name), count in zip(enumerate(inventory_names), inventory_numbers):
#     print(f"{name} [id : {idx}] - inventory: {count}")

for idx, (name, count) in enumerate(zip(inventory_names, inventory_numbers)):
    print(f"{name} [id : {idx}] - inventory: {count}")

# WoW that was really cool!!