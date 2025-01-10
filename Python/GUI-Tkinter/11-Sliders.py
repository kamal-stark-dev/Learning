import tkinter as tk
from tkinter import ttk
from tkinter import scrolledtext

window = tk.Tk()
window.title('Sliders')

"""
Tkinter has both sliders and progress-bar

The slider can be moved by the user or set independently
The progress bar can only be set independently
"""

scale_int = tk.IntVar(value=5)
scale = ttk.Scale(
    window,
    command = lambda value: print(scale_int.get()),
    from_=0,
    to=10,
    length=200,
    orient='horizontal', # horizontal by default
    variable=scale_int
)
scale.pack()

progress = ttk.Progressbar(
    window,
    variable=scale_int,
    maximum=10,
    orient='horizontal'
)
progress.pack(pady=12)

scrolled_text = scrolledtext.ScrolledText(
    window,
    width=60,
    height=10
)
scrolled_text.pack()

window.mainloop()