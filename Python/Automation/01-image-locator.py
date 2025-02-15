import pyautogui

x, y = pyautogui.locateCenterOnScreen("assets/copilot.png", confidence=0.8)
print(f'Copilot Location: {x}, {y}')

pyautogui.moveTo(x, y, duration=1)

# get pixel color
pixel_color = pyautogui.pixel(400, 400)
print(f'Pixel Color: {pixel_color}')  # Output: (R, G, B)