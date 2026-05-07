from ursina import *

app = Ursina()

e1 = Entity(model='cube', texture="pattern.png", scale=2, position=(0, 0, 0))

EditorCamera()
app.run()