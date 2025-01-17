# Comments - annotations in the code that are not executed. They are used to explain the code and make it more readable.

# This is a single-line comment

"""
This is a multi-line comment
that spans multiple lines
"""

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