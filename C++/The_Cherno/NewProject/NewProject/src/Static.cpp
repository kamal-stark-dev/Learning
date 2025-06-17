#include <iostream>

// the global variables and functions that are set to static behaves like private to that functional unit

static int s_variable = 10;

static void Function() {

}

struct Entity {
	static int x, y;

	static void Print() {
		std::cout << x << ", " << y << std::endl;
	}
};

int Entity::x, Entity::y;

int static_() {
	Entity e;
	//e.x = 2, e.y = 3;
	Entity::x = 2, Entity::y = 3;

	Entity e1;
	//e1.x = 4, e1.y = -2;
	Entity::x = 4, Entity::y = -2; // above is same as doing this as they are static (Entity Scope)

	//e.Print();
	//e1.Print();
	Entity::Print(); 
	
	// Note: you can't access non-static data from a static method, it happens because they don't have 
	// the class instance from where they can access the class members.

	return 0;
}
