class Monster:
    def __init__(self, health, energy, **kwargs):
        # print(kwargs)
        self.health = health
        self.energy = energy
        # below super() is very smart as it runs when called from the children but skipped when directly Monster object is created!!
        super().__init__(**kwargs)

    def attack(self, amount):
        print(f'{amount} of damage was dealt!!')
        self.energy -= 20

    def move(self, speed):
        print(f'The moster has moved with the speed of {speed}')

class Fish:
    def __init__(self, speed, has_scales, **kwargs):
        self.speed = speed
        self.has_scales = has_scales
        super().__init__(**kwargs)

    def swim(self):
        print(f'The fish is swiming with the speed of {self.speed}')

# making a class that inherits from both Monster and Fish
class Shark(Monster, Fish):
    def __init__(self, bite_strength, health, energy, speed, has_scales):
        self.bite_strength = bite_strength
        super().__init__(health=health, energy=energy, speed=speed, has_scales=has_scales) # goes to Monster.__init__()


"""
MRO -> Method Resolution Order
print(Shark.mro())
[<class '__main__.Shark'>, <class '__main__.Monster'>, <class '__main__.Fish'>, <class 'object'>]
"""

# creating a Shark object
shark = Shark(
    bite_strength=100,
    health=200,
    energy=80,
    speed=160,
    has_scales=False
)

print(f'''Accessing the attributes ~
{shark.health = }
{shark.energy = }
{shark.speed = }
{shark.has_scales = }
''')
shark.move(60)
shark.swim()