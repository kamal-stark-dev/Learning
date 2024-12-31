import tkinter as tk
# from tkinter import ttk
import ttkbootstrap as ttk

window = ttk.Window()
window.title("Buttons")
window.geometry("400x280")

"""
There are 3 types of buttons in tkinter -
    1. Normal Button
    2. Check Button
    3. Radio Button
"""

def button_function():
    print("Simple Button Clicked")
    button_string.set("Clicked!!")
    print(f"The radio button's selected value is: {radio_var.get()}")  # accessing the radio button's value

# simple button
button_string = tk.StringVar(value="Simple Button")
button = ttk.Button(window, text="Simple Button", command=button_function, textvariable=button_string)
button.pack()

# check buttons
check1_var = tk.BooleanVar(value=0) # defalut value is 0 -> `off`
check_button1 = tk.Checkbutton(
    window, text="Check Box 1",
    command=lambda: print(f"Check-Box 1: {check1_var.get()}"),
    variable=check1_var
)
check_button1.pack()

check2_var = tk.IntVar(value=5)
check_button2 = tk.Checkbutton(
    window, text="Check Box 2",
    command=lambda: print(f"Check-Box 2: {check2_var.get()}"),
    variable=check2_var,
    onvalue=10,
    offvalue=5
)
check_button2.pack()

# radio buttons
radio_var = tk.StringVar(value=0)

radio_1 = tk.Radiobutton(
    master=window, text="Radio Button 1",
    value='radio 1',
    variable= radio_var,
    command=lambda: print(f"Radio Button 1: {radio_var.get()}")
)
radio_1.pack()

radio_2 = tk.Radiobutton(
    master=window,
    text="Radio Button 2",
    value=2,
    variable=radio_var,
    command=lambda: print(f"Radio Button 2: {radio_var.get()}")
)
radio_2.pack()

"""
You can also make your checkboxes behave like the radio buttons by modifying the `command` and setting
the `off` values for the other checkbox buttons, which will make it similar to radio buttons.

Q. How do you pass parameters in a function when you need as the command shouldn't have `()`??
Ans. We we have been doing this for a while without noticing, when we use the print function in lambda we are passing the string or variables as arguments in it.
So we can use the lambda function for the same:
>> command = lambda: func(a, b, c)

Ofcourse, their are other methods but this one's pretty useful.
"""

window.mainloop()