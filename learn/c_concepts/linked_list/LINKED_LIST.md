# LINKED LIST & USAGE

## Linked List ##

![linked list data structure](/etc/Singlelinkedlist.png)

Linked list is a non-continguous, non-sequential storage structure in physical memory. It is a linear data structure that is a series of connected nodes as shown above.

The logical order of the data elements is achieved using pointers. Each element contain two parts: 
1. *data*, memory space for the element 
2. *pointer*, that stores the address of the next node.

```C
struct node{
    int data; // Defines the data field
    struct node *next; // Defines the pointer field, storing the next node
};
```

`struct node *next` creates a pointer of `struct node` type which will store the address of the next node.

### Creation of Linked list ###

For example:
```C
struct link* create(int n){
    struct link *headnode, *node;
    headnode = malloc(sizeof(struct link)); // Allocate memory for the head node
    headnode->next = NULL; // Set the head node's pointer to NULL

    for (int i = 0; i < n; i++){
        node = malloc(sizeof(struct link)); // Allocate memory for new node
        scanf("%d", &node->data); // Input data into the new node
        node->next = headnode->next; // New node points to the current head's next
        headnode->next = node; // Head node points to the new node (new node becomes the last)
    }
    return headnode; // Return the head node
}
```
The structure builds the linked list by inserting a new node at the beginning (after `headnode`). Thus, the latest node will become the first node in the list. For example, given data entered in the order `5, 3, 7`, the linked list will look as follows:
`7 -> 3 -> 5 -> NULL`
`headnode -> [data: 7, next: [data: 3, next: [data: 5, next: NULL]]]`

For more reference, please refer to [linked list example code](/learn/c_concepts/linked_list/linked_list_operations/linked_list_example.c).

### Deletion of nodes ###

For example:

```C
void deleteNode(struct link* head, int n){
    struct link *p = head, *pr = head;
    int i = 0;

    while(i < n && p != NULL){
        pr = p; 
        p = p->next; 
        i++;
    }

    if (p != NULL){
        pr->next = p->next; 
        free(p); 
    } else{
        printf("Node does not exist!\n");
    }
}
```

As shown above, a function called `deleteNode` was created and was called to delete the specified node, `n`. The function loops through the linked list until it finds the specified node and does some assignments where they reassign `pr->next` which is the previous node to the specified node and assign it to `p-next`. Visualization is as below:

```
 [HEAD] -> [SPECIFIED_NODE] -> [NODE] -> NULL
 [HEAD] -> [NODE] -> NULL
```

### Insert new nodes to Existing Lists ###

For reference:

```C
void insertNode(struct link* head, int n){
    struct link *p = head, *pr;
    pr = (struct link*)malloc(sizeof(struct link)); 
    printf("Input data:\n");
    scanf("%d", &pr->data); 

    int i = 0;
    while (i < n && p != NULL){
        p = p->next;
        i++;
    } 
    
    if (p != NULL){
        pr->next = p->next; 
        p->next = pr; 
    } else{
        printf("Node does not exist!\n");
    }
}
```

