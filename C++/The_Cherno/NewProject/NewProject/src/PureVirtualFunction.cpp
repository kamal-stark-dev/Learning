#include <iostream>

class Entity_3 {
public:
	virtual std::string GetName() = 0;
};

class Player : public Entity_3 {
private:
	std::string m_Name;
public:
	Player(const std::string& name) : m_Name(name) {

	}

	std::string GetName() override { return m_Name; }
};

void PrintName(Entity_3* entity) {
	std::cout << entity->GetName() << '\n';
}

int main(void) {
	Entity_3* e = new Player("");
	PrintName(e);

	return 0;
}

// in pure virtual functions -> when you inherit them it's garunteed that you'll find the functionality
// of the methods mentioned in the interface(pure virtual class).