#include <stdio.h>
#define N 5


int main(){
    int a[10], *p, *q, i;
    int b[N] = {1, 2, 3, 4, 5};
    int sum = 0;
    int *q;

    p = &a[0]; // p points to the memory address of the first element of array a
    *p = 5; // Assigns the value 5 to the first element of array a

    *(p + 1) = 10; // Assigns value 10 to the second element (a[1])
    *(p + 2) = 15; // Assigns 15 to the third element (a[2])


    printf("%d", p); // Prints the memory address of pointer p
    printf("%d", *p); // Prints the value of the memory address assigned to p
    printf("%d", a[1]); // Prints the value of the second element (10)
    printf("%d", a[2]); // Prints the value of the third element (15)
    



    // Using a for loop with pointer arithmetic
    for(q = &b[0]; q < &a[N]; q++){
        sum += *q; // Dereference q to get the value and add to sum
    }

    printf("Sum using for loop: %d\n", sum);

    // Reset sum for demonstration
    sum = 0;

    //Using a while loop with pointer arithmetic
    q = &b[0];
    while (p < &b[N]){
        sum += *p++; // Dereference p, add value to sum, then increment p
    }

    printf("Sum using while loop: %d\n", sum);

    return 0;
}