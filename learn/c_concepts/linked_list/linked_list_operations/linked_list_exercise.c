#include <stdio.h>
#include <stdlib.h>

// Create a node
struct node{
    int data;
    struct node *next;
};

// Create the linked list
struct node *create(int n){
    struct node *headnode, *tempnode;

    headnode = malloc(sizeof(struct node));
    headnode->next = NULL;

    for(int i = 0; i < n; i++){
        tempnode = malloc(sizeof(struct node));
        printf("Enter data: ");
        scanf("%d", &tempnode->data);
        tempnode->next = headnode->next;
        headnode->next = tempnode;
    }
    
    return headnode;
}

// Traverse and print the linked list
void printLinkedLists(struct node *head){
    struct node *temp = head->next;

    printf("Linked List: ");
    while (temp != NULL){
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}


// Insert new node to the list
void InsertNode(struct node *head, int n){
    struct node *p = head, *pr;
    pr = malloc(sizeof(struct node));

    printf("Enter new data: ");
    scanf("%d", &pr->data);

    int i = 0;
    while(i < n && p != NULL){
        p = p->next;
        i++;
    }
    if(p != NULL){
        pr->next = p->next;
        p->next = pr;
    } else {
        printf("Node does not exist!\n");
    }
}

//Modify a node to include different data or different structure alltogether
void change(struct node* head, int n){
    struct node* p = head;
    int i = 0;

    while(i < n && p != NULL){
        p = p->next;
        i++;
    }
    if(p != NULL){
        printf("Enter new data: ");
        scanf("%d" , &p->data);
    } else{
        printf("Node does not exist!\n");
    }
}

// Reverse a linked list
struct node* link_reversed_order(struct node* head){
    struct node *previous = NULL, *current = NULL, *next = NULL;

    current = head->next; // Start from the first node
    while(current != NULL)
    {
        next = current->next; // Store the next node to 'next'
        current->next = previous; // Reverse the link
        previous = current; // Move previous pointer one step ahead
        current = next; // move current one step ahead
    }

    head->next = previous; // update head to point to the new head of the list
}

int main(){

    struct node *head = create(5);

    // InsertNode(head, 3);
    printLinkedLists(head);
    head = link_reversed_order(head);
    printLinkedLists(head);
    
    // change(head, 2);
    // printLinkedLists(head);


}