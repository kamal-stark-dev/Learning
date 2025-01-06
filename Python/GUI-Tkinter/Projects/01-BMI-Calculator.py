import tkinter as tk
from tkinter import ttk

window = tk.Tk()
window.title("BMI Calculator")
window.geometry("400x250")

main_label = tk.Label(window, text='BMI Calculator', font='Arial 12 bold')
main_label.pack(pady=(15, 0))

# weight
weight_frame = tk.Frame(window)
weight = tk.IntVar(value=60)
weight_label = tk.Label(weight_frame, text='Enter Weight (in kgs) ', font='Arial 11 italic', fg='darkgreen')
weight_entry = tk.Spinbox(
    weight_frame,
    from_=1,
    to=500,
    textvariable=weight
)
weight_label.pack(side='left')
weight_entry.pack(side='left')
weight_frame.pack(pady=10)

# height
height_frame = tk.Frame(window)
height = tk.IntVar(value=160)
height_label = tk.Label(height_frame, text='Enter Height (in cms) ', font='Arial 11 italic', fg='blue')
height_entry = tk.Spinbox(
    height_frame,
    from_=1,
    to=500,
    textvariable=height
)
height_label.pack(side='left')
height_entry.pack(side='left')
height_frame.pack(pady=(0, 10))

def bmi_index(bmi):
    if bmi < 18.5:
        return 'Underweight', 'violet'
    elif bmi < 25:
        return 'Normal', 'green'
    elif bmi < 30:
        return 'Overweight', 'orange'
    else:
        return 'Obese', 'red'

def calculate_bmi():
    bmi = round((weight.get()) / ((height.get() / 100) ** 2), 2)
    note = bmi_index(bmi)
    BMI.set(f"{bmi} ({note[0]})")
    bmi_label['fg'] = note[1]
    bmi_label.pack()

# calculate button
button = tk.Button(window, text='Find BMI', command=calculate_bmi, font='Arial 11 bold')
button.pack(pady=10)

# BMI display
BMI = tk.DoubleVar()
bmi_label = tk.Label(window, text='', font='Arial 12 bold', textvariable=BMI)

window.mainloop()