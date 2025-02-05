# Modules - extra parts that you can import and make use of, or you can create your own modules to make code more organized~

import random, string
from math import sin, pi as PI

random_number = random.randint(1, 10)
print(f"{random_number = }")

strawhats = ['Luffy', 'Robin', 'Zoro', 'Nami', 'Sanji', 'Ussop', 'Chopper', 'Jimbei', 'Brook', 'Franky']
print(f"\nRandom Strawhat: `{random.choice(strawhats)}`")

print(f"\n{string.ascii_uppercase = }")

print(f"\n{sin(PI / 2) = }")

# Exercise: Print the current date and time using a python module ~
from datetime import datetime as dt

print('\nCurrent Date-Time:', dt.now())

"""
External Modules - Modules made by other programmers. For example game development, data analysis, data visualization, GUI etc.

> This is one of really strong part of Python - it has a large variety of modules that are really useful.

# These modules are imported just like the normal modules the only difference is that you'll first need to install them ~
The installation usually happens in terminal (CLI).

> Just open terminal and type the module_name -> `pip install module_name`
"""

# let's make a fun program which writes text automatically
import pyautogui
from time import sleep

sleep(3)
message = "This text is being written by the machine!!"
pyautogui.write(message, interval=0.1)