Similar to [Node Deletion](#deletion-of-nodes), it will loop through the list and find the specified node, and insert a new node after node, `p`.

```
 [HEAD] -> [SPECIFIED_NODE] -> [NODE] -> NULL
 [HEAD] -> [SPECIFIED_NODE] -> [NEW_NODE] -> [NODE] -> NULL
```

### Modifying data in existing nodes ###

For reference:

```C
void change(struct link* head, int n) {
    struct link* p = head;
    int i = 0;
    
    // Traverse to the nth node
    while (i < n && p != NULL) {
        p = p->next;
        i++;
    }

    if (p != NULL) {
        printf("Insert new data:\n");
        scanf("%d", &p->data); // Modify the node's data
    } else {
        printf("Node does not exist！\n"); 
    }
```
A function is used to loop through and find the specified node and asks the user to insert new data. 
If the specified node is not located, an error message will be shown.

### Reversing the linked list ###

For reference:

```C
struct link* link_reversed_order(struct link* head) {
    struct link *previous = NULL, *current = NULL, *next = NULL;
    current = head->next; 

    while(current != NULL){
        next = current->next; 
        current->next = previous; 
        previous = current; 
        current = next; 
    }
    head->next = previous; 
    return head;
    }
```

To refer and view an example code, go to [linked list operations](/learn/c_concepts/linked_list/linked_list_operations/linked_list_exercise.c).


## Double Circular Linked List ##

![Double Circular Linked List Visualisation](/etc/Circular-doubly-linked-list.png)

A Double Circular Linked list is a type of linked list where each node has pointers to the next and previous nodes and the last node connects back to the head, forming a circular image.


### Double Circular Data Structure ###

For reference;

```C
struct doubleCircularLinkedList{
    struct doubleCircularLinkedList *previous; 
    int data; 
    struct doubleCircularLinkedList *next; 
};
```

A Double Circular Linked List has a data structure as shown above, where two pointer types are used (previous and next) and a data type.


### Double Circular Initialisation ###

For reference:

```C
struct doubleCircularLinkedList* createList(){
    
    struct doubleCircularLinkedList* headnode =malloc(sizeof(struct doubleCircularLinkedList));

    
    headnode->previous = headnode;
    headnode->next = headnode;

    return headnode;
}


struct doubleCircularLinkedList createNode(int data){
    struct doubleCircularLinkedList *newNode = malloc(sizeof(struct doubleCircularLinkedList));

    
    newNode->data = data;
    newNode->next = NULL;
    newNode->previous = NULL;

    return newNode;
}
```

To simplify the steps to generate a double circular linked list, two functions were used `createList()` and `createNode` to create the list and the node.


### Double Circular Node Insertion ###

For reference:

```C
void insertNodeByHead(struct doubleCircularLinkedList* headnode, int data){
    struct doubleCircularLinkedList* newnode = createNode(data);

    newnode->previous = headnode; 
    newnode->next = headnode->next; 
    headnode->next->previous = newnode; 
    headnode->next = newnode; 
}

void insertNodeByTail(struct doubleCircularLinkedList *headnode, int data){
    struct doubleCircularLinkedList *newnode = createNode(data);

    struct doubleCircularLinkedList *lastnode = headnode;
    while(lastnode->next != headnode){
        lastnode = lastnode->next; 
    }

    headnode->previous = newnode; 
    newnode->next = headnode; 
    lastnode->next = newnode; 
    newnode->previous = lastnode; 
}
```

Double Circular Linked Lists supports adding new node by two way:
1. Head
2. Tail

Visual representation of how each insertion is conducted are shown below:

Insertion By Head
```C
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
```

Insertion By Tail
```C
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
```
### Double Circular Node Deletion ###

For reference:

```C
void SpecifyLocationToDelete(struct doubleCircularLinkedList *headnode, int posData){
    struct doubleCircularLinkedList *posNode = headnode->next; 
    struct doubleCircularLinkedList *posNodePrevious = headnode; 

   
    while(posNode->data != posData){
        posNodePrevious = posNode; 
        posNode = posNodePrevious->next; 

        
        if(posNode->next == headnode){
            printf("Specified position does not exist, cannot delete!");
            return;
        }
    }
    posNodePrevious->next = posNode->next; 
    posNode->next->previous = posNodePrevious; 

    free(posNode); 
}
```
Node deletion works the same way as singular linked lists, where it will loop through the list and locate the specified node. Afterwards, it will point the previous node's and next previous node's pointers to each other, ignoring the targeted node. It will then free the memory associated to the specified node to delete the node.

### Double Circular Element Modification ###

For reference:

```C
void modifySpecifiedElement(struct doubleCircularLinkedList *headnode, int posData, int elem){
    struct doubleCircularLinkedList* posNode = headnode->next; 
    struct doubleCircularLinkedList *posNodePrior = headnode; 

    while(posNode->data != posData){
        posNodePrior = posNode; 
        posNode = posNodePrior->next; 

        if(posNode->next == headnode){
            printf("Element does not exist!");
            return; 
        }
    }

    posNode->data = elem; 
    printf("Modification successful!");
    
}
```
Node modification works the same way as singular linked lists, where it will loop through the list and locate the specified node. Afterwards, it will assign the new element to the targeted node.

