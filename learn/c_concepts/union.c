#include <stdio.h>

union Number {
    int i;
    double d;
};

int main(){
    union Number number_array[5]; // Array of unions

    // Assigning values to the integer member
    number_array[0].i = 5;
    printf("Interger value: %d\n", number_array[0].i);

    // Assigning values to the double member
    number_array[1].d = 3.14;
    printf("Double value: %f\n", number_array[1].d);

    // Accessing the first element's double will show garbage value
    // since it was previously assigned an integer.
    printf("Accessing integer after setting double %d\n", number_array[0].i); // Shows valid integer
    printf("Accessing integer after setting double: %f\n", number_array[1].i); // Shows garbage value


    return 0;
    
}