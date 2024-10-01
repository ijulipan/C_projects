// int a = 20;
// int b = 30;
// const int *p1 = &a; // p points to a constant integer
// int *const p2 = &a; // p is a constant pointer to an integer

// *p1 = 21; // Cannot change the value of a using p
// p1 = &b; // Can change p to point to another variable

// *p2 = 21; // Can change the value inside a via p
// p2 = &b; // Cannot change p to point to another variable


#include <stdio.h>

int main(){
    int a = 20;
    int b = 30;

    // Const pointer to an int
    int *const p = &a; // p is a constant pointer to a
    printf("Value of a: %d\n", *p);

    *p = 21; // Changing value of a
    printf("Value of a after change: %d\n", *p); // Output: 21

    // p = &b; // This will cause a compilation error
    a = 20;
    const int *q = &a; // p points to a constant integer
    printf("Value of a: %d\n", *q); // Output: 20

    // *q = 21; // This will cause compilation error

    q = &b;
    printf("Value of b: %d\n", *q);

    return 0;

}
