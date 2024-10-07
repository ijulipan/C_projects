void selectionSort(int arr[], int n){
    int len = n; // Length of the array
    int minIndex, temp;

    for (int i = 0;i < len - 1; i++){
        minIndex = i; // Assume the minimum is the first element of the unsorted array
        for(int j = i + 1; j < len; j++){
            // Find the smallest element in the unsorted portion

            if(arr[j] < arr[minIndex]){
                minIndex = j;// Udate minIndex if a smaller element is found
            }
        }
        // Swap the found minimum element with the first element of the unsorted array

        temp = arr[i];
        arr[i] = arr[minIndex];
        arr[minIndex] = temp;
    }
}