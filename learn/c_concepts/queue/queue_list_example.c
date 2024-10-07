#include <stdio.h>
#include <stdlib.h>

#define MAX 5 // Set maximum queue size

// Node Structure
typedef struct Node{
    int data;
    struct Node* next;
}NODE, *PNODE;


// Queue structure
typedef struct Queue{
    PNODE front; // Pointer to the front node
    PNODE rear; // Pointer to the rear node
}QUEUE, *PQUEUE;

// Function to initialise the front and rear pointers
void initQueue(PQUEUE queue){
    queue->front = NULL;
    queue->rear = NULL;
    printf("Queue initialised.\n");
}

// Function to check if the queue is empty
int isEmpty(PQUEUE queue){
    return(queue->front == NULL);
}

// Function to add element to the queue
void enQueue(PQUEUE queue, int element){
    // Create a new node
    PNODE NewNode = malloc(sizeof(NODE));
    if(NewNode == NULL){
        printf("Memory allocation failed!\n");
        exit(-1);
    }

    NewNode->data = element;
    NewNode->next = NULL;

    // If it's an empty queue, sets the front and rear pointer to the new node
    if(isEmpty(queue)){
        queue->front = NewNode;
        queue->rear = NewNode;
    } else{
        queue->rear->next = NewNode; // Add the new node at the rear
        queue->rear = NewNode; // Update the rear pointer
    }
    printf("%d is enqueued.\n", element);
}

// Function to remove element from the queue
void deQueue(PQUEUE queue){
    // Check if the queue is empty
    if(isEmpty(queue)){
        printf("Queue is empty, Nothing to dequeue.\n");
        return;
    }

    // Get the front node's data
    PNODE temp = queue->front;
    int data = temp->data;

    //Move the front pointer to the next node
    queue->front = queue->front->next;

    // If the queue becomes empty, set the rear to NULL as well
    if(queue->front == NULL){
        queue->rear = NULL;
    }

    // Free the memory of the dequeued node
    free(temp);
    printf("%d dequeued.\n", data);
}

// Function to view the front node without dequeueing it
void peek(PQUEUE queue){
    if(isEmpty(queue)){
        printf("Queue is empty.\n");
    } else{
        printf("Current Front element: %d\n", queue->front->data);
    }
}

int main(){
    // Declare a new queue
    QUEUE queue;

    // Initialise the queue
    initQueue(&queue);

    // Create a MAX number of nodes to enqueue
    for (int i = 0; i < MAX; i++){
        enQueue(&queue, i);
    }

    // Peek the current front node
    peek(&queue);

    // Remove the first 2 nodes
    deQueue(&queue);
    deQueue(&queue);

    // Peek the new front node
    peek(&queue);

    // Remove the last node
    deQueue(&queue);

    // Peeking at an empty queue
    peek(&queue);

    return 0;
}