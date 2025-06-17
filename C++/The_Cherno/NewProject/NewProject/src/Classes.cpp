#include <iostream>
#define Log(x) std::cout << x << std::endl

struct Player {
public:
	int x, y;
	int speed;

	void Move(int xa, int ya) {
		x += xa * speed;
		y += ya * speed;
	}

	void Show() {
		std::cout << "X: " << x << "\nY: " << y << "\nSpeed: " << speed << std::endl;
	}
};

int classes(void) {
	Player player; // variables that are made from classes are called objects.

	player.x = 5, player.y = -3;
	player.speed = 20;
	player.Move(2, -1);

	player.Show();

	// the only technical difference between a struct and a class is that structs are 'public'
	// be default whereas classes are 'private'. Yes, that's it, beside that there is no change
	// you can literally use `#define struct class` and it'll work the same.

	// However, structs are generally used when you only want a structure of data only and no methods
	// that do extra stuff except handling the data. Also if you are using inheritance like features
	// then use classes for it.

	return 0;
}