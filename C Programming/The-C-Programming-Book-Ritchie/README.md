# The C Programming Language Ritchie & Kernighan

C is a:
- general-purpose programming language.
- low level language.

C was designed by Dennis Ritchie at AT&T Bell Labs in New Jersey, USA. It was created between *1969* and *1973*, with its official launch recognized in *1972*.

Predecessors: C was heavily influenced by and based on the **B** programming language (created by Ken Thompson & Dennis Ritchie), which was derived from **BCPL (Basic Combined Programming Language)**.

Hello World:
```c 
#include <stdio.h>

int  main() {
    printf("Hello, World!\n");
    return 0;
}
```

---

# CHAPTER 1

`#include <stdio.h>` tells the compiler to include information about the standard input/output library.

`printf("Hello, World!\n");` Calls *printf* with the argument *"Hello, World!\n"*, *printf* is a library function that prints output, in this case the string of characters between the quotes. 

`\n` in the string is C notation for the *newline* character, which when printed advances the output to the left margin on the next line.

## Datatypes: 
C provides several other data types beside `int` and `float`, including:
```
char    -   character (a single byte)
short   -   short integer
int     -   integer
long    -   long integer
float   -   floating point 
double  -   double-precision floating point
```

## While Loop:
The *while* loop operates as follows: The condition in parentheses is tested. If it is true, the body of the loop is executed. Then the condition is re-checked, and if true, the body is executed again. This goes on until the condition becomes false, the loop ends.

The body of a *while* loop can be one or more statements enclosed in braces, or a single statement without braces, as in:

```c 
while (i < j) {
    // statement 1 
    // statement 2 
    // ...
}

// OR 

while (i < j) 
    i = 2 * i;
```

> NOTE: An interesting fact, `printf` is not part of the C language; there is no input or output defined in C itself. `printf` is just a useful function from the standard library of functions that are normally accessible to C programs. 

## For Loop:
The *for* statement is a loop, a generalization of the *while* loop. If you compare it to the earlier *while*, its operation should be clear. Within the parentheses, there are three parts, separated by semicolons. The first part is, the initialization, the second part is the condition that controls the loop, if it's true then the body of the loop is executed. Then the increment step is executed, and the condition is re-evaluated. The loop terminates if the condition has become false.

example:
```c 
for (int i = 0; i < 100; i = i + 10) {
    // body of the loop
}
```

## Symbolic Constants:
Suppose you have the following code:
```c 
#include <stdio.h>

int main() {
    int fahr;
    for (fahr = 0; fahr <= 300; fahr = fahr + 20) {
        printf("%3d %6.1f\n", fahr, (5.0 / 9.0) * (fahr - 32)); // fahrenheit to celcius
    }
}
```

It's a bad practice to bury "magic numbers" like 300 and 20 in a program; they convey little information to someone who might have to read the program later. One way to deal with these magic numbers is to give them meaningful names. A `#define` line defines a symbolic name or constant to be a particular string of characters:

```c 
#define name replacement-list 

// example
#define PI 3.14159
#define FILE "input.txt" 
```

So we can modify our code like this now:
```c 
#include <stdio.h>

#define LOWER 0 
#define UPPER 300 
#define STEP 20

int main() {
    int fahr;

    for (fahr = LOWER; fahr <= UPPER; fahr = fahr + STEP) {
        printf("%3d %6.1f\n", fahr, (5.0 / 9.0) * (fahr - 32)); // fahrenheit to celcius
    }
}
```

> NOTE: The quantities LOWER, UPPER, and STEP are symbolic quantities not variables, so they do not appear in declarations. Symbolic quantities names are conventionally written in upper case so they can be readily distinguished from lower case variable names. Notice that there is no semicolon at the end of a `#define` line.

## getchar() & putchar():
Given `getchar` and `putchar`, you can write a surprising amount of useful code without knowing anything more about input and output. The simplest example is a program that copies its input to output one character at a time:

```c 
#include <stdio.h>

int main() {
    int ch;
    ch = getchar();
    while (ch != EOF) {
        putchar(ch);
        ch = getchar();
    }

    return 0;
}
```

> NOTE: Use `Ctrl + D` to close the file as `^D` sends end-of-file signal to the standard input.

We used `int` for storing `ch` rather than using `char` for a very specific reason. The problem is distingushing the end of input from valid data (char-range), `getchar` returns a distinctive value when there is no more input, a value that cannot be confused with any real character. 

This value is called `EOF`, for "end-of-file", we must declare `ch` to be a type big enough to hold any value that getchar returns. We can't use `char` since `ch` must be big enough to hold `EOF` in addition to any possible `char`. That's why we use `int`.

