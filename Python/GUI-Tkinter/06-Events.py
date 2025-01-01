import tkinter as tk
from tkinter import ttk

"""
Events can be any of these - Keyboard inputs, widgets getting changed, widgets getting selected/unselected, mouse click/motion/wheel etc.

These events can be observed and made use of -> like when a button is clicked a function is executed.
"""

def get_pos(event):
    print(f"x: {event.x} y: {event.y}")

window = tk.Tk()
window.title("Events")
window.geometry("600x500")

text = tk.Text(window)
text.pack()

entry = tk.Entry(window)
entry.pack()

button = tk.Button(window, text='Button')
button.pack()

# Event - widget.bind('modifier-type-detail', function)
text.bind('<Alt-KeyPress-a>', lambda event: print("event triggered"))
window.bind('<KeyPress>', lambda event: print(f"Key Pressed: {event.char}"))

# window.bind('<Motion>', get_pos)

entry.bind('<FocusIn>', lambda event: print("entry field was selected"))
entry.bind('<FocusOut>', lambda event: print("entry field was unselected"))

text.bind('<Shift-Motion>', lambda event: print("Mouse-Motion-Detected"))

window.mainloop()