#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct person
{
    struct person *parents[2];
    char alleles[2];
} person;

const int GENERATIONS = 2;
const int INDENT_LENGTH = 4;

person *create_family(int generations);
void print_family(person *p, int generation);
void free_family(person *p);
char random_allele();

int main(void)
{
    srand(time(0));

    person *p = create_family(GENERATIONS);

    print_family(p, 0);

    free_family(p);
}

person *create_family(int generations)
{
    person *p = malloc(sizeof(person));

    if (generations > 1)
    {
        person *parent0 = create_family(generations - 1);
        person *parent1 = create_family(generations - 1);

        p->parents[0] = parent0;
        p->parents[1] = parent1;

        p->alleles[0] = parent0->alleles[rand() % 2];
        p->alleles[1] = parent1->alleles[rand() % 2];
    }

    else
    {
        p->parents[0] = NULL;
        p->parents[1] = NULL;

        p->alleles[0] = random_allele();
        p->alleles[1] = random_allele();
    }

    return p;
}

void free_family(person *p)
{
    if (p == NULL)
        return;

    free_family(p->parents[0]);
    free_family(p->parents[1]);

    free(p);
}

void print_family(person *p, int generation)
{
    if (p == NULL)
        return;

    for (int i = 0; i < generation * INDENT_LENGTH; i++)
    {
        printf(" ");
    }

    if (generation == 0)
    {
        printf("Child (Generation %i): blood type %c%c\n", generation, p->alleles[0], p->alleles[1]);
    }
    else if (generation == 1)
    {
        printf("Parent (Generation %i): blood type %c%c\n", generation, p->alleles[0], p->alleles[1]);
    }
    else
    {
        for (int i = 0; i < generation - 2; i++)
        {
            printf("Great-");
        }
        printf("Grandparent (Generation %i): blood type %c%c\n", generation, p->alleles[0], p->alleles[1]);
    }

    print_family(p->parents[0], generation + 1);
    print_family(p->parents[1], generation + 1);
}

char random_allele()
{
    int r = rand() % 3;
    if (r == 0)
        return 'A';
    else if (r == 1)
        return 'B';
    else
        return 'O';
}

/*
this is how you make pointers work for the structure which is user defined and has the functionality for making
user defined data types which can be really helpful, note that the structures are different from objects in a way
that objects can have member functions but structs can only have member data values inside it.

Also the objects are present in object-oriented languages like c++, python etc.

C language can be considered as the father of all languages that are derived from the c language itself. Also the
project and the prototype is taken as the language one but the concept of classes and functions is added new to the
class of the c language.

```c
include<stdio.h>

int main(void)
{
    printf("Hello, World!\n");
    return 0;
}
```

above is the c program to print "Hello, World!" on the console, `\n` stands for a new line.


*/