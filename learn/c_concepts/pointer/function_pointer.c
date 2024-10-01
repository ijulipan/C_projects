#include <stdio.h>

// Function declarations
int hello(char *i);
void new_cmd(void);
void open_cmd(void);
void close_cmd(void);

// A function that matches the function pointer type
int hello(char *i){
    printf("Hello, %s!\n", i);
    return 0;
}

// Example commands
void new_cmd(void){
    printf("New command executed.\n");
}

void open_cmd(void){
    printf("Open command executed.\n");
}

void close_cmd(void){
    printf("Close command executed.\n");
}

int main(){

    // Function Pointer
    // int (*f)(char *);
    int(*f)(char *) = hello; // Assigning hello to the function pointer

    // Calling the function via pointer
    f("World");

    //Array of function pointers
    void (*file_cmd[])(void) = {new_cmd, open_cmd, close_cmd};

    // Calling commands
    for (int i = 0; i < 3; i++){
        file_cmd[i](); // Calls each command in the array
    }

    return 0;
}