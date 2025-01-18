# Comments - annotations in the code that are not executed. They are used to explain the code and make it more readable.

# This is a single-line comment

"""
This is a multi-line comment
that spans multiple lines
"""

'''
This is also a multi-line comment
'''

print("Hello World") # this is a comment after the print statement

def add(a, b):
    """
    This function adds two numbers.

    Parameters:
    a (int): The first number
    b (int): The second number

    Returns:
    int: The sum of the two numbers
    """
    return a + b

# Example usage of the add function
result = add(5, 3)
print("The sum is:", result)

'''
You can use `Ctrl + /` to toggle comment for the selected code/text
'''