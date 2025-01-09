import tkinter as tk
from tkinter import ttk

"""
arff -
@relation sample_data

@attribute id integer
@attribute name string
@attribute age numeric
@attribute gender {male, female}
@attribute phone string

@data
1, 'John Doe', 25, male, '555-1234'
2, 'Jane Smith', 30, female, '555-5678'
3, 'Jim Brown', 22, male, '555-8765'
4, 'Emily Davis', 28, female, '555-4321'
5, 'Michael Wilson', 35, male, '555-6789'
"""

window = tk.Tk()
window.title("Weka formatter (.arff)")
window.geometry("600x400")

table_name = tk.StringVar()
table_name_entry = tk.Entry(window, textvariable=table_name)
table_name_entry.pack()


window.mainloop()