# PREPROCESSOR AND MACRO DEFINITION & USAGES


## Preprocessing ##

Preprocessing is the first stage in the C compilation process, where the preprocessor prepares the code for compilation. Some terms involved with this process is:-

    1. Macros: Replace defined constants or macros with their values
    2 File Inclusion: Insert the contents of included files (#include)
    3. Conditional Compilation: Exclude/include parts of code based on conditions (#ifdef, ifndef)

### Macros ###

Use `#define` to define constants or function expressions, AKA **macros**.

```C
#define N 1000
#define MAX(x, y) ((x) > (y) ? (x) : (y)) 
```

As shown above, N is defined as 1000 and `MAX(x, y)` is a function-like macro that returns the great of `x` and `y`.

### File Inclusion ###

Use `#include` to insert the content of another file into the current file.

```C
    #include <stdio.h>
    #include "myheader.h"
```
### Conditional Compilation ###

`#if`, `#ifdef` and `#ifndef` allow parts of the code to be compiled or excluded based on certain conditions.

```C
#ifdef DEBUG
    printf("Debug mode is ON\n");
#endif
```

## `#` and `##` Operators ##

### # Operator ###

The `#` operator is used to convert the argument of a macro into a string literal. For example,

```C
#define MY_PRINTF(n) printf(#n " = %d\n", n);
```

When written `MY_PRINTF(i/j)` it expands to:

```C
printf("i/j = %d\n", i/j);
```

The `#n` turns `i/j` into the string "i/j" and includes in the formatted string.

### ## Operator ###

`##` Operator is called *token-pasting* operator. It concatenates two tokens into a single token during macro expansion.

```C
#define GENERIC_MAX(type) \
type type##_max(type x, type y) \
{ \
    return x > y ? x : y; \
}
```

When you use `GENERIC_MAX(int)`, it expands to:

```C
int int_max(int x, int y)
{
    return x > y ? x : y;
}
```

The `type##_max` combines `type`(which is `int`) with `_max`, producing `int_max` as the function name.

## Variadic Macros ##

In C, we can define macros that take a variable number of arguments using *ellipsis `(...)`*. The macro `__VA_ARGS__` is used to represent these arguments in the macro's replacement text. For example,

**Basic Variadic Macros**

```C
#define PR(...) printf(__VA_ARGS__)
```

When `PR(Hello, %s\n", "World");` is used, it expands to:

```C
printf("Hello, %s\n", "World");
```

**Mixing Fixed and Variadic Macros**

```C
#define PR(X, ...) printf("Message " #X ": " __VA_ARGS__)
```

Calling `PR(1, "Value: %d\n", 10)` it expands to:

```C
printf("Message 1: Value: %d\n", 10);
```

Here `#X` converts arguement `X` into a string (1) and `__VA_ARGS__` replaces the variable arguments.

**__func__ Keyword**

`__func__` can be used in functions to get the name of the current function.

```C
void my_function(){
    printf("Function nameL %s\n", __func__);
}
```

Output: `Function name: my_function`

**Conditional Compilation**

Conditional compilation allows to include or exclude portions of code depending on whether a macro is defined. Use `#ifdef` and `#endif`.

```C
#ifdef DEBUG
printf("Debugging mode is enabled\n);
#endif
```

If `DEBUG` id defined, the code inside `#ifdef .. #endif` block will be compiled.


**`#include` Directive**

`#include` is used to include the contents of another file into the current file.

```C
#include <file> // Looks into system directories for the file
#include "file" // Looks in the current working directory first, then system directories
```

Example:

```C
#include <stdio.h> // Includes standard I/O header
#include "quectel.h" // Includes local header
```

**Guarding Against Multiple Inclusions**

To prevent multiple inclusions of the same header file, the `#ifndef` is often used. For example:

```C
#ifndef __QUECTEL_H__    // Check if __QUECTEL_H__ is not defined
#define __QUECTEL_H__    // Define it to prevent future inclusions

#include <stdio.h>       // Include required headers

#define QUECTEL_SW 10    // Define constants, macros, etc.

#endif                   // End of multiple-inclusion guard
```