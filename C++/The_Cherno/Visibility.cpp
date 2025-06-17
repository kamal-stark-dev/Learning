/*
Access Modifiers - Visibility: 
  1. Public: Public members are accessible from anywhere, both inside or outside the class.
    - They form the interface of the class allowing external code to interact with the object.

  2. Private: Private members are only accessible within the class itself.
    - Encapsulate data and implementation details, hiding them from external access.
    - This enforces data integrity and prevents accidental modification.

  3. Protected: Protected members are accessible within the class itself and the classes that inherit from this class.
    - They provide a way to share data and functionality between a base class and it's derived classes, while still protecting it from external access.

Inheritance:
  1. Public Inheritance: Public members remains public and protected members remains protected in derived class.
  2. Protected Inheritance: Both public and protected members become protected the in derived class.
  3. Private Inheritance: Both public and protected members become private in the derived class.   
*/

class Base {
  private:
    int privateData;
    void privateFunction();
  
  protected:
    int protectedData;
    void protectedFunction();

  public:
    int publicData;
    void publicFunction();
};

class Derived : public Base {
  void accessMembers() {
    publicData = 100;
    protectedData = 200;
    // privateData = 300; // ERROR: not accessible in derived class
  }
};

int main() {
  Base obj;
  obj.publicData = 100;
  // obj.protectedData = 200; // ERROR: not accessible outside the class 
  // obj.privateData = 300; // ERROR: not accessible outside the class
  
  return 0;
}
