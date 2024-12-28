"""
Widgets are the building blocks of `tkinter`, whether its text, buttons, entry fields, menus, frames or radio buttons etc. Understnading widgets is key to mastering any GUI framework.

Tkinter has 2 types of widgets -
    1. tk widgets - original
    2. ttk widgets - added later on and are much more modern than `tk` ones
"""

import tkinter as tk
# from tkinter import ttk
import ttkbootstrap as ttk

def btnClick():
    print("Button was Clicked")

def change_label():
    label['text'] = entry.get()
    entry['state'] = 'disabled'  # will disable the entry input field

def default_label():
    label.configure(text='This is a label')
    entry.config(state='enabled')

# create a window
window = tk.Tk()
window.title("Widgets")
window.geometry("800x600")  # widthxheight => 400x300

# adding a label
label = ttk.Label(master=window, text="I am a Label", font="Helvetica 14 bold")
label.pack(pady=4)

# adding a text area
tk.Text(master=window).pack()

# ttk entry
entry = ttk.Entry(master=window)
entry.pack(pady=4)

# ttk button
button = ttk.Button(master=window, text="Button", command=btnClick)    # note: the btn will call the fn. itself so don't add `()`
button.pack(pady=4)

button2 = ttk.Button(master=window, text="Print Input", command=lambda: print(entry.get()))    # using lambda fn.
button2.pack(pady=4)

"""
You can use two methods to get data from the widgets -
    1. using the `get()` function
    2. using variables - entry_input = tk.IntVar() -> set textvariable=entry_input

You can use the get() method for simpler tasks but it doesn't works for every widget like for labels.

Widgets can be updated with `config` -
    Label.config(text='some new text')
    Label['text'] = 'some new text'
"""

button3 = ttk.Button(master=window, text="Change Label", command=change_label)
button3.pack(pady=4)

button4 = ttk.Button(master=window, text="Default Label", command=default_label)
button4.pack(pady=4)

# main loop
window.mainloop()

print('Stopped!')  # this block will only run when the mainloop stops