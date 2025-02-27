#include <iostream>
#include <vector>
#include <string>
// #include <cctype> // for lower and upper functions

using namespace std;

vector<string> grades;
vector<int> credits;
vector<string> subjects;

int gradeToNumber(string grade) {
    if (grade == "A+" || grade == "a+") return 10;
    if (grade == "B+" || grade == "b+") return 8;
    if (grade == "C+" || grade == "c+") return 6;

    char check = toupper(grade[0]);
    switch(check) {
        case 'A': return 9;
        case 'B': return 7;
        case 'C': return 5;
        case 'D': return 4;
        case 'E': return 3;
        case 'F': return 0;
        default: return -1;
    }
    return -1;
}

float calculateGPA() {
    int size = subjects.size(), totalCredits = 0, studentPoints = 0;

    for (int i = 0; i < size; i++) {
        totalCredits += credits[i];
        studentPoints += credits[i] * gradeToNumber(grades[i]);
    }
    return studentPoints / (float) totalCredits;
}

int main() {
    int courseCount;
    cout << "Enter the number of courses: ";
    cin >> courseCount;
    cin.ignore();

    string subject;
    int credit;
    string grade;

    for (int i = 0; i < courseCount; i++) {
        cout << "------------------------------------";
        cout << "\nEnter the subject name: ";
        // cin >> subject;
        getline(cin, subject);
        subjects.push_back(subject);

        cout << "\nEnter course credits: ";
        cin >> credit;
        credits.push_back(credit);
        cin.ignore();

        cout << "\nEnter your grade (a/a+, b/b+, c/c+, f): ";
        cin >> grade;
        grades.push_back(grade);
        cin.ignore();
    } cout << "------------------------------------";

    cout << "\nYOUR GPA IS: " << calculateGPA() << endl;
    return 0;
}