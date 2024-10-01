/*
Task: Create a program to reverse the strings. Given the following
function to use:-
void reverse_string(char *string)

Hint: Use two pointers (left and right) to loop through the string and reverse the characters

1. create a array containing the string to be reversed
2. input that array into the reverse_string function
3. create two pointers, left and right
4. initialise the right one on the right side of the string (end of string)
5. keep reversing the strings until left > right (they have met in the middle)
*/


#include <stdio.h>
#include <string.h>

void reverse_string(char *string){
    char *left = string;
    char *right = string;

    while(*right != '\0'){
        right++;
    }
    right--;

    while(left < right){
        char temp = *left;
        *left = *right;
        *right = temp;

        left++;
        right--;

    }
}


int main(){
    char str[100];
    printf("Enter a string you would like to reverse: ");
    fgets(str, sizeof(str), stdin);
    
    str[strcspn(str, "\n")] = '\0';

    printf("Original: %s\n", str);
    reverse_string(str);
    printf("Reversed: %s\n", str);

    return 0;
}