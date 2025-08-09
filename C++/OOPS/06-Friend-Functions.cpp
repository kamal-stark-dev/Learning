// Friend Function - Normally, private members can only be accessed using methods like getters and setters. But in some cases, you can use a special function called a `friend` function to access them directly.

#include <iostream>
using namespace std;

class Employee {
private:
    double salary;
public:
    Employee(double salary_) {
        salary = salary_;
    }

    // declare friend function
    friend void displaySalary(Employee emp);

    friend void changeSalary(Employee& emp, double salary);
};

void displaySalary(Employee emp) {
    cout << "Salary: " << emp.salary << "\n";
}

void changeSalary(Employee& emp, double salary) { // calling emp by reference to change it inplace
    emp.salary = salary;
}

int main(void) {
    Employee emp(50000);
    displaySalary(emp);

    changeSalary(emp, 70000);
    displaySalary(emp);

    return 0;
}

// The `friend` keyword allows non-member functions to access private and protected members of a class.