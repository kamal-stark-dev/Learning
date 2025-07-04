#include <iostream>
using namespace std;

class Entity {
public:
    virtual string getName() { return "Entity"; }
};

class Player : public Entity {
private:
    string m_name;
public:
    Player(string name) : m_name(name) {}

    string getName() override {
        return m_name;
    }
};

int main(void) {
    Entity* e = new Player("Anoop");

    cout << e->getName() << '\n';
    // cout << p.getName() << '\n';

    return 0;
}