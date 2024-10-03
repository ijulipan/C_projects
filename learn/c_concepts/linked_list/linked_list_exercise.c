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

// STU structure
struct STU{
    int id;
    char name[50];
    struct STU* next;
};

//Modify a node to include different data or different structure alltogether
void change(struct STU* head, int n){
    struct STU* p = head;
    int i = 0;

    while(i < n && p != NULL){
        p = p->next;
        i++;
    }
    if(p != NULL){
        printf("Enter new data:\n");
        scanf("%d %s", &p->id, &p->name);
    } else{
        printf("Node does not exist!\n");
    }
}

int main(){

    struct node *head = create(5);

    InsertNode(head, 3);
    printLinkedLists(head);

    struct STU *head2;
    change(head2, 2);
    printLinkedLists(head);


}