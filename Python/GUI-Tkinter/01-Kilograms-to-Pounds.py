import tkinter as tk
# from tkinter import ttk
import ttkbootstrap as ttk

"""
tk -> has all the basic logics for the app
ttk -> has all the widgets which we nee d
ttkbootstrap -> used to improve the UI
"""

def convertKgToLbs():
    # 1 kg = 2.20462262185 lbs
    lbs_value.set(str(round(entryInt.get() * 2.20462262185, 2)) + ' lbs')

# main window
window = ttk.Window(themename="solar")
window.title("Kilograms to Pounds")
window.geometry("400x240")

# title
title_label = ttk.Label(master=window, text="Kilograms to Pounds", font="Helvetica 18 bold")
title_label.pack(pady=(55, 5))


# input field
input_frame = ttk.Frame(master=window)
entryInt = tk.DoubleVar()
kilogramEntry = ttk.Entry(master=input_frame, textvariable=entryInt)
convertButton = ttk.Button(master=input_frame, text='Convert', command=convertKgToLbs) # do not add `()` with fn. the btn will do it itself

kilogramEntry.pack(side="left", padx=5)
convertButton.pack(side="left")
input_frame.pack(pady=10)

# output
lbs_value = tk.StringVar()
output_label = ttk.Label(master=window, text=f"{lbs_value} lbs", font='Helvetica 18 italic', textvariable=lbs_value)
output_label.pack()

# main loop
window.mainloop()
