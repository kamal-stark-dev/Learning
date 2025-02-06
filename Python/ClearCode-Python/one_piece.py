from random import choice

strawhats = ['Luffy', 'Zoro', 'Nami', 'Ussop', 'Sanji', 'Chopper', 'Robin', 'Franky', 'Brook', 'Jimbei']
pirates = ['Blackbeard', 'Shanks', 'Big Mom', 'Kaido', 'Whitebeard', 'Doflamingo', 'Crocodile', 'Buggy', 'Law', 'Kid']
marines = ['Akainu', 'Aokiji', 'Kizaru', 'Fujitora', 'Ryokugyu', 'Garp', 'Sengoku', 'Smoker', 'Tashigi', 'Coby']

class Character:
    '''contains the information about the characters <name, age, gender, status, fav_food> and some cool methods <attack, list_details>'''
    def __init__(self, name, age, gender, status, fav_food):
        self.name = name
        self.age = age
        self.gender = gender
        self.status = status
        self.fav_food = fav_food

    def attack(self):
        print(f'{self.name} is now attacking their special move!!')

    def list_details(self):
        message = f'''\nDetails of {self.name}:
    Age: {self.age} | Gender: {self.gender} | Status: {self.status} | Favorite Food: {self.fav_food}'''
        print(message)

def random_strawhat():
    return choice(strawhats)

def random_pirate():
    return choice(pirates)

def random_marine():
    return choice(marines)

def random_character():
    all_characters = strawhats + pirates + marines
    return choice(all_characters)

def random_fight():
    fighter1 = random_character()
    fighter2 = random_character()
    while fighter1 == fighter2:
        fighter2 = random_character()
    return f"{fighter1} vs {fighter2}"