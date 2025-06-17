// Pure Virtual Functions

#include <iostream>

class Printable {
public:
    virtual std::string GetClassName() = 0; // declared using `= 0` syntax
};

/*
  Abstract Classes: A class containing at least one pure virtual function is considered an abstract class.
  Abstract classes can't be instantiated (you can't create objects of these classes).

  Pure Virtual Functinos serve as a way to define an interface that a derived class must implement.

  Any concrete(non-abstract) derived class must provide an implementation (override) for all the virtual functions inherited from it's base class.

  Dynamic Polymorphism : Pure virtual functions are designed to call through pointers or references to the base class, allowing for dynamic polymorphism. (The specific information that gets executed actually depends on the object's type at runtime).
*/

class Entity : public Printable { // pure virtual class - interface
public:
    virtual std::string GetName() { return "Entity"; }
    
    std::string GetClassName() override { return "Entity"; }
};

class Player : public Entity {
private:
    std::string m_Name;
public:
    Player(const std::string& name) : m_Name(name) {}
    
    std::string GetName() override {
        return m_Name;
    }
    
    std::string GetClassName() override { return "Player"; }
};

class A : public Printable {
public:
    std::string GetClassName() override { return "A"; }    
};

void PrintName(Entity* e) {
    std::cout << e->GetName() << '\n';
}

void PrintClassName(Printable* obj) { // anything that has the Printable type -> will have all the methods definitions of it.   
    std::cout << obj->GetClassName() << '\n';
}

int main(void) {
    Entity* e = new Entity();
    PrintName(e);
    PrintClassName(e);
    
    Player* p = new Player("Mason");
    PrintName(p);
    PrintClassName(p);
    
    PrintClassName(new A());
}
