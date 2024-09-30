#include <stdio.h>

#define MAX_SIZE 1000

int is_balanced(const char *code){
    char stack[MAX_SIZE]; // Stack to keep track of opening braces
    int top = -1; // Stack pointer (initially empty)

    //Go through the code
    for(int i = 0; code[i] != '\0'; i++){
        char ch = code[i];

        // If opening brace is found, push it onto the stack
        if (ch == '{'){
            if (top == MAX_SIZE - 1){
                printf("Stack Overflow\n");
                return 0; // error: stack is full
            }
            stack[++top] = ch; // Push '{' onto the stack
        }
        // If closing brace is found, check if it matches an opening brace
        else if (ch == '}'){
            if (top == -1){
                // No matching opening brace found
                return 0;
            }
            top--; // pop the last opening brace
        }

    }

    // If stack is empty, all braces were matched
    return(top == -1);
}


int main(){
    char code[MAX_SIZE];

    printf("Enter your C code (max %d characters):\n", MAX_SIZE);
    // fgets is used to read string value with spaces
    // fgets stops reading when a newline is read
    fgets(code, MAX_SIZE, stdin); 

    if(is_balanced(code)){
        printf("Braces are balanced.\n");
    }
    else{
        printf("Braces are unbalanced.\n");
    }
    return 0;
}
