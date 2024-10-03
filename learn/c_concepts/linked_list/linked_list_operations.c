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
void change(struct Stu* head, int n) {
    struct Stu* p = head;
    int i = 0;
    
    // Traverse to the nth node
    while (i < n && p != NULL) {
        p = p->next;
        i++;
    }

    if (p != NULL) {
        printf("Insert new data:\n");
        scanf("%d%s", &p->id, p->name); // Modify the node's data
    } else {
        printf("Node does not exist！\n"); 
    }


// Reverses a linked list by reversing the direction of the links between nodes
STU* link_reversed_order(STU* head) {
    STU *pf = NULL, *pb = NULL, *tmp = NULL;
    pf = head; // Initialize pf with the head

    if (head == NULL) {
        printf("Empty list, no need to reverse！\n"); 
        return head;
    } else if (head->next == NULL) {
        printf("Single node, no need to reverse！\n"); 
        return head;
    } else {
        pb = pf->next; // pb points to the next node
        head->next = NULL; // Set head’s next to NULL (head becomes the tail)

        while (pb != NULL) {
            tmp = pb; // Temporarily store pb
            pb = pb->next; // Move pb to the next node
            tmp->next = pf; // Reverse the link
            pf = tmp; // Move pf to tmp
        }
        head = pf; // New head of the reversed list
        return head;
    }
}