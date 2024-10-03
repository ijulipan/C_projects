// Define a node structure
typedef struct Node {
    ElementType Element; // Element stored in the node
    struct  Node* next; // Pointer to the next node
} NODE, *PNODE; // Define PNODE as a pointer to NODE

// Define the stack structure
typedef struct Stack{
    PNODE PTOP; // Pointer to the top node of the stack
    PNODE PBOTTOM; // Pointer to the bottom node of the stack
} STACK, *PSTACK; // Define PSTACK as a pointer to STACK

// Function to initialize a new stack
void InitStack(PSTACK Stack){
    PNODE PNew = (PNODE)malloc(sizeof(NODE)); // Allocate memory for a new node
    if (PNew == NULL){
        printf("Failed to allocate memory for new node!\n");
        exit(-1);
    }
    Stack->PTOP = PNew; // Set the top pointer to the new node
    Stack->PBOTTOM = PNew; // Set the bottom pointer to the new node
    PNew->next = NULL; // Initialize the next pointer to NULL
    printf("Stack created successfully!\n");
}


// Function to Push onto the stack
void PushStack(PSTACK Stack, int val){
    PNODE P = (PNODE)malloc(sizeof(NODE)); // Allocate memory for a new node
    if (P == NULL){
        printf("Failed to allocate memory for new node!\n");
        exit(-1);
    }
    P->Element = val; // Assign the value to the node's element
    P->next = Stack->PTOP; // Point the new node to the current top node
    Stack->PTOP = P; // Update the top pointer to the new node
}

//Function to Pop from the stack
void PopStack(PSTACK Stack, int *val){
    if(Stack->PBOTTOM == Stack->PTOP){ // Check if the stack is empty
        printf("Stack is empty!\n");
        return;
    }
    PNODE P = Stack->PTOP; // Get the current top node
    *val = P->Element; // Retrieve the value from the top node
    Stack->PTOP = P->next; // Update the top pointer to the next node
    free(P); // Free the memory of the popped node
    P = NULL; // Set the pointer to NULL to avoid dangling reference
    printf("%d has been popped from the stack!\n", *val);
}