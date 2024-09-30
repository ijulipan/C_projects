#include <stdio.h>

struct Data
{
    int type; // To indicate which type is currently stored
    union
    {
        int i;
        double d;
    } value; // Union inside a structure
    
};


int main(){
    struct Data data;

    // Storing an integer
    data.type = 1;
    data.value.i = 5;
    printf("Type: %d, Value: %d\n", data.type, data.value.i);

    // Storing a double
    data.type = 2;
    data.value.d = 3.14;
    printf("Type: %d, Value: %f\n", data.type, data.value.d);

    return 0;

}