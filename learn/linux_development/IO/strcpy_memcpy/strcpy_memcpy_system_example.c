#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>

int main(){
    // strcpy and strncpy example
    printf("strcpy example: \n");

    char str1[] = "Sample string";
    char str2[40];
    char str3[10];

    // copy entire string
    char *string1 = strcpy(str2, str1);
    printf("String 2: %s\n", string1);

    // Copy the first 9 characters
    char *string2 = strncpy(str3, str1, 9);
    printf("String 3: %s\n", string2);

    // strcmp and strncmp example
    printf("strcmp example: \n");

    char str4[15] = "abcdef";
    char str5[15] = "ABCDEF";
    int ret;
    
    // Compare strings
    ret = strcmp(str4, str5);

    if(ret < 0){
        printf("str4 is less than str5\n");
    } else if (ret > 0){
        printf("str4 is greater than str5\n");
    } else{
        printf("str4 is equal to str5\n");
    }

    // strstr example
    printf("strstr example: \n");

    const char haystack[20] = "RUNOOB";
    const char needle[10] = "NOOB";
    char *ret1;

    // Search for the substring
    ret1 = strstr(haystack, needle);

    printf("Substring found: %s\n", ret1);

    // memcpy example
    printf("memcpy example: \n");

    char *s = "http://www.quectel.com";
    char d[20];

    // Copy 6 characters from the 11th character of s
    memcpy(d,s + 11, 6);
    d[6] = '\0';

    printf("%s", d);
    return 0;
}