class Monster:
    '''A monster that has attributes like health and energy. <doc-string>'''
    def __init__(self, health, energy):
        self.health = health
        self.energy = energy

        # private attributes and methods - it's just convention
        self._id = "Private Attribute"

    def _private_method(self):
        print("This is a private method")

    def attack(self, amount):
        print(f'{amount} of damage was dealt!!')
        self.energy -= 20

    def move(self, speed):
        print(f'The moster has moved with the speed of {speed}')

monster = Monster(100, 60)

# private
print(f"{monster._id = }")

# hasattr - (object, "attr_name")
print(f'\n{hasattr(monster, "health") = }')
print(f'{hasattr(monster, "fire") = }')

# setattr - (object, "attr_name", value)
setattr(monster, "weapon", "Axe") # same as doing - monster.weapon = 'Axe'
print(f"\n{monster.weapon = }")

print(f"\n{vars(monster) = }\n")

# docstring
print(monster.__doc__)
# help(monster)