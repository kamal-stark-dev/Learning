#include <stdio.h>
#include <string.h>

#define POINTS_LEN 5

struct Student
{
    char name[20];
    int age;
    char gender[6];
    int marks[4];
};

typedef struct
{
    char sub_name[20];
    int credits;
} Subject;

struct Point
{
    int x;
    int y;
} p1, p2, p3; // you can declare structs in here too

const char subjects[4][20] = {"Maths", "Machine Learning", "DSA", "Web Devlopment"};

void printStudentDetails(struct Student student);

void printPoints(struct Point *points);

int main()
{
    struct Student kamal;

    strcpy(kamal.name, "Kamalveer");
    kamal.age = 19;
    strcpy(kamal.gender, "Male");
    kamal.marks[0] = 89;
    kamal.marks[1] = 84;
    kamal.marks[2] = 69;
    kamal.marks[3] = 78;

    printStudentDetails(kamal);

    Subject maths = {"Mathemetics", 4}; // you can also declare them in {}

    Subject dsa = {
        .credits = 3,
        .sub_name = "DSA"};

    // we can assign one structure object to another
    Subject dsa2 = dsa;

    // ARRAY OF STRUCTS

    struct Point points[POINTS_LEN];

    for (int i = 0; i < POINTS_LEN; i++)
    {
        points[i].x = i;
        points[i].y = POINTS_LEN - i;
    }

    printPoints(points);

    // NOTE: Structures can behave different when you have pointers in them -> https://youtu.be/dqa0KMSMx2w?si=i8wtdAeW1J8AcVSX&t=1083

    return 0;
}

void printStudentDetails(struct Student student)
{
    printf("\nGENERAL DETAILS\n");
    printf("Name: %s\nAge: %d\nGender: %s\n\n", student.name, student.age, student.gender);

    printf("MARKS\n------------------------\n");
    for (int i = 0; i < 4; i++)
    {
        printf("%-20s: %d\n", subjects[i], student.marks[i]);
    }
    printf("------------------------\n");
}

void printPoints(struct Point *points)
{
    for (int i = 0; i < POINTS_LEN; i++)
        printf("p%d = (%d, %d)\n", i, points[i].x, points[i].y);
}