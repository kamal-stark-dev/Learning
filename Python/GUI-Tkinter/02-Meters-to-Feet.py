import tkinter as tk
# from tkinter import ttk
import ttkbootstrap as ttk

def meters_to_feet():
    feets_output.set(str(round(meters_input.get() * 3.2808399, 2)) + ' ft')

theme = "journal"
def switch_mode():
    global theme
    if (mode_value.get() == "Light"):
        theme = "darkly"
        mode_value.set('Dark')
    else:
        theme = "journal"
        mode_value.set("Light")

    style = ttk.Style()
    style.theme_use(theme)


# window
window = ttk.Window(themename=theme)
window.title('Meters to Feets')
window.geometry('400x300')

# title
title_label = ttk.Label(master=window, text='Meters to Feet', font='arial 16 bold')
title_label.pack(pady=(30, 0))

# input frame
input_frame = ttk.Frame(master=window)

meters_input = tk.DoubleVar()
entry = ttk.Entry(master=input_frame, textvariable=meters_input)

convertBtn = ttk.Button(master=input_frame, text='Convert', command=meters_to_feet)

entry.pack(side='left')
convertBtn.pack(side='left')
input_frame.pack(pady=12)

# output
feets_output = tk.StringVar()
output = tk.Label(master=window, textvariable=feets_output, font="arial 14 italic bold")
output.pack()

# Light / Dark mode
mode_value = tk.StringVar(value="Light")
mode_button = ttk.Button(master=window, text="light", command=switch_mode, textvariable=mode_value)
mode_button.pack(side='right', padx=(0, 10))

# mainloop
window.mainloop()
