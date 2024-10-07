#include <stdio.h>
#include <stdlib.h>

// Define a node structure
typedef struct Node
{
    int data; // Element to hold the data
    struct Node* next; // Pointer to point to the next node
}NODE, *PNODE; // Define PNODE as a pointer to NODE structure

// Define a stack structure
typedef struct Stack{
    PNODE PTOP; // Pointer to the top pointer of the stack
    PNODE PBOTTOM; // Pointer to the bottom pointer of the stack
} STACK, *PSTACK; // Define PSTACK as a pointer to STACK structure

// Function to Initialise a new stack
void initStack(PSTACK stack){
    PNODE PNewNode = malloc(sizeof(NODE)); // Allocate memory for each new node
    // If allocation failed
    if (PNewNode == NULL){
        printf("Memory allocation failed!\n");
        exit(-1);
    }

    stack->PTOP = PNewNode; // Set the top pointer to the new node pointer
    stack->PBOTTOM = PNewNode; // Set the bottom pointer to the new node pointer
    PNewNode->next = NULL; // Initialise the next pointer to NULL
    printf("Stack successfully created!\n");
}

// Function to push to the stack
void PushStack(PSTACK stack, int data){
    PNODE P = malloc(sizeof(NODE));
    if(P == NULL){
        printf("Memory allocation failed!\n");
        exit(-1);
    }

    P->data = data; // Set the data in the new node
    P->next = stack->PTOP; // points the next pointer of the new node to the current top node
    stack->PTOP = P; // Updates the top pointer to P node
    printf("%d has been pushed onto the stack!\n", P->data);
}

// Function to pop the stack
void PopStack(PSTACK stack, int *data){
    // Check if the stack is empty
    if(stack->PBOTTOM == stack->PTOP){
        printf("Stack is empty!\n");
        return;
    }

    PNODE P = stack->PTOP; // Get the current top node
    *data = P->data; // Retrieve the data for the top node
    stack->PTOP = P->next; // Set the top pointer to the next node
    free(P); // Free the memory allocated to P
    P = NULL; // Set the pointer to NULL to avoid dangling reference
    printf("%d has been popped from the stack!\n", *data);
}

int main(){
    STACK stack;
    initStack(&stack);

    // Push some data onto the stack
    PushStack(&stack, 10);
    PushStack(&stack, 20);
    PushStack(&stack, 30);

    int value;

    // Pop the stack's top value
    PopStack(&stack, &value);
    PopStack(&stack, &value);
    PopStack(&stack, &value);
    PopStack(&stack, &value);

    return 0;
}
