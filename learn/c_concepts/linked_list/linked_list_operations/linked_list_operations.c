struct link{
    int data;
    struct link *next;
};

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

// Deletes the node at position n in the linked list
void deleteNode(struct link* head, int n){
    struct link *p = head, *pr = head;
    int i = 0;

    // Traverse to the nth node
    while(i < n && p != NULL){
        pr = p; // Save current node as previous
        p = p->next; // Move the next node
        i++;
    }

    if (p != NULL){
        pr->next = p->next; // Skip over the node to be deleted
        free(p); // Free the memory for the deleted node
    } else{
        printf("Node does not exist!\n");
    }
}

// Inserts a new node at position n in the linked list
void insertNode(struct link* head, int n){
    struct link *p = head, *pr;
    pr = (struct link*)malloc(sizeof(struct link)); // Allocate memory for the new node 
    printf("Input data:\n");
    scanf("%d", &pr->data); // Input data for new node

    int i = 0;
    while (i < n && p != NULL){
        p = p->next;
        i++;
    } 
    
    if (p != NULL){
        pr->next = p->next; // Point the new node to the next node in the list
        p->next = pr; // Insert the new node in the list
    } else{
        printf("Node does not exist!\n");
    }
}


// Modifies an existing node in the linked list
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


// Reverses a linked list by reversing the direction of the links between nodes
struct link* link_reversed_order(struct link* head) {
    struct link *previous = NULL, *current = NULL, *next = NULL;
    current = head->next; // Initialize current node to the first node

    while(current != NULL){
        next = current->next; // set next to the next node of the current node
        current->next = previous; // Set the current pointer to point to the previous node
        previous = current; // Set the previous node to the current node
        current = next; // Set the current node to the next node
    }
    head->next = previous; // Point the head to the previous node
    return head;
    }