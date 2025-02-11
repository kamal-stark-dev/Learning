import tkinter as tk
from tkinter import ttk
from random import choice

window = tk.Tk()
window.title("Treeview")
window.geometry("600x400")

first_names = ['Naruto', 'Sasuke', 'Kakashi', 'Zoro', 'Robin', 'Luffy', 'Sanji', 'Madara', 'Itachi', 'Oden']
last_names = ['Uzumaki', 'Uchiha', 'Hatake', 'Roronoa', 'Nico', 'Taro', 'Vinsmoke', 'Uchiha', 'Uchiha', 'Kozuki']

# treeview
table = ttk.Treeview(
    window,
    columns=('first', 'last', 'email'),
    show='headings',
)
table.heading('first', text='First name')
table.heading('last', text='Last name')
table.heading('email', text='Email')
table.pack(fill='both', expand=True)

# Insert values
# table.insert(parent='', index=0, values=('Kamalveer', 'Singh', 'Kamalveer3829@gmail.com'))

email_ends = ['gmail.com', 'outlook.com', 'email.me', 'hotmail.in', 'yahoo.in', 'email.com']

for i in range(30):
    fn = choice(first_names)
    ln = choice(last_names)
    email = f"{fn.lower()}{ln.lower()}@{choice(email_ends)}"
    table.insert(parent='', index=i, values=(fn, ln, email))

def item_select(_):
    for item in table.selection():
        print(table.item(item)['values'])

table.bind('<<TreeviewSelect>>', item_select)

def delete_item(_):
    for item in table.selection():
        table.delete(item)

table.bind('<Delete>', delete_item)

window.mainloop()