void insertionSort(int arr[], int n){
    int len = n; // Length of the array
    int preIndex, current;


    // Start from the second element as the first is considered sorted
    for(int i = 1; i < len; i++){
        preIndex = i - 1; // Index of the last sorted element
        current = arr[i]; // Element to be inserted

        //Shift elements of the sorted segment that are greater than current
        while(preIndex >= 0 && arr[preIndex] > current){
            arr[preIndex + 1] = arr[preIndex]; // Move larger elements to the right
            preIndex--;
        }

        // Inser the current element into its correct position
        arr[preIndex + 1] = current;
    }
}