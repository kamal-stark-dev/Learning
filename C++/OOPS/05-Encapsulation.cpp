// Encapsulation - make sure that "sensitive" data is hidden from users. To achieve this you must declare class members as `private`, and if you want others to read or modify the value of private members, you can provide public `get` and `set` methods.

#include <iostream>
using namespace std;

class Employee {
private:
    double salary;
public:
    Employee(double s) {
        salary = s;
    }
    // getter
    double get_salary() {
        return salary;
    }
    // setter
    void set_salary(double new_salary) {
        salary = new_salary;
    }
};

int main(void) {
    Employee e(40000);

    // e.salary = 50000; -> this can't be done but you can use setter function

    cout << "Salary: " << e.get_salary() << "\n";
    e.set_salary(50000);
    cout << "New Salary: " << e.get_salary() << "\n";

    return 0;
}

/*
Why Encapsulation?
> It's considered a good practice to perform encapsulation as it ensures better control over the data which leads to increased security of data.

It allows you(or others) to modify certain members without affecting other members in the class.
*/