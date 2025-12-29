# Open-Addressing goes brrr...

"""
Open-Addressing: When a collision occurs the key-value pair that are creating collision are stored in the table itself as opposed to a data structure like in separate chaining.

This means we need to care a great deal about the size of our hash table and how many elements are currently in the table.

Load Factor = items in table / size of table

The time complexity to find the elements grows exponentially after a certain threshold (usually when load factor > 0.8), so when our alpha(load factor) goes beyond our threshold value we need to grow the size of table (ideally exponentially, e.g. double).

How it works?
> When the position our key hashed is occupied we try another position in the hash table by offsetting the current position subject to a Probing sequence P(x). We keep doing this until we find an unoccupied position.

# Probing: There are infinite amount of probing sequences you can come up with, some of the popular ones are:

1. Linear Probing:
    P(x) = ax + b where a, b are constants and a != 0.

2. Quadratic Probing:
    P(x) = ax^2 + bx + c where a, b, c are constants and a != 0.

3. Double Hashing:
    P(k, x) = x * H2(k), where H2(k) is a secondary hash function.

4. Pseudo Random Number Generator:
    P(k, x) = x * RNG(H(k), x), where RNG is a random number generator function seeded with H(k).


NOTE: Most randomly selected probing sequences modulo N will produce a cycle shorter than the table size, which creates a problem when you try to insert value and all the indexes(buckets) on the cycle are filled because you'll get stuck in an infinite loop.
"""

class MyCustomError(Exception):
    def __init__(self, message, error_code):
        super().__init__(message)
        self.error_code = error_code

    def __str__(self):
        return f"{super().__str__()} (Error Code: {self.error_code})"

class hash_table_open_addressing:
    def __init__(self, SIZE=11):
        """
        Docstring for __init__

        :param self: it's needed to store members, so yeah!
        :param SIZE: size of the hash table (make sure it's prime to prevent early cycles)
        """
        self.SIZE = SIZE
        self.table = [None] * SIZE

    def hash(self, x):
        """
        Docstring for hash

        :param self: it's requried to access class members, so yeah!
        :param x: value you want to hash
        """
        return (x * x + 3) % self.SIZE

    def probe(self, key):
        """
        Docstring for probe

        :param self: it's required so yeah!
        :param key: to compute probe value
        """
        return 1 + (key % (self.SIZE - 1))

    def insert(self, key, value):
        """
        Docstring for insert

        :param self: it's a function inside the class so yeah!
        :param key: key for the value you want to insert
        :param value: value you want to insert in the hash table
        """
        hash_val = self.hash(key)
        step = self.probe(key)

        x = 0
        index = hash_val

        while self.table[index] is not None and self.table[index] != (): # not empty or a tombstone
            if self.table[index][0] == key: # key already exists (just update the value)
                self.table[index] = (key, value)
                return

            # print('Collision:', key)
            index = (hash_val + x * step) % self.SIZE
            x += 1

            if x > self.SIZE:
                raise MyCustomError("Hash Table is full.", 69)

        self.table[index] = (key, value)

    def find(self, key):
        """
        Docstring for find

        :param self: it's a class method so yeah!
        :param key: to find the element in the hash table
        """
        hash_val = self.hash(key)
        step = self.probe(key)

        x = 0
        index = hash_val

        while self.table[index] is not None:
            if self.table[index] != () and self.table[index][0] == key:
                return self.table[index]

            index = (hash_val + x * step) % self.SIZE
            x += 1

            if x > self.SIZE:
                return None
        return None

    def remove(self, key):
        """
        Docstring for remove

        :param self: it's a member function so yeah!
        :param key: key is used to find the pair to remove

        refer to this for better understanding - https://youtu.be/7eLDTtbzX4M?si=fs7nISmMooF6TyNy
        """
        hash_val = self.hash(key)
        step = self.probe(key)

        x = 0
        index = hash_val

        while self.table[index] is not None:
            if self.table[index] != () and self.table[index][0] == key:
                self.table[index] = () # set bucket to tombstone
                return
            index = (hash_val + x * step) % self.SIZE
            x += 1

            if x > self.SIZE:
                return

# creating a hash table
ht = hash_table_open_addressing()
values = ["Naruto", "Sasuke", "Sakura", "Kakashi", "Jiraya", "Tsunade", "Itachi", "Might Guy", "Madara", "Danzo"]

for key, value in enumerate(values):
    try:
        # insertion
        ht.insert(key, value)
    except MyCustomError as e:
        print("Error:", e)

# removal
ht.remove(4)
ht.remove(6)

# printing
print(ht.table)

# insertion of already existing key
ht.insert(1, "Kamal Stark is Awesome!")

# searching
print(ht.find(1))