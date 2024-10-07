#include <stdio.h>
#include <stdlib.h>

int arr[] = {103, 457, 69, 10, 78, 49, 123};
int n = 7;


void SelectionSort(int arr[], int n){
    int len = n;
    int minIndex, temp;

    for(int i = 0;i < len - 1;i++){
        minIndex = i;
        for(int j = i + 1; j < len; j++){
            if (arr[j] < arr[minIndex]){
                minIndex = j;
            }
        }
        temp = arr[i];
        arr[i] = arr[minIndex];
        arr[minIndex] = temp;
    }

}

int main(){

    printf("Elements before sorted: ");
    for(int i = 0; i < n - 1; i++){
       printf("%d ", arr[i]); 
    }
    printf("\n");

    printf("Elements after sorted: ");
    for(int z = 0; z < n - 1; z++){
        SelectionSort(arr, n);
        printf("%d ", arr[z]);
    }
    
}