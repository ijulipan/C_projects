/*
    Task: Find the largest and 2nd largest in an array and
    put them in the addresses given by the parameters

    void find_two_largest(int *a, int n, int *largest, int *second_lar);

    1. create a dummy array
    2. pass on the array to the function
    3. create an algorithm to find the largest and second largest
    (for loop?)
    4. store the values at the addresses provided
    5. Display the values

*/
#include <stdio.h>


void find_two_largest(int *a, int n, int *largest, int *second_largest){
    // Init largest and second_largest 
    *largest = *second_largest = -1;

    for(int i = 0; i < n; i++){
        if(a[i] > *largest){
            /*If the current element is larger than the largest,
            then the second largest will become the largest while
            the largest becomes the current element.*/ 
            *second_largest = *largest;
            *largest = a[i];
        } else if (a[i] > *second_largest && a[i] != *largest){
            /*If the current element is larger than the second largest
            but smaller than the largest, then the second largest will become
            the current element*/
            *second_largest = a[i];
        }
    }
}


int main(){
    int array[] = {1, 2, 3, 4, 5};
    int n = sizeof(array) / sizeof(array[0]); // Used to determine the number of elements in a array
    int largest, second_largest;

    find_two_largest(array, n, &largest, &second_largest);

    printf("Largest: %d\n", largest);
    printf("Second Largest: %d\n", second_largest);

    return 0;


}