# STRINGS

"""
created with '' or ""

example -
    greet = 'Hello World'
    bye = "Bye World"

you can also concatenate strings
    greet = 'hello' + 'world'
"""

print('Hello World')

print('Bye' + ' World')

# if you want to add the '' or "" symbols you can use `\`
print('He\'s smart~')

# use `\n` to add a new line
print("Line 1\nLine 2")

# add multiple lines as a comment
multiline_string = """ _______
< Hello! >
 -------
        \   ^__^
         \  (oo)\_______
            (__)\       )\/\\
                ||----w |
                ||     ||"""
print(multiline_string)

# repeat a string `n` times
print('cool ' * 8)

# format and f-strings
name = "Sam"
age = 21
text1 = "\nHii I am {} and I am {} years old!!".format(name, age)

name, age = "Jake", 19
text2 = "Hii I am {one} and I am {two} years old!!".format(two=age, one=name)

name, age = "Sophia", 22
text3 = f"Hii I am {name} and I am {age} years old!!" # f-strings ==> directly enter the variables in `{}`

print(text1, text2, text3, sep='\n')
