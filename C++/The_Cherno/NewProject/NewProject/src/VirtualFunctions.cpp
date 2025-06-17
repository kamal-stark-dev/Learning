#include <iostream>
#include <string>

// just named it `Entity_` because I have `Entity` in the same project.

class Entity_2 {
public:
	virtual std::string GetName() { return "Entity"; }
};

class Player : public Entity_2 {
private:
	std::string m_Name;
public:
	Player(const std::string& name) 
		: m_Name(name) {}

	std::string GetName() override { return m_Name; }
};

void PrintName(Entity_2* e) {
	std::cout << e->GetName() << '\n';
}

int virtualFunctions_() {
	Entity_2* e = new Entity_2();
	PrintName(e);

	Player* p = new Player("Jake");
	PrintName(p);

	delete e;
	delete p;

	return 0;
}