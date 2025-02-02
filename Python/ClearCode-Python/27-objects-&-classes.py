# OBJECTS AND CLASSES

"""
Objects: Container for variables and functions.

For example a `monster` object might contain:
    Variables: health, energy, stamina, damage
    Functions: attack, movement, animations, roar

although they have special names ->
    variables in an object are called attributes
    functions in an object are called methods

(this is the only difference)

It is possible to have multiple objects ~
- Each object has its own attributes and methods
- Objects can also interact with each other (monster2 can attack monster1 and reduce its health)
"""

# Object Oriented Programming (OOP)
# Organizing code via objects -> almost all the projects are organized with OOPs

# CLASSES
"""
Class - blueprint for an object, when creating an object we first need a class.

A class also accepts arguments to customize objects.

+------------+          +------------+
|   CLASS    |          |   OBJECT   |
+------------+          +------------+
| health = ? |          | health = 5 |
| energy = ? |    ==>   | energy = 3 |
| attack()   |          | attack()   |
| move()     |          | move()     |
+------------+          +------------+

~ INHERITENCE ~
A class can injerit from another class, the resulting objects will have attributes and methods from both classes.

example - a class `Shark` inherit from `Monster`
    Monster -> Shark (speed = ?, bite())

we have only set speed and bite for the Shark but it's object can have the following attributes and methods
    - health, energy, speed and attack(), move(), bite()

Q. Why use classes and objects ?
-> 1. They organize complex code
   2. They help to create usable code
   3. They are used everywhere
   4. Some module requires you to create classes
   5. Makes it easier to work with scope

With increase in complexity of code, need of classes increases more and more.
"""

# Enough of theory let's do it practically
class Monster: # classes have `CamelCase` as naming convention
    # attributes
    health = 90
    energy = 30

    # methods
    def details(self): # you don't have to name `self` everytime but that's the convention
        return f"Health = {self.health}\nEnergy = {self.energy}"
    def attack(self, damage):
        print(f"Monster Attacked!!\nDamage of {damage} was dealt!!")

monster = Monster()
print(monster)

# accessing attributes
print(f"\n{monster.health = }")
print(f"{monster.energy = }\n")

# calling methods
print(monster.details())
monster.attack(100)

# dunder methods -> double underscore methods
"""
A dunder metnods is not called by the user. Instead, it is called by python when something happens.
example:
__init__ is called when the object is created
__len__ is called when the object is passed into len()
__abs__ is called when the object is passed into abs()
"""

class Monster:
    def __init__(self, health, energy):
        self.health = health
        self.energy = energy

    def details(self):
        return f"Health = {self.health}\nEnergy = {self.energy}"

    def __str__(self):
        return f"use the `details()` method to get monster details~"

monster_1 = Monster(100, 50)
monster_2 = Monster(70, 40)

print('\nMonster 1:\n' + monster_1.details())
print('\nMonster 2:\n' + monster_2.details())

print(f"\n{dir(monster_1) = }")

# see the attributes with their values
print(f"\n{vars(monster_1) = }")
print(f"\n{monster_2.__dict__ = }")

"""
NOTE: Everything in python is an object including strings, integers and even functions.
"""