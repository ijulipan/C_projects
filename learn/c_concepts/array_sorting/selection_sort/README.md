# DATA STRUCTURE: ARRAY SORTING - SELECTION SORT

## Selection Sort ##

Selection Sort is a simple algorithm. It works by repeatedly selecting the smallest(or largest) element from the unsorted portiong of the array and moves it to the sorted portion. The algorithm can be represented as below:

![Selection Sort Algorithm](/etc/untitled-22-28681.jpg)

### How it works ###

The algorithm has two loops, **outer** and **inner** loops. Outer loop controls the border between the sorted and unsorted parts of the array. Inner loop finds the minimum element within the unsorted array.

It will loop through the array *except* the sorted element `(i + 1)`. The first element is assumed the smallest element and the rest of the array is looped through and compared with the first array. 

If the first array is larger than the current array then the current array is put inside the sorted portion of the array. The algorithm will loop until it has reached the end of the array.

For reference: [selection sort algorithm](/learn/c_concepts/array_sorting/selection_sort/example.c)

