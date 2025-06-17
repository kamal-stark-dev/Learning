#include <iostream>>

class Entity {
public:
	float X, Y;

	// constructor
	Entity() { 
		X = 0.0f;
		Y = 0.0f;
		std::cout << "Created Entity!\n";
	}

	Entity(int x, int y) {
		X = x, Y = y;
		std::cout << "Created Entity!\n";
	}

	~Entity() { // to remove the dynamically allocated memory in the heap
		std::cout << "Destroyed Entity!\n";
	}

	void Print() {
		std::cout << X << ", " << Y << '\n';
	}
};

class temp {
/*private:
	temp() {}*/
public:
	temp() = delete;
	void static greet(const char* user) {
		std::cout << "Hello " << user << "!\n";
	}
};

void function() {
	Entity e;
	e.Print();

	Entity e1(2, 3);
	e1.Print();
}

int constutors_and_destructors() {
	function();
	//temp t; // will not be possible
	temp::greet("Jake");

	return 0;
}

/*
### Constructor - 

If you don't create your own constructor then you have something 
called a `default constructor` which is nothing but an empty constructor.

Default Constructor:
```cpp
ClassName() {

}
```

You can write as many constructor you want to as long as they have different signatures.

> Constructor would not run if you just use a static method from a class.

if you want your class to not be instantiated then you can do the same by either making your 
default constructor private scoped or using `ClassName() = delete;`.

### Destructor - 

Destructor is a special member function which is invoked when an object goes out of scope
or is explicitly deleted. 

1. A class can only have one destructor.
2. It must have the same name as class preceeded by a (~).
3. It cannot take any parameters.(No Overloading).
4. If you don't call your own destructor there will be a defult destructor.
*/