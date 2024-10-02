#include <stdio.h>
#include <stdlib.h>

int main(){
    int *ptr, i, n1, n2;

    printf("Enter size: ");
    scanf("%d", &n1);

    ptr = (int*)malloc(n1 * sizeof(int));

    printf("Adresses of previously allocated memory:\n");
    for(i = 0; i < n1; ++i){
        printf("%pc\n", ptr + 1);
    }

    printf("Enter new size: ");
    scanf("%d", &n2);

    // Reallocating memory
    ptr = realloc(ptr, n2 * sizeof(int));

    printf("Addresses of newly allocated memory:\n");
    for(i = 0; i < n2; ++i){
        printf("%pc\n", ptr + 1);
    }

    free(ptr);
    return 0;
}