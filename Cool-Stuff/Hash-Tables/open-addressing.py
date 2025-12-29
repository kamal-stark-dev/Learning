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

# Selecting a good load factor threshold value:

Q. Why alpha = 1 is a bad choice?
> Empty slots become rare, probe chains get longer and performance falls of the cliff.

For uniform hashing (which double hashing approximates very well):

Expected probe counts
Load factor  	    Successful search	    Unsuccessful search
0.50	            ~1.5 probes	            ~2.0 probes
0.70	            ~2.1 probes	            ~3.3 probes
0.80	            ~2.5 probes	            ~5.0 probes
0.90	            ~3.6 probes	            ~10.0 probes

Notice what happens after 0.7-0.75 👀, unsuccessful searches explode.

# Suggested Thresholds:
1. Linear Probing               0.5-0.6
2. Quadrating Probing           <= 0.5
3. Double Hashing               0.7-0.75

Double hashing tolerates higher threshold values because of:
    - minimal clustering
    - near-uniform distribution
"""

class MyCustomError(Exception):
    def __init__(self, message, error_code):
        super().__init__(message)
        self.error_code = error_code

    def __str__(self):
        return f"{super().__str__()} (Error Code: {self.error_code})"

class hash_table_open_addressing:
    def __init__(self, SIZE=11, threshold=0.7):
        """
        Docstring for __init__

        :param self: it's needed to store members, so yeah!
        :param SIZE: size of the hash table (make sure it's prime to prevent early cycles)
        :param threshold: decides when to start rehashing (default=0.7 is best for double hashing)
        """
        self.SIZE = SIZE
        self.table = [None] * SIZE

        # data for resizing table when needed
        self.currSize = 0
        self.load_factor = 0
        self.threshold = threshold

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

    def updateLoadFactor(self):
        self.load_factor = self.currSize / self.SIZE

    def insert(self, key, value):
        """
        Docstring for insert

        :param self: it's a function inside the class so yeah!
        :param key: key for the value you want to insert
        :param value: value you want to insert in the hash table
        """
        hash_val = self.hash(key)
        step = self.probe(key)

        x = 1
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

        # rehash the table if threshold reached
        self.currSize += 1
        self.updateLoadFactor()
        if self.load_factor >= self.threshold:
            self.rehash()


    def find(self, key):
        """
        Docstring for find

        :param self: it's a class method so yeah!
        :param key: to find the element in the hash table
        """
        hash_val = self.hash(key)
        step = self.probe(key)

        x = 1
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

        x = 1
        index = hash_val

        while self.table[index] is not None:
            if self.table[index] != () and self.table[index][0] == key:
                self.table[index] = () # tombstone
                self.currSize -= 1
                self.updateLoadFactor()
                return

            index = (hash_val + x * step) % self.SIZE
            x += 1

            if x > self.SIZE:
                return

    def greater_prime(self, num):
        """
        Docstring for greater_prime

        :param self: self is needed that's it!
        :param num: to get the prime number which is just greater than num
        """
        def is_prime(x):
            if x < 2:
                return False
            if x == 2:
                return True
            if x % 2 == 0:
                return False

            i = 3
            while i * i <= x:
                if x % i == 0:
                    return False
                i += 2
            return True

        num += 1
        while not is_prime(num):
            num += 1
        return num

    def rehash(self):
        """
        Docstring for rehash

        :param self: self is cool, I guess!

        This function rehashes the old table and created a new table which is nearly double the size of the previous one.
        """
        oldTable = self.table

        self.SIZE = self.greater_prime(2 * self.SIZE)
        self.table = [None] * self.SIZE

        # Reset State
        self.currSize = 0
        self.load_factor = 0

        # rehash the oldTable
        for bucket in oldTable:
            if bucket is not None and bucket != ():
                key, value = bucket
                self.insert(key, value)
                pass

        self.updateLoadFactor()


# creating a hash table
ht = hash_table_open_addressing()
values = ["Naruto", "Sasuke", "Sakura", "Kakashi", "Jiraya", "Tsunade", "Itachi"]

for key, value in enumerate(values):
    try:
        # insertion
        ht.insert(key, value)
    except MyCustomError as e:
        print("Error:", e)

# size
print("Table Size: ", ht.SIZE)

# removal
ht.remove(4)
ht.remove(6)

print(ht.table)

ht.insert(101, "Jake")
ht.insert(102, "Finn")
ht.insert(103, "Steve")
ht.insert(104, "Simon")

print("\nNew Table Size: ", ht.SIZE)

# printing
print(ht.table)
print()

# insertion of already existing key
ht.insert(1, "Kamal Stark is Awesome!")

# searching
print(ht.find(1))

"""
If you want to get deeper insight about selecting a good probing function and it's working, here's a deep dive.

Our Implementation: Double Hashing (Cycle-Safe Probing)

We use double hashing for collision resolution. When implemented correctly, double hashing
guarantees that no premature cycle occurs—meaning:

> If the hash table has at least one empty slot, probing will eventually reach it.

This property is what makes double hashing superior to most ad-hoc probing schemes.

---------------------------------------------------------------------

CORE REQUIREMENT (VERY IMPORTANT)

To avoid short cycles, the probe step must be coprime (no common positive integer is a factor except `1`) with the table size:

    gcd(step size, table size) = 1

This is why:
- The table size must be a prime number
- The secondary hash function must never return 0

---------------------------------------------------------------------

WHY NAIVE PROBING FAILS (RECAP)

Consider the probing rule:

    index = (hash + 2x) % SIZE

Example:
    SIZE = 10
    gcd(2, 10) = 2

This probe sequence can visit only:

    SIZE / gcd(2, SIZE) = 10 / 2 = 5 slots

Even if empty buckets exist, the probe may cycle early and loop forever.

This violates the invariant:

    "If space exists, probing must reach it."

---------------------------------------------------------------------

DOUBLE HASHING: THE CORRECT APPROACH

Double hashing uses a key-dependent step size:

    index(x) = (h1(key) + x * h2(key)) % SIZE

Where:
- h1(key) = primary hash function
- h2(key) = secondary hash function (step size)
- SIZE = prime table size

A standard and safe choice for h2 is:

    h2(key) = 1 + (key % (SIZE - 1))

Why this works:
- Output range is [1, SIZE - 1]
- Never returns 0
- Always coprime with SIZE when SIZE is prime

---------------------------------------------------------------------

DOUBLE HASHING EXAMPLE (CORRECT BEHAVIOR)

Given:
    SIZE = 11 (prime)
    h1(key) = key % 11
    h2(key) = 1 + (key % 10)

Let:
    key = 21

Compute:
    h1 = 21 % 11 = 10
    h2 = 1 + (21 % 10) = 2

Probe sequence:

    x = 0 → (10 + 0*2) % 11 = 10
    x = 1 → (10 + 1*2) % 11 = 1
    x = 2 → (10 + 2*2) % 11 = 3
    x = 3 → (10 + 3*2) % 11 = 5
    x = 4 → (10 + 4*2) % 11 = 7
    x = 5 → (10 + 5*2) % 11 = 9
    x = 6 → (10 + 6*2) % 11 = 0
    x = 7 → (10 + 7*2) % 11 = 2
    x = 8 → (10 + 8*2) % 11 = 4
    x = 9 → (10 + 9*2) % 11 = 6
    x = 10 → (10 + 10*2) % 11 = 8

All 11 indices are visited exactly once.
No early cycle occurs.
No empty slot is missed.

---------------------------------------------------------------------

WHY THIS WORKS (KEY INSIGHT)

When:
- SIZE is prime
- 1 ≤ h2(key) ≤ SIZE - 1

Then:

    gcd(h2(key), SIZE) = 1

This guarantees that the sequence:

    (h1 + x * h2) % SIZE

is a full permutation of all table indices.

This is a number-theoretic guarantee, not a heuristic.

---------------------------------------------------------------------

FINAL TAKEAWAY

Double hashing is the only commonly used open-addressing method that provides a
mathematical guarantee of full table coverage when implemented correctly.

Because of this:
- x > SIZE is a correct "table full" check
- No explicit cycle detection is needed
- Performance degrades gracefully instead of catastrophically
"""