import pyautogui
import time

def openCalculator():
    pyautogui.press('win')
    time.sleep(1)

    pyautogui.write('calculator', interval=0.1)
    time.sleep(1)

    pyautogui.press('enter')
    time.sleep(1)

# performing calculation 2 + 2 =
def pressButton(button):
    imgPath = rf'buttons/{button}.png'
    location = pyautogui.locateCenterOnScreen(imgPath, confidence=0.9)
    if location is not None:
        x, y = location
        pyautogui.moveTo(x, y, duration=0.5)
        pyautogui.leftClick()

# open calculator
openCalculator()

# perform calculation
pressButton('2')
pressButton('dot')
pressButton('5')
pressButton('plus')
pressButton('2')
pressButton('equals')
