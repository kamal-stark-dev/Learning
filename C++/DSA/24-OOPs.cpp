// Object Oriented Programming (OOPs)

#include <iostream>
#include <string>
using namespace std;

class Teacher {
    // properties or attributes
    private:
    double salary;

    public:
    string name, dept, subject;

    Teacher() {
        cout << "Teacher Created!\n";
    }
    Teacher(string name, string dept, string subject) { // constructor - no return type
        cout << "Teacher Created!\n";
        this->name = name; // this->var_name -> refers to the member variable
        this->dept = dept;
        this->subject = subject;
    }
    // copy constructor
    Teacher(Teacher &obj) { // pass by reference
        cout << "This is a custom copy constructor.\n";
        this->name = obj.name;
        this->dept = obj.dept;
        this->subject = obj.subject;
        this->salary = obj.salary;
    }


    // methods or member functions
    void showDetails() {
        cout << "Name: " << name << "\nDept: " << dept << "\nSubject: " << subject << "\nSalary: " << salary << "\n";
    }
    void changeDept(string newDept) {
        dept = newDept;
    }
    // setter
    void setSalary(double amount) {
        salary = amount;
    }
    // getter
    double getSalary() {
        return salary;
    }
};

class Student {
    public:
    string name;
    double* cgpaPtr;

    Student(string name, double cgpa) {
        this->name = name;
        cgpaPtr = new double;
        *cgpaPtr = cgpa;
    }

    // copy constructor
    /* this will be shallow copy
    Student(Student &obj) {
        this->name = obj.name;
        this->cgpaPtr = obj.cgpaPtr;
    }
    */
    Student(Student &obj) {
        this->name = obj.name;
        cgpaPtr = new double;
        *(cgpaPtr) = *(obj.cgpaPtr);
    }

    // destructor
    ~Student() {
        delete cgpaPtr;
        // cout << "Allocated memory removed!\n";
    }

    void getInfo() {
        cout << "Name: " << name << "\n";
        cout << "CGPA: " << *cgpaPtr << "\n";
    }
};

class Person {
    public:
    string name;
    int age;

    // default constructor
    Person() {

    }

    Person(string name, int age) {
        this->name = name;
        this->age = age;
    }
};

class Engineer: public Person { // Public Inheritance (single inheritance)
    // name, age, emp_id
    public:
    int emp_id;

    Engineer(string name, int age, int emp_id) : Person(name, age) {
        this->emp_id = emp_id;
    }

    void getInfo() {
        cout << "Name: " << name << endl;
        cout << "Age: " << age << endl;
        cout << "Emp. ID: " << emp_id << endl;
    }
};

class Researcher: public Engineer { // multi-level inheritance
    public:
    string researchArea;

    Researcher(string name, int age, int emp_id, string researchArea) : Engineer(name, age, emp_id) {
        this->researchArea = researchArea;
    }
};

class a {
    public:
    int var1;
};

class b {
    public:
    int var2;
};

class c : public a, public b { // multiple inheritance
    public:
    int var3;
};

// hierarchial inheritance (one parent multiple children)
class d : public a {
    // code
};
class e : public a {
    // code
};

// hybrid inheritance -> mix of hierarchial, multiple, multi-level.

class Poly {
    public:
    // function overloading
    void type() {
        cout << "void\n";
    }
    void type(int i) {
        cout << "int\n";
    }
    void type(string s) {
        cout << "string\n";
    }
    void type(int a, int b) {
        cout << "two ints\n";
    }
};

// operator overloading
class Complex {
public:
    double real, imag;

    Complex(double r, double i) : real(r), imag(i) {}

    // overloading the + operator
    Complex operator+(const Complex& other) {
        return Complex(real + other.real, imag + other.imag);
    }

    // overloading the << operator to print the result
    friend ostream& operator <<(ostream& os, const Complex& c) {
        os << c.real << " + " << c.imag << "i";
        return os;
    }
};

