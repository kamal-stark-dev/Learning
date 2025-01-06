import tkinter as tk

start_x = None
start_y = None

def set_start_point(event):
    global start_x, start_y
    start_x, start_y = event.x, event.y  # Set the starting point to the mouse click position

def on_key_press(event):
    if event.char == 'r' and start_x is not None and start_y is not None:
        # Create a rectangle from the starting point to the current mouse position
        canvas.create_rectangle(start_x, start_y, event.x, event.y, fill="blue")

def on_mouse_motion(event):
    # Update the rectangle's position dynamically as the mouse moves
    if start_x is not None and start_y is not None:
        canvas.delete("temp_rectangle")  # Remove the previous temporary rectangle
        canvas.create_rectangle(start_x, start_y, event.x, event.y, outline="red", tags="temp_rectangle")

root = tk.Tk()
canvas = tk.Canvas(root, width=400, height=400)
canvas.pack()

# Bind mouse click to set the starting point
canvas.bind("<Button-1>", set_start_point)

# Bind the 'R' key press event
canvas.bind("<KeyPress>", on_key_press)

# Bind mouse motion event
canvas.bind("<Motion>", on_mouse_motion)

# Focus the canvas to capture key events
canvas.focus_set()

root.mainloop()