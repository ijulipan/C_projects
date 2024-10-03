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

