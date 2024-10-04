#include <stdio.h>
#include <stdlib.h>

// Double Circular Data Structure
struct DoubleCircular{
    struct DoubleCircular *previous;
    int data;
    struct DoubleCircular *next;
};

// Create the nodes
struct DoubleCircular* createNode(){
    struct DoubleCircular *newNode = malloc(sizeof(struct DoubleCircular));

    // Initialise the node with given data and set both pointers to NULL
    printf("Enter data: ");
    scanf("%d", &newNode->data);
    newNode->next = NULL;
    newNode->previous = NULL;

    return newNode;
}

// Insert the nodes via the head
void InsertByHead(struct DoubleCircular* headnode, int n){
    struct DoubleCircular *newnode, *temp;
    temp = headnode->next;

    for(int i = 0; i < n; i++){
        // Create the new nodes
        struct DoubleCircular *newnode = createNode();

        newnode->previous = headnode; // newnode's previous points towards the headnode
        newnode->next = headnode->next; // newnode's next points towards the headnode's next pointer (head or first node inputted)
        headnode->next->previous = newnode; // headnode or node after headnode's previous points back to the newnode
        headnode->next = newnode; // headnode's next points to the newnode
    }
}

// Insert the nodes via the tail
void InsertByTail(struct DoubleCircular* headnode, int n){
    struct DoubleCircular *newnode, *lastnode;

    // Loops through and creates the number of nodes specified
    for(int i = 0; i < n; i++){
        newnode = createNode();
        lastnode = headnode;

        //Traverse the list and reach the end of the list
        while(lastnode->next != headnode){
            lastnode = lastnode->next;
        }

        headnode->previous = newnode; // The Head node's previous points to the new node
        newnode->next = headnode; // The new node's next points to the Head
        lastnode->next = newnode; // The last node's next points to the new node
        newnode->previous = lastnode; // The new node's previous points to the last node
    }
}

void NodeDelete(struct DoubleCircular* headnode, int deldata){
    struct DoubleCircular *specNode, *prevNode;
    specNode = headnode->next; // Pointer to the specified node
    prevNode = headnode; // Pointer to the previous node

    // Loop through the list and find the specified node
    while(specNode->data != deldata){
        prevNode = specNode;
        specNode = prevNode->next;

        // Error handling if node is not found
        if(specNode->next == headnode){
            printf("Node does not exist!\n");
            return;
        }
    }
    prevNode->next = specNode->next; // The previous node's next points to the specified node's next (skipping the speicfied node)
    specNode->next->previous = prevNode; // The node after the specified node's previous points back to the previous node (skipping the specified node)
    free(specNode); // Free the memory occupied by the specified node
}

void ModifyNode(struct DoubleCircular* headnode, int data, int moddata){
    struct DoubleCircular *specNode, *prevNode;
    specNode = headnode->next; // Pointer to the specified node
    prevNode = headnode; // Pointer to the previous node

    // Loop through the list and find the specified node
    while(specNode->data != data){
        prevNode = specNode;
        specNode = prevNode->next;

        // Error handling if node is not found
        if(specNode->next == headnode){
            printf("Data does not exist!\n");
            return;
        }
    }

    // Modifies the data
    specNode->data = moddata;
    printf("Modification successful!\n");
}

// Traverse the linked list and print the list
void printLinkedLists(struct DoubleCircular *head){
    struct DoubleCircular *temp = head->next;

    // Head is placed to visualize the circular list
    printf("Linked List: Head <-> ");

    while (temp != head){
        printf("%d <-> ", temp->data);
        temp = temp->next;
    }
    printf("Head\n");
}

// Create the linked list
struct DoubleCircular* create(int n){
    struct DoubleCircular *headnode = malloc(sizeof(sizeof(struct DoubleCircular)));

    // Initialise both headnode's previous and next pointers to itself
    headnode->next = headnode;
    headnode->previous = headnode;

    // Create and insert the nodes to the list
    // InsertByHead(headnode, n);
    InsertByTail(headnode, n);

    return headnode;
}



int main(){
    struct DoubleCircular *head = create(5);
    printLinkedLists(head);

    // NodeDelete(head, 3);
    // ModifyNode(head, 3, 69);

    // printLinkedLists(head);
}