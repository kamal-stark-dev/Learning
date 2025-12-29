# Hash Tables go brrr...
import random

print("Hash Tables go brrr...\n")

def Hash_Int(n: int) -> int:
    return ((n * n) - (6 * n) + 9) % 10

def Hash_String(s: str) -> int:
    sum = 0
    for c in s:
        sum += ord(c)
    return sum % 50

nums = [5,  0, -7, 8, 100]
print("Integers Hashes:")
for num in nums:
    print(Hash_Int(num), end=" ")


strs = ["hello", "bam", "cool", "BOOM", ""]
print("\n\nStrings Hashes:")
for s in strs:
    print(Hash_String(s), end=" ")

names = ["William", "Hina", "Samuel", "Rose"]
ages = [21, 19, 32, 24]
genders = ["M", "F", "M", "F"]

def hash_group(name: str, age: int, gender: str) -> int:
    n = age
    n += len(name)
    n //= 2 if gender == "M" else 1
    return n % 6

print("\n\nGroup Hashes:")
for name, age, gender in zip(names, ages, genders):
    print(hash_group(name, age, gender), end=" ")
print()

"""
NOTE: if H(a) == H(b) then objects a and b might be equal but if H(a) != H(b) then a and b are definitely not equal.

We can use this to our advantage, How?
> if we have already computed hash values of two objects then before comparing them first we can compare their hash values and proceed to compare them when both of their hash values are same.

- If you need to check if two very large files have the same comtents, if we have precomputed their hash values H(file1) and H(file2) then we should compare them first as it's O(1) operation and only proceed to check their contents if their hash values are same.

NOTE: Hash functions for files are more complex than that used for hash-tables. Instead for files we use 'cryptographic hash functions' also called 'checksums'.

A hash function H(x) must be deterministic, this means if H(x) = k, then H(x) must always produce k and never another value.
"""

# example of non-deterministic hash funciton
def nd_hash(n):
    return ( n + random.randint(1, 6) ) % 13# die roll

print('\nNon-Deterministic Hash Function:')
print('H(7):', nd_hash(7))
print('H(7):', nd_hash(7))

"""
We try to make 'uniform' hash functions to minimize the number of hash collisions.

What's a hash collision?
> A 'hash collison' is when two different objects x and y has the same hash value (i.e. H(x) == H(y)).

To enforce a hash functions be deterministic, we demand that the 'key used in hash table are immutable' data types.
> Immutable integers, strings and tuples are valid keys, whereas lists or sets are not.

We would like to have very fast insertion, lookup and removal for the data we are placing withing our hash table.
> We can achieve all this in O(1) time using a 'hash function as a way to index into a hash table'. * The constant time behaviour attributed to hash functions is only true if you have a good 'uniform' hash function. *
"""

"""
SIZE = 10
def hash(x):
    return (x * x + 3) % SIZE

hashTable = [()] * SIZE

def insert(pair, table=hashTable):
    key, val = pair
    hashTable[hash(key)] = (key, val)

def getVal(key, table=hashTable):
    return hashTable[hash(key)][1]
"""

class hashTable:
    def __init__(self, SIZE = 10):
        self.table = [()] * SIZE
        self.SIZE = SIZE

    def hash(self, x):
        return (x * x + 3) % self.SIZE

    def insert(self, key, val):
        self.table[self.hash(key)] = (key, val)

    def getVal(self, key):
        pair = self.table[self.hash(key)]
        return pair[1] if pair else None

    def remove(self, key):
        self.table[self.hash(key)] = ()

ht = hashTable()
names = ["Luffy", "Zoro", "Nami", "Ussop", "Sanji", "Chopper"]
for i, name in enumerate(names):
    ht.insert(i, name)

print("\nHash Table:", ht.table)
print("\nKey 4:", ht.getVal(4))
ht.remove(4)
print("Key 4 (after removal):", ht.getVal(4))

ht2 = hashTable()
names = ["Luffy", "Zoro", "Nami", "Ussop", "Sanji", "Chopper", "Robin", "Brook", "Jimbei", "Franky"]
for i, name in enumerate(names):
    ht2.insert(i, name)

print("\nHash Table 2:", ht2.table)

"""
But how do we manage collisions in the hash table?
> currently it'll just override our previous pair with the new pair on the place of collision. (we can see that in our hash table 2)

`Hash Table 2: [(), (), (7, 'Brook'), (0, 'Luffy'), (9, 'Franky'), (), (), (8, 'Jimbei'), (5, 'Chopper'), (6, 'Robin')]`
We can notice that 4 values are overridden -> 'Zoro', 'Nami', 'Ussop', 'Sanji' the OG strawhats are missing :(
These names are overridden due to collisions on those indexes which occured due to hash function yielding the same key for 2 values.

We can also notice that 4 values in our hash table are empty, even after inserting values that the structure can hold. It happens due to our hash function being non-uniform (making it a poor hash function). -> which leads to more collisions


# Collision Handling:

1. Separate Chaining: deals with hash collisions by maintaining a data structure (usually a linked list) to hold all the different values which hashed to a particular value.

2. Open Addressing: deals with hash collisions by finding another place within the hash table for the object to go by offsetting it from the position to which it hashed to.

# What real systems do (sanity check):

<System>                            <Strategy>                          <Threshold>
Java - HashMap                      Double hashing–like	                0.75
(open addressing variant)
CPython - dict	                    Perturbed probing (OA)              ~0.66
C++ - unordered_map	                Separate chaining                   1.0 (different rules)


# Complexity:
Operation           Average             Worst
Insertion           O(1)                O(n)
Removal             O(1)                O(n)
Search              O(1)                O(n)
"""