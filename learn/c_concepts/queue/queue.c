#define max 5 // Maximum size of the queue

int enQueue(int *a, int front, int rear, int data){
    // Check if the queue is full
    if((rear + 1) % max == front){
        printf("Queue is full\n");
        return rear; // Return the current rear if the queue is full
    }
    a[rear % max] = data; // Insert data into the queue
    rear++; // Move rear pointer forward
    return rear; // Return the updated rear
}

int deQueue(int *a, int front, int rear){
    // Check if the queue is empty
    if(front == rear % max){
        printf("Queue is empty\n");
        return front; // Return the current fron if the queue is empty
    }

    printf("%d\n", a[front]); // Print the data at the front of the queue
    // Move front pointer forward and wrap around if needed
    front = (front + 1) % max;
    return front; // Return the updated front
}