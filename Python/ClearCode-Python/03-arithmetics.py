# assigning two numbers
a = 10
b = 2

# addition
print('10 + 2 = ', a + b)
# subtraction
print('10 - 2 = ', a - b)
# multiplication
print('10 * 2 = ', a * b)
# division
print('10 / 2 = ', a / b)
# floor division
print('10 // 3 = ', a // 3) # will be 3 not 3.33...
# modulo - remainder
print('10 % 3 = ', a % 3)
# power
print('10 ^ 2 = ', a ** b) # 10 ^ 2 = 10 * 10 = 100

# operator precedence
# () > *, / > // > % > +, -
print('\n10 + 2 * 3 = ', a + b * 3)  # multiplication has higher precedence than addition
print('(10 + 2) * 3 = ', (a + b) * 3)  # parentheses change the order of operations
print('10 / 2 + 3 = ', a / b + 3)  # division has higher precedence than addition
print('10 / (2 + 3) = ', a / (b + 3))  # parentheses change the order of operations

# can you know print the average of numbers from 1 to 10 ?
average = (1 + 2 + 3 + 4 + 5 + 6 + 7 + 8 + 9 + 10) / 10
print('\nAverage of nums from 1 to 10 is', average)