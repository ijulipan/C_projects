# DYNAMIC MEMORY ALLOCATION & USAGES

## Dynamic Memory Allocation ##

C supports dynamic memory allocation which allows the program to allocate memory during execution. 

## MALLOC ##

The `malloc()` function stands for memory allocation. It reserves a block of memory of the specified number of bytes

For example:
```C
ptr = (Type*) malloc(size);
ptr = (int*) malloc(100 * sizeof(int));
```

Above is an example of how to use `malloc()` function, where the function returns a void pointer which can be casted into pointers of any form (i.e int). 

The above example will allocate 400 bytes of memory because the size of `int` is always 4 bytes. 

The pointer `ptr` will hold the address of the first byte in the allocated memory.

The expression will result in a `NULL` pointer if the memory cannot be allocated.

## CALLOC ##

The `calloc()` functions stands for contiguous allocation. The `malloc()` function allocates memory but leaves the memory uninitialized whereas the `calloc()` function allocates memory and initializes all bits to zero.

For example:
```C
ptr = (Type*) calloc(n, size);
ptr = (int *) calloc(25, sizeof(int));
```

The above statement will allocate contiguous space in memory for 25 elements of `int` type.

## FREE ##

Dynamically allocated memory created with either `calloc()` or `malloc()` won't be freed on their own. We must explicitly use `free()` to release the space.

For example:
```C
// Syntax of free()
free(ptr);

//Example program

// Program to calculate the sum of n numbers entered by the user

#include <stdio.h>
#include <stdlib.h>

int main() {
  int n, i, *ptr, sum = 0;

  printf("Enter number of elements: ");
  scanf("%d", &n);

  ptr = (int*) malloc(n * sizeof(int));
 
  // if memory cannot be allocated
  if(ptr == NULL) {
    printf("Error! memory not allocated.");
    exit(0);
  }

  printf("Enter elements: ");
  for(i = 0; i < n; ++i) {
    scanf("%d", ptr + i);
    sum += *(ptr + i);
  }

  printf("Sum = %d", sum);
  
  // deallocating the memory
  free(ptr);

  return 0;
}
```

The `free()` function will free the space allocated in the memory pointed by `ptr`.


## REALLOC ##

If the allocated memory is insufficient or more than required, we can change the size using the `realloc()` function.

For example:
```C
// Syntax of realloc()
ptr = realloc(ptr, x);

#include <stdio.h>
#include <stdlib.h>

int main() {
  int *ptr, i , n1, n2;
  printf("Enter size: ");
  scanf("%d", &n1);

  ptr = (int*) malloc(n1 * sizeof(int));

  printf("Addresses of previously allocated memory:\n");
  for(i = 0; i < n1; ++i)
    printf("%pc\n",ptr + i);

  printf("\nEnter the new size: ");
  scanf("%d", &n2);

  // rellocating the memory
  ptr = realloc(ptr, n2 * sizeof(int));

  printf("Addresses of newly allocated memory:\n");
  for(i = 0; i < n2; ++i)
    printf("%pc\n", ptr + i);
  
  free(ptr);

  return 0;
}
```
As shown above, the `ptr` is reallocated with a new size `n2` based on the user's input.
