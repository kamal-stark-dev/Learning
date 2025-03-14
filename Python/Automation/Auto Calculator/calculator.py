import pyautogui
import time

def openCalculator():
    pyautogui.press('win')
    time.sleep(1)

    pyautogui.write('calculator', interval=0.1)
    time.sleep(1)

    pyautogui.press('enter')
    time.sleep(1)

def pressButton(button):
    imgPath = rf'buttons/{button}.png'
    location = pyautogui.locateCenterOnScreen(imgPath, confidence=0.9)
    if location is not None:
        x, y = location
        pyautogui.moveTo(x, y, duration=0.5)
        pyautogui.leftClick()

# open calculator
# openCalculator()

# # perform calculation
# pressButton('2')
# pressButton('dot')
# pressButton('5')
# pressButton('plus')
# pressButton('2')
# pressButton('equals')

validSymbols = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', '+', '-', '*', '/', '.', '='}
convertor = {'.': 'dot', '+': 'plus', '*': 'multiply', '-': 'minus', '=': 'equals', '/': 'divide'}

def parseString(calculationStr):
    paths = []
    for symbol in calculationStr:
        if symbol not in validSymbols:
            continue
        elif symbol in convertor:
            paths.append(convertor[symbol])
        else:
            paths.append(symbol)
    return paths

def calculate(input: str):
    # find the relative paths
    buttons = parseString(input)

    # open the calculator
    openCalculator()

    # click appropriate buttons
    for button in buttons:
        pressButton(button)
    time.sleep(1)

calString = '2   *  2.5 = '
calculate(calString)

# TODO: Need to make it more functional and have things like "squares and roots and all"