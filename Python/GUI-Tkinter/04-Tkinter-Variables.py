import tkinter as tk
from tkinter import ttk

window = tk.Tk()
window.title('Tkinter Variables')
window.geometry('400x300')

def display_username():
    socials = ["github", "x","instagram"]
    output = ""
    for social in socials:
        output += f"https://www.{social}.com/{entry.get().lower()}\n"
    string_input.set(output)

info_label = ttk.Label(master=window, text="Enter desired Username - ")
info_label.pack(pady=8)

# Tkinter variable
string_input = tk.StringVar()

entry = ttk.Entry(master=window)
entry.pack(pady=(0, 10))

button = ttk.Button(master=window, text="Give Socials", command=display_username)
button.pack()

label = ttk.Label(master=window, textvariable=string_input, font="Helvetica 12")
label.pack(pady=(5, 0))

window.mainloop()