// Malloc: allocates a block of memory of the specified size in bytes
// malloc(size_t size)

// Calloc: allocates memory for an array of num elements each of size bytes
//         and initialises all allocated memory to zero
// calloc(size_t num, size_t size)

// EXP:-
// int *arr = malloc(10 * sizeof(int)); Allocate memory for an array of 10 integers
// int *arr = calloc(10, sizeof(int)); Allocate and zero-initialise an array of 10 integers

// char *p = malloc(n + 1); Allocate memory for a string of n characters

#include <stdio.h>
#include <stdlib.h>

int main(){
    int n;

    printf("Enter the number of integers you want to store: ");
    scanf("%d", &n);

    // Dynamically allocate memory using malloc
    int *arr1 = malloc(n * sizeof(int));
    if (arr1 == NULL)
    {
        printf("Memory allocation failed!\n");
        return 1; // Exit if allocation fails
    }

    // Fill the array with some values
    for (int i = 0; i < n; i++){
        arr1[i] = i * 2; // Assign even numbers
    }

    // Print the values
    printf("Array using malloc: \n");
    for (int i = 0; i < n; i++){
        printf("%d", arr1[i]);
    }
    printf("\n");

    free(arr1); // Free the allocated memory

    // Dynamically allocate memory using calloc
    int *arr2 = calloc(n, sizeof(int));
    if (arr2 == NULL){
        printf("Memory allocation failed!\n");
        return 1; // Exit if allocation fails
    }


    // Print the values (should be all zero)
    printf("Array using calloc (initialized to zero): \n");
    for (int i = 0; i < n; i++){
        printf("%d", arr2[i]);
    }
    printf("\n");

    free(arr2);

    return 0;
}



