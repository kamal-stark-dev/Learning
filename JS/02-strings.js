// Strings = Text

msg = "Hello world!!";

/*
You can create strings with 3 ways -
    1. using "text"
    2. using 'text'
    3. using `text`
*/

// you can add two strings - concatenation
console.log("apple" + "-nvidia");

// you can use the `typeof` function to see the types
console.log(typeof "text");
console.log(typeof 100);

// how to escape a character --> use '\' before it
console.log('You\'e "Cool"');

// '\n' --> newline character, you are going to use this quite often
console.log("Wow that was\nReally Cool!!");
/* output -
Wow that was
Really Cool!!
*/

// what if we add a string and a number
console.log("abc" + 100); // abc100
console.log(100 + "abc"); // 100abc

/*
In above examples when we try to add number with string the number is automatically converted to a string.

And string concatenation is performed afterwards resulting in a string.
*/

// can you guess what will be '1' + 1 = ?
console.log("1" + 1); // ??

console.log("$" + 10 + 7); // will it be $17 ??

/*
naah, it'll give `$107`.

what really happening is that all the operations here have same precedence so they are performed left to right.

'$' + 10 + 7 ==> '$10' + 7 ==> '$107'

So, how can you get $17 ??
-> Simple just change the precedence.
*/

console.log("$" + (10 + 7)); // operator precedence go brrrr....

// but what would have happened if we used (10 + 7 + '$') ??
console.log(10 + 7 + "$"); // 17$ (10 + 7 + '$' ==> 17 + '$' ==> '17$')

/*
NOTE: Don't get humbled by this ~ We'll learn this soon

Order of Precedence:
1. Parentheses: ()
2. Exponents: **
3. Multiplication, Division, and Modulus: *, /, %
4. Addition and Subtraction: +, -
5. String Concatenation: + (when used with strings)
6. Comparison: <, <=, >, >=
7. Equality: ==, !=, ===, !==
8. Logical AND: &&
9. Logical OR: ||
10. Assignment: =, +=, -=, *=, /=, %=
*/

// Template Strings ~ allows `Interpolation`
console.log(`Items(${1 + 1}): $${(2050 + 999) / 100}`);

// multiline strings (works only in template strings)
console.log(`
This is a
Multiline String.
`);
