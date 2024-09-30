#include <stdio.h>

// Define BYTE as a alias for unsigned char
typedef unsigned char BYTE;

// Define STRING as a pointer to char
typedef char* STRING;

// Define a structure for a point
typedef struct
{
    int x;
    int y;
} Point;

int main(){
    BYTE a = 255;  // Using BYTE alias for unsigned char
    BYTE arr[5] = {1, 2, 3, 4, 5};

    STRING str = "Hello World!";
    printf("%s\n", str);

    Point p = {10, 20};
    printf("Point coordinates: (%d, %d)\n", p.x, p.y);

    return 0;
}