> NOTE: `EOF` is just an integer defined in `<stdio.h>`, the specific numeric value doesn't matter as long as it is not the same as any `char` value. It's a symbolic constant (It's a negative number typically `-1`).

`c = getchar()` is an expression and has a value, which is the value of the left hand side after the assigment. This means that an assignment can appear as a part of a larger expression.

for example the above code can be rewritten as:
```c 
#include <stdio.h>

int main() {
    int ch;
    while ((ch = getchar()) != EOF) {
        putchar(ch);
    }

    return 0;
}
```

The `while` gets a character, assigns it to `ch`, and then tests whether it's `EOF` signal. If it's not, the body of the loop is executed, printing the character, and it repeats until you find `EOF`.

> NOTE: the parentheses around the assigment, within the condition are necessary as the precedence of `!=` is higher than that of `=`, which means in the absence of parentheses the relational test `!=` would be done before assignment `=`. The statement `c = getchar() != EOF` would become equivalent to `c = (getchar() != EOF)`, this has the undesired effect of setting `ch` to either 0 or 1 depending on whether or not `getchar` returned `EOF`.

## Character Counting:
```c 
#include <stdio.h>

int main() {
    long count;

    count = 0;
    while (getchar() != EOF) {
        ++count;
    }
    printf("Character Count: %ld\n", count);

    return 0;
}
```

The statement `++count` introduces new operator `++`, which means increment by one. You could also write `count = count + 1` but `++count` is more concise and efficient. There is corresponding operator `--` to decrement by 1. These `++` and `--` operators can either be prefix (++var) or postfix (var--), both having a little difference which we'll learn later.

We could also use a `for` loop for the same:
```c 
long count;
for (count = 0; getchar() != EOF; ++count)
    ;
printf("Character Count: %ld\n", count);
```

The body of the `for` loop is empty, because all the work is done in the check and implementation parts. But the grammatical rules of C require that a `for` statement have a body. The isolated semicolon, called a *null statement*, is there to satisfy that requirement. We put it on a separate line to make it noticeable.

Notice that both the loops handle no characters input and display zero in that case.

## Line Counting:
```c 
#include <stdio.h>

int main() {
    int ch;
    long lines;

    lines = 0;
    while ((ch = getchar()) != EOF) {
        if (ch == '\n') 
            ++lines;
    }
    printf("Lines Count: %ld\n", lines);

    return 0;
}
```

- The `if` statement in the while loop tests the parentheses condition, and if the condition is true, it executes the statement (or group or statements in braces) that follows.

- `==` in C is the notation for *is-equal-to*, note that newcomers to C occassionally write `=` whent they mean to `==`, and you won't get a warning as `=` is a legal expression (beware of that).

- A character written betweeen single quotes represent an integer value equal to the numerical value of that character in the machine's character set (ex: 'a' becomes 97). This is called a *character constant* although it is just another way to write small integer. 

So, for example '*A*' is a character constant; in the ASCII character set its value is *65*, the internal representation of the character '*A*'. Ofcourse '*A*' is to be preferred over *65* as its meaning is obvious, and it's independent of a particular character set.

- The escape sequences used in string constants are also legal in character constants, so `\n` stands for the value of newline character, which is 10 in ASCII. 

## Word Counting:
```c 
#include <stdio.h>

#define IN   1 
#define OUT  0

int main() {
    int ch, state;
    long char_count, word_count, line_count;

    state = OUT;
    char_count = word_count = line_count = 0;

    while ((ch = getchar()) != EOF) {
        ++char_count;

        if (ch == '\n') 
            ++line_count;

        if (ch == ' ' || ch == '\n' || ch == '\t') 
            state = OUT;

        else if (state == OUT) {
            state = IN;
            ++word_count;
        }
    }

    printf("Char Count: %ld\n", char_count);
    printf("Word Count: %ld\n", word_count);
    printf("Line Count: %ld\n", line_count);

    return 0;
}
```

The `state` variable records whether the program is currently in a word or not, initially it's `OUT` and if we get a valid char that could be the start of the word we set it to `IN` and only change it back to `OUT` when we encounter a space, tab or a new-line.

We prefer using symbolic constants `IN` and `OUT` to the literal variables 1 and 0 because they make the program more readable. (You'll also find it easier to make extensive changes in programs where magic numbers appear only as symbolic constants).

- `char_count = word_count = line_count = 0;` sets all three variables to zero. This is not a special case, but a consequence of the fact that an assignment is an expression with value and assignments associated from right to left. It's as if we had written `char_count = (word_count = (line_count = 0));`

- the `||` operator means *OR*, so the line `if (ch == ' ' || ch == '\n' || ch == '\t')` says "if ch is a blank or ch is a newline or ch is a tab". There is a corresponding operator `&&` for *AND*; its precedence is just higher than `||`.

Expressions connected by `&&` or `||` are evaluated left to right, and it is garunteed that evaluation will stop as soon as the truth or falsehood is known.

- The expression also shows an `else`, which specifies an alternative action if the conditional part of the `if` statement is false. The general form is:
```c 
if (condition)
    statement;
else 
    statement;
```

