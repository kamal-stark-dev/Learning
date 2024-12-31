import tkinter as tk
from tkinter import ttk

window = tk.Tk()
window.title("Challenge on Buttons")

# check button
check_var = tk.IntVar()

check_button = tk.Checkbutton(
    window, text="Check Box",
    variable=check_var,
    onvalue=100,
    offvalue=20,
    command=lambda: print(f"Radio Value: {radio_var.get()}")
)
check_button.pack()

def radio_function():
    print(f"Check Button value is: {radio_var.get()}")
    check_var.set(20)

# radio buttons
radio_var = tk.StringVar()

radio_1 = tk.Radiobutton(
    window, text="Radio 1",
    value='radio 1',
    variable=radio_var,
    command=radio_function
)
radio_1.pack()

radio_2 = tk.Radiobutton(
    window, text="Radio 1",
    value='radio 2',
    variable=radio_var,
    command=radio_function
)
radio_2.pack()

window.mainloop()