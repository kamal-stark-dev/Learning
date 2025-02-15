import pyautogui

# move mouse to position (400, 400)
pyautogui.moveTo(400, 400, duration=1)

# moves mouse relative to current mouse position
pyautogui.moveRel(100, 0, duration=1)

# click at the current mouse position
pyautogui.click()
# pyautogui.click(300, 400)
# pyautogui.rightClick()
# pyautogui.doubleClick()
# pyautogui.middleClick()

# type text<<< Hello World >>>

pyautogui.write('# <<< Hello World >>>', interval=0.1)

# press enter key
pyautogui.press('enter')

# hold down multiple keys (Ctrl + C for copy)
# pyautogui.hotkey("ctrl", "c")
# pyautogui.keyUp("shift")

# take a screenshot
screenshot = pyautogui.screenshot()
screenshot.save("screenshots/screenshot.png")
# screenshot a specific region
# pyautogui.screenshot("screenshots/cutout.png", region=(0, 0, 300, 300))
