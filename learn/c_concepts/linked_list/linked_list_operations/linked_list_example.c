#include <stdio.h>
#include <stdlib.h>

// Create a node
struct node{
    int value;
    struct node *next;
};

// Print the linked list values
void printLinkedList(struct node *p){
    // First value will print a garbage value because no value was given to head, if you want, you can use head a just a pointer or assign a value to head.
    while(p != NULL){
        printf("%d ", p->value);
        p = p->next;
    }
    free(p);
}

int main(){
    // Initialize the nodes and points to the address of the new nodes
    struct node *head = NULL;
    struct node *one = NULL;
    struct node *two = NULL;
    struct node *three = NULL;

    // Allocate memory the new nodes
    head = malloc(sizeof(struct node));
    one = malloc(sizeof(struct node));
    two = malloc(sizeof(struct node));
    three = malloc(sizeof(struct node));

    // Assign value values
    one->value = 1;
    two->value = 2;
    three->value = 3;

    // Connect the nodes
    head->next = one;
    one->next = two;
    two->next = three;
    three->next = NULL;

    // Save address of first node in head & skips printing head
    // head = one;
    
    // Printing node-values
    printLinkedList(head);
}