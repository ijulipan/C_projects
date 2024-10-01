// int myAge = 43;  -- an int variable
// printf("%d", myAge);  -- Prints the VALUE of myAge (43)
// printf("%p", &myAge); -- Prints the memory address of myAge (0x7ff35467e044)
#include <stdio.h>

int main(){
    int myAge = 43;
    // The type of pointer has to match to the type of variable working with
    int *ptr = &myAge;

    // Output the value of MyAge (43)
    printf("%d\n", myAge);

    // Output the memory address of myAge
    printf("%p\n", &myAge);


    // Reference: Output the memory address of myAge with the pointer
    printf("%p\n", ptr);

    // Dereference: Output the value of myAge with the pointer (43)
    printf("%d\n", *ptr);



    int i = 0x11223344; 
    int *ptr2 = &i;

    printf("This is the memory address of 0x%x: %x", i, ptr2);

    return 0;
}