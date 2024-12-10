# Package - collection of modules

# To create a package then create a file and there add your modules also add one `__init__.py` file to tell it's a module.

from numbers.primes import listPrimes

from numbers import factors

print(listPrimes(100))

print(factors.getFactors(100))
