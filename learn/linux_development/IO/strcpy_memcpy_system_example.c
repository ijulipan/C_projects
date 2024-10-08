#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>

int main(){
    // strcpy and strncpy example
    char str1[] = "Sample string";
    char str2[40];
    char str3[10];

    // copy entire string
    char *string1 = strcpy(str2, str1);
    printf("String 2: %s\n", string1);

    // Copy the first 9 characters
    char *string2 = strncpy(str3, str1, 9);
    printf("String 3: %s\n", string2);

    return 0;

}