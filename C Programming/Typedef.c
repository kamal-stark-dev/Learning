#include <stdio.h>

typedef int marks;

typedef struct
{
    char name[20];
    int age;
    char gender;
    int gpa;
} Student;

typedef char string[20];

typedef int grades[5]; // usage - grades = { _, _, _, _, _ }, no need for even [] in initialization

int main()
{

    marks maths = 87, science = 92, english = 97; // marks is like an alias for int - more readable

    // typedef is generally used in struct
    Student starky = {"Starky", 19, 'M', 6.5}; // instead of using - struct Student student;

    string str = "Hello";

    printf("\n%s\n", str);

    grades student1 = {1, 2, 3, 4, 5};

    for (int i = 0; i < 5; i++)
    {
        printf("Grade %d = %d\n", i, student1[i]);
    }

    return 0;
}