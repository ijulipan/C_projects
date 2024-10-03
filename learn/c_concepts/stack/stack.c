#include <stdio.h>
#define LIMIT 100 // The limited number of elements in this stack is set to 100

int stack[LIMIT];
int top = -1; // Initialised to -1 which indicates an empty stack

void push(){
    int element;
    // Check if the stack is full, thus we cannot add more elements
    if (top == LIMIT - 1){
        printf("Stack Overflow: Cannot push element\n");
    }
    else{
        // If not, take the elements from the user input
        printf("Enter the element to be inserted: ");
        // Store in a variable
        scanf("%d", &element);
        // Open a place in the array for the new element
        top++;
        // add the value to the position
        stack[top] = element;
    }
}

void pop(){
    int element;

    // Check if the array is empty
    if(top == -1){
        printf("Stack Underflow\n");
    }
    else{
        element = stack[top];
        printf("Popped item: %d\n", element);
        top--;
    }
}

int main(){

    int i;
    // Call the function
    push();

    printf("Stack elements: ");
    // Loop for printing the result
    for(i = 0; i<= top; i++){
        printf("%d", stack[i]);
    }
    printf("\n");

    // Pop function is called to clear the top element once used
    pop();
    return 0;
}