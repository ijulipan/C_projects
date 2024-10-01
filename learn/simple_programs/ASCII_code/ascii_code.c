#include <stdio.h>

int main(void) {
    int ascii_value;

    printf("Enter an ASCII code value (0-127): ");
    scanf("%d", &ascii_value);

    printf("The character corresponding to ASCII code %d is: %c\n", ascii_value, ascii_value);

    return 0;
}