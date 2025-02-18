import pyautogui, time

# moving clockwise in square boundaries for `n` times
'''
n = 3
for i in range(n):
    pyautogui.moveTo(500, 500, duration=0.25)
    pyautogui.moveTo(600, 500, duration=0.25)
    pyautogui.moveTo(600, 600, duration=0.25)
    pyautogui.moveTo(500, 600, duration=0.25)
'''

# achieving the same with moveRel
'''
for i in range(3):
    pyautogui.moveRel(100, 0, duration=0.25)
    pyautogui.moveRel(0, 100, duration=0.25)
    pyautogui.moveRel(-100, 0, duration=0.25)
    pyautogui.moveRel(0, -100, duration=0.25)
'''

# getting mouse position
print(f"{pyautogui.position() = }")

# getting screen's size
width, height = pyautogui.size()
print(f"Width: {width}\nHeight: {height}")

# getting mouse coordinates
'''
print('\nPress Ctrl-C to quit.')
try:
    while True:
        x, y = pyautogui.position()
        positionStr = 'X: ' + str(x).rjust(4) + ' Y: ' + str(y).rjust(4)
        print(positionStr, end='')
        print('\b' * len(positionStr), end='', flush=True) # try using this without flush
        # Note: once a new line is printed you can't erase any characters before it
except KeyboardInterrupt:
    print('\nDone.\n')

# the coordinates where you stopped will be printed
print('X:', str(x).rjust(4), ' Y:', str(y).rjust(4))
'''

# clicking the mouse
# pyautogui.rightClick(x, y)

# dragging mouse
'''
time.sleep(3) # move to paint program and select brush
pyautogui.click()

distance = 400
while distance > 0:
    pyautogui.dragRel(distance, 0, duration=0.2) # move right
    distance -= 20
    pyautogui.dragRel(0, distance, duration=0.2) # move down
    pyautogui.dragRel(-distance, 0, duration=0.2) # move left
    distance -= 20
    pyautogui.dragRel(0, -distance, duration=0.2) # move up
'''