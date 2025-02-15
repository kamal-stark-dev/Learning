import pyautogui

# Fail-Safe: Move the cursor to the top-left corner to abort any running script.

# Getting screen size
width, height = pyautogui.size()
print(f'The screen is {width}x{height} pixels')

# Message boxes
pyautogui.confirm("Do you want to continue?")
pyautogui.alert('Automation Complete')