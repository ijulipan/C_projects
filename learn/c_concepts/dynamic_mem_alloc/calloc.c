#include <stdio.h>
#include <stdlib.h>

int main(){
    int n, i, *ptr, sum = 0;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    ptr = (int*)calloc(n, sizeof(int));

    // If memory allocation failed
    if (ptr == NULL){
        printf("Error! Memory allocation failed");
        exit(0);
    }

    printf("Enter the elements: ");
    for(i = 0; i < n; ++i){
        scanf("%d", ptr + 1);
        sum += *(ptr + 1);
    }

    printf("Sum = %d", sum);
    
    free(ptr);
    return 0;
}