# FIlE HANDLING IN PYTHON
"""
Python can open any simple file (example- '.txt')
Python can actually open nearly any file but you may need external modules :)
"""

# Open and Close a file manually
file = open('./assets/file-handling/demo.txt')
print(f"Manual Opening and Closing: {list(file)}")
file.close()

# open and close file automatically
print('File Contents: ')
with open('./assets/file-handling/demo.txt') as file:
    # print(file.read())
    for line in list(file):
        print(line, end="")

# write in a file
# with open('./assets/file-handling/demo.txt', 'a') as file:
#     file.write('\nXXXXX This is text put from code XXXXX')

# NOTE: if you use 'w' instead of 'a' then the whole file will be over-written and not appended

# You can also use 'w' or 'a' to create a new file and then write to it

# This is pure basics of file-handling in python. (it has a lot of potential usecases)