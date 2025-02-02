# Inheritance - one class get the attributes and methods from another class(es)

# Parent
class Monster:
    def __init__(self, health, energy):
        self.health = health
        self.energy = energy

    def attack(self, amount):
        print('The monster has attacked!!')
        print(f'Damage of {amount} was dealt')
        self.energy -= 20

    def move(self, speed):
        print('The monster has moved')
        print('It has a speed of', speed)

# Child
class Shark(Monster):
    def __init__(self, speed, health, energy):
        # Monster.__init__(self, health, energy)
        super().__init__(health, energy) # super() refers to the parent class
        self.speed = speed

    def bite(self):
        print('The shark has bitten!!')

    # overwriting the `move` method
    def move(self):
        print('Shark has moved with the speed of', self.speed)

    # NOTE: you can still call the `move()` method of Monster by `super().move()`

shark = Shark(70, 100, 50)
print(f"{shark.health = }")
print(f"{shark.speed = }")

# inherited method
shark.attack(30)
# shark method
shark.bite()
# overridden method
shark.move()