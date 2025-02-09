"""
@property -> allows you to turn methods into attributes
"""

from datetime import datetime

class Generic:
    def __init__(self):
        self._x = 10

    def getter(self):
        print(f'Get x: at {datetime.now()}')
        return self._x

    def setter(self, value):
        print('Set x')
        self._x = value

    def deleter(self):
        print('Delete x')
        del self._x

    x = property(getter, setter, deleter)


generic = Generic()
generic.x = 20 # set
print(f"{generic.x = }") # get
del generic.x # del

print()

class Generic_2:
    def __init__(self):
        self._x = 10

    @property
    def x(self):
        print(f'Get x: at {datetime.now()}')
        return self._x

    @x.setter
    def x(self, value):
        print('Set x')
        self._x = value

    @x.deleter
    def x(self):
        print('Delete x')
        del self._x

    # we do not need this now
    # x = property(getter, setter, deleter)

generic = Generic_2()
generic.x = 20 # set
print(f"{generic.x = }") # get
del generic.x # del