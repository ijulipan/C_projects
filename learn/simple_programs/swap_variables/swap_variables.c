/*
1. Create a function to swap two variables
2. Pass in the addresses of the variables
3. Swap the variables inside the function
4. Display before and after variables
*/ 


#include <stdio.h>

int swap_variables(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}


int main(){
    int a, b;
    printf("Enter 2 numbers:\n");
    scanf ("%d %d", &a, &b);

    printf("Before swapping: a = %d, b = %d\n", a, b);

    swap_variables(&a, &b);

    printf("After swapping: a = %d, b = %d\n", a, b);

    return 0;
}