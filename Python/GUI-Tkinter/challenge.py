import tkinter as tk
from tkinter import ttk
from tkinter.colorchooser import askcolor

def draw_on_canvas(event, bclr='black', bs = 5):
    x = event.x
    y = event.y
    canvas.create_oval((x - bs/2, y - bs/2, x + bs/2, y + bs/2), fill=bclr, outline=bclr)

def pick_color():
    global bclr
    color = askcolor(title='Choose a color')
    if color[1]:
        bclr = color[1]

def on_key_press(event):
    if event.char == 'r':
        canvas.create_rectangle((10, 10, event.x, event.y))


window = tk.Tk()
window.title("Drawing app")
window.geometry("600x400")

main_label = tk.Label(window, text='Basic Drawing App', font='Arial 12 bold')
main_label.pack()

canvas = tk.Canvas(window, bg='white')
canvas.pack()

bclr = 'black'
canvas.bind('<Motion>', lambda event: on_key_press(event))
canvas.bind('<Control-Motion>', lambda event: draw_on_canvas(event, bclr, brush_size_var.get()))
canvas.bind('<Shift-Motion>', lambda event: draw_on_canvas(event, 'white', eraser_size_var.get()))

brush_size_label = tk.Label(window, text='Brush Size')
brush_size_label.pack()

brush_size_var = tk.IntVar(value=4)
brush_size = tk.Spinbox(
    window,
    from_=1,
    to=25,
    textvariable=brush_size_var
)
brush_size.pack()

brush_color = tk.Button(window, text='Pick a Color', command=pick_color)
brush_color.pack()

eraser_size_label = tk.Label(window, text='Eraser Size')
eraser_size_label.pack()

eraser_size_var = tk.IntVar(value=10)
eraser_size = tk.Spinbox(
    window,
    from_=1,
    to=25,
    textvariable=eraser_size_var
)
eraser_size.pack()

window.mainloop()