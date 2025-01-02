import tkinter as tk
from tkinter import ttk

window = tk.Tk()
window.geometry("600x400")
window.title("Combo-box and Spin-box")
# both needs to get a list of values passed

# Combobox
items = ('Ice Cream', 'Pizza', 'Sandwich', 'Mango Smoothie')
selected_food = tk.StringVar(value=items[0])
combo  = ttk.Combobox(window, textvariable=selected_food)
# combo['values'] = items
combo.config(values=items)
combo.pack()

food_label = tk.Label(window, text='Select your favorite food~')
food_label.pack()

# events for combobox
combo.bind('<<ComboboxSelected>>', lambda event: food_label.config(text=f'Favorite Food: {selected_food.get()}'))

# Spinbox
spin_int = tk.IntVar(value=10)
spin = ttk.Spinbox(
    window,
    from_=0, to=50, increment=10,
    textvariable=spin_int,
    command= lambda: print(spin_int.get())
)
# spin['values'] = [1, 2, 3, 4, 5]
spin.bind('<<Increment>>', lambda event: print('up'))
spin.bind('<<Decrement>>', lambda event: print('down'))
spin.pack()

window.mainloop()