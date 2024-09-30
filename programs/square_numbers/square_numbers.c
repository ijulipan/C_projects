#include <stdio.h>

int main(){
    int n;

    printf("Enter a number: ");
    scanf("%d", &n);

    printf("Squares of even numbers from 1 to %d are:\n", n);
    for (int i = 1; i <= n; i++){
        if(i % 2 == 0){
            printf("%d^2 = %d\n ", i, i * i);
        }
    }
    return 0;
}