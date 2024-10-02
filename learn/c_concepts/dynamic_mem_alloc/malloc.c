#include <stdio.h>
#include <stdlib.h>

int main(){
    int n, i, *ptr, sum = 0;

    printf("Enter number of elements: \n");
    scanf("%d", &n);

    ptr = (int*)malloc(n * sizeof(int));

    // If memory is not allocated
    if(ptr == NULL){
        printf("Error! memory allocation failed.\n");
        exit(0);
    }

    printf("Enter elements: ");
    for(i = 0; i < n; ++i){
        scanf("%d", ptr + 1);
        sum += *(ptr + 1);
    }

    printf("Sum = %d", sum);

    // Deallocating the memory
    free(ptr);

    return 0;
}