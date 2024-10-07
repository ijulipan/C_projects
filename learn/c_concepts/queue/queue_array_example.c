#include <stdio.h>
#include <stdlib.h>

#define max 5

typedef struct Queue{
    int data[max];
    int front;
    int rear;
} QUEUE, *PQUEUE;

void initQueue(PQUEUE queue){
    queue->front = 0;
    queue->rear = 0;
    printf("Queue initialised.\n");
}

int isEmpty(PQUEUE queue){
    return (queue->front == queue->rear);
}

int isFull(PQUEUE queue){
    return((queue->rear + 1) % max == queue->front);
}

void enQueue(PQUEUE queue, int element){
    if(isFull(queue)){
        printf("Queue is full, cannot add element %d\n", element);
        return;
    }

    queue->data[queue->rear] = element;
    queue->rear = (queue->rear + 1) % max;
    printf("%d enqueued.\n", element);
}

void deQueue(PQUEUE queue){
    if(isEmpty(queue)){
        printf("Queue is empty, nothing to dequeue.\n");
        return;
    }

    int data = queue->data[queue->front];
    queue->front = (queue->front + 1) % max;
    printf("%d dequeued.\n", data);
}

void peekQueue(PQUEUE queue){
    if(isEmpty(queue)){
        printf("Queue is empty.\n");
    } else{
        printf("Front element: %d", queue->data[queue->front]);
    }
}

int main(){
    QUEUE queue;
    initQueue(&queue);

    for(int i = 0; i < max; i++){
        enQueue(&queue, i);
    }

    peekQueue(&queue);
    deQueue(&queue);

    for(int f = 0; f < max; f++){
        deQueue(&queue);
    }

    peekQueue(&queue);
    return 0;
}