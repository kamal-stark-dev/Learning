// Access Specifiers - We have seen public and private access specifiers till now, the third specifier is `protected`, similar to private but members can be accessed in the inherited class.

#include <iostream>
using namespace std;

class Employee {
protected:
    double salary;
};

class Programmer : public Employee {
public:
    int bonus;
    void setSalary(double salary_) {
        salary = salary_; // accessing protected member
    }
    double getSalary() {
        return salary;
    }
};

int main(void) {
    Programmer Jake;

    Jake.setSalary(80000);
    Jake.bonus = 15000;

    cout << "Salary: " << Jake.getSalary() << "\n";
    cout << "Bonus: " << Jake.bonus << "\n";

    return 0;
}