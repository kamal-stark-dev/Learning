import tkinter as tk
from tkinter import ttk

window = tk.Tk()
window.title("Canvas")
window.geometry('600x400')

# Canvas is a widget that allows you to 'draw shapes'

canvas = tk.Canvas(window, bg='#fff')
canvas.pack()

# rectangle
canvas.create_rectangle((10, 10, 100, 50), fill='#444', width=0) # left top right bottom

canvas.create_rectangle((50, 100, 100, 200), fill='cyan', width=5, dash=(1, 2, 4), outline='darkgreen')
canvas.create_line(50, 100, 100, 200, fill='orange')

# circle
canvas.create_oval(120, 50, 220, 150, fill='green', width=1)

# arc
canvas.create_arc(120, 50, 220, 150, fill='darkgreen', start=0, extent=120)

# polygon
canvas.create_polygon((250, 160, 200, 240, 300, 240), fill='violet')

# text
canvas.create_text((75, 80), text='Canvas Text', fill='#111')

# window
canvas.create_window((170, 200), window=ttk.Label(window, text='this is text label (widget)'))
canvas.create_window((170, 220), window=ttk.Entry(window))

# get the pointer's position
window.bind('<Shift-Motion>', lambda event: print(f"x: {event.x} y: {event.y}"))

window.mainloop()