// function overridding (runtime polymorphism)
class Parent {
public:
    void getInfo() {
        cout << " - Parent Class\n";
    }
    virtual void func() {
        cout << "This is func inside Parent.\n";
    }
    /*
    Virtual Functions: These are member functions which are expected to be initialized in the derived class.
        - Dynamic in nature
        - defined with keyword "virtual"
        - called using "runtime"
    */
};

class Child {
public:
    void getInfo() {
        cout << " - Child Class\n"; // the parent class `getInfo()` is overridden.
    }
    void func() {
        cout << "This is func inside Child.\n";
    }
};

/*
Abstract Classes: Basically used as blueprints for other classes to derive from it and be used as a template.
    - cannot be instantiated, are meant to be inherited.
    - used to define an interface for derived classes.
    - declared using "Abstract" keyword.
*/

class Shape {
    virtual void draw() = 0; // pure virtual function -> makes the class abstract
};

class Circle: public Shape {
public:
    void draw() {
        cout << "Drawing a Circle.\n";
    }
};

// Static
void func() {
    static int x = 0;
    cout << "x: " << x << endl;
    x++;
}

int main(void) {
    /*
    `Objects` are real world entities, whereas `Classes` are blueprint of these entities.

    *Access Modifiers*: Private (default), Protected, Public.

    1. *Encapsulation*: wrapping up of data and member functions in a single unit. (Data Hiding)
    2. *Inheritance*: when properties and functions of base class are passed on to the derived class.
    3. *Polymorphism*: objects behave differently based on the context in which they are used. (Multiple Forms)
    4. *Abstraction*: hiding all unnecessary details & only showing the important parts. (Acess Modifiers or Abstract Classes)

    *Constructor* - Special method which is invoked automatically at the time of object creation, this is used for initialization.
        - same name as the class
        - has no return type
        - only called once, automatically
        - memory allocation happens when it's called
    *Constructor Overloading* - A single class can have multiple constructor as long as their types or number of params are different.
    Which is an example of Polymorphism.

    *this* pointer is a special pointer which points to the current object. ( `this->prop` is same as doing `*(this).prop` )

    *Copy Constructor* is a special constructor (default) which is used to copy properties of one object to another.
        - Shallow Copy - Copies all the attributes.
        - Deep Copy - Also make copies of any dynamically allocated memory that the member points to.

    *Destructor* - Opposite of constructor, it deallocates the memory allocated to an object. (present by default)
        But the destructor only deallocates statically created memory and not the dynamically allocated memory.
        - Prevents memory leak.

    *Static Keyword* -
        1. Static Variables - variables declared as static in a function are created and initialized only once for the lifetime of the program. And static variables in a class are created and initialized once and used by all the objects of the class.

        2. Static Objects - TODO: notes.
    */

    // objects
    Teacher t1("Jake", "Computer Science", "C++");
    t1.setSalary(45'000);

    t1.changeDept("Programming");
    t1.showDetails();

    cout << "--------------------\nObjects\n";
    Teacher t2(t1);
    t2.showDetails();

    cout << "--------------------\nDeep & Shallow Copy\n";
    Student s1("Snape", 8.2);
    Student s2(s1);
    *(s2.cgpaPtr) = 8.6;

    // understanding the issue with shallow copys
    s1.getInfo();
    s2.getInfo();

    cout << "--------------------\nInheritance\n";
    Engineer e1("Sam", 23, 1245);
    e1.getInfo(); // as we know it's parent class is `Person`, `Person` class constrcutor will be called before the `Engineer` one.
    // while in destructor the child is called first then the parent.

    cout << "--------------------\nFunction Overloading\n";
    Poly p;
    p.type();
    p.type(10);
    p.type("ABC");
    p.type(10, 20);

    cout << "--------------------\nOperator Overloading\n";
    Complex c1(3.0, 2.0);
    Complex c2(2.0, 4.0);

    Complex c3 = c1 + c2;
    cout << "C3 = " << c3 << endl;

    cout << "--------------------\nRuntime Polymorphism\n";
    Parent parent;
    Child child;
    parent.getInfo();
    child.getInfo();
    child.func();

    cout << "--------------------\nStatic Keyword\n";
    func();
    func();
    func();

    return 0;
}