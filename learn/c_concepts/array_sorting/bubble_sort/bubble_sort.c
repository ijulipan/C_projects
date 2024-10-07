void bubbleSort(int arr[], int n){
    int len = n; // Length of the array

    // Outer loop for each element
    for(int i = 0; i < len - 1; i++){
        // Inner loop to compare adjacent elements
        for(int j = 0; j < len - 1 - i; j++){
            // Compare adjacent elements and swap if necessary
            if(arr[j > arr[j + 1]]){
                int temp = arr[j + 1]; // Store the next element
                arr[j + 1] = arr[j]; // Swap elements
                arr[j] = temp; // Update the current element
            }
        }
    }
}