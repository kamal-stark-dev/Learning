# A Class is just a blueprint for what an object should look like

class Microwave:
    def __init__(self, brand: str, power_rating: str) -> None:    # constructors
        self.brand = brand
        self.power_rating = power_rating
        self.turned_on = False

    def print_info(this) -> None:    # you can name it self or this or whatever you want to but it common to use self
        print("Brand        :", this.brand)
        print("Power Rating :", this.power_rating)

    def turn_on(self) -> None:
        if self.turned_on:
            print("Microwave is already turned on.")
        else:
            self.turned_on = True
            print("Microwave is now turned on.")

    def turn_off(self) -> None:
        if self.turned_on:
            self.turned_on = False
            print("Microwave is now turned off.")
        else:
            print("Microwave is already turned off.")

    def run(self, seconds: int) -> None:
        if not self.turned_on:
            print("Please turn on the microwave to use it.")
        else:
            print(f"Running the Microwave for {seconds} seconds.")

    def __add__(self, other):    # dunder methods
        return self.brand + "-" + other.brand

    def __mul__(self, other):
        return "I don't know what to do when you multiply them : )"

    def __str__(self) -> str:
        return f"{self.brand} (Rating: {self.power_rating})"

smeg: Microwave = Microwave("Smeg", "B")
print(smeg.brand, smeg.power_rating)

bosch: Microwave = Microwave("Bosch", "A")
bosch.print_info()
bosch.turn_off()
bosch.turn_on()
bosch.run(120)

print(smeg + bosch)
print(smeg * bosch)
print(smeg)
print(bosch)