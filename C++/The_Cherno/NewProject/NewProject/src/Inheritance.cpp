#include <iostream>

class Entity {
public:
	float X, Y;

	void Move(int xa, int ya) {
		X += xa;
		Y += ya;
	}
};

class Player : public Entity { // Player class is inheriting from Entity class (public)
public:
	const char* Name;

	void PrintName() {
		std::cout << Name << '\n';
	}
};

int inheritance_(void) {
	Player p;

	p.X = 10, p.Y = 20;
	p.Move(5, -5);
	std::cout << p.X << ", " << p.Y << '\n';

	p.Name = "Mario";
	p.PrintName();

	std::cout << "sizeof(Player): " << sizeof(Player) << " bytes.\n";
	std::cout << "sizeof(Entity): " << sizeof(Entity) << " bytes.\n";

	return 0;
}