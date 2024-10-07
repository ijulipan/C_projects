# QUEUE & USAGE

## Queue ##

Queue is similar to a stack which has requirements on how data is stored and retreived. However, unlike a stack, queue has two open ends which means that data enter via one end and exit from the other. Refer the illustration below:

![Queue illustraition](/etc/Queue.png)

As shown in the illustration, queue structure has two ends:

- Data entry - The end where data enters the queue is called the **rear**. The process of adding data is called **enqueue**.
- Data Exit - The end where data exits the queue is called the **front**. The process of removing data is called **dequeue**.

Similar to stack, Queue also follows a principle which is the **First In, First Out (FIFO)** principle, meaning that the first element added to the queue will be the first to be removed.

**Note**: In C, Queue is usually used in arrays.

## USAGE ##

### Basic Operations ###

Queue has the following operations:

- **Enqueue**: Add an element to the queue
- **Dequeue**: Remove an element from the queue
- **IsEmpty**: Checks if the queue is empty
- **IsFull**: Checks if the queue is full
- **Peek**: Gets the value of the front of the queue without removing it

An example code using *queue with linked lists* can be found at [queue in linked lists](/learn/c_concepts/queue/queue_list_example.c).

An example code using *queue with arrays* can be found at [queue in arrays](/learn/c_concepts/queue/queue_array_example.c)

### Applications of Queue ###

- CPU scheduling, Disk Scheduling
- When data is transferred asynchronously between two processes. The queue is used for synchronization. For example: IO Buffers, pipes, file IO, etc

- Handling of interrupts in real-time systems.

- Call Center phone systems use Queues to hold people calling them in order.