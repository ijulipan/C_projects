# STACK & USAGE

## Stack ## 

A data structure following the Last In First Out (LIFO) principle. Elements are *pushed* (added) to the top of the stack and *popped* (removed) from the top, allowing access to only the most recently added item. 

Stacks are commonly used in recursive algorithms and for tracking function calls.

**LIFO Principle**: The most recently added element is the first one to be removed. This can be visualized as below:

![Stack Visualization](/etc/stack-768.png)

It is widely used in programming for tasks such as function calls, expression evaluation, and backtracking algorithms.

An example of how to create and manipulate a stack data structure using **linked nodes** is shown at [stacked data structure](/learn/c_concepts/stack/stack_data_struct.c).


## -> Operator ##

It is used when a pointer is used to point to a structure, it cannot access its members using the `.` operator. For example:

```C
struct data{
    int data;
    char string;
}

struct data *newdata;

// Accessing the members in a structure 
newdata.data = 3; // This won't work.
newdata->data = 3; // This will work.
```

This is because pointers don't contain the actual structure data, it just holds the address of the structure.

The operator `->` combines two actions:
  - Dereference the pointer 
  - Access the specified member of the structure