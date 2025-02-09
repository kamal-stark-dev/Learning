"""
Both `eval` and `exec` are special functions that translate strings into python code.

Eval('1 + 1') will return 2
You can also use this to create new variables.

+--------------------------------------------------------+
| CAUTION: BE VERY CAREFUL WHILE USING `EVAL` OF `EXEC`. |
+--------------------------------------------------------+

Because if handled badly it can allow users to add their own code.
- Your database might get stealed.

Example: you are using eval or exec on input field designed to enter user's name, but they entered some malicious code to get your data.
"""

"""
Eval : it's less powerful and can only evaluate code, you can not create variables from it but can run simple function.

Exec : more powerful, can execute any code. You can create variables and fun functions etc.
"""

print(f"{eval('10 + 5') = }")
print(f"""{eval('"test".upper()') = }""")

# you can not create variables
# eval('a = 10') # SyntaxError: invalid syntax

# you can not run 'if' statement
# print(eval(if True: print('True'))) # SyntaxError: invalid syntax

# you can do the above in `exec`
exec('exec_a = 10')
print(f"{exec_a = }")

exec('if True: print("Cool")')

functions = ['upper', 'lower', 'title', 'casefold']
var = "Kamalveer Singh"

for method in functions:
    print(eval(f'"{var}".{method}()'))