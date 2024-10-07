// Function to partition the array
int partition(int arr[], int low, int high){
    int key = arr[low]; // Choose the first element as the pivot
    while(low < high){
        // Move high pointer left until finding an element smaller than pivot
        while(low < high && arr[high] >= key){
            high--;
        }
        if (low < high){
            arr[low++] = arr[high]; // Place smaller element on the left
        } 

        // Move low pointer right until finding an element larger than pivot
        while(low < high && arr[low] <= key){
            low++;
            if (low < high){
                arr[high--] = arr[low]; // Place larger element on the right
            }
        }
        arr[low] = key; // Place the pivot in its correct position
        return low; // Return the pivot index
    }
}

/*
Quick Sort Function
 * @param arr[] Array to be sorted
 * @param start Starting index of the array
 * @param end Last index of the array
*/

void quick_sort(int arr[], int start, int end){
    int pos;
    if(start < end){
        pos = partition(arr, start, end); // Partition the array
        quick_sort(arr,start, pos - 1); // Recursively sort the left sub-array
        quick_sort(arr, pos + 1, end); // Recursively sort the right sub-array
    }
    return;
}