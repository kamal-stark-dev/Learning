# Templates in C++

A C++ template is a tool for creating generic classes or functions. This allows us to write code that works for any data type without rewriting it for each type.

- Avoid code duplication by allowing one class or function to work for multiple datatypes.
- Form the basis of STL containers and algorithms like vector, map and sort.

Ex: Below code demonstrates a generic function that return the maximum ammond the two passed arguments to the function.

```c++ 
#include <iostream>
using namespace std;

template <typename T> T myMax(T x, T y) {
    return (x > y) ? x : y;
}

int main() {
    cout << "Max of 3 and 7 is: " << myMax<int>(3,7) << "\n";
    cout << "Max of 3.5 and 6.9 is: " << myMax<double>(3.5, 6.9) << "\n";
    cout << "Max of 'g' and 'e' is: " << myMax<char>('g', 'e') << "\n";

    return 0;
}
```

### Explanation
- `template <typename T>` makes `myMax` a generic function that works with any data type.
- The compiler creates a separate version of `myMax` for int, double, and char based on how it's called.
- `myMax<int>(3, 7)`, `myMax<double>(3.5, 6.9)`, and `myMax<char>('g', 'e')` compare values of those types.
- The function returns the larger of the two values using the condition `(x > y) ? x : y`.

![](./template generating code according to types.webp)

### Syntax of Templates
Templates are defined using the template keyword and template parameters declared using typename or class.

```c++
template<typename A, typename B, ...>
entity_definition
```
typename and class are interchangable in template declarations.

### Templates can be used to define
1. Function Templates
2. Class Templates
3. Variable Templates (C++14 onwards)

### 1. Function Templates 
We have already seen an example of function templates above, which finds the maximum of two values.

### 2. Class Templates 
Class templates like function templates, are useful when a class defines something that is independent of the data type. It is useful for classes like LinkedList, BinaryTree, Stack, Queue, Array etc.

Code in './02-generic-class.cpp' file, you can also add multiple template types in your function or class, check out './03-multiple-types.cpp' for that.

### 3. Template Variables
A template variable is a variable that can work with any type specified when the variable is used, similar to how we use templates for functions or classes.

```c++
template<typename T> constexpr T pi = T(3.14159);
```
`pi` is a template variable, we used `constexpr` with the template variable because it ensures that the variable is a constant expression and is evaluated at compile time rather than at runtime.


