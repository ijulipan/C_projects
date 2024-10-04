// Structure of a Double Circular Linked List Node
struct doubleCircularLinkedList{
    struct doubleCircularLinkedList *previous; // Pointer to the previous node
    int data; // Data field
    struct doubleCircularLinkedList *next; // Pointer to the next node
};

// Creating a Double Circular Linked List
struct doubleCircularLinkedList* createList(){
    // Create a head node (often used as a placeholder or control node)
    struct doubleCircularLinkedList* headnode =malloc(sizeof(struct doubleCircularLinkedList));

    // Since it's a circular linked list, initialise both head node's previous and next pointer to itself
    headnode->previous = headnode;
    headnode->next = headnode;

    return headnode;
}

// Creating a new double circular node
struct doubleCircularLinkedList createNode(int data){
    struct doubleCircularLinkedList *newNode = malloc(sizeof(struct doubleCircularLinkedList));

    // Initialise the node with given data and set both pointers to NULL
    newNode->data = data;
    newNode->next = NULL;
    newNode->previous = NULL;

    return newNode;
}

void insertNodeByHead(struct doubleCircularLinkedList* headnode, int data){
    // Create a new node
    struct doubleCircularLinkedList* newnode = createNode(data);


    // Adjust four pointer variables at the head
    newnode->previous = headnode; // newnode's previous points towards the headnode
        /*
            [HEAD] <- [NEWNODE]  [HEAD/NODE]
        */
    newnode->next = headnode->next; // newnode's next points towards the headnode's next pointer (head or first node inputted)
        /*
            [HEAD] <- [NEWNODE] -> [HEAD/NODE]
        */
    headnode->next->previous = newnode; // headnode or node after headnode's previous points back to the newnode
        /*
            [HEAD] <- [NEWNODE] <-> [HEAD/NODE]
        */
    headnode->next = newnode; // headnode's next points to the newnode
        /*
            [HEAD] <-> [NEWNODE] <-> [HEAD/NODE]
        */
}

void insertNodeByTail(struct doubleCircularLinkedList *headnode, int data){
    struct doubleCircularLinkedList *newnode = createNode(data);

    struct doubleCircularLinkedList *lastnode = headnode;
    while(lastnode->next != headnode){
        lastnode = lastnode->next; // Move to the next node until the last one is found
    }

    headnode->previous = newnode; // Head's previous point to the new node
    /*
        [HEAD/NODE] <-> [LASTNODE]  [NEWNODE] <- [HEAD]
    */
    newnode->next = headnode; // The new node's next points to head
    /*
        [HEAD/NODE] <-> [LASTNODE]  [NEWNODE] <-> [HEAD]
    */
    lastnode->next = newnode; // The last node's next points to the new node
    /*
        [HEAD/NODE] <-> [LASTNODE] -> [NEWNODE] <-> [HEAD]
    */
    newnode->previous = lastnode; // The new node's previous point to the last node
    /*
        [HEAD/NODE] <-> [LASTNODE] <-> [NEWNODE] <-> [HEAD]
    */
}

// Function to locate and delete a node
void SpecifyLocationToDelete(struct doubleCircularLinkedList *headnode, int posData){
    struct doubleCircularLinkedList *posNode = headnode->next; // Pointer to the specified node
    struct doubleCircularLinkedList *posNodePrevious = headnode; // Pointer to the previous node

    // Find the specified node
    while(posNode->data != posData){
        posNodePrevious = posNode; // Move to the next node
        posNode = posNodePrevious->next; // Update the posNode pointer

        // Handling if the node is not found
        if(posNode->next == headnode){
            printf("Specified position does not exist, cannot delete!");
            return;// Exit if the node is not found
        }
    }
    posNodePrevious->next = posNode->next; // Previous node's next points to the node after the specified node
    posNode->next->previous = posNodePrevious; // The node after the specified node points back to the previous node

    free(posNode); // Free the memory of the deleted node
}

// Modifying a specified element
void modifySpecifiedElement(struct doubleCircularLinkedList *headnode, int posData, int elem){
    struct doubleCircularLinkedList* posNode = headnode->next; // Pointer to the specified node
    struct doubleCircularLinkedList *posNodePrior = headnode; // Pointer to the previous node


    // Find the specified element
    while(posNode->data != posData){
        posNodePrior = posNode; // Move to the next node
        posNode = posNodePrior->next; //Update the posnode pointer

        // Handling if node not found
        if(posNode->next == headnode){
            printf("Element does not exist!");
            return; // Exit if element is not found
        }
    }

    //Modify the data of the found node
    posNode->data = elem; // Set the new value
    printf("Modification successful!");
    
}