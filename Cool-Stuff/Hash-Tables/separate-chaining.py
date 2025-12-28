# Separate Chaining

"""
Separate Chaining: is one of many strategies to deal with hash collisions by maintaining a data structure (usually a linked list) to hold all the different values which hashed to a particular(same) value.

NOTE: The data structure used to cache the items which hashed to a particular value is not limited to linked list. Some implementations use one or a mixture of: arrays, binary trees, self balancing trees etc.
"""

class node:
    def __init__(self, key=0, val=0, next=None):
        self.key = key
        self.val = val
        self.next = next


class linked_list:
    def __init__(self):
        self.head = None
        self.tail = None

    def insert(self,key,  val):
        if not self.head:
            self.head = self.tail = node(key, val)
            return

        self.tail.next = node(key, val)
        self.tail = self.tail.next

    def find(self, key):
        if not self.head:
            return None

        curr = self.head
        while curr and curr.key != key:
            curr = curr.next
        if curr:
            return curr.val
        return None

    def remove(self, val):
        if not self.head:
            return

        if self.head.val == val:
            node = self.head
            if not self.head.next:
                self.head = self.tail = None
            self.head = self.head.next
            del node
            return

        curr = self.head
        while curr.next and curr.next.val != val:
            curr = curr.next

        if curr:
            nodeToDelete = curr.next
            curr.next = nodeToDelete.next
            if not curr.next:
                # we deleted last node
                self.tail = curr
            del nodeToDelete

    def print(self):
        curr = self.head
        while curr:
            print("{", curr.key, ":" , curr.val, "}", end=" -> ")
            curr = curr.next
        print("NULL")

class hashTable_separate_chaining:
    def __init__(self, SIZE = 10):
        self.table = [linked_list() for _ in range(SIZE)]
        self.SIZE = SIZE

    def hash(self, x):
        return (x * x + 3) % self.SIZE

    def insert(self, key, val):
        self.table[self.hash(key)].insert(key, val)

    def getVal(self, key):
        curr = self.table[self.hash(key)]
        return curr.find(key)

    def remove(self, key):
        self.table[self.hash(key)].remove(self.getVal(key))

    def printTable(self):
        for head in self.table:
            head.print()


ht = hashTable_separate_chaining()
names = ["Luffy", "Zoro", "Nami", "Ussop", "Sanji", "Chopper", "Robin", "Brook", "Jimbei", "Franky"]

for i, name in enumerate(names):
    # insertion
    ht.insert(i, name)


# print table
print("Hash Table:")
ht.printTable()

# searching
print("\nVal at 3: ", ht.getVal(3))

# deletion
ht.remove(3)
print("Val at 3 (after removal): ", ht.getVal(3))

print("\nUpdated Hash Table:")
ht.printTable()