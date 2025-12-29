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
        self.SIZE = SIZE
        self.table = [None] * SIZE

    def hash(self, x):
        return (x * x + 3) % self.SIZE

    def probe(self, key):
        return 1 + (key % (self.SIZE - 1))

    def insert(self, key, value):
        x = 1
        hash_val = self.hash(key)
        index = hash_val

        while self.table[index] not in [None, ()]: # not empty or a tombstone
            if self.table[index][0] == key: # key already exists (just update the value)
                self.table[index] = (key, value)
                return

            # print('Collision:', key)
            index = (hash_val + x * self.probe(key)) % self.SIZE
            x += 1

            if x > self.SIZE:
                raise MyCustomError("Cycle detected or Table is full.", 69)

        self.table[index] = (key, value)

    def find(self, key):
        x = 1
        hash_val = self.hash(key)
        index = hash_val
        while self.table[index] is not None:
            if self.table[index] != () and self.table[index][0] == key:
                return self.table[index]

            index = (hash_val + x * self.probe(key)) % self.SIZE
            x += 1

            if x > self.SIZE:
                return None
        return None

    def remove(self, key):
        x = 1
        hash_val = self.hash(key)
        index = hash_val

        while self.table[index] is not None:
            if self.table[index] != () and self.table[index][0] == key:
                self.table[index] = () # set bucket to tombstone
            index = (hash_val + x * self.probe(key)) % self.SIZE
            x += 1

            if x > self.SIZE:
                return

ht = hash_table_open_addressing()
values = ["Naruto", "Sasuke", "Sakura", "Kakashi", "Jiraya", "Tsunade", "Itachi", "Might Guy", "Madara", "Danzo"]

for key, value in enumerate(values):
    try:
        ht.insert(key, value)
    except MyCustomError as e:
        print("Error:", e)

ht.remove(4)
ht.remove(6)

print(ht.table)

ht.insert(1, "Kamal Stark is Awesome!")
print(ht.find(1))