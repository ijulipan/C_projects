#include <stdio.h>

// Function to print the array

void PrintArray(int arr[], int len){
    for (int i = 0; i < len; i++){
        printf("%d ", arr[i]);
    }
    printf ("\n");
}

// Selection Sort

void SelectionSort(int arr[], int len){
    int minIndex, temp;

    for (int i = 0; i < len - 1; i++){
        // Set minIndex to the first element (assumed it is the smallest)
        minIndex = i;
        // Loop through the unsorted element (exluding arr[minIndex]) and finding if there's a smaller element
        for (int j = i + 1; j < len; j++){
            if (arr[j] < arr[minIndex]){
                minIndex = j; // If a smaller element is found, replace it with minIndex
            }
        }
        // Swaps the current lowest element with the actual lowest element in the array
        temp = arr[i];
        arr[i] = arr[minIndex];
        arr[minIndex] = temp;

    }
}


// Bubble Sort
void BubbleSort(int arr[], int len){
    int temp;
    // Outer loop for each element
    for(int i = 0; i < len - 1; i++){
        // Inner loop to do the swapping
        for(int j = 0; j < len - 1 - i; j++){
            if(arr[j] > arr[j + 1]){
                temp = arr[j + 1];
                arr[j + 1] = arr[j];
                arr[j] = temp;
            }
        }
    }
}


// Insertion Sort
void InsertionSort(int arr[], int len){
    int preIndex, current;

    // Start from the second element as the first is considered sorted
    for(int i = 1; i < len; i++){
        preIndex = i - 1;
        current = arr[i];

        while(preIndex >= 0 && arr[preIndex] > current){
            arr[preIndex + 1] = arr[preIndex];
            preIndex--;
        }

        arr[preIndex + 1] = current;
    }
}

// Quick Sort

// Partition the array
int Partition(int arr[], int low, int high){
    int key = arr[low];
    while(low < high){
        while(low < high && arr[high] >= key){
            high--;
        }
        if(low < high){
            arr[high--] = arr[low];
        }

        while (low < high && arr[low] <= key){
            low++;
            if(low < high){
                arr[high--] = arr[low];
            }
        }
        arr[low] = key;
        return low;
    }
}

void QuickSort(int arr[], int start, int end){
    int pos;
    if(start < end){
        pos = Partition(arr, start, end);
        QuickSort(arr, start, pos - 1);
        QuickSort(arr, pos + 1, end);
    }
}


void main(){

    int test_arr[] = {10, 9, 20, 30, 40, 50, 23, 34};
    int n = sizeof(test_arr) / sizeof(test_arr[0]);

    printf("Original Array: \n");
    PrintArray(test_arr, n);

    SelectionSort(test_arr, n);

    printf("Sorted Array using Selection Sort: \n");
    PrintArray(test_arr, n);

    BubbleSort(test_arr, n);

    printf("Sorted Array using Bubble Sort: \n");
    PrintArray(test_arr, n);

    InsertionSort(test_arr, n);

    printf("Sorted Array using Insertion Sort: \n");
    PrintArray(test_arr, n);

    QuickSort(test_arr, 0, 7);

    printf("Sorted Array using Quick Sort: \n");
    PrintArray(test_arr, n);

    return 0;
}